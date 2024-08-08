//
// Created by sullung on 8/8/24.
//
#include <stdio.h>
#include <stdlib.h>

int Compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b); // 1, 0, -1만 되는게 아니라 qsort에서는 양수, 0, 음수를 요구하므로 이렇게 해도 된다
}

int main(void){
    int DataSet[] = { 5, 2, 4, 6, 1, 3 };
    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
    qsort(DataSet, Length, sizeof(int), Compare);
    for (int i = 0; i < Length; i++){
        printf("%d ", DataSet[i]);
    }
    return 0;
}