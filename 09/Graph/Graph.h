#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

enum VisitMode { Visited, NotVisited }; // 0 : Visited, 1 : NotVisited

typedef int VertexElementType; // 정점(vertex)에 저장될 데이터의 타입

typedef struct tagVertex
{
    VertexElementType Data;
    int               Visited; // Using Visited variable when DFS, BFS
    int               Index; // Using Index variable when Topological Sort, Minimum Spanning Tree, Dijkstra, ...

    struct tagVertex* Next; // 정점들을 연결 리스트 형태로 관리할 때 사용
    struct tagEdge*   AdjacencyList; // 현재 정점과 연결된 모든 간선(edge)들의 리스트
} Vertex;

typedef struct tagEdge
{
    int    Weight; // 가중치
    struct tagEdge* Next; // 동일한 출발 정점에서 나가는 다음 간선을 가리키는 포인터
    Vertex* From; // Departure
    Vertex* Target; // Destination
} Edge;

typedef struct tagGraph // G = (V, E)
{
    Vertex* Vertices; // 그래프를 이루는 정점을 모아놓을 리스트 Pointer
    int     VertexCount; // Vertext 개수
} Graph;

Graph* CreateGraph();
void   DestroyGraph( Graph* G );

Vertex* CreateVertex( VertexElementType Data );
void    DestroyVertex( Vertex* V );

Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight );
void    DestroyEdge( Edge* E );

void   AddVertex( Graph* G, Vertex* V );
void   AddEdge( Vertex* V, Edge* E );
void   PrintGraph ( Graph* G );

#endif
