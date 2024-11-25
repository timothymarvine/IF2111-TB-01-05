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

char *GetL(ArrayDin array, IdxType i) {
    return array.A[i].name;
}

int GetCapacityL(ArrayDin array) {
    return array.Capacity;
}

void InsertAtL(ArrayDin *array, char *el, IdxType i, int x) {
    int length = LengthDin(*array);
    int capacity = GetCapacityL(*array);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        Barang *arr = (Barang *) malloc(desiredCapacity * sizeof(Barang));
        for (int a = 0; a < length; a++) {
            strCopy(arr[a].name, GetL(*array, a));
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

void InsertLastL(ArrayDin *array, Barang *el) {
    int insertAt = LengthDin(*array);
    InsertAtL(array, el->name, insertAt, el->price);
}

void InsertFirstL(ArrayDin *array, Barang *el) {
    InsertAtL(array, el->name, 0, el->price);
}

void DeleteAtL(ArrayDin *array, IdxType i) {
    int length = LengthDin(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

void DeleteLastL(ArrayDin *array) {
    int deleteAt = LengthDin(*array) - 1;
    DeleteAtL(array, deleteAt);
}

void DeleteFirstL(ArrayDin *array) {
    DeleteAtL(array, 0);
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

boolean SearchArrayDin(ArrayDin array, char *el) {
    for (int i = 0; i < array.Neff; i++) {
        if (strCmpr(array.A[i].name, el)) {
            return 1;
        }
    }
    return 0;
}