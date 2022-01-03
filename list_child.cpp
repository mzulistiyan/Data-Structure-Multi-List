#include "list_child.h"


void createList(List_child &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

void newElm_data(Data_peserta info, address_child &S)
{
    S = new elmlist_child;
    next(S) = NULL;
    prev(S) = NULL;
    info(S) = info;
}

void insertFirst(List_child &L, address_child p)
{
    if(first(L) == NULL){
        first(L) = p;
    } else {
        next(p) = first(L);
        first(L) = p;
    }
}



void deleteFirst(List_child &L, address_child &P){
    P = first(L);
    if (next(first(L)) == NULL) {
        first(L) = NULL;
    } else {
        first(L) = next(first(L));
    }
    next(P) = NULL;
};

void deleteLast(List_child &L, address_child &P){
    address_child q = first(L);
    while (next(next(q)) != NULL){
        q = next(q);
    }
    P=next(q);
    next(q)= NULL;
};

void deleteAfter(List_child &L,address_child Prec, address_child &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
};


address_child findNopeserta(List_child &L, string no_peserta)
{
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).no_peserta==no_peserta) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void hapus_childs(List_child &L ,string no)
{
    address_child Prec,Q;
    address_child P = findNopeserta(L,no);
    if (P == NULL){
        cout<<"Data NIP tidak ada";
    }else{
        if (P == first(L)){
            //memanggil procedure deleteFirst
            deleteFirst(L,Q);
        }else if(next(P)== NULL){
            //memanggil procedure deleteLast
            deleteLast(L, Q);
        }else{
            Prec = first(L);
            while (next(Prec) != P){
                Prec = next(Prec);
            }
            //memanggil procedure deleteAfter
            deleteAfter(L, Prec, Q);
        }
    }
}


void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"===================== PESERTA ======================"<<endl;
        cout<<"No Peserta                  :"<<info(P).no_peserta<<endl;
        cout<<"Nama Peserta                :"<<info(P).nama_peserta<<endl;
        cout<<"Email Peserta               :"<<info(P).email<<endl;
        cout<<"No Telpon Peserta           :"<<info(P).no_telp<<endl;
        cout<<"No Tempat Duduk Peserta     :"<<info(P).no_tempat_duduk<<endl;
        cout<<"Jenis Peserta               :"<<info(P).jenis_peserta<<endl;
        P = next(P);
    }
}

int selectMenuParents(){
    cout<< "===== MENU =====" << endl;
    cout<< "1. Registrasi Peserta "<< endl;
    cout<< "2. Delete Akun Peserta" << endl;
    cout<< "3. Pilih Event" << endl;
    cout<< "4. Batalkan Event" << endl;
    cout<< "5. Update Jumlah Data Peserta setiap Event" << endl;
    cout<< "0. Exit" << endl;
    cout<< "pilihan menu : ";

    int input = 0;
    cin>>input;

    return input;
}
