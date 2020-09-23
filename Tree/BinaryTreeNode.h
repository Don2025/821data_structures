#ifndef INC_821DATA_STRUCTURES_BINARYTREENODE_H
#define INC_821DATA_STRUCTURES_BINARYTREENODE_H

typedef int ElementType;
typedef struct binaryTreeNode {
    ElementType *data;
    struct binaryTreeNode *lchild,*rchild;
};
#endif //INC_821DATA_STRUCTURES_BINARYTREENODE_H
