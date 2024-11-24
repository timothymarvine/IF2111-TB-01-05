#include "storereq.h"
#include <stdio.h>

Queue Request(Queue q, ArrayDin list){
	Produk antri;
	printf("Nama barang yang diminta: ");
	scanf("%s", antri);

	if(IsMemberQ(q, antri)){
		printf("Barang dengan nama yang sama sudah tersedia di antrian!");
		Request(q, list);
	} else if(SearchArrayDin(list, antri)){
		printf("Barang dengan nama yang sama sudah tersedia di toko!");
		Request(q, list);
	} else {
		enqueue(&q, antri);
	}

	return q;
}

void Supply(Queue q, ArrayDin list){
	char jawab[20];
	int harga;
	int i = 0;
	while(!IsEmpty(q)){
		printf("Apakah kamu ingin menambahkan barang %s: ", HEAD(q));
		scanf("%s", jawab);

		if(strCmpr(jawab, "Terima")){
			printf("Harga barang: ");
			scanf("%d", &harga);
			
			Barang masuk;
			strCopy(masuk.name, HEAD(q));
			masuk.price = harga;

			InsertLast(&list, masuk);
			q = dequeue(q);
		} else if(strCmpr(jawab, "Tunda")){
			enqueue(&q, HEAD(q));
			q = dequeue(q);
			if(HEAD(q) == TAIL(q)){
				break;
			}
		} else if(strCmpr(jawab, "Tolak")){
			q = dequeue(q);
		} else if(strCmpr(jawab, "Purry")){
			// Mainmenu
		}
	}
}

int main(void){
	Queue q; ArrayDin L = MakeArrayDin();
	CreateQueue(&q);

	q = Request(q, L);

	Supply(q, L);

	DisplayQueue(q);
	PrintArrayDin(L);
}