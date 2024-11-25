#include <stdio.h>
#include "storeRemove.h"

void STOREREMOVE(ArrayDin *StoreList){
  STORELIST(*StoreList); 
    printf("\nNama barang yang akan dihapus : "); 
    STARTSENTENCE();

    if (SearchArrayDin(*StoreList, currentWord.TabWord)) { 
      for (int i = 0; i < StoreList.Neff; i++) {
        if (WordCompareString(currentWord, StoreList.A[i].name)) {
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