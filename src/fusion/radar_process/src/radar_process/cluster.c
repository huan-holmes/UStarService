#include <assert.h>
#include <stdlib.h>
#include "radar_process/kd_tree.h"


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
