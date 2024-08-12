//
// Created by sullung on 7/30/24.
//

# include "LinkedList.h"

Node* SLL_CreateNode(ElementType NewData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = NewData;
    newNode->NextNode = NULL;
    return newNode;
}

void SLL_DestroyNode(Node* Node){
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode){
    if(*Head == NULL){
        *Head = NewNode;
    }
    else{
        Node* Tail = (*Head); // Head 부터 탐색
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode; // 새 노드를 List의 맨 끝에 삽입
    }
}

void SLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead){
    if(*Head == NULL){
        *Head = NewHead;
    }
    else{
        NewHead->NextNode = *Head;
        *Head = NewHead;
    }
}

void SLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head == Remove){
        *Head = Remove->NextNode;
    }
    else{
        Node* Current = *Head; // Head 부터 Remove 노드 이전 까지 탐색
        while(Current != NULL && Current->NextNode != Remove){
            Current = Current->NextNode;
        }

        if(Current != NULL){ // Remove 이전 노드를 찾은 경우
            Current->NextNode = Remove->NextNode;
        }
    }
}

Node* SLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(--Location > 0 && Current != NULL){
        Current = Current->NextNode;
    }
    return Current;
}

int SLL_GetNodeCount(Node* Head){
    Node* Current = Head;
    int Count = 0;
    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}