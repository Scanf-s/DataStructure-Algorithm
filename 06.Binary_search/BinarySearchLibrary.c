////
//// Created by sullung on 8/12/24.
////
//#include <stdlib.h>
//#include <stdio.h>
//#include "BinarySearch.h"
//
//int ComparePoint(const void *_elem1, const void *_elem2) {
//    Point* elem1 = (Point*)_elem1;
//    Point* elem2 = (Point*)_elem2;
//
//    if (elem1->point > elem2->point) {
//        return 1;
//    }
//    else if (elem1->point < elem2->point) {
//        return -1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int main(void) {
//
//    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
//    Point* found = NULL;
//    Point target;
//    target.id = 0;
//    target.point = 671.78;
//
//    qsort(DataSet, Length, sizeof(Point), ComparePoint);
//
//    found = bsearch(
//            &target,
//            DataSet,
//            Length,
//            sizeof(Point),
//            ComparePoint
//            );
//
//    printf("found... ID: %d, Point: %f \n", found->id, found->point);
//
//    return 0;
//}