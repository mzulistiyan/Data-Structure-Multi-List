#include "list_child.h"
#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

int selectMenu(){
    cout<< "===== MENU =====" << endl;
    cout<< "1. Menu Event" << endl;
    cout<< "2. Menu Peserta" << endl;
    cout<< "3. Menampilkan Event Tersedia" << endl;
    cout<< "4. Menampilkan Data Peserta setiap Event" << endl;
    cout<< "5. Menampilkan Semua Event Dan Data Peserta" << endl;
    cout<< "6. Mencari Event Yang Masih Tersedia" << endl;
    cout<< "7. Mencari Nama Peserta Di Sebuah Event" << endl;
    cout<< "0. Exit" << endl;
    cout<< "pilihan menu : ";

    int input = 0;
    cin>>input;

    return input;
}

address_relasi alokasi(address_child C) {
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;

    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;

}

void insertLast(List_relasi &L, address_relasi P){


    address_relasi Q = first(L);

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }

        next(Q) = P;
    }
}


void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"===================== LIST PESERTA EVENT ======================"<<endl;
        cout<<"No Peserta                  :"<<info(info(P)).no_peserta<<endl;
        cout<<"Nama Peserta                :"<<info(info(P)).nama_peserta<<endl;
        cout<<"Email Peserta               :"<<info(info(P)).email<<endl;
        cout<<"No Telpon Peserta           :"<<info(info(P)).no_telp<<endl;
        cout<<"No Tempat Duduk Peserta     :"<<info(info(P)).no_tempat_duduk<<endl;
        cout<<"Jenis Peserta               :"<<info(info(P)).jenis_peserta<<endl;
        cout<<endl;
        P = next(P);
    }
}


address_relasi findElm(List_relasi L, address_child C) {
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(P)== C) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}


void deleteFirst(List_relasi &L, address_relasi &P){
    P = first(L);
    if (next(first(L)) == NULL) {
        first(L) = NULL;
    } else {
        first(L) = next(first(L));
    }
    next(P) = NULL;
};

void deleteLast(List_relasi &L, address_relasi &P){
    address_relasi q = first(L);
    while (next(next(q)) != NULL){
        q = next(q);
    }
    P=next(q);
    next(q)= NULL;
};

void deleteAfterRelasi(List_relasi &L,address_relasi Prec, address_relasi &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
};






address_child CariNamaPesertaEvent(List_relasi &L, string nama_peserta)
{
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(info(P)).nama_peserta==nama_peserta){
             cout<<"Hasil : "<<info(info(P)).nama_peserta<<" ";
        }
        P = next(P);

    }

    return NULL;
}
