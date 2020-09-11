#ifndef _KD_TREE_H_
#define _KD_TREE_H_


// A kd tree

typedef struct
{
    //　Cell size
    double size[3];

    // The root node of the tree
    tree_node_t *root;

    // The number of nodes in the tree
    int node_count, node_max_count;

    // The number of leaf in the tree
    int leaf_count;

    tree_node_t *nodes;
} kd_tree;



// Info for a node in kd tree
typedef struct tree_node
{
    // If leaf; Depth in the tree
    int leaf, depth;

    // Pivot dimension and value
    int pivot_dim;
    double pivot_value;

    // The key for this node
    int key[3];

    // The value for this node
    double value;

    // The cluster label
    int cluster;

    // Child nodes
    struct kdtree_node *children[2];
} tree_node_t;

typedef struct 
{
    double p[3];
} p_vector;


// Create a tree
extern kd_tree *tree_alloc(int max_size);

// Destory a tree
extern void tree_free(kd_tree *self);

// Insert a node into the tree
extern void tree_insert(kd_tree *self, p_vector pose, double value);

// Cluster the tree
extern void tree_cluster(kd_tree *self);

extern int get_cluster(kd_tree *self, p_vector pose);

#endif