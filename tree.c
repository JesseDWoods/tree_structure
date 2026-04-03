//
// Created by Jesse on 3/28/2026.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"



TreeNode *createNode(const int val) {
    const auto temp = (TreeNode *)malloc(sizeof(TreeNode));
    if (temp == nullptr) {
        fprintf(stderr, "Error: out of memory while creating tree node.\n");
        exit(EXIT_FAILURE);
    }

    temp->data = val;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void insert_node(TreeNode *root,const int value) {
    if (root == nullptr) {
        return;
    }

    if (root->data == value) {
        return;
    }

    if (value < root->data) {
        if (root->left != nullptr) {
            insert_node(root->left, value);
        } else {
            root->left = createNode(value);
            root->left->parent = root;
        }
    } else {
        if (root->right != nullptr) {
            insert_node(root->right, value);
        } else {
            root->right = createNode(value);
            root->right->parent = root;
        }
    }
}

void insert(BinarySearchTree *tree, const int value) {
    if (tree == nullptr) {
        return;
    }

    if (tree->root == nullptr) {
        tree->root = createNode(value);
    } else {
        insert_node(tree->root, value);
    }
}
TreeNode* find_tree_node(BinarySearchTree *tree, const int value) {
    if (tree->root == nullptr) {
        return nullptr;
    }
    return search_branch(tree->root, value);
}

TreeNode* search_branch(TreeNode *current,const int value) {

    TreeNode *tree = current;
    while (tree != nullptr && value != tree->data) {
        if (value < tree->data) {
            tree = tree->left;
        }
        else {
            tree = tree->right;
        }
    }
    return tree;
}

bool search(const BinarySearchTree *tree,const int value) {
    if (tree == nullptr || tree->root == nullptr) {
        return false;
    }

    return search_branch(tree->root, value);
}

void free_tree(TreeNode *root) {

    if (root == nullptr) {
        return; // Base case: empty tree
    }

    // Recursively free left and right subtrees
    free_tree(root->left);
    free_tree(root->right);

    // Free the current node

    free(root);


}
void print_tree(const BinarySearchTree * tree) {

    if (tree == nullptr) {
        printf("Tree is empty\n");
        return;
    }
    print_branch(tree->root, "", true);

}

void print_branch(const TreeNode * node, char * prefix, const bool is_left) {
    if (node != nullptr) {
        if (is_left) {
            printf("%s|__%d\n", prefix, node->data);
        }
        else {
            printf("%s|--%d\n", prefix, node->data);
        }
        if (is_left) {
            const auto new_prefix = (char *)malloc(strlen(prefix) + 1);
            strcpy(new_prefix, prefix);
            strcat(new_prefix, " ");
            print_branch(node->left, new_prefix, true);
            print_branch(node->right,new_prefix, false);
        }
        else {
            const auto new_prefix = (char *)malloc(strlen(prefix) + 2);
            strcpy(new_prefix, prefix);
            strcat(new_prefix, "| ");
            print_branch(node->left, new_prefix, true);
            print_branch(node->right, new_prefix, false);
        }

    }
}

void delete_node(BinarySearchTree * tree, TreeNode * node) {

    if (tree->root == nullptr || node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        if (node->parent == nullptr) {
            tree->root = nullptr;
        }
        else if (node->parent->left == node) {
            node->parent->left = nullptr;
        }
        else {
            node->parent->right = nullptr;
        }
    }
    else if (node->left == nullptr || node->right == nullptr) {
        TreeNode * temp = node->left;
        if (node->left == nullptr) {
            temp = node->right;
        }
        temp->parent = node->parent;
        if (node->parent == nullptr) {
            tree->root = temp;
        }
        else if (node->parent->left == node) {
            node->parent->left = temp;
        }
        else {
            node->parent->right = temp;
        }
    }
    else {
        TreeNode * temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        delete_node(tree, temp);

        if (node->parent == nullptr) {
            tree->root = temp;
        }
        else if (node->parent->left == node) {
            node->parent->left = temp;
        }
        else {
            node->parent->right = temp;
        }

        temp->parent = node->parent;
        temp->left = node->left;
        node->left->parent = temp;
        temp->right = node->right;

        if (node->right == nullptr) {
            node->right->parent = temp;
        }
    }
    //free(node);
}