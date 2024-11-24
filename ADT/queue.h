#ifndef QUEUE_H
#define QUEUE_H

#include "..\boolean.h"

#define IDX_MAX 99
#define IDX_UNDEF -1

typedef char Produk[50];
typedef int IdxType;

typedef struct {
	Produk Tab[IDX_MAX + 1];
	IdxType idxHead;
	IdxType idxTail;
} Queue;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).Tab[(q).idxHead]
#define     TAIL(q) (q).Tab[(q).idxTail]

boolean IsEmpty (Queue Q);

boolean IsFull (Queue Q);

int Length (Queue Q);

void CreateQueue (Queue * Q);

void enqueue (Queue * Q, Produk X);

Queue dequeue (Queue Q);

boolean IsMemberQ(Queue Q, Produk x);

void DisplayQueue(Queue q);

boolean strCmpr(char *a, char *b);

void strCopy(Produk a, Produk b);

#endif