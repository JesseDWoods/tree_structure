#ifndef TREE_STRUCTURE_TREE_H
#define TREE_STRUCTURE_TREE_H


typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

typedef struct BinarySearchTree {
    TreeNode *root;
} BinarySearchTree;

TreeNode *createNode(int);
void insert(BinarySearchTree *, int);
void insert_node(TreeNode *, int);
bool search(const BinarySearchTree *, int);
TreeNode* find_tree_node(BinarySearchTree *, int);
TreeNode* search_branch(TreeNode *, int);
void print_tree(const BinarySearchTree *);
void print_branch(const TreeNode *, char *, bool);
void delete_node(BinarySearchTree *,TreeNode *);
void free_tree(TreeNode *);

#endif // TREE_STRUCTURE_TREE_H
