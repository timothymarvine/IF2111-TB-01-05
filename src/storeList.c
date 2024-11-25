#include <stdio.h>
#include "storeList.h"

void STORELIST(ArrayDin StoreList){
  if (StoreList.Neff == 0) {
      printf("TOKO KOSONG\n");
      return;
  }

  printf("List barang yang ada di toko : \n");
  for (int i = 0; i<StoreList.Neff; i++){
    printf("- %s\n", StoreList.A[i].name); 
  }
}