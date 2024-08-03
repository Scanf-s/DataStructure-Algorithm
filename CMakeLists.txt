cmake_minimum_required(VERSION 3.28)
project(C_datastructure_algorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(C_datastructure_algorithm main.c)
add_executable(
        LinkedList
        LinkedList/SLL.c
        LinkedList/LinkedList.h
        LinkedList/DoublyLinkedList.h
        LinkedList/DLL.c
        LinkedList/CDLL.c
        LinkedList/CircularDoublyLinkedList.h
        LinkedList/Test_CircularDoublyLinkedList.c
        LinkedList/Test_DoublyLinkedList.c
        LinkedList/Test_LinkedList.c
)
add_executable(
        Stack
        Stack/ArrayStack.c
        Stack/ArrayStack.h
        Stack/LinkedListStack.c
        Stack/LinkedListStack.h
        Stack/Calculator.c
        Stack/Test_ArrayStack.c
        Stack/Test_Calculator.c
        Stack/Test_LinkedListStack.c
)
