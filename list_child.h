#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) P->info
#define next(P) P->next

#define first(L) L.first
#define last(L) L.last

struct Data_peserta{
    string nama_peserta, email, no_telepon, jenis_peserta;
    int no_peserta, no_tempat_duduk;
};

typedef struct elmlist_child *address_child;

struct elmlist_child{
    Data_peserta info;
    address_child next;
};

struct List_child {
    address_child first;
    address_child last;
};

void createList(List_child &Lc);
void newElm_data(Data_peserta info, address_child &Pc);
void insertPeserta(List_child &Lc, address_child Pc);
void deleteFirst(List_child &Lc, address_child &Pc);
void deleteLast(List_child &Lc, address_child &Pc);
void deleteAfter(address_child prec, address_child &Pc);
void DeletePeserta(List_child &Lc, string no_peserta);
address_child find_namaPeserta(List_child &Lc, string nama_peserta);
void infoChild(address_child Pc);
void printChild(List_child Lc);

#endif // LIST_CHILD_H_INCLUDED
