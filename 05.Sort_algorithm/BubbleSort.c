//
// Created by sullung on 8/8/24.
//
# include <stdio.h>

void BubbleSort( int* DataSet, int Length )
{
    int i = 0;
    int j = 0;
    int swp = 0;

    for (i = 0; i < Length - 1; i++){
        for (j = 0; j < (Length - 1 - i); j++){
            // Ascending bubble sort
            if (DataSet[j] > DataSet[j + 1]){
                swp = DataSet[j];
                DataSet[j] = DataSet[j + 1];
                DataSet[j + 1] = swp;
            }
        }
    }
}

//int main(void){
//    int DataSet[] = { 5, 2, 4, 6, 1, 3 };
//    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
//
//    BubbleSort(DataSet, Length);
//
//    for (int i = 0; i < Length; i++){
//        printf("%d ", DataSet[i]);
//    }
//
//    return 0;
//}