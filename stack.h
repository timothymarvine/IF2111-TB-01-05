#ifndef stackt_H
#define stackt_H

#include "boolean.h"

#define Nil -1
#define CAPACITY 100

// Define struct Purchase
typedef struct {
    char itemName[50];
    int quantity;
    float price;
} Purchase;

// Use Purchase as infotypeStack
typedef Purchase infotypeStack;
typedef int idxTypeStack;

typedef struct { 
    infotypeStack T[CAPACITY]; /* tabel penyimpan elemen */
    idxTypeStack TOP;          /* alamat TOP: elemen puncak */
} Stack;

/* Definisi akses dengan Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
void CreateEmptyStack(Stack *S);
boolean IsEmptyStack(Stack S);
boolean IsFullStack(Stack S);
void Push(Stack *S, infotypeStack X);
void Pop(Stack *S, infotypeStack *X);

#endif
