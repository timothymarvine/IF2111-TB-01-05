#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void Alokasi(addr *p, Produk x){
    *p = (addr) malloc(sizeof(Produk));
    if(*p != Nil){
        strCopy(Info(*p), x);
        Next(*p) = Nil;
    }
}

void Dealokasi(addr p){
    free(p);
}

boolean IsEmptyQ(Queue q){
    return Head(q) == Nil && Tail(q) == Nil;
}

int NbElmt(Queue q){
    int ctr = 0;
    addr p = Head(q);
    while(p != Tail(q)){
        ctr++;
        p = Next(p);
    }

    return ctr + 1;
}

void CreateEmptyQ(Queue *q){
    Head(*q) = Nil;
    Tail(*q) = Nil;
}

void Enqueue(Queue *q, Produk x){
    addr p;
    Alokasi(&p, x);
    if(p != Nil){
        if(IsEmptyQ(*q)){
            Head(*q) = p;
            Tail(*q) = p;
        } else {
            Next(Tail(*q)) = p;
            Tail(*q) = p;
        }
    }
}

void Dequeue(Queue *q){
    if(IsEmptyQ(*q)){
        return;
    }
    addr p = Head(*q);
    if(Head(*q) == Tail(*q)){
        Head(*q) = Nil;
        Tail(*q) = Nil;
    } else {
        Head(*q) = Next(Head(*q));
    }
    Dealokasi(p);
}

boolean isMemberQ(Queue q, Produk x){
    if(IsEmptyQ(q)){
        return false;
    }
    addr p = Head(q);
    while(p != Nil){
        if(strCmpr(x, Info(p))){
            return true;
        }
        p = Next(p);
    }
    return false;
}

void DisplayQueue(Queue q){
    if(IsEmptyQ(q)){
        printf("Antrian kosong!");
        return;
    }
    addr p = Head(q);
    while(p != Nil){
        printf("%s", Info(p));
        if(Next(p) != Nil){
            printf(", ");
        }
        p = Next(p);
    }
    printf("\n");
}
