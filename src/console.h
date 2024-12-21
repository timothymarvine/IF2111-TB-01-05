#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT\array\array.h"
#include "ADT\array\arraydin.h"
#include "ADT\definitions.h"
#include "ADT\kustom\datatype.h"
#include "ADT\kustom\mainadt.h"
#include "ADT\linkedlist\linkedlist.h"
#include "ADT\map\map.h"
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\queue\queue.h"
#include "ADT\stack\stack.h"
#include "boolean.h"

extern array StoreList;

#define MAX_USERS 100
#define MAX_LENGTH 100
// Konstanta permainan
#define BIAYA_PERMAINAN 500
#define HADIAH 1500
#define PANJANG_KATA 5
#define MAX_PELUANG 6

typedef struct {
    char namaUser[50];
    char password[50];
    int uang;
} User;

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} UserData;

typedef struct {
    UserData users[MAX_USERS];
    int totalUsers;
    char activeUser[MAX_LENGTH];
} System;

/* Fitur-fitur pada PURRMART */

void STORELIST(ArrayDin StoreList);
/* Menampilkan daftar barang terkini yang dimiliki oleh store */

void STOREREMOVE(ArrayDin *StoreList);
/* Menghapus sebuah barang pada store */

void CartAdd(Map *c, int qty, ArrayDin list, char newItem[]);

void CartRemove(Map *c, int qty, char item[]);

void CARTPAY(Map *cart, ArrayDin list, Stack *history, int *money);

void CARTSHOW(Map cart, ArrayDin list);

void initializeSystem(System *sys);

boolean isUsernameTaken(UserCheckOut user[], const char *username, int totalUser);

void registerUser(UserCheckOut user[], const char *username, const char *password, int *totalUser);

boolean findUser(UserCheckOut user[], const char *username, const char *password, int totalUser);

void loginUser(UserCheckOut user[], char *username, const char *password, int *loggedIn, int totalUser, char activeUser[]);

void logoutUser(char username[], int *isLoggedIn);

void LOAD(char dir[], UserCheckOut data[], ArrayDin *barang, int *jumlahUser, int *loaded);

void SAVE(char dir[], UserCheckOut data[], ArrayDin barang, int jumlahUser);

void ConfigReader(UserCheckOut sys[], int *userCtr, ArrayDin *list, int *loaded);

void Request(Queue *q, ArrayDin *list);

void Supply(Queue *q, ArrayDin *list);

int generateRandomNumber(int min, int max);

void tebakAngka(int *uang_asal);

// Deklarasi fungsi untuk menangani logika permainan
int string_length(const char *str);

// Fungsi untuk memilih kata acak dari kumpulan kata
void pilih_kata_acak(char *kata_terpilih);

// Fungsi untuk memproses tebakan
void proses_tebakan(const char *tebakan, const char *target, char *hasil);

// Fungsi untuk membandingkan dua string
int bandingkan_string(const char *str1, const char *str2);

// Fungsi untuk menampilkan progres permainan
void tampilkan_progress(char tebakan[MAX_PELUANG][PANJANG_KATA * 2 + 1], int peluang);

// Fungsi utama permainan W0RDL399
void WORDL399(int *uang_asal);

void delay(int seconds);

void work(int *uang_asal);

void workChallenge(int *uang_asal);

int CountElements(Stack *S);

void ShowHistory(Stack *S, int N);

void AddPurchase(Stack *S, char *itemName, float price);

int MyStrLen(const char *str);

void MyStrCpy(char *dest, const char *src);

int MyStrCmp(const char *str1, const char *str2);

int IsBarangValid(const char *NamaBarang);

void wishlistAdd(LinkedList *L);

void wishlistSwap(LinkedList *L, int i, int j);

void wishlistRemoveIndex(LinkedList *L, int index);

void wishlistRemove(LinkedList *L);

void wishlistClear(LinkedList *L);

void wishlistShow(LinkedList L);

void showProfile(char user[], int uang_asal);

#endif