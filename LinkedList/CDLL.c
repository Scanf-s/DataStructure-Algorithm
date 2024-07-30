//
// Created by sullung on 7/30/24.
//
#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(ElementType NewData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = NewData;
    newNode->PrevNode = NULL;
    newNode->NextNode = NULL;
    return newNode;
}

void  CDLL_DestroyNode(Node* Node){
    free(Node);
}

void  CDLL_AppendNode(Node** Head, Node* NewNode){
    if (*Head == NULL){
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else{
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->PrevNode = Tail;
        NewNode->NextNode = *Head;
    }
}

void  CDLL_InsertAfter(Node* Current, Node* NewNode){
    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;

    NewNode->PrevNode = Current;
    NewNode->NextNode = Current->NextNode;
}

void  CDLL_RemoveNode(Node** Head, Node* Remove){
    if (*Head == Remove){
        if((*Head)->NextNode == *Head){
            // If Head node is the only one
            *Head = NULL;
        }
        else {
            (*Head)->PrevNode->NextNode = Remove->NextNode;
            (*Head)->NextNode->PrevNode = Remove->PrevNode;

            // Update Head
            *Head = Remove->NextNode;

            Remove->NextNode = NULL;
            Remove->PrevNode = NULL;
        }
    }
    else{
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }

    free(Remove);
    Remove = NULL;
}

Node* CDLL_GetNodeAt(Node* Head, int Location){
    if (Location == 0){
        return Head;
    }
    else{
        Node* Current = Head;
        while((--Location) > 0 && Current != NULL && Current != Head){
            Current = Current->NextNode;
        }
        return Current;
    }
}

size_t CDLL_GetNodeCount(Node* Head){
    if (Head == NULL) return 0;

    size_t Count = 1;
    Node* Current = Head;
    while(Current->NextNode != Head){
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}