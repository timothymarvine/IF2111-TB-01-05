#include "storereq.h"
#include "ADT\mesinkata\mesinkata.h"
#include <stdio.h>

void Request(Queue *q, ArrayDin *list){
	Produk antri;
	printf("Nama barang yang diminta: ");
	STARTWORD();
	strCopy(antri, currentWord.TabWord);

	if(IsMemberQ(*q, antri)){
		printf("Barang dengan nama yang sama sudah tersedia di antrian!\n");
	} else if(SearchArrayDin(*list, antri)){
		printf("Barang dengan nama yang sama sudah tersedia di toko!\n");
	} else {
		enqueue(&*q, antri);
	}
}

void Supply(Queue *q, ArrayDin *list){
	char jawab[20];
	int harga;
	int i = 0;
	while(!IsEmpty(*q)){
		printf("Apakah kamu ingin menambahkan barang %s: ", HEAD(*q));
		STARTWORD();
		strCopy(jawab, currentWord.TabWord);

		Word temp;

		if(strCmpr(jawab, "Terima")){
			printf("Harga barang: ");
			STARTWORD();
			WordToString(temp, currentWord.TabWord);
			harga = stringToInteger(temp.TabWord);
			
			Barang masuk;
			strCopy(masuk.name, HEAD(*q));
			masuk.price = harga;

			InsertLast(&*list, masuk);
			printf("\n%s dengan harga %d telah ditambahkan ke toko.\n", masuk.name, masuk.price);
			dequeue(&*q);
		} else if(strCmpr(jawab, "Tunda")){
			enqueue(&*q, HEAD(*q));
			printf("\n%s dikembalikan ke antrian.\n", HEAD(*q));
			dequeue(&*q);
			if(i++ == Length(*q) - 1){
				break;
			}
		} else if(strCmpr(jawab, "Tolak")){
			printf("\n%s dihapuskan dari antrian.\n", HEAD(*q));
			dequeue(&*q);
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