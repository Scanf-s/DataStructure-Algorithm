//
// Created by sullung on 8/8/24.
//
#include <stdio.h>

void InsertionSort(int* DataSet, int Length) {
    for (int i = 1; i < Length; i++) {
        int key = DataSet[i];
        int j = i - 1;

        while (j >= 0 && DataSet[j] > key) {
            DataSet[j + 1] = DataSet[j];
            j--;
        }
        DataSet[j + 1] = key;
    }
}

//int main(void){
//    int DataSet[] = { 5, 2, 4, 6, 1, 3 };
//    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
//
//    InsertionSort(DataSet, Length);
//
//    for (int i = 0; i < Length; i++){
//        printf("%d ", DataSet[i]);
//    }
//
//    return 0;
//}