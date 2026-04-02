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
        }
    } else {
        if (root->right != nullptr) {
            insert_node(root->right, value);
        } else {
            root->right = createNode(value);
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

bool search_branch(const TreeNode *current,const int value) {
    if (current == nullptr) {
        return false;
    }

    if (current->data == value) {
        return true;
    }

    if (value < current->data) {
        return search_branch(current->left, value);
    }

    return search_branch(current->right, value);
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