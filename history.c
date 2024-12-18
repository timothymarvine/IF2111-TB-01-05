#include <stdio.h>
#include "stacklinked.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

int CountElements(Stack *S) {
    return length(*S);
}

void ShowHistory(Stack *S, int N) {
    if (isEmpty(*S)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    int totalElements = CountElements(S);

    if (N > totalElements) {
        N = totalElements;
    }

    Stack tempStack;
    CreateStack(&tempStack);

    Purchase temp;
    while (!isEmpty(*S)) {
        pop(S, &temp);
        push(&tempStack, temp);
    }

    int count = 0;
    while (!isEmpty(tempStack) && count < N) {
        pop(&tempStack, &temp);
        if (temp.price == (int)temp.price) {
            printf("%d. %s %d\n", count + 1, temp.itemName, (int)temp.price);
        } else {
            printf("%d. %s %.2f\n", count + 1, temp.itemName, temp.price);
        }
        push(S, temp);
        count++;
    }

    while (!isEmpty(tempStack)) {
        pop(&tempStack, &temp);
        push(S, temp);
    }

    printf("\n// Command mati; Kembali ke main menu\n");
}


void AddPurchase(Stack *S, const char *itemName, float price) {
    Purchase newPurchase;

    int i;
    for (i = 0; itemName[i] != '\0' && i < 49; i++) {
        newPurchase.itemName[i] = itemName[i];
    }
    newPurchase.itemName[i] = '\0';

    newPurchase.price = price;
    newPurchase.quantity = 1;
    push(S, newPurchase);
}

int main() {
    Stack S;
    CreateStack(&S);

    AddPurchase(&S, "AK47", 40);
    AddPurchase(&S, "AK47", 100);
    AddPurchase(&S, "Lalabu", 35);
    AddPurchase(&S, "AK47", 10);
    AddPurchase(&S, "Meong", 500);
    AddPurchase(&S, "Ayam Goreng Crisbar", 20);

    int pilihanhistory;
    char convert[50];

    printf("\n>> HISTORY ");
    STARTWORD();
    WordToString(currentWord, convert);
    pilihanhistory = stringToInteger(convert);
    if (pilihanhistory <= 0) {
        printf("Input tidak valid. Harap masukkan angka positif.\n");
        return 0;
    }

    ShowHistory(&S, pilihanhistory);

    return 0;
}
