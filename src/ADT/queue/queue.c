#include "queue.h"
#include <stdio.h>

boolean IsEmpty(Queue q){
	return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
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

    // return q;
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

// boolean strCmpr(char *dest, char *src){
// 	while (*dest != '\0' && *src != '\0') {
//         if (*dest != *src) {
//             return 0;
//         }
//         dest++;
//         src++;
//     }

//     return (*dest == '\0' && *src == '\0');
// }

boolean strCmpr(char *a, char *b) {
    while (*a && *b) {
        if (*a++ != *b++) return false;
    }
    return *a == '\0' && *b == '\0';
}

void strCopy(Produk dest, Produk src){
	for(int i = 0; i < 50; i++){
		if(src[i] == '\0'){
			dest[i] = '\0';
			break;
		}
		dest[i] = src[i];
	}
}