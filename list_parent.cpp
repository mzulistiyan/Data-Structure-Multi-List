#include "list_parent.h"
#include "list_child.h"

void createList(List_parent &Lp) {
    first(Lp) = NULL;
}

void newElm_data(Data_event info, address_parent &Pp) {
    Pp = new elmlist_parent;
    info(Pp) = info;
    next(Pp) = NULL;
    prev(Pp) = NULL;
    createList(child(Pp));
}

void insertEvent(List_parent &Lp, address_parent Pp) {
     if (first(Lp) == NULL) {
        first(Lp) = Pp;
        next(first(Lp)) = first(Lp);
        prev(first(Lp)) = first(Lp);
    } else {
        next(Pp) = first(Lp);
        prev(Pp) = prev(first(Lp));
        next(prev(first(Lp))) = Pp;
        prev(first(Lp)) = Pp;
        first(Lp) = Pp;
    }
}

void deleteFirst(List_parent &Lp, address_parent &Pp) {
    if (next(first(Lp)) == first(Lp)) {
        Pp = first(Lp);
        first(Lp) = NULL;
    } else {
        Pp = first(Lp);
        first(Lp) = next(first(Lp));
        next(prev(Pp)) = first(Lp);
        prev(first(Lp)) = prev(Pp);
        next(Pp) = NULL;
        prev(Pp) = NULL;
    }
}

void deleteLast(List_parent &Lp, address_parent &Pp) {
     if (next(first(Lp)) == first(Lp)) {
        Pp = first(Lp);
        first(Lp) = NULL;
    } else {
        Pp = prev(first(Lp));
        prev(first(Lp)) = prev(Pp);
        next(prev(Pp)) = first(Lp);
        next(Pp) = NULL;
        prev(Pp) = NULL;
    }
}

void deleteAfter(address_parent prec, address_parent &Pp) {
    Pp = next(prec);
    next(prec) = next(Pp);
    prev(next(Pp)) = prec;
    next(Pp) = NULL;
    prev(Pp) = NULL;
}

void DeleteEvent(List_parent &Lp, string nama_event, address_parent &Pp) {
    address_parent prec;

    if (first(Lp) == NULL) {
        cout << "EVENT KOSONG! HAPUS EVENT GAGAL." << endl;
    } else {
        prec = first(Lp);

        while (info(prec).nama_event != nama_event && next(prec) != first(Lp)) {
            prec = next(prec);
        }

        if (first(Lp) == prec) {
            deleteFirst(Lp, Pp);
            cout << endl;
            cout << "EVENT DIHAPUS!" << endl;
        } else if (info(prec).nama_event == nama_event && next(prec) == first(Lp)) {
            deleteLast(Lp, Pp);
            cout << endl;
            cout << "EVENT DIHAPUS!" << endl;
        } else if (info(prec).nama_event != nama_event && next(prec) == first(Lp)) {
            cout << "EVENT TIDAK DITEMUKAN" << endl;
        } else {
            prec = prev(prec);
            deleteAfter(prec, Pp);
            cout << endl;
            cout << "EVENT DIHAPUS!" << endl;
        }
    }
}

address_parent find_namaEvent(List_parent &Lp, string nama_event) {
    address_parent Pp = first(Lp);

    do {
        if (info(Pp).nama_event == nama_event) {
            return Pp;
        }

        Pp = next(Pp);
    } while(Pp != first(Lp));

    return NULL;
}

void connect(List_relasi &Lr, List_parent Lp, List_child Lc, string nama_event, string nama_peserta) {
    address_parent Pp = find_namaEvent(Lp, nama_event);
    address_child Pc = find_namaPeserta(Lc, nama_peserta);

    if (Pp != NULL && Pc != NULL) {
        if (info(Pp).jumlah < info(Pp).quota_maks) {
            info(Pc).no_tempat_duduk = info(Pp).jumlah + 1;

            address_relasi Pr = alokasi(Pc);
            insertLast(child(Pp), Pr);

            info(Pp).jumlah++;
            info(Pc).jenis_peserta = "reguler";
        } else {
            address_relasi Pr = alokasi(Pc);
            insertLast(child(Pp), Pr);

            info(Pc).jenis_peserta = "waiting_list";
        }
    }
}

void hapus_relasi(List_parent &Lp, List_child &Lc, List_relasi &Lr, string nama_event, string nama_peserta) {
    address_parent Pp = find_namaEvent(Lp,nama_event);
    address_child Pc = find_namaPeserta(Lc, nama_peserta);
    address_relasi Pr = findElm(child(Pp), Pc);

    address_relasi Qr, Rr, prec;
    int tempat_duduk;

    if (Pr == NULL) {
        cout << "LIST KOSONG!" << endl;
    } else {
        tempat_duduk = info(Pc).no_tempat_duduk;

        if (Pr == first(child(Pp))) {
            deleteFirst(child(Pp), Qr);
        } else if (next(Pr) == NULL) {
            deleteLast(Lr, Qr);
        } else {
            prec = first(Lr);

            while (next(prec) != Pr) {
                prec = next(prec);
            }

            deleteAfter(prec, Qr);
        }

        info(Pp).jumlah--;
        info(Pc).jenis_peserta = "-";

        Rr = first(child(Pp));

        while(info(info(Rr)).jenis_peserta != "waiting_list" && next(Rr)!=NULL ){
            Rr = next(Rr);
        }

        if(info(info(Rr)).jenis_peserta == "waiting_list"){
            info(info(Rr)).jenis_peserta = "reguler";
            info(Pp).jumlah++;
            info(info(Rr)).no_tempat_duduk = tempat_duduk;
        }
    }
}

void infoParent(address_parent Pp) {
    cout << "========================== EVENT ======================" << endl;
    cout << "Nama Event           : " << info(Pp).nama_event << endl;
    cout << "Jenis Event          : " << info(Pp).jenis_event << endl;
    cout << "Tanggal Pelaksanaan  : " << info(Pp).tanggal_pelaksanaan << endl;
    cout << "Tempat Pelaksanaan   : " << info(Pp).tempat_pelaksanaan << endl;
    cout << "Kuota Maksimal       : " << info(Pp).quota_maks << endl;
    cout << "Jumlah Peserta       : " << info(Pp).jumlah << endl;
    cout << endl;
}

void printParent(List_parent &Lp) {
    address_parent Pp = first(Lp);

    if(Pp != NULL) {
        infoParent(Pp);
        printRelasi(child(Pp));
        Pp = next(Pp);

        while (Pp != first(Lp)) {
            infoParent(Pp);
            printRelasi(child(Pp));
            Pp = next(Pp);
        }
    } else {
        cout<<"TIDAK ADA EVENT!";
    }
}

void printParent_only(List_parent &Lp) {
    address_parent Pp = first(Lp);

    if(Pp != NULL) {
        infoParent(Pp);
        Pp = next(Pp);

        while (Pp != first(Lp)) {
            infoParent(Pp);
            Pp = next(Pp);
        }
    } else {
        cout<<"TIDAK ADA EVENT!";
    }
}

void printParent_available(List_parent &Lp) {
    address_parent Pp = first(Lp);

    if(Pp != NULL) {
        if (info(Pp).jumlah < info(Pp).quota_maks) {
                infoParent(Pp);
        }
        Pp = next(Pp);

        while (Pp != first(Lp)) {
            if (info(Pp).jumlah < info(Pp).quota_maks) {
                infoParent(Pp);
            }

            Pp = next(Pp);
        }
    } else {
        cout<<"TIDAK ADA EVENT!" << endl;
    }
}

string menu_masuk() {
    string masuk;

    cout << "!!! SELAMAT DATANG !!!" << endl;
    cout << "====Pilih Tipe Pengguna====" << endl;
    cout << "1. Panitia" << endl;
    cout << "2. Peserta" << endl << endl;
    cout << "Silakan input pilihan : ";
    cin >> masuk;
    cout << endl << endl;

    return masuk;
}

int menu_panitia() {
    int pilihan;
    cout << "MENU PANITIA" << endl;
    cout << "1. Menambah Event Baru" << endl;
    cout << "2. Menghapus Event" << endl;
    cout << "3. Menampilkan seluruh event dan data peserta" << endl;
    cout << "4. Menampilkan data peserta di event tertentu" << endl;
    cout << "5. Mencari nama peserta di sebuah event" << endl;
    cout << "6. Keluar" << endl << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan; cout << endl;

    return pilihan;
}

int menu_peserta() {
    int pilihan;
    cout << "MENU PESERTA" << endl;
    cout << "1. Menampilkan seluruh event" << endl;
    cout << "2. Menampilkan event dengan kuota yang masih tersedia" << endl;
    cout << "3. Registrasi peserta" << endl;
    cout << "4. Undur diri peserta" << endl;
    cout << "5. Keluar" << endl << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan; cout << endl;

    return pilihan;
}
