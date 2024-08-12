//
// Created by sullung on 8/12/24.
//

#include "BinarySearchTree.h"


BSTNode* BST_CreateNode( ElementType NewData ){
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (newNode == NULL) return NULL;

    newNode -> Left = NULL;
    newNode -> Right = NULL;
    newNode -> Data = NewData;
    return newNode;
}

void BST_DestroyNode( BSTNode* Node ){
    free(Node);
}

void BST_DestroyTree(BSTNode* Tree){

    if (Tree->Left != NULL){
        BST_DestroyTree(Tree->Left);
    }
    if (Tree->Right != NULL){
        BST_DestroyTree(Tree->Right);
    }

    Tree->Left = NULL;
    Tree->Right = NULL;

    BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target){
    if (Tree == NULL) return NULL;

    if (Tree->Data == Target){
        return Tree;
    }
    else if (Tree->Data > Target){
        return BST_SearchNode(Tree->Left, Target);
    }
    else {
        return BST_SearchNode(Tree->Right, Target);
    }
}

BSTNode* BST_SearchMinNode(BSTNode* Tree){

    if (Tree == NULL) return NULL;

    if ( Tree->Left == NULL ) return Tree;
    else return BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode* Tree, BSTNode *Child){

    if (Tree->Data == Child->Data) {
        return; // Ignore
    }
    else if (Tree->Data < Child->Data){
        if (Tree->Right == NULL) Tree->Right = Child;
        else BST_InsertNode(Tree->Right, Child);
    }
    else if (Tree->Data > Child->Data){
        if (Tree->Left == NULL) Tree->Left = Child;
        else BST_InsertNode(Tree->Left, Child);
    }
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target){

    BSTNode* RemovedNode = NULL;

    if (Tree == NULL) return NULL;

    if (Tree->Data > Target) {
        RemovedNode = BST_RemoveNode(Tree->Left, Tree, Target);
    }
    else if (Tree->Data < Target) {
        RemovedNode = BST_RemoveNode(Tree->Right, Tree, Target);
    }
    else { // Tree->Data == Target

        RemovedNode = Tree;

        // if RemovedNode is a Leaf node
        if (Tree->Left == NULL && Tree->Right == NULL){
            if (Parent != NULL) {
                if (Parent->Left == RemovedNode) {
                    Parent->Left = NULL;
                } else Parent->Right = NULL;
            }
        }

        // if RemovedNode has two children
        else if (Tree->Left != NULL && Tree->Right != NULL){
            // Find the least node in a right-side subtree with its root
            BSTNode* MinNode = BST_SearchMinNode(RemovedNode->Right);
            ElementType MinData = MinNode->Data;
            BST_RemoveNode(RemovedNode->Right, RemovedNode, MinData);
            RemovedNode->Data = MinData;
        }

        // if RemovedNode has one child
        else {
            BSTNode* Temp = (Tree->Left != NULL) ? Tree->Left : Tree->Right;
            if (Parent != NULL){
                if (Parent->Left == Tree) {
                    Parent->Left = Temp;
                }
                else {
                    Parent->Right = Temp;
                }
            }
            if (Tree == Parent) { // if Root node has one child
                Tree->Data = Temp->Data;
                Tree->Left = Temp->Left;
                Tree->Right = Temp->Right;
                RemovedNode = Temp;
            }
        }
    }
    return RemovedNode;
}

void BST_InorderPrintTree( BSTNode* Node )
{
    if ( Node == NULL )
        return;

    //  왼쪽 하위 트리 출력
    BST_InorderPrintTree( Node->Left );

    //  루트 노드 출력
    printf( "%d ", Node->Data );

    //  오른쪽 하위 트리 출력
    BST_InorderPrintTree( Node->Right );
}


