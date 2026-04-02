#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
    // Construct above tree
    const auto firstTree = (struct BinarySearchTree *)malloc(sizeof(struct BinarySearchTree));
    firstTree->root = nullptr;
    insert(firstTree, 65);
    insert(firstTree, 34);
    insert(firstTree, 33);
    insert(firstTree, 52);
    //insert(firstTree, 97);
    insert(firstTree, 71);
    insert(firstTree, 72);
    insert(firstTree, 12);
    insert(firstTree, 10);
    if (search(firstTree, 97)) {
        printf("This works!\n");
    }
    print_tree(firstTree);
    free_tree(firstTree->root);
    return EXIT_SUCCESS;
}
