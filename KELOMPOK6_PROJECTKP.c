#include <stdio.h>
#include <string.h>

int main() {
    char nama[50];
    char nim[20];
    float tugas, kehadiran, uts, uas;
    float total;
    char grade;
    char status[10];

    printf("======= KALKULATOR NILAI MAHASISWA =======\n");

    // Input nama dan NIM
    printf("Masukkan Nama: ");
    fgets(nama, sizeof(nama), stdin);

    printf("Masukkan NIM : ");
    fgets(nim, sizeof(nim), stdin);

    // =============================
    // INPUT NILAI + VALIDASI INPUT
    // =============================

    // Input Tugas
    do {
        printf("\nMasukkan nilai Tugas     (20%%): ");

        if (scanf("%f", &tugas) != 1) {
            printf("Input tidak valid! Masukkan angka 0-100.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (tugas < 0 || tugas > 100)
            printf("Skor tidak valid! Masukkan ulang.\n");

    } while (tugas < 0 || tugas > 100);

    // Input Kehadiran
    do {
        printf("Masukkan nilai Kehadiran (10%%): ");

        if (scanf("%f", &kehadiran) != 1) {
            printf("Input tidak valid! Masukkan angka 0-100.\n");
            while (getchar() != '\n');
            continue;
        }

        if (kehadiran < 0 || kehadiran > 100)
            printf("Skor tidak valid! Masukkan ulang.\n");

    } while (kehadiran < 0 || kehadiran > 100);

    // Input UTS
    do {
        printf("Masukkan nilai UTS       (35%%): ");

        if (scanf("%f", &uts) != 1) {
            printf("Input tidak valid! Masukkan angka 0-100.\n");
            while (getchar() != '\n');
            continue;
        }

        if (uts < 0 || uts > 100)
            printf("Skor tidak valid! Masukkan ulang.\n");

    } while (uts < 0 || uts > 100);

    // Input UAS
    do {
        printf("Masukkan nilai UAS       (35%%): ");

        if (scanf("%f", &uas) != 1) {
            printf("Input tidak valid! Masukkan angka 0-100.\n");
            while (getchar() != '\n');
            continue;
        }

        if (uas < 0 || uas > 100)
            printf("Skor tidak valid! Masukkan ulang.\n");

    } while (uas < 0 || uas > 100);

    // ===================================
    // HITUNG NILAI AKHIR (SESUAI FLOWCHART)
    // ===================================

    float nilai_tugas  = tugas * 0.20;
    float nilai_absen  = kehadiran * 0.10;
    float nilai_uts    = uts * 0.35;
    float nilai_uas    = uas * 0.35;

    total = nilai_tugas + nilai_absen + nilai_uts + nilai_uas;

    // STATUS LULUS/GAGAL
    if (total >= 60) {
        sprintf(status, "Lulus");
    } else {
        sprintf(status, "Gagal");
    }

    // ===================================
    // GRADE SESUAI FLOWCHART (A–E)
    // ===================================
    if (total >= 80) {
        grade = 'A';
    } 
    else if (total >= 70) {
        grade = 'B';
    } 
    else if (total >= 55) {
        grade = 'C';
    } 
    else if (total >= 40) {
        grade = 'D';
    } 
    else {
        grade = 'E';  // default, sesuai flowchart
    }

    // ===================================
    // OUTPUT HASIL
    // ===================================

    printf("\n============ HASIL PENILAIAN ============\n");
    printf("Nama       : %s", nama);
    printf("NIM        : %s", nim);

    printf("\n---------- Rincian Perhitungan ----------\n");
    printf("Tugas  (20%%) : %.2f\n", nilai_tugas);
    printf("Absensi(10%%) : %.2f\n", nilai_absen);
    printf("UTS    (35%%) : %.2f\n", nilai_uts);
    printf("UAS    (34%%) : %.2f\n", nilai_uas);

    printf("-------------------------------------------\n");
    printf("Nilai Akhir  : %.2f\n", total);
    printf("Status       : %s\n", status);
    printf("Grade        : %c\n", grade);

    return 0;
}