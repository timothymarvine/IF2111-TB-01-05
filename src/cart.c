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

void CARTPAY(Map *cart, ArrayDin list){
  if (cart->Count == 0) {
      printf("Keranjang kamu kosong!\n");
      return;
  }
  int userMoney = 100;
  printf("Kamu akan membeli barang-barang berikut.\n");
  printf("Kuantitas\tNama\t\tTotal\n");

  int totalCost = 0;
  for (int i = 0; i < cart->Count; i++) {
    int j = 0;
    while(!strCmpr(cart->Elements[i].Key, list.A[j].name)){
      j++;
    }
    int itemTotal = list.A[j].price * cart->Elements[i].Value;
    totalCost += itemTotal;
    printf("%d\t\t%s\t%d\n", cart->Elements[i].Value, cart->Elements[i].Key, itemTotal);
  }
  printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak)\n", totalCost);
  STARTSENTENCE();
  
  Barang maxItem;
  if (WordCompareString(currentWord, "Ya")){
    if (userMoney >= totalCost) {
      userMoney -= totalCost;
      // Purchase purchase;
      // for (int i = 0; maxItem.name[i] != '\0'; i++) {
      //   purchase.itemName[i] = maxItem.name[i];
      //   purchase.itemName[i + 1] = '\0';
      // }
      // purchase.quantity = 1;
      // purchase.price = maxTotal;

      // if (!IsFullStack(*history)) {
      //   Push(history, purchase);
      // }
      // else {
      //   printf("Riwayat pembelian penuh. Tidak dapat menyimpan riwayat ini.\n");
      // }

      cart->Count = 0;

      printf("Selamat kamu telah membeli barang-barang tersebut!\n");
    }
    else {
      printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", userMoney);
    }
  }
  else if (WordCompareString(currentWord, "Tidak")) {
    return;
  }
  else {
    return;
  }
}

void CARTSHOW(Map cart, ArrayDin list){
  if (cart.Count == 0) {
      printf("Keranjang kamu kosong!\n");
      return;
  }
  printf("Berikut adalah isi keranjangmu.\n");
  printf("Kuantitas\tNama\t\tTotal\n");

  int totalCost = 0;
  for (int i = 0; i < cart.Count; i++) {
    int j = 0;
    while(!strCmpr(cart.Elements[i].Key, list.A[j].name)){
      j++;
    }
    int itemTotal = list.A[j].price * cart.Elements[i].Value;
    totalCost += itemTotal;
    printf("%d\t\t%s\t%d\n", cart.Elements[i].Value, cart.Elements[i].Key, itemTotal);
  }
  printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalCost);
}
