#include <stdio.h>
#include "cart.h"

void CartAdd(Map *c, int qty, ArrayDin list, Word newItem){
    if(SearchArrayDin(list, newItem.TabWord)){
        if(!IsMemberM(*c, newItem.TabWord)){
            strCopy(c->Elements[c->Count].Key, newItem.TabWord);
            c->Elements[c->Count].Value = 0;
            c->Count++;
        }
        ChangeVal(c, newItem.TabWord, qty);
    } else {
        printf("Barang tidak ada di toko!");
    }
}

void CartRemove(Map *c, int qty, Word item){
    Produk i;
    strCopy(i, item.TabWord);
    if(IsMemberM(*c, i)){
        ChangeVal(c, i, qty);
    } else {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}

int main(void){
    Map cart; CreateEmptyM(&cart);
    int qty = 5;
    ArrayDin barang = MakeArrayDin(); 
    char kata[4] = "Ayam";
    for(int i = 0; i < 4; i++){
        barang.A[0].name[i] = kata[i];
    }
    barang.A[0].name[4] = '\0';
    barang.Neff++;

    printf("Barang ke keranjang: ");
    STARTSENTENCE();

    CartAdd(&cart, qty, barang, currentWord);

    printf("Hapus barang: ");
    STARTSENTENCE();

    qty = -10;
    CartRemove(&cart, qty, currentWord);

    if(cart.Count == 0){
        printf("Keranjang kosong!");
    } else {
        DisplayMap(cart);
    }
}