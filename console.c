#include <stdio.h>
#include <stdlib.h>
#include "console.h"

array StoreList;

void STORELIST(array StoreList){
  if (StoreList.Neff == 0) {
      printf("TOKO KOSONG\n");
      return;
  }

  printf("List barang yang ada di toko : \n");
  for (int i = 0; i<StoreList.Neff; i++){
    printf("- "); 
    PrintKata(StoreList.A[i]); 
    printf("\n");
  }
}


void STOREREMOVE(array *StoreList){
  STORELIST(*StoreList); 
    printf("\nNama barang yang akan dihapus : "); 
    STARTSENTENCE();

    if (IsMemberArr(*StoreList, currentWord)) { 
      for (int i = 0; i < StoreList.Neff; i++) {
        if (WordCompare(StoreList.A[i], currentWord)) {
          DeleteAt(StoreList, i); 
          PrintKata(currentWord);
          printf(" telah berhasil dihapus.\n");
          return;
        }
      }
    } 
    else {
      printf("Toko tidak menjual ");
      PrintKata(currentWord);
      printf("\n");
    }
} 
