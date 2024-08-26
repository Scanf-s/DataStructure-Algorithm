#include "GraphTraversal.h"

void DFS( Vertex* V ){
    if (V == NULL) return;

    printf("%d", V->Data);
    V->Visited = Visited;
    Edge* EdgeElement = V->AdjacencyList;

    while (EdgeElement != NULL) {
        if (EdgeElement->Target->Visited == NotVisited && EdgeElement->Target != NULL) {
            DFS(EdgeElement->Target);
        }
        EdgeElement = EdgeElement->Next;
    }
}

void BFS( Vertex* V, LinkedQueue* Queue ){

    printf("%d", V->Data);
    V->Visited = Visited;
    LQ_Enqueue( Queue, LQ_CreateNode( V ) );

    while( !LQ_IsEmpty( Queue ) ){
        Node* PoppedNode = LQ_Dequeue(Queue);
        Edge* EdgeElement = PoppedNode->Data->AdjacencyList;

        while (EdgeElement != NULL) {
            if(EdgeElement->Target->Visited == NotVisited && EdgeElement->Target != NULL){
                EdgeElement->Target->Visited = Visited;
                LQ_Enqueue(Queue, LQ_CreateNode(EdgeElement->Target));
                printf("%d", EdgeElement->Target->Data);
            }
            EdgeElement = EdgeElement->Next;
        }
    }
}
