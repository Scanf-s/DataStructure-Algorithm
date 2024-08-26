//#include "Graph.h"
//
//Graph* CreateGraph(){
//    Graph* graph = (Graph*)malloc(sizeof(Graph)); // Graph struct 크기만큼 메모리 할당
//    if (graph == NULL) return NULL;
//
//    graph->VertexCount=0; // 그래프가 처음에는 비어있음
//    graph->Vertices=NULL; // 그래프가 처음에는 비어있음
//    return graph;
//}
//
//void DestroyGraph( Graph* G ){
//    if (G == NULL) return;
//
//    // 그래프를 이루는 정점 리스트 메모리 해제
//    while(G->Vertices != NULL) {
//        // 맨 앞부터 메모리 해제
//        Vertex* vertices = G->Vertices->Next; // 먼저 맨 앞의 정점이 가리키는 다음 정점의 메모리를 저장해놓고
//        DestroyVertex(G->Vertices);
//        G->Vertices = vertices; // 맨 앞의 정점이 삭제되었으니까 다음 정점부터 다시 While문 수행
//    }
//    free(G); // 그래프 해제
//}
//
//Vertex* CreateVertex( VertexElementType Data ){
//    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
//    if (vertex == NULL) return NULL;
//
//    vertex->Data = Data;
//    vertex->Visited = NotVisited;
//    vertex->Index = -1;
//    vertex->Next = NULL;
//    vertex->AdjacencyList = NULL;
//    return vertex;
//}
//
//void DestroyVertex( Vertex* V ){
//    // Vertex를 삭제하려면 해당 정점과 이어져있는 모든 간선도 삭제해야함
//    if (V == NULL) return;
//    while(V -> AdjacencyList != NULL) {
//        Edge* edge = V->AdjacencyList->Next;
//        DestroyEdge(V->AdjacencyList);
//        V->AdjacencyList = edge;
//    }
//    free(V);
//}
//
//Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight ){
//    Edge* edge = (Edge*) malloc(sizeof(Edge));
//    if (edge == NULL) return NULL;
//
//    edge->From = From;
//    edge->Target = Target;
//    edge->Next = NULL;
//    edge->Weight = Weight;
//    return edge;
//}
//
//void    DestroyEdge( Edge* E ){
//    free(E);
//}
//
//void AddVertex( Graph* G, Vertex* V ){
//    if (G == NULL || V == NULL) return;
//
//    Vertex* vertexList = G->Vertices;
//    if (vertexList == NULL) {
//        G->Vertices = V;
//    } else {
//        while(vertexList->Next != NULL) {
//            vertexList = vertexList->Next;
//        }
//        vertexList->Next = V;
//    }
//    G->VertexCount++;
//    V->Index = G->VertexCount;
//}
//
//void AddEdge( Vertex* V, Edge* E ){
//    if(V == NULL || E == NULL) return;
//
//    if(V->AdjacencyList == NULL) {
//        V->AdjacencyList = E;
//    } else {
//        Edge* AdjacencyList = V->AdjacencyList;
//
//        while(AdjacencyList->Next != NULL) {
//            AdjacencyList = AdjacencyList->Next;
//        }
//        AdjacencyList->Next = E;
//    }
//}
//
//void PrintGraph ( Graph* G )
//{
//    Vertex* V = NULL;
//    Edge*   E = NULL;
//
//    if ( ( V = G->Vertices ) == NULL )
//        return;
//
//    while ( V != NULL )
//    {
//        printf( "%c : ", V->Data );
//
//        if ( (E = V->AdjacencyList) == NULL ) {
//            V = V->Next;
//            printf("\n");
//            continue;
//        }
//
//        while ( E != NULL )
//        {
//            printf("%c[%d] ", E->Target->Data, E->Weight );
//            E = E->Next;
//        }
//
//        printf("\n");
//
//        V = V->Next;
//    }
//
//    printf("\n");
//}
