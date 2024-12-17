#ifndef __ARRAY_DINAMIK_H__
#define __ARRAY_DINAMIK_H__

#include"..\queue\queue.h"

#define InitialSize 10

typedef struct {
    Barang *A;
    int Capacity;
    int Neff;
} ArrayDin;

ArrayDin MakeArrayDin();

void DeallocateArrayDin(ArrayDin *array);

boolean IsEmptyDin(ArrayDin array);

int LengthDin(ArrayDin array);

char *GetL(ArrayDin array, IdxType i);

int GetCapacityL(ArrayDin array);

void InsertAtL(ArrayDin *array, char *el, IdxType i, int x);

void InsertLastL(ArrayDin *array, Barang *el);

void InsertFirstL(ArrayDin *array, Barang *el);

void DeleteAtL(ArrayDin *array, IdxType i);

void DeleteLastL(ArrayDin *array);

void DeleteFirstL(ArrayDin *array);

void PrintArrayDin(ArrayDin array);

boolean SearchArrayDin(ArrayDin array, char *el);

#endif