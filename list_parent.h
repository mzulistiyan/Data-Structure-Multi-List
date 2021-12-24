
#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#include "list_relasi.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#define prev(p) p->prev


struct Data_event{
    string nama_event;
    string jenis_event;
    string tgl;
    string tempat;
    int kouta_maks;
    int jumlah;
};



typedef struct elmlist_parent *address_parent;
struct elmlist_parent {
    Data_event info;
    address_parent next;
    address_parent prev;
    List_relasi child;
};

struct List_parent {
    address_parent first;
};


void createList(List_parent &L);
void newElm_data(Data_event info, address_parent &S);
void printInfo(List_parent &L);

void hapus_parents(List_parent &L ,string nama, address_parent &P);
void insertFirst(List_parent &L, address_parent P);

void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
void delete_Event(List_parent &L ,string nama_event, address_parent &P);
address_parent findNamaevent(List_parent &L, string nama_event);

int selectMenuParents();

#endif // LIST_PARENT_H_INCLUDED
