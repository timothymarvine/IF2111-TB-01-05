#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h> 
#include "..\..\boolean.h"
#include "..\mesinkata\mesinkata.h"
#include "..\definitions.h"

#define NIL NULL

typedef char* ElementType;
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
boolean IsListEmpty(LinkedList L);
int ListLength(LinkedList L);

Address Allocate(ElementType X);
void Deallocate(Address P);

void InsertFirstList(LinkedList *L, Address P);
void InsertLastList(LinkedList *L, Address P);
void DeleteFirstList(LinkedList *L, Address *P);
void DeleteLastList(LinkedList *L, Address *P);
void DeleteMemberList(LinkedList *L, Produk x);

Address Search(LinkedList L, ElementType X);
void PrintListForward(LinkedList L);
void PrintListBackward(LinkedList L);

#endif
