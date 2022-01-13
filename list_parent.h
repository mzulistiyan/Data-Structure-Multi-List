#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#include "list_relasi.h"

#define info(P) P->info
#define next(P) P->next
#define prev(p) p->prev

#define child(P) P->child
#define relasi(P) P->relasi

#define first(L) L.first

struct Data_event{
    string nama_event, jenis_event, tanggal_pelaksanaan, tempat_pelaksanaan;
    int quota_maks, jumlah;
};

typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    Data_event info;
    address_parent next;
    address_parent prev;
    List_relasi child;
    address_relasi relasi;
};

struct List_parent {
    address_parent first;
};

void createList(List_parent &Lp);
void newElm_data(Data_event info, address_parent &Pp);
void insertEvent(List_parent &Lp, address_parent Pp);
void deleteFirst(List_parent &Lp, address_parent &Pp);
void deleteLast(List_parent &Lp, address_parent &Pp);
void deleteAfter(address_parent prec, address_parent &Pp);
void DeleteEvent(List_parent &Lp, string nama_event, address_parent &Pp);
address_parent find_namaEvent(List_parent &Lp, string nama_event);

/*========================*/
void connect(List_relasi &Lr, List_parent Lp, List_child Lc, string nama_event, string nama_peserta);
void hapus_relasi(List_parent &Lp, List_child &Lc, List_relasi &Lr, string nama_event, string nama_peserta);
void infoParent(address_parent Pp);
void printParent(List_parent &Lp);
void printParent_only(List_parent &Lp);
void printParent_available(List_parent &Lp);

string menu_masuk();
int menu_panitia();
int menu_peserta();

#endif // LIST_PARENT_H_INCLUDED
