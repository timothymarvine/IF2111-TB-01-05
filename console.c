#include <stdio.h>
#include <stdlib.h>
#include "console.h"

array StoreList;

// void LOAD(char *fname){
//   ListGame = Makearray(); CreateQueue(&QueueGame);
//   CreateEmptystack(&HistoryGame); ScoreBoardGame = Makearraymap();
//   Stack awal; CreateEmptystack(&awal);
//   char file[25] = "../data/";
//   ConcatString(file, fname);
//   STARTWORDFILE(file);
//   if (pita != NULL){
//     int loop=0;
//     for (int i = 0; i<currentWord.Length; i++){
//       loop = (loop*10) + currentWord.TabWord[i]-'0';
//     } ADVSENTENCE();
//     while(loop--){
//       InsertLast(&ListGame, currentWord);
//       ADVSENTENCE();
//     } loop=0;
//     for (int i = 0; i<currentWord.Length; i++){
//       loop = (loop*10) + currentWord.TabWord[i]-'0';
//     } ADVSENTENCE();
//     while(loop--){
//       Push(&awal, currentWord);
//       ADVSENTENCE();
//     } HistoryGame = Reversestack(&awal);
//     keytype k; valuetype v; Map m;
//     for (int j = 0; j<ListGame.Neff; j++){
//       loop=0; CreateEmptymap(&m);
//       for (int i = 0; i<currentWord.Length; i++){
//         loop = (loop*10) + currentWord.TabWord[i]-'0';
//       }
//       while(loop--){
//         ADVWORD(); k = currentWord;
//         ADVWORD(); v = 0;
//         for (int i = 0; i<currentWord.Length; i++){
//           v = (v*10) + currentWord.TabWord[i]-'0';
//         } Insertmap(&m, k, v);
//       } InsertLastarrmap(&ScoreBoardGame,m); ADVSENTENCE();
//     }
//   } else {
//     printf("\n"); mode = 0;
//   }
// }

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

