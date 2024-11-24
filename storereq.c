#include "storereq.h"
#include <stdio.h>

void Request(Queue *q, ArrayDin *list){
	Produk antri;
	while(1){
		printf("Nama barang yang diminta: ");
		scanf("%s", antri);

		if(IsMemberQ(*q, antri)){
			printf("Barang dengan nama yang sama sudah tersedia di antrian!");
		} else if(SearchArrayDin(*list, antri)){
			printf("Barang dengan nama yang sama sudah tersedia di toko!");
		} else {
			enqueue(&*q, antri);
			break;
		}
	}

	// return q;
}

void Supply(Queue *q, ArrayDin *list){
	char jawab[20];
	int harga;
	int i = 0;
	while(!IsEmpty(*q)){
		printf("Apakah kamu ingin menambahkan barang %s: ", HEAD(*q));
		scanf("%s", jawab);

		if(strCmpr(jawab, "Terima")){
			printf("Harga barang: ");
			scanf("%d", &harga);
			
			Barang masuk;
			strCopy(masuk.name, HEAD(*q));
			masuk.price = harga;

			InsertLast(&*list, masuk);
			dequeue(&*q);
		} else if(strCmpr(jawab, "Tunda")){
			enqueue(&*q, HEAD(*q));
			dequeue(&*q);
			if(i++ == Length(*q)){
				break;
			}
		} else if(strCmpr(jawab, "Tolak")){
			dequeue(&*q);
		} else if(strCmpr(jawab, "Purry")){
			// Mainmenu
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