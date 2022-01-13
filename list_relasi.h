#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
using namespace std;

#include "list_child.h"

#define next(P) P->next
#define info(P) P->info

#define first(L) L.first

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child info;
};

struct List_relasi{
    address_relasi first;
};

void createList(List_relasi &Lr);
address_relasi alokasi(address_child Pc);
void insertFirst(List_relasi &Lr, address_relasi Pr);
void insertLast(List_relasi &Lr, address_relasi Pr);
void deleteFirst(List_relasi &Lr, address_relasi &Pr);
void deleteLast(List_relasi &Lr, address_relasi &Pr);
void deleteAfter(address_relasi prec, address_relasi &Pr);
address_relasi findElm(List_relasi Lr, address_child Pc);
address_child CariNamaPesertaEvent(List_relasi &Lr, string nama_peserta);
void printRelasi(List_relasi Lr);

#endif // LIST_RELASI_H_INCLUDED
