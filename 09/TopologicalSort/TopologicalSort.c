#include "TopologicalSort.h"

void TopologicalSort( Vertex* V, Node** List ) // V : Vertex 집합
{
    while ( V != NULL && V->Visited == NotVisited )
    {
        TS_DFS( V, List ); // DFS 사용해서 위상정렬

        V = V->Next; // DFS 수행 후 빠져나왔을 때 진입간선 개수가 0인 정점이 있을 수 있으니까 다음 정점으로 이동
    }
}

void TS_DFS( Vertex* V, Node** List )
{
    Node* NewHead = NULL; // Linked List
    Edge* E = NULL; // 정점에 달려있는 진출차선 집합

    V->Visited = Visited;

    E = V->AdjacencyList; // 진출차선 가져오기

    while ( E != NULL )
    {
        if ( E->Target != NULL && E->Target->Visited == NotVisited )
            TS_DFS( E->Target, List ); // 방문여부가 NotVisited인 경우에만 DFS 수행

        E = E->Next; // 다음 진출차선에 대해 탐색해야 하므로
    }

    printf("%c\n", V->Data );

    NewHead = SLL_CreateNode( V ); // 노드 하나 생성해서
    SLL_InsertNewHead( List, NewHead ); // 링크드리스트의 새로운 Head로 삽입
}
