#include <stdio.h>
#include "menu.h"
#include "rll.h"
#include "work.h"
#include "mesinkata.h"

void showProfile(System *sys, User user[], int userCount, int uang_asal){

    uang_asal = 2000;
    if (sys->activeUser[0] == '\0')
    {
        printf("silakan LOGIN terlebih dahulu untuk melihat profil. \n");
        return;
    }
    
    for (int i = 0; i < userCount; i++)
    {
        if (isWordEqual(sys->activeUser, user[i].namaUser))
        {
            printf("== PROFILE ==\n ");
            printf("Nama: ");
            for (int j = 0; user[i].namaUser[j] != '\0'; j++){
                putchar(user[i].namaUser[j]);
            }
            printf("\nSaldo : %d\n", uang_asal);
            printf("\n // Kembali ke menu utama\n");
            return;
        }
    }
    
}
