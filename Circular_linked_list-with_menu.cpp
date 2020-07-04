/*
Created: WahyuS
*/

#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;

struct MAHASISWA{
    char nim[15];
    char nama[20];
    char gender;
    int uts;
    int uas;
    MAHASISWA *LINK; //pointer ke linked
}; MAHASISWA *FIRST, *LAST, *P;

void inisialisasi(){
    FIRST = NULL;
    LAST = NULL;
}

//alokasi memori
void buatSimpul(){
    P=(MAHASISWA *)malloc(sizeof(MAHASISWA));
    if(P==NULL){
        cout<<"Gagal Membuat Simpul";
        exit(0);
    }
}

void awal(){
    if(FIRST==NULL){
        FIRST=P;
        LAST=P;
        P->LINK=FIRST;
    }
}

void INSERT_KANAN(){
    if(LAST!=NULL){
        LAST->LINK=P;
        LAST=P;
        P->LINK=FIRST;
    }else{
        cout<<"Linked List Belum Di Buat"<<endl;;
    }
}

void INSERT_KIRI(){
    if(FIRST!=NULL){
        P->LINK=FIRST;
        FIRST=P;
        LAST->LINK=FIRST;
    }else{
        cout<<"Linked List Belum Di Buat";
    }
}

//menampilkan semua data mahasiswa
void CETAK(){
    P=FIRST;
    while(P!=NULL){
        cout<<"     Data-Data Mahasiswa     "<<endl<<endl;
        cout<<"NIM: "<<P->nim<<endl;
            cout<<"NAMA: "<<P->nama<<endl;
            cout<<"GENDER: ";
            if((P->gender != 'L') && (P->gender != 'P')){
                cout<<"Input Code Salah"<<endl;
            }else{
                cout<<P->gender<<endl;
            }
            cout<<"UTS: "<<P->uts<<endl;
            cout<<"UAS: "<<P->uas<<endl<<endl;
            P=P->LINK;  //ke simpul selanjutya

            if(P==FIRST){
                break;
            }
    }
    cout<<endl;
    cout<<"     Data Sudah Keluar Semua     "<<endl;
}

//tiga data mahasiswa
void mahasiswa1(){
    strcpy(P->nim, "191012345");
    strcpy(P->nama, "BUDI");
    P->gender = 'L';
    P->uts = 93;
    P->uas = 90;
}

void mahasiswa2(){
    strcpy(P->nim, "191012346");
    strcpy(P->nama, "SARAH");
    P->gender = 'P';
    P->uts = 85;
    P->uas = 87;
}

void mahasiswa3(){
    strcpy(P->nim, "191012347");
    strcpy(P->nama, "DEDI");
    P->gender = 'L';
    P->uts = 76;
    P->uas = 79;
}

int main()
{
    int inputMenu, inputUts, inputUas;
    char inputNama[20];
    char inputNim[15];
    char inputGender;
    char ulang;

    inisialisasi();

    //Memasukkan data mahasiswa 1
    buatSimpul(); //panggil fungsi alokasi memori
    awal();
    mahasiswa1();  //data mahasiswa
    INSERT_KANAN(); //memasukan data dengan insert kanan

    //Memasukkan data mahasiswa 2
    buatSimpul(); //panggil fungsi alokasi memori
    awal();
    mahasiswa2(); //data mahasiswa
    INSERT_KANAN(); //memasukan data dengan insert kanan

    //Memasukkan data mahasiswa 3
    buatSimpul(); //panggil fungsi alokasi memori
    awal();
    mahasiswa3(); //data mahasiswa
    INSERT_KANAN(); //memasukan data dengan insert kanan

    //CETAK(); //panggil fungsi untuk mencetak data

    menu:
    system("CLS");
    cout<<endl;
    cout<<"Menu Pilihan : "<<endl<<endl;
    cout<<"1. INSERT KANAN"<<endl;
    cout<<"2. INSERT KIRI"<<endl;
    cout<<"3. CETAK DATA"<<endl;
    cout<<"4. SELESAI"<<endl<<endl;
    cout<<"Masukan Pilihan: ";cin>>inputMenu;
    cout<<endl;

    switch(inputMenu){
        case 1 :    cout<<"Pilihan Insert Kanan"<<endl<<endl;
                buatSimpul();
                cout<<"Masukan Nim: ";cin>>inputNim;
                strcpy(P->nim, inputNim);
                cout<<"Masukan Nama: ";cin>>inputNama;
                strcpy(P->nama, inputNama);
                cout<<"Tipe Gender (L/P): ";cin>>inputGender;
                P->gender = inputGender;
                cout<<"Masukan Nilai Uts: ";cin>>inputUts;
                P->uts = inputUts;
                cout<<"Masukan Nilai Uas: ";cin>>inputUas;
                P->uas = inputUas;
                INSERT_KANAN();
                cout<<endl;
                cout<<"Data Di Masukan Ke List"<<endl;
                goto menu;

    case 2 :    cout<<"Pilihan Insert Kiri"<<endl<<endl;
                buatSimpul();
                cout<<"Masukan Nim: ";cin>>inputNim;
                strcpy(P->nim, inputNim);
                cout<<"Masukan Nama: ";cin>>inputNama;
                strcpy(P->nama, inputNama);
                cout<<"Tipe Gender (L/P): ";cin>>inputGender;
                P->gender = inputGender;
                cout<<"Masukan Nilai Uts: ";cin>>inputUts;
                P->uts = inputUts;
                cout<<"Masukan Nilai Uas: ";cin>>inputUas;
                P->uas = inputUas;
                INSERT_KIRI();
                cout<<endl;
                cout<<"Data Di Masukan Ke List"<<endl;
                goto menu;

    case 3 :    cout<<"         Data Tercetak           "<<endl<<endl;
                CETAK();
                cout<<endl;
                cout<<"Ingin Kembali Ke Menu? (y/t)";cin>>ulang;
                if((ulang == 'Y') || (ulang == 'y')){
                     goto menu;
                }else{
                    exit(0);
                }

    case 4 :    cout<<"     Program Selesai     "<<endl;
                exit(0);
    }

    return 0;
}
