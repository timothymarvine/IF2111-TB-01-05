#include "arraydin.h"

int main(void){
    ArrayDin arr;
    arr = MakeArrayDin();

    Barang drug;

    strCopy(drug.name, "Meth");
    drug.price = 10000000;

    InsertFirst(&arr, drug);

    PrintArrayDin(arr);
}