#include "Heap.h"

Heap* HEAP_Create( int InitialSize ) {
    Heap *NewHeap = (Heap*) malloc(sizeof(Heap));
    NewHeap->Capacity = InitialSize;
    NewHeap->Nodes = (HeapNode*) malloc(sizeof(HeapNode) * NewHeap -> Capacity); // Node
    NewHeap->UsedSize = 0;

    printf("Initialized Heap size : %lu\n", sizeof(HeapNode));
    return NewHeap;
}

void HEAP_Destroy( Heap* H ) {
    free(H->Nodes);
    free(H);
}

void HEAP_Insert( Heap* H, ElementType NewData ) {
    int CurrentIndex = H->UsedSize;
    int ParentIndex = HEAP_GetParent(CurrentIndex);

    // If Heap full
    if ( H->UsedSize == H->Capacity) {
        H->Capacity = H->Capacity * 2;
        H->Nodes = (HeapNode *) realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
        if (H->Nodes == NULL) {
            printf("Heap full\n");
            exit(1);
        }
        printf("Heap size : %lu\n", sizeof(HeapNode));
    }

    H->Nodes[CurrentIndex].Data = NewData;

    // Reheapification
    while ( CurrentIndex > 0 && H->Nodes[CurrentIndex].Data < H->Nodes[ParentIndex].Data ) {
        HEAP_SwapNodes(H, CurrentIndex, ParentIndex);

        CurrentIndex = ParentIndex;
        ParentIndex = HEAP_GetParent(CurrentIndex);
    }

    H->UsedSize++;
}

void HEAP_SwapNodes( Heap* H, int Index1, int Index2 ) {
    HeapNode Temp = H->Nodes[Index1];
    H->Nodes[Index1] = H->Nodes[Index2];
    H->Nodes[Index2] = Temp;
}

ElementType HEAP_DeleteMin( Heap* H ) {

    if (H->UsedSize == 0) {
        printf("Heap is already empty\n");
        return -1;
    }

    ElementType Min = H->Nodes[0].Data;
    H->Nodes[0].Data = H->Nodes[H->UsedSize - 1].Data;
    H->UsedSize--;

    int ParentIndex = 0;
    while (1) {
        int LeftIndex = HEAP_GetLeftChild(ParentIndex);
        int RightIndex = HEAP_GetRightChild(ParentIndex);
        int SelectedIndex = ParentIndex;

        if (LeftIndex < H->UsedSize && H->Nodes[LeftIndex].Data < H->Nodes[ParentIndex].Data) {
            SelectedIndex = LeftIndex;
        }

        if (RightIndex < H->UsedSize && H->Nodes[RightIndex].Data < H->Nodes[SelectedIndex].Data) {
            SelectedIndex = RightIndex;
        }

        if (SelectedIndex == ParentIndex) {
            break;
        }

        HEAP_SwapNodes(H, ParentIndex, SelectedIndex);
        ParentIndex = SelectedIndex;
    }

    return Min;
}

int HEAP_GetParent( int Index ) {
    int ParentIndex = (int) ((Index - 1) / 2);
    return ParentIndex;
}

int HEAP_GetLeftChild( int Index ) {
    int LeftIndex = (2 * Index) + 1;
    return LeftIndex;
}

int HEAP_GetRightChild( int Index ) {
    int RightIndex = (2 * Index) + 2;
    return RightIndex;
}

void      HEAP_PrintNodes(Heap* H )
{
    int i = 0;
    for ( i=0; i < H->UsedSize; i++ )
    {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}
