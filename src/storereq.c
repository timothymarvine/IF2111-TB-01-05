#include "storereq.h"
#include "ADT\mesinkata\mesinkata.h"
#include <stdio.h>

void Request(Queue *q, ArrayDin *list){
	char antri[50];
	printf("Nama barang yang diminta: ");
	STARTWORD();
	strCopy(antri, currentWord.TabWord);

	if(IsMemberQ(*q, antri)){
		printf("\nBarang dengan nama yang sama sudah tersedia di antrian!\n");
	} else if(SearchArrayDin(*list, antri)){
		printf("\nBarang dengan nama yang sama sudah tersedia di toko!\n");
	} else {
		enqueue(&*q, antri);
	}
}

void Supply(Queue *q, ArrayDin *list, array *storelist){
	char jawab[20];
	int harga;
	int i = 0;
	if(IsEmptyQ(*q)){
		printf("\nTidak ada permintaan barang.\n");
		return;
	}
	while(!IsEmptyQ(*q)){
		printf("Apakah kamu ingin menambahkan barang %s: ", HEAD(*q));
		STARTWORD();
		strCopy(jawab, currentWord.TabWord);

		Word temp, item;
		strCopy(item.TabWord, HEAD(*q));
		for(int i = 0; i < NMax; i++){
			currentWord.TabWord[i] = '\0';
		}

		if(strCmpr(jawab, "Terima")){
			InsertLast(storelist, item);
			storelist->A[storelist->Neff - 1].Length = Strlen(HEAD(*q));

			printf("Harga barang: ");
			STARTWORD();
			WordToString(currentWord, temp.TabWord);
			harga = stringToInteger(temp.TabWord);
			
			Barang masuk;
			strCopy(masuk.name, HEAD(*q));
			masuk.price = harga;

			InsertLastL(list, &masuk);
			printf("\n%s dengan harga %d telah ditambahkan ke toko.\n", masuk.name, masuk.price);
			dequeue(q);
		} else if(strCmpr(jawab, "Tunda")){
			enqueue(q, HEAD(*q));
			printf("\n%s dikembalikan ke antrian.\n", HEAD(*q));
			dequeue(q);
			if(i++ >= LengthQ(*q) - 1){
				break;
			}
		} else if(strCmpr(jawab, "Tolak")){
			printf("\n%s dihapuskan dari antrian.\n", HEAD(*q));
			dequeue(q);
		} else if(strCmpr(jawab, "Purry")){
			return;
		}
	}
}

// int main(void){
// 	Queue q; ArrayDin L = MakeArrayDin();
// 	CreateQueue(&q);

// 	Request(&q, &L);

// 	Supply(&q, &L);

// 	DisplayQueue(q);
// 	PrintArrayDin(L);
// }