# TOKO-ONLINE
TUGAS AKHIR ALGORITMA DAN PEMROGRAMAN RANGGA RIZKY NUGRAHA(23346018)
#include <stdio.h>
#include <string.h>

#define MAKS_BARANG 10
#define MAKS_PANJANG_STRING 50
#define MAX_USERS 5

// Struktur untuk menyimpan informasi pengguna
struct User {
    char username[MAKS_PANJANG_STRING];
    char password[MAKS_PANJANG_STRING];
};

// Variabel untuk menyimpan data pengguna
struct User users[MAX_USERS];

char nama_barang[MAKS_BARANG][MAKS_PANJANG_STRING] = {
    "pensil", 
	"buku", 
	"spidol", 
	"penghapus",
	"penggaris", 
	"tip-x", 
	"stabilo", 
	"twinpen",
	"pena", 
	"crayon"
};

int harga_barang[MAKS_BARANG] = {
    5000, 
	3000, 
	7000, 
	4000, 
	1000,
	6000, 
	8000, 
	12000, 
	4500, 
	20000
};

int total_users = 0; // Jumlah pengguna yang telah terdaftar
int current_user_index = -1; // Indeks pengguna yang saat ini login

// Fungsi untuk melakukan login
void login() {
    char input_username[MAKS_PANJANG_STRING];
    char input_password[MAKS_PANJANG_STRING];

    printf("Masukkan username: ");
    scanf("%s", input_username);
    
    for (int i = 0; i < total_users; ++i) {
        if (strcmp(users[i].username, input_username) == 0) {
            printf("Masukkan password: ");
            scanf("%s", input_password);

            if (strcmp(users[i].password, input_password) == 0) {
                printf("Login berhasil!\n");
                current_user_index = i;
                return;
            } else {
                printf("Password salah. Silakan coba lagi.\n");
                return;
            }
        }
    }

    printf("Username tidak ditemukan. Silakan mendaftar terlebih dahulu.\n");
}

// Fungsi untuk melakukan registrasi
void register_user() {
    if (total_users < MAX_USERS) {
        printf("Masukkan username baru: ");
        scanf("%s", users[total_users].username);

        printf("Masukkan password baru: ");
        scanf("%s", users[total_users].password);

        printf("Registrasi berhasil!\n");
        total_users++;
    } else {
        printf("Maaf, jumlah pengguna maksimum telah tercapai.\n");
    }
}

// Fungsi untuk menampilkan menu
void print_menu() {
    printf("=====================================\n");
    printf("| Silahkan Pilih Menu yang anda mau |\n");
    printf("=====================================\n");
    printf("| 1. Tampilkan daftar barang        |\n");
    printf("| 2. Beli barang                    |\n");
    printf("| 0. Keluar                         |\n");
    printf("=====================================\n");
}

// Fungsi untuk menampilkan daftar barang
void tampilkan_barang() {
    printf("====================================\n");
    printf("| No |   Nama Barang   |   Harga   |\n");
    printf("====================================\n");

    int ada_barang = 0;
    for (int i = 0; i < MAKS_BARANG; ++i) {
        if (nama_barang[i][0] != '\0') {
            printf("| %-2d | %-15s | Rp %-6d |\n", i + 1, nama_barang[i], harga_barang[i]);
            ada_barang = 1;
        }
    }

    if (!ada_barang) {
        printf("|                   Belum ada barang yang ditambahkan.                  |\n");
    }
    
    printf("====================================\n");
}

// Fungsi untuk melakukan pembelian barang
void beli_barang() {
    int pilihan, total_harga = 0, uang_sisa;
    char lanjut;

    do {
        printf("Pilih barang yang ingin dibeli (nomor): ");
        scanf("%d", &pilihan);

        if (pilihan <= 0 || pilihan > MAKS_BARANG || nama_barang[pilihan - 1][0] == '\0') {
            printf("Pilihan tidak valid.\n");
            continue;
        }

        total_harga += harga_barang[pilihan - 1];

        printf("Apakah Anda ingin membeli barang lain? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    printf("\nTotal harga yang harus dibayarkan: %d\n", total_harga);

    int uang_bayar;
    printf("Masukkan uang yang anda bayar: ");
    scanf("%d", &uang_bayar);
	
	uang_sisa = total_harga - uang_bayar;
	
    if (uang_bayar >= total_harga) {
        printf("Terima kasih telah berbelanja. Kembalian: %d\n", uang_bayar - total_harga);
    } else {
        printf("Maaf, uang anda kurang %d. Pembelian dibatalkan.\n",uang_sisa);
    }
}

int main() {
    int pilihan, pilihan2;

    // Loop untuk login atau registrasi
    do {
        printf("==================================\n");
		printf("|  SELAMAT DATANG DITOKO RANGGA  |\n");
		printf("==================================\n");
        printf("| Silahkan login terlebih dahulu |\n");
		printf("| 1. Login                       |\n");
        printf("| 2. Registrasi                  |\n");
        printf("| 0. Keluar                      |\n");
        printf("==================================\n");
	    printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                login();
                break;
            case 2:
                register_user();
                break;
            case 0:
                printf("Terima kasih!\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (current_user_index == -1);

    // Setelah login berhasil, tampilkan menu utama
    do {
        print_menu();
        printf("Pilih menu: ");
        scanf("%d", &pilihan2);

        switch (pilihan2) {
            case 1:
                tampilkan_barang();
                break;
            case 2:
                beli_barang();
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan2 != 0);

    return 0;
}
