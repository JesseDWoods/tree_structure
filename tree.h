#ifndef TREE_STRUCTURE_TREE_H
#define TREE_STRUCTURE_TREE_H


typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinarySearchTree {
    TreeNode *root;
} BinarySearchTree;

TreeNode *createNode(int);
void insert(BinarySearchTree *, int);
void insert_node(TreeNode *, int);
bool search(const BinarySearchTree *, int);
bool search_branch(const TreeNode *, int);
void print_tree(const BinarySearchTree *);
void print_branch(const TreeNode *, char *, bool);
void free_tree(TreeNode *);

#endif // TREE_STRUCTURE_TREE_H
