#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

int main() {
    Data_event dataE; Data_peserta dataP;
    List_parent Lp; address_parent Pp;
    List_child Lc; address_child Pc;
    List_relasi Lr; address_relasi Pr;
    int no_peserta = 1100;

    createList(Lp);
    createList(Lc);
    string akses = "y";
    while (akses == "y") {
        string masuk;
        while (masuk != "1" && masuk != "2") {
            masuk = menu_masuk();
        }

        int pilihan;
        string nama_peserta, nama_event, print;
        address_child ketemu;

        if (masuk == "1") {
            pilihan = menu_panitia();
            if (pilihan == 3) {
                cout<< "====DATA SELURUH EVENT dan PESERTA===="<<endl;
                printParent(Lp);
            } else if (pilihan == 4) {
                cout << "====DATA PESERTA===="<<endl;
                cout << "Masukan nama event : "<<endl; cin >> nama_event;
                cout << "Data Peserta pada Event "<<nama_event<<" : "<<endl;
                address_parent find_event = find_namaEvent(Lp, nama_event);
                printRelasi(child(find_event));
            } else if (pilihan == 5) {
                cout << "Input nama peserta : "; cin >> nama_peserta;
                ketemu = find_namaPeserta(Lc, nama_peserta);

                if (ketemu != NULL) {
                    cout << "Tampilkan info peserta? (y/t) : "; cin >> print;

                    if (print == "y") {
                        infoChild(ketemu);
                    }
                } else {
                    cout << endl;
                    cout << "PESERTA TIDAK DITEMUKAN!" << endl << endl << endl;
                }

            } else if (pilihan == 1) {
                cout<< "====REGISTRASI EVENT===="<<endl;
                cout << "   Nama Event : "; cin >> dataE.nama_event;
                cout << "   Jenis Event : "; cin >> dataE.jenis_event;
                cout << "   Tanggal Pelaksanaan : "; cin >> dataE.tanggal_pelaksanaan;
                cout << "   Tempat Pelaksanaan : "; cin >> dataE.tempat_pelaksanaan;
                cout << "   Kuota Maksimal : "; cin >> dataE.quota_maks;
                dataE.jumlah = 0;

                newElm_data(dataE, Pp);
                insertEvent(Lp, Pp);

                cout << endl;
                cout << "REGISTRASI EVENT BERHASIL!" << endl << endl << endl;
            } else if (pilihan == 2) {
                cout<< "====DELETE EVENT===="<<endl;
                cout <<"Masukkan nama event : "; cin >> nama_event;
                DeleteEvent(Lp, nama_event, Pp);
            } else if (pilihan == 6) {
                break;
            } else {
                cout <<"SALAH INPUTAN."<< endl << endl;
            }

            cout << "Kembali ke menu utamas? (y/t) : "; cin >> akses;
            cout << endl << endl;
        } else {
            pilihan = menu_peserta();

            if (pilihan == 1) {
                cout<< "====DATA SELURUH EVENT===="<<endl;
                printParent_only(Lp);
            } else if (pilihan == 2) {
                cout<< "====Available EVENT===="<<endl;
                printParent_available(Lp);
            } else if (pilihan == 3) {
                cout<< "====REGISTRASI PESERTA===="<<endl;
                cout << "   Nama Event : "; cin >> nama_event;
                cout << "   Nama : "; cin >> dataP.nama_peserta;
                cout << "   Email : "; cin >> dataP.email;
                cout << "   No. telepon : "; cin >> dataP.no_telepon;
                dataP.no_peserta = no_peserta;

                newElm_data(dataP, Pc);
                insertPeserta(Lc, Pc);
                connect(Lr, Lp, Lc, nama_event, dataP.nama_peserta);

                no_peserta++;

                cout << endl;
                cout << "REGISTRASI BERHASIL!" << endl << endl << endl;
            } else if (pilihan == 4) {
                cout<< "====UNDUR DIRI===="<<endl;
                cout << "   Nama event : "; cin >> nama_event;
                cout << "   Nama peserta : "; cin >> nama_peserta;

                hapus_relasi(Lp, Lc, Lr, nama_event, nama_peserta);
            } else if (pilihan == 5) {
                break;
            } else {
                cout << "MASUKAN SALAH." << endl << endl;
            }

            cout << "Kembali ke menu utama? (y/t) : "; cin >> akses;
            cout << endl << endl;
        }
    }



    return 0;
}
