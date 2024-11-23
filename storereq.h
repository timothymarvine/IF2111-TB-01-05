#ifndef STOREREQ_H
#define STOREREQ_H

#define IDX_MAX 99
#define IDX_UNDEF -1

#include "boolean.h"

typedef int IdxType;

typedef char Produk[50];

typedef struct {
	Produk Tab[IDX_MAX + 1];
	IdxType idxHead;
	IdxType idxTail;
} Queue;

typedef struct {
	char name[50];
	int price;
} Barang;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).Tab[(q).idxHead]
#define     TAIL(q) (q).Tab[(q).idxTail]

boolean IsEmpty (Queue Q);

boolean IsFull (Queue Q);

int Length (Queue Q);

void strCopy(Produk a, Produk b);

void CreateQueue (Queue * Q);

void enqueue (Queue * Q, Produk X);

void dequeue (Queue * Q);

boolean IsMember(Queue Q, Produk x);

Queue Request(Queue q);

void DisplayQueue(Queue q);

boolean strCmpr(char *a, char *b);

#endif