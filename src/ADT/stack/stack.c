#include <stdlib.h>
#include <stdio.h>
#include "..\..\boolean.h"
#include "stack.h"


/* Prototype manajemen memori */
Address newNode(Purchase x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   
{
    Address p = (Address) malloc (sizeof(Node));
    if(p != Nil){
        strCopy(INFO(p).itemName, x.itemName);
        INFO(p).total = x.total;
        NEXT(p) = Nil;
    } else {
        p = Nil;
    }

    return p;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s)
/* Mengirim true jika Stack kosong: ADDR_TOP(s) = Nil */
{
    return ADDR_TOP(s) == Nil;
}

int length(Stack s)
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */
{
    int count = 0;
    Address p;

    if(!isEmpty(s)) {
        p = ADDR_TOP(s);
        while (p!=Nil) {
            count++;
            p = NEXT(p);
        }
    }

    return count;
}

void CreateEmptyStack(Stack *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    ADDR_TOP(*s) = Nil;
}

void DisplayStack(Stack s, int x)
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */
{
    Address p;
	p = ADDR_TOP(s);
    int i = 0;
	printf("Riwayat pembelian barang:\n");
    while(i < x && p != Nil){
        printf("%d. %s %d\n", i + 1, INFO(p).itemName, INFO(p).total);
        i++; p = NEXT(p);
    }
}

void push(Stack *s, Purchase x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    Address p = newNode(x);
    if (p != NULL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, Purchase *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    Address p;
    p = ADDR_TOP(*s);
    *x = TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    free(p);
}