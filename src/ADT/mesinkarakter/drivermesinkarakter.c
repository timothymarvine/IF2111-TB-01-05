#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    char mode;
    char fileName[100];
    int i = 0;

    
    printf("Pilih mode (S untuk stdin, F untuk file): ");
    START();  
    mode = currentChar;  
    ADV();  

    
    if (mode == 'S' || mode == 's') {
        
        printf("Masukkan teks (akhiri dengan newline):\n");
        START();  
        while (!IsEOP()) {
            putchar(currentChar);  
            ADV();  
        }
    } else if (mode == 'F' || mode == 'f') {
       
        printf("Masukkan nama file: ");
        START();  
        while (!IsEOP() && i < 99) {
            fileName[i++] = currentChar;  
            ADV();  
        }
        fileName[i] = '\0';  

        
        STARTFILE(fileName);  
        if (pita != NULL) {
            while (!IsEOP()) {
                putchar(currentChar);  
                ADV();  
            }
        } else {
            printf("File tidak ditemukan.\n");
        }
    } else {
        printf("Mode tidak valid. Pilih 'S' atau 'F'.\n");
    }

    printf("\nSelesai.\n");
    return 0;
}
