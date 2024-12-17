#include <stdio.h>
#include "stack.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

int CountElements(Stack *S) {
    int count = 0;
    Stack tempStack;
    CreateEmptyStack(&tempStack);

    infotypeStack temp;
    while (!IsEmptyStack(*S)) {
        Pop(S, &temp);
        Push(&tempStack, temp);
        count++;
    }

    // Restore the original stack
    while (!IsEmptyStack(tempStack)) {
        Pop(&tempStack, &temp);
        Push(S, temp);
    }

    return count;
}

void ShowHistory(Stack *S, int N) {
    if (IsEmptyStack(*S)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    int totalElements = CountElements(S);

    // Adjust N if it exceeds the total number of elements
    if (N > totalElements) {
        N = totalElements;
    }

    Stack tempStack;
    CreateEmptyStack(&tempStack);

    // Copy stack content to tempStack
    infotypeStack temp;
    while (!IsEmptyStack(*S)) {
        Pop(S, &temp);
        Push(&tempStack, temp);
    }

    // Display history
    int count = 0;
    while (!IsEmptyStack(tempStack) && count < N) {
        Pop(&tempStack, &temp);
        printf("%d. %s %d\n", count + 1, temp.itemName, (int)temp.price);
        Push(S, temp); // Push back to the original stack
        count++;
    }

    // Restore remaining elements
    while (!IsEmptyStack(tempStack)) {
        Pop(&tempStack, &temp);
        Push(S, temp);
    }

    printf("\n// Command mati; Kembali ke main menu\n");
}

void AddPurchase(Stack *S, const char *itemName, int price) {
    if (IsFullStack(*S)) {
        printf("History penuh! Tidak bisa menambahkan pembelian baru.\n");
        return;
    }

    infotypeStack newPurchase;
    snprintf(newPurchase.itemName, sizeof(newPurchase.itemName), "%s", itemName);
    newPurchase.price = price;
    newPurchase.quantity = 1; // Example: default quantity
    Push(S, newPurchase);
}

int main() {
    Stack S;
    CreateEmptyStack(&S);

    // Contoh pembelian
    AddPurchase(&S, "AK47", 40);
    AddPurchase(&S, "AK47", 100);
    AddPurchase(&S, "Lalabu", 35);
    AddPurchase(&S, "AK47", 10);
    AddPurchase(&S, "Meong", 500);
    AddPurchase(&S, "Ayam Goreng Crisbar", 20);

    int pilihanhistory;
    char convert[50];

    printf("\n>> HISTORY (Masukkan jumlah history yang ingin ditampilkan): ");
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
