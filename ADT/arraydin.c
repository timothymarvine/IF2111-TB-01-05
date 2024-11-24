#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin() {
    ArrayDin array;
    array.A = (Barang *) malloc(InitialSize * sizeof(Barang));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);
}

boolean IsEmptyDin(ArrayDin array) {
    return array.Neff == 0;
}

int LengthDin(ArrayDin array) {
    return array.Neff;
}

char *Get(ArrayDin array, IdxType i) {
    return array.A[i].name;
}

int GetCapacity(ArrayDin array) {
    return array.Capacity;
}

void InsertAt(ArrayDin *array, char *el, IdxType i, int x) {
    int length = LengthDin(*array);
    int capacity = GetCapacity(*array);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        Barang *arr = (Barang *) malloc(desiredCapacity * sizeof(Barang));
        for (int a = 0; a < length; a++) {
            strCopy(arr[a].name, Get(*array, a));
        }
        free(array->A);
        
        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    strCopy(array->A[i].name, el);
    array->A[i].price = x;
    array->Neff++;
}

void InsertLast(ArrayDin *array, Barang el) {
    int insertAt = LengthDin(*array);
    InsertAt(array, el.name, insertAt, el.price);
}

void InsertFirst(ArrayDin *array, Barang el) {
    InsertAt(array, el.name, 0, el.price);
}

void DeleteAt(ArrayDin *array, IdxType i) {
    int length = LengthDin(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

void DeleteLast(ArrayDin *array) {
    int deleteAt = LengthDin(*array) - 1;
    DeleteAt(array, deleteAt);
}

void DeleteFirst(ArrayDin *array) {
    DeleteAt(array, 0);
}

void PrintArrayDin(ArrayDin array) {
    if (IsEmptyDin(array)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < array.Neff; i++) {
            printf("%s ", array.A[i].name);
            printf("%d", array.A[i].price);
            if (i < array.Neff - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

ArrayDin CopyArrayDin(ArrayDin array) {
    ArrayDin copy = MakeArrayDin();
    for (int i = 0; i < array.Neff; i++) {
        InsertLast(&copy, array.A[i]);
    }
    return copy;
}

boolean SearchArrayDin(ArrayDin array, char *el) {
    for (int i = 0; i < array.Neff; i++) {
        if (strCmpr(array.A[i].name, el)) {
            return 1;
        }
    }
    return 0;
}