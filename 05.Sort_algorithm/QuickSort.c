//
// Created by sullung on 8/8/24.
//

#include <stdio.h>

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int* DataSet, int Left, int Right){
    int First = Left;
    int Pivot = DataSet[First];
    Left += 1;

    while(Left <= Right){
        while(DataSet[Left] < Pivot && Left < Right){
            Left += 1;
        }
        while(DataSet[Right] > Pivot && Left <= Right){
            Right -= 1;
        }

        if(Left < Right){
            Swap(&DataSet[Left], &DataSet[Right]);
        }else{
            break;
        }
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int* DataSet, int Left, int Right){
    if(Left < Right){
        int Index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, Index - 1);
        QuickSort(DataSet, Index + 1, Right);
    }
}

//int main(void){
//    int DataSet[] = { 5, 2, 4, 6, 1, 3 };
//    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
//
//    QuickSort(DataSet, 0, Length - 1);
//
//    for (int i = 0; i < Length; i++){
//        printf("%d ", DataSet[i]);
//    }
//
//    return 0;
//}