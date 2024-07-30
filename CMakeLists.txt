cmake_minimum_required(VERSION 3.28)
project(C_datastructure_algorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(C_datastructure_algorithm main.c)
add_executable(SingularLinkedList LinkedList/SLL.c
        LinkedList/LinkedList.h)
add_executable(DoublyLinkedList LinkedList/DLL.c LinkedList/DoublyLinkedList.h
        LinkedList/DoublyLinkedList.h
        LinkedList/DLL.c)
add_executable(CircularDoublyLinkedList LinkedList/CDLL.c LinkedList/CircularDoublyLinkedList.h
        LinkedList/CircularDoublyLinkedList.h
        LinkedList/CDLL.c)
