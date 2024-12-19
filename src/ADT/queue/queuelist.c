#include "queue.h"
#include <stdio.h>

boolean IsEmptyQ(Queue q){
	return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean IsFullQ(Queue q){
	return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % IDX_MAX;
}

int LengthQ(Queue q){
	if (IsEmptyQ(q)) {
        return 0;
    }
    if (q.idxTail >= q.idxHead) {
        return q.idxTail - q.idxHead + 1;
    } else {
        return (IDX_MAX - q.idxHead + q.idxTail + 2);
    }
}

void CreateQueue(Queue *q){
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}

void enqueue(Queue *q, Produk x){
	if(IsEmptyQ(*q)){
		IDX_HEAD(*q) = 0;
	} else if(IsFullQ(*q)){
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

    // return q;
}

void DisplayQueue(Queue q){
	if (IsEmptyQ(q)) {
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

boolean IsMemberQ(Queue q, Produk x){
	int i = IDX_HEAD(q);
	while(i != IDX_TAIL(q)){
		if(strCmpr(x, q.Tab[i])){
			return true;
		}

		i = (i + 1) % (IDX_MAX + 1);
	}

	return strCmpr(x, q.Tab[i]);
}
