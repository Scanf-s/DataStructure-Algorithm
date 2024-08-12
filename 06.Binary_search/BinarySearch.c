////
//// Created by sullung on 8/12/24.
////
//#include <stdlib.h>
//#include <stdio.h>
//#include "BinarySearch.h"
//
////Point* BinarySearch(Point* PointSet, int Length, double Target) {
////
////    int Left = 0;
////    int Right = Length - 1;
////    int Mid = 0;
////
////    while (Left <= Right){
////        Mid = (Left + Right) / 2;
////
////        if (Target == PointSet[Mid].point){
////            return &(PointSet[Mid]);
////        }
////        else if (Target < PointSet[Mid].point){
////            Right = Mid - 1;
////        }
////        else {
////            Left = Mid + 1;
////        }
////    }
////
////    return NULL;
////}
//
////int ComparePoint(const void *_elem1, const void *_elem2) {
////    Point* elem1 = (Point*)_elem1;
////    Point* elem2 = (Point*)_elem2;
////
////    if (elem1->point > elem2->point) {
////        return 1;
////    }
////    else if (elem1->point < elem2->point) {
////        return -1;
////    }
////    else {
////        return 0;
////    }
////}
//
////int main(void) {
////
////    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
////    Point* found = NULL;
////
////    qsort(DataSet, Length, sizeof(Point), ComparePoint);
////
////    found = BinarySearch(DataSet, Length, 671.78);
////
////    printf("found... ID: %d, Point: %f \n", found->id, found->point);
////
////    return 0;
////}