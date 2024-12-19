/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUELIST_H
#define _QUEUELIST_H
#include "..\..\boolean.h"
#include "..\mesinkata\mesinkata.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL
#define IDX_MAX 99
#define IDX_UNDEF -1

typedef int IdxType;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue *addr;
typedef struct tElmtQueue
{
    Produk Info;
    addr Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct
{
    addr HEAD; /* alamat penghapusan */
    addr TAIL; /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void Alokasi(addr *P, Produk X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi(addr P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQ(Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQ(Queue *Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, Produk X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Dequeue(Queue *Q);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

boolean isMemberQ(Queue q, Produk x);

void DisplayQueue(Queue q);

#endif