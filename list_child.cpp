#include "list_child.h"

void createList(List_child &Lc) {
    first(Lc) = NULL;
    last(Lc) = NULL;
}

void newElm_data(Data_peserta info, address_child &Pc) {
    Pc = new elmlist_child;
    info(Pc) = info;
    next(Pc) = NULL;
}

void insertPeserta(List_child &Lc, address_child Pc) {
    if (first(Lc) == NULL && last(Lc) == NULL) {
        first(Lc) = Pc;
        last(Lc) = Pc;
    } else {
        next(Pc) = first(Lc);
        first(Lc) = Pc;
    }
}

void deleteFirst(List_child &Lc, address_child &Pc) {
    Pc = first(Lc);

    if (next(first(Lc)) == NULL) {
        first(Lc) = NULL;
    } else {
        first(Lc) = next(first(Lc));
    }

    next(Pc) = NULL;
}

void deleteLast(List_child &Lc, address_child &Pc) {
    address_child Qc = first(Lc);

    while (next(next(Qc)) != NULL) {
        Qc = next(Qc);
    }
    Pc = next(Qc);
    next(Qc) = NULL;
}

void deleteAfter(address_child prec, address_child &Pc) {
    Pc = next(prec);
    next(prec) = next(Pc);
    next(Pc) = NULL;
}

void DeletePeserta(List_child &Lc, string nama_peserta) {
    address_child Pc, Qc, prec;

    Pc = find_namaPeserta(Lc, nama_peserta);

    if (Pc == NULL) {
        cout << "PESERTA TIDAK ADA! HAPUS PESERTA GAGAL." << endl;
    } else {
        if (Pc == first(Lc)) {
            deleteFirst(Lc, Qc);
        } else if (next(Pc) == NULL) {

            deleteLast(Lc, Qc);
        } else {

            prec = first(Lc);

            while (next(prec) != Pc){
                prec = next(prec);
            }

            deleteAfter(prec, Qc);
        }
    }
}

address_child find_namaPeserta(List_child &Lc, string nama_peserta) {
    address_child Pc = first(Lc);

    while (Pc != NULL) {
        if (info(Pc).nama_peserta == nama_peserta) {
            return Pc;
        }

        Pc = next(Pc);
    }

    return NULL;
}

void infoChild(address_child Pc) {
    cout << "===================== PESERTA ======================" << endl;
    cout << "No Peserta               :" << info(Pc).no_peserta << endl;
    cout << "Nama Peserta             :" << info(Pc).nama_peserta << endl;
    cout << "Email Peserta            :" << info(Pc).email << endl;
    cout << "No Telpon Peserta        :" << info(Pc).no_telepon << endl;
    cout << "No Tempat Duduk Peserta  :" << info(Pc).no_tempat_duduk << endl;
    cout << "Jenis Peserta            :" << info(Pc).jenis_peserta << endl;
    }

void printChild(List_child Lc) {
    address_child Pc = first(Lc);

    while (Pc != NULL) {
        infoChild(Pc);
        Pc = next(Pc);
    }

    if (Pc == NULL) {
        cout << "TIDAK ADA PESERTA!" << endl;
    }
}
