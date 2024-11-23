#include "storereq.h"

boolean IsEmpty(Queue q){
	return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean IsFull(Queue q){
	return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % IDX_MAX;
}

int Length(Queue q){
	if (IsEmpty(q)) {
        return 0;
    }
    if (q.idxTail >= q.idxHead) {
        return q.idxTail - q.idxHead + 1;
    } else {
        return (IDX_MAX - q.idxHead + q.idxTail + 2);
    }
}

void strCopy(Produk a, Produk b){
	for(int i = 0; i < 50; i++){
		if(b[i] == '\0'){
			a[i] = '\0';
			break;
		}
		a[i] = b[i];
	}
}

void CreateQueue(Queue *q){
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}

void enqueue(Queue *q, Produk x){
	if(IsEmpty(*q)){
		IDX_HEAD(*q) = 0;
	} else if(IsFull(*q)){
		printf("Antrian sudah penuh! Silakan coba lagi nanti!");
		return;
	}

	IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % (IDX_MAX + 1);
	strCopy(TAIL(*q), x);
}

void dequeue(Queue *q){
	if(IDX_HEAD(*q) == IDX_TAIL(*q)){
		IDX_HEAD(*q) = IDX_UNDEF;
		IDX_TAIL(*q) = IDX_UNDEF;
	} else {
		IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % (IDX_MAX + 1); 
	}
}

boolean IsMember(Queue q, Produk x){
	int i = IDX_HEAD(q);
	while(i != IDX_TAIL(q)){
		if(q.Tab[i] == x){
			return true;
		}

		i = (i + 1) % (IDX_MAX + 1);
	}

	return false;
}

Queue Request(Queue q){
	Produk antri;
	printf("Nama barang yang diminta: ");
	scanf("%s", antri);

	if(IsMember(q, antri)){
		printf("Barang dengan nama yang sama sudah tersedia di antrian!");
		Request(q);
	} else {
		enqueue(&q, antri);
	}

	return q;
}

void DisplayQueue(Queue q){
	if (IsEmpty(q)) {
        printf("[]\n");
    } else {
        int i = q.idxHead;
        printf("[");
        while (1) {
            printf("%s", q.Tab[i]);
            if (i == q.idxTail) break;
            printf(", ");
            i = (i + 1) % (IDX_MAX + 1);
        }
        printf("]\n");
    }
}

void Supply(Queue q){
	char *jawab;
	int harga;
	int i = 0;
	while(!IsEmpty(q)){
		printf("Apakah kamu ingin menambahkan barang %s: ", HEAD(q));
		scanf("%s", jawab);

		char *terima = "Terima", *tunda = "Tunda", *tolak = "Tolak";

		if(strCmpr(jawab, terima)){
			printf("Harga barang: ");
			scanf("%d", &harga);

			// Insert list disini

			dequeue(&q);
		} else if(strCmpr(jawab, tunda)){
			enqueue(&q, HEAD(q));
			dequeue(&q);
		} else if(strCmpr(jawab, tolak)){
			dequeue(&q);
		}
	}
}

boolean strCmpr(char *a, char *b){
	boolean status = false;
	for(int i = 0; i < 50; i++){
		if(*a == '\0'){
			break;
		} else if(*a != *b){
			return false;
		} else {
			status = true;
			a++; b++;
		}
	}

	return status;
}

int main(void){
	Queue q;
	CreateQueue(&q);

	q = Request(q);

	Supply(q);

	DisplayQueue(q);
}