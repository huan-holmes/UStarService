#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "radar_process/kd_tree.h"

// Create a tree
kd_tree *tree_alloc(int max_size)
{
    kd_tree *self;
    self = calloc(1, sizeof(kd_tree));
    self->size[0] = 0.50;
    self->size[1] = 0.50;
    self->size[2] = (10 * M_PI / 180);

    self->leaf_count = 0;

    self->root = NULL;
    self->node_count = 0;
    self->node_max_count = max_size;
    self->nodes = calloc(self->node_max_count, sizeof(tree_node_t));
    
    self->cluster_d = 0.5;
    self->cluster_count = 0;
    self->cluster_max_count = max_size;
    self->clusters = calloc(self->node_max_count, sizeof(tree_cluster_t));
    return self;
}

// Destory a tree
void tree_free(kd_tree *self)
{
    free(self->nodes);
    free(self);
}

tree_node_t *tree_insert_node(kd_tree *self, tree_node_t *parent, tree_node_t *node, int key[], double value, p_vector pose)
{
    int i;
    int split, max_split;

    if (node == NULL)
    {
        assert(self->node_count < self->node_max_count);
        node = self->nodes + self->node_count++;
        memset(node, 0, sizeof(tree_node_t));

        node->leaf = 1;

        if (parent == NULL)
            node->depth = 0;
        else
            node->depth = parent->depth + 1;
        
        for (i = 0; i < 3; i++)
            node->key[i] = key[i];
        
        node->value = value;
        node->pose = pose;
        self->leaf_count += 1;
    }
    else if (node->leaf)
    {
        if (tree_node_equal(self, key, node->key))
        {
            node->value += value;
        }
        else
        {
            max_split = 0;
            node->pivot_dim = -1;
            for (i = 0; i < 3; i++)
            {
                split = abs(key[i] - node->key[i]);
                if (split > max_split)
                {
                    max_split = split;
                    node->pivot_dim = i;
                }
            }
            assert(node->pivot_dim >= 0);
            
            node->pivot_value = (key[node->pivot_dim] + node->key[node->pivot_dim]) / 2.0;
            
            if (key[node->pivot_dim] < node->pivot_value)
            {
                node->children[0] = tree_insert_node(self, node, NULL, key, value, pose);
                node->children[1] = tree_insert_node(self, node, NULL, node->key, node->value, node->pose);
            } 
            else
            {
                node->children[0] = tree_insert_node(self, node, NULL, node->key, node->value, node->pose);
                node->children[1] = tree_insert_node(self, node, NULL, key, value, pose);
            }

            node->leaf = 0;
            self->leaf_count -= 1;
            
        }
        
    }
    else
    {
        assert(node->children[0] != NULL);
        assert(node->children[1] != NULL);
        if (key[node->pivot_dim] < node->pivot_value)
            tree_insert_node(self, node, node->children[0], key, value, pose);
        else
            tree_insert_node(self, node, node->children[1], key, value, pose);
        
    }
    
}
// Insert a node into the tree
void tree_insert(kd_tree *self, p_vector pose, double value)
{
    int key[3];

    key[0] = floor(pose.p[0] / self->size[0]);
    key[1] = floor(pose.p[1] / self->size[1]);
    key[2] = floor(pose.p[2] / self->size[2]);

    self->root = tree_insert_node(self, NULL, self->root, key, value, pose);
    
    return;
}





tree_node_t *tree_find_node(kd_tree *self, tree_node_t *node, int key[])
{
  if (node->leaf)
  {
    //printf("find  : leaf %p %d %d %d\n", node, node->key[0], node->key[1], node->key[2]);

    // If the keys are the same...
    if (tree_node_equal(self, key, node->key))
      return node;
    else
      return NULL;
  }
  else
  {
    //printf("find  : brch %p %d %f\n", node, node->pivot_dim, node->pivot_value);

    assert(node->children[0] != NULL);
    assert(node->children[1] != NULL);

    // If the keys are different...
    if (key[node->pivot_dim] < node->pivot_value)
      return tree_find_node(self, node->children[0], key);
    else
      return tree_find_node(self, node->children[1], key);
  }

  return NULL;
}
tree_node_t *tree_find_sim_node(kd_tree *self, tree_node_t *node, int key[])
{
    if (node->leaf)
    {
        if (tree_node_sim(self, node))
            return node;
        else
            return NULL;
    }   
    else
    {
        assert(node->children[0] != NULL);
        assert(node->children[1] != NULL);
        if (key[node->pivot_dim] < node->pivot_value)
            return tree_find_sim_node(self, node->children[0], key);
        else
            return tree_find_sim_node(self, node->children[1], key);
    }
    return NULL;
    
}




int tree_node_sim(kd_tree *self, tree_node_t *node)
{
    tree_cluster_t *cluster;
    cluster = self->clusters + node->cluster;
    double d = sqrt((cluster->mean.p[0] - node->pose.p[0]) * (cluster->mean.p[0] - node->pose.p[0]) +
                    (cluster->mean.p[1] - node->pose.p[1]) * (cluster->mean.p[1] - node->pose.p[1]));
    if (d > self->cluster_d)
        return 0;
    return 1;
}

int tree_node_equal(kd_tree *self, int key_a[], int key_b[])
{
    if (key_a[0] != key_b[0])
        return 0;
    if (key_a[1] != key_b[1])
        return 0;
    if (key_a[2] != key_b[2])
        return 0;
    return 1;
}

p_vector p_vector_zero()
{
    p_vector pz;
    pz.p[0] = 0;
    pz.p[1] = 0;
    pz.p[2] = 0;
    return pz;
}

void tree_cluster(kd_tree *self)
{
    int i;
    int queue_count, cluster_count;
    tree_node_t **queue, *node;
    tree_cluster_t *cluster;
    queue_count = 0;
    queue = calloc(self->node_count, sizeof(queue[0]));

    for (i = 0; i < self->node_count; i++)
    {
        node = self->nodes + i;
        if (node->leaf)
        {
            node->cluster = -1;
            assert(queue_count < self->node_count);
            queue[queue_count++] = node;
            assert(node == tree_find_node(self, self->root, node->key));
        }
    }

    cluster_count = 0;
    while (queue_count > 0)
    {
        node = queue[--queue_count];
        if (node->cluster >= 0)
            continue;
        node->cluster = cluster_count;
        self->cluster_count = cluster_count;
        cluster = self->clusters + cluster_count;
        cluster->count = 1;
        cluster->mean = node->pose; 
        tree_cluster_node(self, node, 0);
        cluster_count += 1;
    }
    free(queue);
    return;
}

void tree_cluster_node(kd_tree *self, tree_node_t *node, int depth)
{
    int i;
    int nkey[3];
    tree_node_t *nnode;
    tree_cluster_t *cluster;
    
    for (i = 0; i < 3 * 3 * 3; i++)
    {
        nkey[0] = node->key[0] + (i / 9) - 1;
        nkey[1] = node->key[1] + ((i % 9) / 3) -1;
        nkey[2] = node->key[2] + ((i % 9) % 3) - 1;

        nnode = tree_find_sim_node(self, self->root, nkey);
        if (nnode == NULL)
            continue;

        assert(nnode->leaf);

        if (node->cluster >= 0)
        {
            assert(nnode->cluster == node->cluster);
            continue;
        }
        cluster = self->clusters + node->cluster;
        cluster->count += 1;
        cluster->mean.p[0] = (cluster->mean.p[0] * (cluster->count - 1) + nnode->pose.p[0]) / cluster->count;
        cluster->mean.p[1] = (cluster->mean.p[1] * (cluster->count - 1) + nnode->pose.p[1]) / cluster->count;
        cluster->mean.p[2] = (cluster->mean.p[2] * (cluster->count - 1) + nnode->pose.p[2]) / cluster->count;nnode->cluster = node->cluster;
        tree_cluster_node(self, nnode, depth + 1);
    }
    return;
}

int get_cluster(kd_tree *self, p_vector pose)
{
    int key[3];
    tree_node_t *node;
    key[0] = floor(pose.p[0] / self->size[0]);
    key[1] = floor(pose.p[1] / self->size[1]);
    key[2] = floor(pose.p[2] / self->size[2]);

    node = tree_find_node(self, self->root, key);
    if (node == NULL)
        return -1;
    return node->cluster;
}


