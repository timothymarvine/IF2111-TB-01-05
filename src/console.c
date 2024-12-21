#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"

// Daftar kata yang bisa dipilih secara acak
const char *daftar_kata[] = {"STEIK", "CISCO", "JAKET", "HUJAN", "LUCKY","INGIN","MAKAN"};
const int ukuran_daftar_kata = 5;

void STORELIST(ArrayDin StoreList){
  if (IsEmptyDin(StoreList)) {
      printf("TOKO KOSONG\n");
      return;
  }

  printf("List barang yang ada di toko : \n");
  for (int i = 0; i < StoreList.Neff; i++){
    printf("- ");
    printf("%s - %d\n", StoreList.A[i].name, StoreList.A[i].price);
  }
}


void STOREREMOVE(ArrayDin *StoreList){
  STORELIST(*StoreList); 
    printf("\nNama barang yang akan dihapus : "); 
    STARTSENTENCE();

    if (SearchArrayDin(*StoreList, currentWord.TabWord)) { 
      for (int i = 0; i < StoreList->Neff; i++) {
        if (strCmpr(StoreList->A[i].name, currentWord.TabWord)) {
          DeleteAtL(StoreList, i);
          PrintKata(currentWord);
          printf(" telah berhasil dihapus.\n");
        }
      }
    } 
    else {
      printf("Toko tidak menjual ");
      PrintKata(currentWord);
      printf("\n");
    }
} 

void CartAdd(Map *c, int qty, ArrayDin list, char newItem[]){
    if(SearchArrayDin(list, newItem)){
        if(!IsMemberM(*c, newItem)){
            strCopy(c->Elements[c->Count].Key, newItem);
            c->Elements[c->Count].Value = 0;
            c->Count++;
        }
        ChangeVal(c, newItem, qty);
    } else {
        printf("Barang tidak ada di toko!");
    }
}

void CartRemove(Map *c, int qty, char item[]){
    Produk i;
    strCopy(i, item);
    if(IsMemberM(*c, i)){
        ChangeVal(c, i, qty);
    } else {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}

void CARTPAY(Map *cart, ArrayDin list, Stack *history, int *money){
  if (cart->Count == 0) {
      printf("Keranjang kamu kosong!\n");
      return;
  }
  int userMoney = *money;
  printf("Kamu akan membeli barang-barang berikut.\n");
  printf("Kuantitas\tNama\t\tTotal\n");

  int totalCost = 0;
  for (int i = 0; i < cart->Count; i++) {
    int j = 0;
    while(!strCmpr(cart->Elements[i].Key, list.A[j].name)){
      j++;
    }
    int itemTotal = list.A[j].price * cart->Elements[i].Value;
    totalCost += itemTotal;
    printf("%d\t\t%s\t%d\n", cart->Elements[i].Value, cart->Elements[i].Key, itemTotal);
  }
  printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak)\n", totalCost);
  STARTSENTENCE();

  if (WordCompareString(currentWord, "Ya")){
    if (userMoney >= totalCost) {
      userMoney -= totalCost;
      Purchase purchase;
      for (int i = 0; i < cart->Count; i++) {
        int j = 0;
        while(1){
            if(strCmpr(list.A[j].name, cart->Elements[i].Key)){
                break;
            } else {
                j++;
            }
        }
        strCopy(purchase.itemName, cart->Elements[i].Key);
        purchase.total = list.A[j].price * cart->Elements[i].Value;
        push(history, purchase);
      }

      cart->Count = 0;

      printf("Selamat kamu telah membeli barang-barang tersebut!\n");
    }
    else {
      printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", userMoney);
    }
  }
  else if (WordCompareString(currentWord, "Tidak")) {
    return;
  }
  else {
    return;
  }
}

void CARTSHOW(Map cart, ArrayDin list){
  if (cart.Count == 0) {
      printf("Keranjang kamu kosong!\n");
      return;
  }
  printf("Berikut adalah isi keranjangmu.\n");
  printf("Kuantitas\tNama\t\tTotal\n");

  int totalCost = 0;
  for (int i = 0; i < cart.Count; i++) {
    int j = 0;
    while(!strCmpr(cart.Elements[i].Key, list.A[j].name)){
      j++;
    }
    int itemTotal = list.A[j].price * cart.Elements[i].Value;
    totalCost += itemTotal;
    printf("%d\t\t%s\t%d\n", cart.Elements[i].Value, cart.Elements[i].Key, itemTotal);
  }
  printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalCost);
}

void initializeSystem(System *sys) {
    sys->totalUsers = 0;
    sys->activeUser[0] = '\0';
}

boolean isUsernameTaken(UserCheckOut user[], const char *username, int totalUser) {
    for(int i = 0; i < totalUser; i++){
        if (isWordEqual(username, user[i].name)) {
            return true;
        }
    }
    return false;
}

void registerUser(UserCheckOut user[], const char *username, const char *password, int *totalUser) {
    if (isUsernameTaken(user, username, *totalUser)) {
        printf("\nAkun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return;
    }

    if (*totalUser < MAX_USERS) {
        for(int i = 0; i < MAX_LENGTH; i++){
            if(username[i] == '\0' || username[i] == '\n') break;
            user[*totalUser].name[i] = username[i];
        }
        for(int i = 0; i < MAX_LENGTH; i++){
            if(password[i] == '\0' || username[i] == '\n') break;
            user[*totalUser].password[i] = password[i];
        }
        CreateEmptyStack(&user[*totalUser].history);
        CreateList(&user[*totalUser].wishlist);
        CreateEmptyM(&user[*totalUser].cart);
        user[*totalUser].money = 0;
        totalUser++;
        printf("\nAkun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    } else {
        printf("\nSistem penuh, tidak bisa menambahkan akun baru.\n");
    }
}

boolean findUser(UserCheckOut user[], const char *username, const char *password, int totalUser) {
    for (int i = 0; i < totalUser; i++) {
        if (isWordEqual(username, user[i].name) && isWordEqual(password, user[i].password)) {
            return true;
        }
    }
    return 0;
}

void loginUser(UserCheckOut user[], char *username, const char *password, int *loggedIn, int totalUser, char activeUser[]) {
    if (activeUser[0] != '\0') {
        printf("\nAnda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", activeUser);
        return;
    }

    if (findUser(user, username, password, totalUser)) {
        printf("\nAnda telah login ke PURRMART sebagai %s.\n", username);
        *loggedIn = 1;
        strCopy(activeUser, username);
    } else {
        printf("\nUsername atau password salah.\n");
    }
}

void logoutUser(char activeUser[], int *isLoggedIn) {
    printf("\n%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", activeUser);
    activeUser[0] = '\0';
    *isLoggedIn = 0;
}

void LOAD(char dir[], UserCheckOut data[], ArrayDin *barang, int *jumlahUser, int *loaded) {
    int i, N, M;
    char filename[100] = "src/save/";

    for (i = 0; i < Strlen(dir); i++) {
        filename[9 + i] = dir[i];
    }
    filename[9 + Strlen(dir)] = '\0';

    STARTWORDFILE(filename);

    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }

    N = WordToInt(currentWord);

    for (i = 0; i < N; i++) {
        ADVWORD();
        barang->A[i].price = WordToInt(currentWord);

        ADVSENTENCE();
        WordToCharArray(currentWord, barang->A[i].name);
    }

    ADVWORD();
    M = WordToInt(currentWord);
    *jumlahUser = M;

    for (i = 0; i < M; i++) {
        ADVWORD();
        data[i].money = WordToInt(currentWord);

        ADVWORD();
        WordToCharArray(currentWord, data[i].name);

        ADVWORD();
        WordToCharArray(currentWord, data[i].password);

        ADVWORD();
        int historyCnt = WordToInt(currentWord);
        for(int j = 0; j < historyCnt; j++){
            Purchase x;
            ADVWORD();
            x.total = WordToInt(currentWord);

            ADVSENTENCE();
            strCopy(x.itemName, currentWord.TabWord);

            push(&data[i].history, x);
        }
 
        ADVWORD();
        int wishlistCnt = WordToInt(currentWord);
        for(int j = 0; j < wishlistCnt; j++){
            ADVSENTENCE();
            Address p = Allocate(currentWord.TabWord);
            if(p != NULL){
                InsertLastList(&data[i].wishlist, p);
            }
        }
    }

    if(strCmpr(dir, "config.txt")){
        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.");
        *loaded = 1;
    } else {
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
    }
}

void SAVE(char dir[], UserCheckOut data[], ArrayDin barang, int jumlahUser) {
    int i;
    char filename[100] = "src/save/";

    for (i = 0; i < Strlen(dir); i++) {
        filename[9 + i] = dir[i];
    }
    filename[9 + Strlen(dir)] = '\0';

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal menyimpan file.\n");
        return;
    }

    printf("%s\n", filename);
    fprintf(file, "%d\n", LengthDin(barang));

    for (i = 0; i < LengthDin(barang); i++) {
        fprintf(file, "%d %s\n", barang.A[i].price, barang.A[i].name);
    }

    fprintf(file, "%d\n", jumlahUser);

    for (i = 0; i < jumlahUser; i++) {
        fprintf(file, "%d %s %s\n", data[i].money, data[i].name, data[i].password);

        int jumlahHistory = length(data[i].history);
        fprintf(file, "%d\n", jumlahHistory);
        Addr p = ADDR_TOP(data[i].history);
        for(int j = 0; j < jumlahHistory; j++){
            fprintf(file, "%d %s\n", INFO(p).total, INFO(p).itemName);
            p = NEXT(p);
        }

        int jumlahWishlist = ListLength(data[i].wishlist);
        fprintf(file, "%d\n", jumlahWishlist);
        Address q = FirstL(data[i].wishlist);
        for(int j = 0; j < jumlahWishlist; j++){
            fprintf(file, "%s\n", InfoL(q));
            q = NextL(q);
        }
    }

    fclose(file);
    printf("Save file berhasil disimpan.\n");
}

void ConfigReader(UserCheckOut sys[], int *userCtr, ArrayDin *list, int *loaded){
    LOAD("config.txt", sys, list, userCtr, loaded);
}

void Request(Queue *q, ArrayDin *list){
	char antri[50];
	printf("Nama barang yang diminta: ");
	STARTSENTENCE();
	strCopy(antri, currentWord.TabWord);

	if(isMemberQ(*q, antri)){
		printf("\nBarang dengan nama yang sama sudah tersedia di antrian!\n");
	} else if(SearchArrayDin(*list, antri)){
		printf("\nBarang dengan nama yang sama sudah tersedia di toko!\n");
	} else {
		Enqueue(q, antri);
	}
}

void Supply(Queue *q, ArrayDin *list){
	char jawab[20];
	int harga;
	int i = 0;
	if(IsEmptyQ(*q)){
		printf("\nTidak ada permintaan barang.\n");
		return;
	}
	while(!IsEmptyQ(*q)){
		printf("Apakah kamu ingin menambahkan barang %s: ", InfoHead(*q));
		STARTWORD();
		strCopy(jawab, currentWord.TabWord);

		Word temp, item;
		strCopy(item.TabWord, InfoHead(*q));
		for(int i = 0; i < NMax; i++){
			currentWord.TabWord[i] = '\0';
		}

		if(strCmpr(jawab, "Terima")){
			Barang masuk;
			strCopy(masuk.name, InfoHead(*q));

			printf("Harga barang: ");
			STARTWORD();
			WordToString(currentWord, temp.TabWord);
			harga = stringToInteger(temp.TabWord);

			masuk.price = harga;
			InsertLastL(list, &masuk);
			
			printf("\n%s dengan harga %d telah ditambahkan ke toko.\n", masuk.name, masuk.price);
			Dequeue(q);
		} else if(strCmpr(jawab, "Tunda")){
			Enqueue(q, InfoHead(*q));
			printf("\n%s dikembalikan ke antrian.\n", InfoHead(*q));
			Dequeue(q);
			if(i++ >= NbElmt(*q) - 1){
				break;
			}
		} else if(strCmpr(jawab, "Tolak")){
			printf("\n%s dihapuskan dari antrian.\n", InfoHead(*q));
			Dequeue(q);
		} else {
			return;
		}
	}
}

int generateRandomNumber(int min, int max) {
    time_t t;
    t = time(NULL);

    unsigned int seed = (unsigned int)t;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;

    int randomNum = (seed % (max - min + 1)) + min;
    return randomNum;
}

void tebakAngka(int *uang_asal){
    int biaya_main = 200, tebakAngka, RNGnumber, hadiah = 500, hadiah_sisa_uang;
    int kesempatan = 10;
    char convert;
    boolean tebakanBenar = false;
    if (*uang_asal < biaya_main){
        printf("Uang Anda tidak cukup!");
        return;
    }

    *uang_asal -= biaya_main;
    printf("Uang Anda tersisa %d.\n\n", *uang_asal);

    printf("Tebak Angka (1-100) dengan kesempatan tersisa %d.\n", kesempatan);

    RNGnumber = generateRandomNumber(1,100);

    while(kesempatan > 0 && tebakanBenar == false){
        printf("Tebak Angka = ");
        STARTWORD();
        WordToString(currentWord, &convert);
        tebakAngka = stringToInteger(&convert);
        if (tebakAngka < RNGnumber){
            printf("Tebakanmu lebih kecil!\n");
        }else if(tebakAngka > RNGnumber){
            printf("Tebakanmu lebih besar!\n");
        }else if(tebakAngka == RNGnumber){
            tebakanBenar = true;
            if(kesempatan == 10){
                hadiah_sisa_uang = 500;
                printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun Anda\n",hadiah_sisa_uang);
                *uang_asal += hadiah_sisa_uang;
                printf("Uang anda sekarang adalah = %d.\n", *uang_asal);
                return;
            }else{
                hadiah_sisa_uang = 500 - 50*(10-kesempatan);
                printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun Anda\n",hadiah_sisa_uang);
                *uang_asal += hadiah_sisa_uang;
                printf("Uang anda sekarang adalah = %d.\n", *uang_asal);
                return;
            }
        }
    kesempatan--;
    printf("Sisa kesempatan adalah %d.\n\n", kesempatan);
    }
    hadiah_sisa_uang = 500 - 50*(10-kesempatan);
    *uang_asal -= hadiah_sisa_uang;
    printf("Kesempatan Anda sudah habis. Angka yang benar adalah %d. Uang Anda tersisa %d\n", RNGnumber, *uang_asal);
}

// Deklarasi fungsi untuk menangani logika permainan
int string_length(const char *str){
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}


// Fungsi untuk memilih kata acak dari kumpulan kata
void pilih_kata_acak(char *kata_terpilih) {
    srand(time(NULL)); // Menyebabkan kata acak setiap kali dijalankan
    int indeks = rand() % ukuran_daftar_kata;
    for (int i = 0; i < PANJANG_KATA; i++) {
        kata_terpilih[i] = daftar_kata[indeks][i];
    }
    kata_terpilih[PANJANG_KATA] = '\0'; // Menambahkan null terminator untuk mengakhiri string
}

// Fungsi untuk memproses tebakan
void proses_tebakan(const char *tebakan, const char *target, char *hasil) {
    boolean sudah_digunakan[PANJANG_KATA] = {false};  // Array untuk melacak huruf yang sudah diproses

    // Memeriksa huruf yang tepat di posisi yang benar
    for (int i = 0; i < PANJANG_KATA; i++) {
        if (tebakan[i] == target[i]) {
            hasil[i * 2] = tebakan[i]; // Huruf yang benar
            hasil[i * 2 + 1] = ' ';
            sudah_digunakan[i] = true;
        }
    }

    // Memeriksa huruf yang tepat tetapi di posisi yang salah
    for (int i = 0; i < PANJANG_KATA; i++) {
        if (tebakan[i] != target[i]) {
            boolean ditemukan = false;
            for (int j = 0; j < PANJANG_KATA; j++) {
                if (!sudah_digunakan[j] && tebakan[i] == target[j]) {
                    hasil[i * 2] = tebakan[i];
                    hasil[i * 2 + 1] = '*';  // Huruf benar tapi posisinya salah
                    sudah_digunakan[j] = true;
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                hasil[i * 2] = tebakan[i];
                hasil[i * 2 + 1] = '%';  // Huruf tidak ada dalam kata
            }
        }
    }

    hasil[PANJANG_KATA * 2] = '\0';  // Menambahkan null terminator
}

// Fungsi untuk membandingkan dua string
int bandingkan_string(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Fungsi untuk menampilkan progres permainan
void tampilkan_progress(char tebakan[MAX_PELUANG][PANJANG_KATA * 2 + 1], int peluang) {
    for (int i = 0; i < MAX_PELUANG; i++) {
        if (i < peluang) {
            printf("%s\n", tebakan[i]);
        } else {
            for (int j = 0; j < PANJANG_KATA; j++) {
                printf("_ ");  // Menampilkan tempat kosong
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Fungsi utama permainan W0RDL399
void WORDL399(int *uang_asal) {
    if (*uang_asal < BIAYA_PERMAINAN) {
        printf("Uang Anda tidak cukup untuk memainkan W0RDL399.\n");
        return;
    }

    *uang_asal -= BIAYA_PERMAINAN;  // Mengurangi biaya permainan
    printf("Uang Anda tersisa %d.\n\n", *uang_asal);
    printf("\nSELAMAT DATANG DI W0RDL3, ANDA MEMILIKI %d PELUANG UNTUK MENEBAK KATA!\n\n", MAX_PELUANG);

    char kata_target[PANJANG_KATA + 1];
    pilih_kata_acak(kata_target);  // Memilih kata acak

    char tebakan[MAX_PELUANG][PANJANG_KATA * 2 + 1] = {0};  // Menyimpan tebakan pemain
    char tebakan_input[PANJANG_KATA + 1];
    int peluang = 0;
    boolean tebakan_benar = false;
    char temp[PANJANG_KATA+1];
    while (peluang < MAX_PELUANG && !tebakan_benar) {
        tampilkan_progress(tebakan, peluang + 1);  // Menampilkan progres permainan

        
        printf("Masukkan kata tebakan Anda: ");
        
        STARTWORD();  // Menggunakan mesinkata untuk membaca input kata
        WordToString(currentWord,temp);

        // Menyalin kata yang dimasukkan ke dalam tebakan
        for (int i = 0; i < PANJANG_KATA; i++) {
            tebakan_input[i] = currentWord.TabWord[i];
        }
        tebakan_input[PANJANG_KATA] = '\0'; // Menambahkan null terminator

        // Validasi panjang kata
        if (string_length(tebakan_input) != PANJANG_KATA) {
            printf("Kata harus terdiri dari %d huruf. Coba lagi.\n", PANJANG_KATA);
            continue;
        }

        // Memproses tebakan
        proses_tebakan(tebakan_input, kata_target, tebakan[peluang]);
        printf("Hasil:\n");
        tampilkan_progress(tebakan, peluang + 1);

        // Memeriksa apakah tebakan benar
        if (bandingkan_string(tebakan_input, kata_target) == 0) {
            tebakan_benar = true;
            printf("Selamat, Anda menang!\n");
            printf("+%d rupiah telah ditambahkan ke akun Anda.\n", HADIAH);
            *uang_asal += HADIAH;  // Memberikan hadiah
            printf("Uang Anda sekarang: %d\n", *uang_asal);
            return;
        }

        peluang++;
    }

    // Jika pemain tidak berhasil menebak dalam percobaan terbatas
    printf("Maaf, Anda kalah! Kata yang benar adalah: %s\n", kata_target);
    printf("Uang Anda tersisa: %d\n", *uang_asal);
}

void delay(int seconds){
    clock_t start_time = clock();
    clock_t end_time = start_time + seconds * CLOCKS_PER_SEC;

    while (clock() < end_time);
}


void work(int *uang_asal){
    int pendapatan = 0, durasi = 0;
    char *pekerjaan;
    char tes[50];
    char pilihankerja[20];
    printf("Daftar pekerjaan: \n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("Masukkan pekerjaan yang dipilih: ");
    STARTSENTENCE();
    WordToString(currentWord, tes);

    for (int i = 0; i < currentWord.Length; i++) {
        pilihankerja[i] = tes[i];
    }
    pilihankerja[currentWord.Length] = '\0';

    if (manual_strcmp(pilihankerja, "Evil Lab Assistant") == 0){
        pekerjaan = "Evil Lab Assistant";
        pendapatan = 100;
        durasi = 14;
    }else if(manual_strcmp(pilihankerja, "OWCA Hiring Manager") == 0){
        pekerjaan = "OWCA Hiring Manager";
        pendapatan = 4200;
        durasi = 21;
    }else if(manual_strcmp(pilihankerja, "Cikapundunginator") == 0){
        pekerjaan = "Cikapundunginator";
        pendapatan = 7000;
        durasi = 30;
    }else if(manual_strcmp(pilihankerja, "Mewing Specialist") == 0){
        pekerjaan = "Mewing Specialist";
        pendapatan = 10000;
        durasi = 22;
    }else if(manual_strcmp(pilihankerja, "Inator Connoisseur") == 0){
        pekerjaan = "Inator Connoisseur";
        pendapatan = 997;
        durasi = 15;
    }else{
        printf("Pilihan tidak valid!\n");
        return;
    }
    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaan);
    delay(durasi);
    *uang_asal += pendapatan;
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pendapatan);
    printf("Uang anda sekarang adalah : %d rupiah\n", *uang_asal);
}

void workChallenge(int *uang_asal){
        if (*uang_asal <= 0) {
        printf("Uang anda tidak cukup untuk memulai challenge! Silakan bekerja terlebih dahulu pada menu work.\n");
        return;
        }

    int pilihanchallenge;
    char apapun;
    printf("Daftar challenge yang tersedia: \n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("Masukkan challenge yang hendak dimainkan: ");
    STARTWORD();
    WordToString(currentWord, &apapun);
    pilihanchallenge = stringToInteger(&apapun);
    printf("\n");

    switch (pilihanchallenge){
        case 1:
            tebakAngka(uang_asal);
            break;
        case 2:
            WORDL399(uang_asal);
            break;
        default:
            printf("Pilihanmu tidak ada!");
            break;
    }
}

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
    CreateEmptyStack(&tempStack);

    Purchase temp;
    while (!isEmpty(*S)) {
        pop(S, &temp);
        push(&tempStack, temp);
    }

    int count = 0;
    while (!isEmpty(tempStack) && count < N) {
        pop(&tempStack, &temp);
        if (temp.total == (int)temp.total) {
            printf("%d. %s %d\n", count + 1, temp.itemName, (int)temp.total);
        } else {
            printf("%d. %s %.2f\n", count + 1, temp.itemName, temp.total);
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


void AddPurchase(Stack *S, char *itemName, float price) {
    Purchase newPurchase;

    strCopy(newPurchase.itemName, itemName);
    newPurchase.total = price;
    push(S, newPurchase);
}

int MyStrLen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void MyStrCpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int MyStrCmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

const char *DatabaseBarang[] = {
    "Ayam Geprek Bakar Crispy Besthal",
    "Ayam Geprek Sambalado Besthal"
};
const int TotalBarang = 2;

int IsBarangValid(const char *NamaBarang) {
    for (int i = 0; i < TotalBarang; i++) {
        if (MyStrCmp(DatabaseBarang[i], NamaBarang) == 0) {
            return 1; // Barang valid
        }
    }
    return 0; // Barang tidak valid
}

void wishlistAdd(LinkedList *L) {
    char NamaBarang[100];

    printf("\n>> WISHLIST ADD\n");
    printf("Masukkan nama barang: ");

    STARTSENTENCE();
    WordToString(currentWord, NamaBarang);

    if (!IsBarangValid(NamaBarang)) {
        printf("Tidak ada barang dengan nama %s!\n", NamaBarang);
        return;
    }

    if (Search(*L, NamaBarang) != NIL) {
        printf("%s sudah ada di wishlist!\n", NamaBarang);
    } else {
        Address P = Allocate(NamaBarang);
        if (P != NIL) {
            InsertLastList(L, P);
            printf("Berhasil menambahkan %s ke wishlist!\n", NamaBarang);
        } else {
            printf("Gagal menambahkan %s ke wishlist. Alokasi memori gagal.\n", NamaBarang);
        }
    }
}

void wishlistSwap(LinkedList *L, int i, int j) {
    if (i == j) {
        printf("Gagal menukar posisi, posisi ke-%d dan ke-%d adalah sama.\n", i, j);
        return;
    }

    Address Pi = FirstL(*L), Pj = FirstL(*L);

    for (int index = 1; Pi != NIL && index < i; index++) {
        Pi = NextL(Pi);
    }
    for (int index = 1; Pj != NIL && index < j; index++) {
        Pj = NextL(Pj);
    }

    if (Pi == NIL || Pj == NIL) {
        printf("Gagal menukar posisi! Salah satu indeks tidak valid.\n");
    } else {
        char *temp = InfoL(Pi);
        InfoL(Pi) = InfoL(Pj);
        InfoL(Pj) = temp;

        printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", InfoL(Pi), InfoL(Pj));
    }
}

void wishlistRemoveIndex(LinkedList *L, int index) {
    if (IsListEmpty(*L)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    Address P = FirstL(*L);
    for (int currentIndex = 1; P != NIL && currentIndex < index; currentIndex++) {
        P = NextL(P);
    }

    if (P == NIL) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", index);
    } else {
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", index);
        if (P == FirstL(*L)) {
            DeleteFirstList(L, &P);
        } else if (P == LastL(*L)) {
            DeleteLastList(L, &P);
        } else {
            NextL(PrevL(P)) = NextL(P);
            PrevL(NextL(P)) = PrevL(P);
        }
        Deallocate(P);
    }
}

void wishlistRemove(LinkedList *L) {
    char item[100];

    printf("Masukkan nama barang yang akan dihapus: ");
    STARTSENTENCE();
    WordToString(currentWord, item);

    for (Address temp = FirstL(*L); temp != NIL; temp = NextL(temp)) {
        if (MyStrCmp(InfoL(temp), item) == 0) {
            if (temp == FirstL(*L)) {
                DeleteFirstList(L, &temp);
            } else if (temp == LastL(*L)) {
                DeleteLastList(L, &temp);
            } else {
                NextL(PrevL(temp)) = NextL(temp);
                PrevL(NextL(temp)) = PrevL(temp);
            }
            printf("%s berhasil dihapus dari WISHLIST!\n", item);
            Deallocate(temp);
            return;
        }
    }

    printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item);
}

void wishlistClear(LinkedList *L) {
    Address P;
    while (!IsListEmpty(*L)) {
        DeleteFirstList(L, &P);
        Deallocate(P);
    }
    printf("Wishlist telah dikosongkan.\n");
}

void wishlistShow(LinkedList L) {
    if (IsListEmpty(L)) {
        printf("Wishlist kamu kosong!\n");
    } else {
        printf("Berikut adalah isi wishlist-mu:\n");
        int index = 1;
        for (Address P = FirstL(L); P != NIL; P = NextL(P)) {
            printf("%d. %s\n", index, InfoL(P));
            index++;
        }
    }
}

void showProfile(char username[], int uang){
    if (username[0] == '\0')
    {
        printf("silakan LOGIN terlebih dahulu untuk melihat profil. \n");
        return;
    }
    
    printf("\n== PROFILE ==\n");
    printf("Nama  : %s", username);
    printf("\nSaldo : %d\n\n", uang);
    return;
    
}
