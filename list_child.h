#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;



#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#define prev(p) p->prev
#define last(p) p.last

struct Data_peserta{
    string no_peserta;
    string nama_peserta;
    string email;
    string no_telp;
    int no_tempat_duduk;
    string jenis_peserta;
};


typedef struct elmlist_child *address_child;



struct elmlist_child{
    Data_peserta info;
    address_child next;
    address_child prev;
};

struct List_child {
    address_child first;
    address_child last;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_child &L);
void newElm_data(Data_peserta info, address_child &S);
void printInfo(List_child L);
void newElm_data(Data_peserta info, address_child &S);
address_child findNopeserta(List_child &L, string no_peserta);
void deleteElm(List_child &L, address_child p);
void hapus_childs(List_child &L ,string no);

void insertFirst(List_child &L, address_child P);
void insertAfter(List_child &L, address_child Prec, address_child P);
void insertLast(List_child &L, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(List_child &L, address_child Prec, address_child &P);



#endif // LIST_CHILD_H_INCLUDED
