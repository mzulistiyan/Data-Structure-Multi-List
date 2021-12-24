
#include "list_parent.h"

void createList(List_parent &L)
{
    first(L) = NULL;
}

void newElm_data(Data_event info, address_parent &S)
{
    S = new elmlist_parent;
    info(S) = info;
    next(S) = NULL;
    prev(S) = NULL;
    createList(child(S));

}

void insertFirst(List_parent &L, address_parent P)
{
     address_parent q = first(L);
     if (first(L) == NULL){
        first(L) = P;
        next(first(L)) = first(L);
        prev(first(L)) = first(L);
    } else{
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo(List_parent &L){
    address_parent P = first(L);

    if(P!=NULL){
            cout<<"========================== EVENT ======================"<<endl;
            cout<<"Nama Event                  :"<<info(P).nama_event<<" "<<endl;
            cout<<"Jenis Event                 :"<<info(P).jenis_event<<" "<<endl;
            cout<<"Tanggal Event               :"<<info(P).tgl<<" "<<endl;
            cout<<"Tempat Event                :"<<info(P).tempat<<" "<<endl;
            cout<<"Kuota Max Event             :"<<info(P).kouta_maks<<" "<<endl;
            cout<<"Jumlah Peserta Event        :"<<info(P).jumlah<<" "<<endl;
            printInfo(child(P));
            cout<<endl;
        P = next(P);
        while(P!=first(L)){
            cout<<"========================== EVENT ======================"<<endl;
            cout<<"Nama Event                  :"<<info(P).nama_event<<" "<<endl;
            cout<<"Jenis Event                 :"<<info(P).jenis_event<<" "<<endl;
            cout<<"Tanggal Event               :"<<info(P).tgl<<" "<<endl;
            cout<<"Tempat Event                :"<<info(P).tempat<<" "<<endl;
            cout<<"Kuota Max Event             :"<<info(P).kouta_maks<<" "<<endl;
            cout<<"Jumlah Peserta Event        :"<<info(P).jumlah<<" "<<endl;
            cout<<endl;
            printInfo(child(P));
            P = next(P);
        }

    }else{
        cout<<"Kosong";
    }
}

void deleteFirst(List_parent &L, address_parent &P){
    if(first(L) == NULL){
        cout<< " Data Event Kosong ";
    }else if(next(first(L))== first(L)){
        P = first(L);
        first(L) = NULL;
    }else {
        P = first(L);
        first(L) = next(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) =NULL;
        prev(P) = NULL;
    }
}
void deleteLast(List_parent &L, address_parent &P){
     if(first(L) == NULL){
        cout<< " Data Event Kosong ";
    }else if(next(first(L))== first(L)){
        P = first(L);
        first(L) = NULL;
    }else {
        P = prev(first(L));
        prev(first(L))= prev(P);
        next(prev(P)) = first(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}

address_parent findNamaevent(List_parent &L, string nama_event)
{
    address_parent P = first(L);
    do {
        if(info(P).nama_event == nama_event) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

void hapus_parents(List_parent &L ,string nama, address_parent &P){
    address_parent prec;

    if(first(L)== NULL){
        cout<<" Data Document Kosong "<<endl;

    }else {
        prec = first(L);
        while(info(prec).nama_event != nama && next(prec)!= first(L)){
            prec =next(prec);
        }
        if(first(L)== prec){
            deleteFirst(L , P);
        }else if(info(prec).nama_event == nama && next(prec)== first(L)){
            deleteLast(L,P);
        }else if(info(prec).nama_event != nama && next(prec)== first(L)){
            cout<<" documen yang ingin di hapus tidak ditemukan "<<endl;
        }else{
            prec = prev(prec);
            deleteAfter(L,prec,P);
        }
    }
}


