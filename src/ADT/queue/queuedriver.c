#include "queuelist.h"

int main(){
    Queue q; CreateEmpty(&q);
    char breaker[4];
    strCopy(breaker, "exit");
    for(int i = 0; i < 3; i++){
        printf("Masukkan nama barang: ");
        STARTSENTENCE();

        Enqueue(&q, currentWord.TabWord);
    }

    DisplayQueue(q);
}