#include "list_relasi.h"
#include "list_parent.h"
#include "list_child.h"

void createList(List_relasi &Lr) {
    first(Lr) = NULL;
}

address_relasi alokasi(address_child Pc) {
    address_relasi Pr = new elmlist_relasi;
    info(Pr) = Pc;
    next(Pr) = NULL;

    return Pr;
}

void insertFirst(List_relasi &Lr, address_relasi Pr) {
    next(Pr) = first(Lr);
    first(Lr) = Pr;
}

void insertLast(List_relasi &Lr, address_relasi Pr) {
    address_relasi Qr = first(Lr);

    if (first(Lr) == NULL) {
        first(Lr) = Pr;
    } else {
        while (next(Qr) != NULL) {
            Qr = next(Qr);
        }

        next(Qr) = Pr;
    }
}

void deleteFirst(List_relasi &Lr, address_relasi &Pr) {
    Pr = first(Lr);
    if (next(first(Lr)) == NULL) {
        first(Lr) = NULL;
    } else {
        first(Lr) = next(first(Lr));
    }

    next(Pr) = NULL;
}

void deleteLast(List_relasi &Lr, address_relasi &Pr) {
    address_relasi Qr = first(Lr);

    while (next(next(Qr)) != NULL){
        Qr = next(Qr);
    }
    Pr = next(Qr);
    next(Qr)= NULL;
}

void deleteAfter(address_relasi prec, address_relasi &Pr) {
    Pr = next(prec);
    next(prec) = next(Pr);
    next(Pr) = NULL;
}

address_relasi findElm(List_relasi Lr, address_child Pc) {
    address_relasi Pr = first(Lr);

    while (Pr != NULL) {
        if (info(Pr) == Pc) {
            return Pr;
        }

        Pr = next(Pr);
    }

    return NULL;
}


void printRelasi(List_relasi Lr) {
    address_relasi Pr = first(Lr);

    while(Pr != NULL && info(info(Pr)).jenis_peserta != "waiting_list") {
        cout << "===================== LIST PESERTA EVENT ======================" << endl;
        cout << "No Peserta                  :" << info(info(Pr)).no_peserta << endl;
        cout << "Nama Peserta                :" << info(info(Pr)).nama_peserta << endl;
        cout << "Email Peserta               :" << info(info(Pr)).email << endl;
        cout << "No Telpon Peserta           :" << info(info(Pr)).no_telepon << endl;
        cout << "No Tempat Duduk Peserta     :" << info(info(Pr)).no_tempat_duduk << endl;
        cout << "Jenis Peserta               :" << info(info(Pr)).jenis_peserta << endl;
        cout << endl;
        Pr = next(Pr);
    }
}
