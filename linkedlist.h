#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h> // Untuk tipe boolean
#include <stdlib.h>  // Untuk malloc dan free
#include <string.h>  // Untuk manipulasi string

#define NIL NULL

typedef char* ElementType; // Elemen berupa string
typedef struct Node *Address;
typedef struct Node {
    ElementType info;
    Address next;
    Address prev;
} Node;

typedef struct {
    Address first;
    Address last;
} LinkedList;

// Macro untuk mempermudah akses
#define InfoL(P) (P)->info
#define NextL(P) (P)->next
#define PrevL(P) (P)->prev
#define FirstL(L) ((L).first)
#define LastL(L) ((L).last)

// Prototipe fungsi
void CreateList(LinkedList *L);
bool IsListEmpty(LinkedList L);

Address Allocate(ElementType X);
void Deallocate(Address P);

void InsertFirstL(LinkedList *L, Address P);
void InsertLastL(LinkedList *L, Address P);
void DeleteFirstL(LinkedList *L, Address *P);
void DeleteLastL(LinkedList *L, Address *P);

Address Search(LinkedList L, ElementType X);
void PrintListForward(LinkedList L);
void PrintListBackward(LinkedList L);

#endif
