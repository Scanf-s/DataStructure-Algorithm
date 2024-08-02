//
// Created by sullung on 8/1/24.
//
#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity){
    // Capacity = number of nodes

    // Create Stack in Free Memory
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    // Allocate Memory for Nodes
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

    // Initialize
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack){
    // Free allocated Nodes in Free Memory
    free(Stack->Nodes);

    // Free allocated Stack in Free Memory
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data){
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack){
    int Position = Stack->Top--;
    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack){
    return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack){
    return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack){
    return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack* Stack){
    return (Stack->Top == Stack->Capacity - 1);
}