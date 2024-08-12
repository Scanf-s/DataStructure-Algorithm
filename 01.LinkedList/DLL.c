//
// Created by sullung on 7/30/24.
//
#include "DoublyLinkedList.h"

Node* DLL_CreateNode( ElementType NewData ){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->PrevNode = NULL;
    newNode->Data = NewData;
    newNode->NextNode = NULL;
    return newNode;
}

void  DLL_DestroyNode( Node* Node){
    free(Node);
}

void  DLL_AppendNode( Node** Head, Node* NewNode ){
    if (*Head == NULL){
        *Head = NewNode;
    }
    else{
        Node* Tail = *Head;
        while(Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

void  DLL_InsertAfter( Node* Current, Node* NewNode ){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

void  DLL_RemoveNode( Node** Head, Node* Remove ){
    if(*Head == Remove){
        // if target is HEAD
        *Head = Remove->NextNode;
        if ( (*Head) != NULL ){
            (*Head)->PrevNode = NULL;
        }
        // After modify head pointer, remove target's pointer
        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
    else{
        // If the node to remove is not the head
        Node* temp = Remove;

        // Connect the previous node to the next node
        temp->PrevNode->NextNode = temp->NextNode;

        // If it's not the last node, connect the next node to the previous node
        if (temp->NextNode != NULL){
            temp->NextNode->PrevNode = temp->PrevNode;
        }

        // Clear the pointers of the node to be removed
        temp->PrevNode = NULL;
        temp->NextNode = NULL;
    }
}

Node* DLL_GetNodeAt( Node* Head, int Location ){
    int MIN = 0;

    if (Head == NULL){
        return NULL;
    }
    else {
        Node *Current = Head;
        while((--Location) > MIN && Current != NULL){
            Current = Current->NextNode;
        }
        return Current;
    }
}

size_t DLL_GetNodeCount( Node* Head ){
    size_t Count = 0;

    if (Head == NULL){
        return Count;
    }
    else{
        Node* Current = Head;
        while(Current != NULL){
            Current = Current->NextNode;
            Count++;
        }
        return Count;
    }
}