#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include"..\queue\queue.h"

#define InitialSize 10

typedef struct {
	char name[50];
	int price;
} Barang;

typedef struct {
    Barang *A;
    int Capacity;
    int Neff;
} ArrayDin;

ArrayDin MakeArrayDin();

void DeallocateArrayDin(ArrayDin *array);

boolean IsEmptyDin(ArrayDin array);

int LengthDin(ArrayDin array);

char *Get(ArrayDin array, IdxType i);

int GetCapacity(ArrayDin array);

void InsertAt(ArrayDin *array, char *el, IdxType i, int x);

void InsertLast(ArrayDin *array, Barang el);

void InsertFirst(ArrayDin *array, Barang el);

void DeleteAt(ArrayDin *array, IdxType i);

void DeleteLast(ArrayDin *array);

void DeleteFirst(ArrayDin *array);

void PrintArrayDin(ArrayDin array);

ArrayDin CopyArrayDin(ArrayDin array);

boolean SearchArrayDin(ArrayDin array, char *el);

#endif