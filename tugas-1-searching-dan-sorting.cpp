#include <iostream>
#include <string>
using namespace std;

// Struktur data buku
struct Buku {
    string judul;
    int tahun;
};

const int MAX_BUKU = 20;
Buku daftarBuku[MAX_BUKU] = {
    {"Pemrograman C++", 2015},
    {"Struktur Data", 2018},
    {"Algoritma Dasar", 2012},
    {"Jaringan Komputer", 2020},
    {"Keamanan Siber", 2019},
    {"Kecerdasan Buatan", 2016},
    {"Basis Data", 2017},
    {"Sistem Operasi", 2014},
    {"Pemrograman Web", 2021},
    {"Manajemen Proyek TI", 2013}
};
int jumlahBuku = 10; 

// Fungsi untuk menyalin array buku
void salinArray(Buku sumber[], Buku tujuan[], int size) {
    for (int i = 0; i < size; i++) {
        tujuan[i] = sumber[i];
    }
}

// Fungsi untuk menambahkan buku
void inputBuku() {
    if (jumlahBuku >= MAX_BUKU) {
        cout << "\nKapasitas penuh! Tidak bisa menambahkan buku lagi.\n";
        system("pause");
        return;
    }
    cin.ignore();
    cout << "\nMasukkan Judul Buku: ";
    getline(cin, daftarBuku[jumlahBuku].judul);
    int tahunInput;
    while (true) {
        cout << "Masukkan Tahun Terbit (1900 - 2025): ";
        cin >> tahunInput;
        if (tahunInput >= 1900 && tahunInput <= 2025) break;
        cout << "Tahun tidak valid. Mohon masukkan antara 1900 hingga 2025.\n";
    }
    daftarBuku[jumlahBuku].tahun = tahunInput;
    jumlahBuku++;
    cout << "\nBuku berhasil ditambahkan!\n";
    system("pause");
}

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku(Buku arr[], int size, string pesan) {
    cout << "\n" << pesan << "\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << arr[i].judul << " (" << arr[i].tahun << ")\n";
    }
}

// Bubble Sort
void bubbleSort(Buku arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].tahun > arr[j + 1].tahun) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort
int partition(Buku arr[], int low, int high) {
    int pivot = arr[high].tahun;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].tahun < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(Buku arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Sequential Search
void sequentialSearch(int tahun) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].tahun == tahun) {
            cout << "\nDitemukan: " << daftarBuku[i].judul << " (" << daftarBuku[i].tahun << ")\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "\nBuku dengan tahun " << tahun << " tidak ditemukan.\n";
    system("pause");
}

// Binary Search
int binarySearch(Buku arr[], int size, int tahun) {
    int kiri = 0, kanan = size - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah].tahun == tahun) {
            return tengah;
        } else if (arr[tengah].tahun < tahun) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

// Menu utama
int main() {
    int pilihan, tahun;
    do {
        system("cls");
        cout << "\n=== Menu ===\n";
        cout << "1. Input Data Buku\n";
        cout << "2. Tampilkan Data Buku\n";
        cout << "3. Urutkan Buku dengan Bubble Sort\n";
        cout << "4. Urutkan Buku dengan Quick Sort\n";
        cout << "5. Cari Buku dengan Sequential Search\n";
        cout << "6. Cari Buku dengan Binary Search\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: 
                inputBuku(); 
                break;
            case 2: 
                system("cls");
                tampilkanBuku(daftarBuku, jumlahBuku, "Daftar Buku (Belum Urut)"); 
                system("pause"); 
                break;
            case 3: {
                system("cls");
                Buku temp[MAX_BUKU];
                salinArray(daftarBuku, temp, jumlahBuku);
                bubbleSort(temp, jumlahBuku);
                tampilkanBuku(daftarBuku, jumlahBuku, "Daftar Buku (Belum Urut)");
                tampilkanBuku(temp, jumlahBuku, "Daftar Buku (Setelah Bubble Sort)");
                system("pause");
                break;
            }
            case 4: {
                system("cls");
                Buku temp[MAX_BUKU];
                salinArray(daftarBuku, temp, jumlahBuku);
                quickSort(temp, 0, jumlahBuku - 1);
                tampilkanBuku(daftarBuku, jumlahBuku, "Daftar Buku (Belum Urut)");
                tampilkanBuku(temp, jumlahBuku, "Daftar Buku (Setelah Quick Sort)");
                system("pause");
                break;
            }
            case 5: 
                cout << "\nMasukkan Tahun Terbit: "; 
                cin >> tahun; 
                sequentialSearch(tahun); 
                break;
            case 6: {
                cout << "\nMasukkan Tahun Terbit: "; cin >> tahun;
                Buku temp[MAX_BUKU];
                salinArray(daftarBuku, temp, jumlahBuku);
                quickSort(temp, 0, jumlahBuku - 1);
                int hasil = binarySearch(temp, jumlahBuku, tahun);
                if (hasil != -1)
                    cout << "\nDitemukan: " << temp[hasil].judul << " (" << temp[hasil].tahun << ")\n";
                else
                    cout << "\nBuku dengan tahun " << tahun << " tidak ditemukan.\n";
                system("pause");
                break;
            }
            case 7: 
                cout << "\nKeluar dari program...\n"; 
                break;
            default: 
                cout << "\nPilihan tidak valid!\n"; 
                system("pause"); 
                break;
        }
    } while (pilihan != 7);
    return 0;
}
