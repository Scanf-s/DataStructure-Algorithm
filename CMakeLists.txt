cmake_minimum_required(VERSION 3.28)
project(C_datastructure_algorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(C_datastructure_algorithm main.c)
add_executable(
        LinkedList
        01.LinkedList/SLL.c
        01.LinkedList/LinkedList.h
        01.LinkedList/DoublyLinkedList.h
        01.LinkedList/DLL.c
        01.LinkedList/CDLL.c
        01.LinkedList/CircularDoublyLinkedList.h
        01.LinkedList/Test_CircularDoublyLinkedList.c
        01.LinkedList/Test_DoublyLinkedList.c
        01.LinkedList/Test_LinkedList.c
)
add_executable(
        Stack
        02.Stack/ArrayStack.c
        02.Stack/ArrayStack.h
        02.Stack/LinkedListStack.c
        02.Stack/LinkedListStack.h
        02.Stack/Calculator.c
        02.Stack/Test_ArrayStack.c
        02.Stack/Test_Calculator.c
        02.Stack/Test_LinkedListStack.c
)
add_executable(
        Queue
        03.Queue/CircularQueue.c
        03.Queue/CircularQueue.h
        03.Queue/LinkedQueue.c
        03.Queue/LinkedQueue.h
        03.Queue/Test_CircularQueue.c
        03.Queue/Test_LinkedQueue.c
        03.Queue/Test_CircularQueue.c
)
add_executable(
        Sort_algorithm
        05.Sort_algorithm/BubbleSort.c
        05.Sort_algorithm/InsertionSort.c
        05.Sort_algorithm/QuickSort.c
        05.Sort_algorithm/Qsortlib.c
)
add_executable(
        BinarySearchTree
        06.Binary_search/BinarySearch.h
        06.Binary_search/BinarySearch.c
        06.Binary_search/BinarySearchLibrary.c
        06.Binary_search/BinarySearchTree.c
        06.Binary_search/BinarySearchTree.h
        06.Binary_search/BST_Test.c
        06.Binary_search/RedBlackTree.c
        06.Binary_search/RedBlackTree.h
)