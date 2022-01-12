#include "list_parent.h"

#include "list_child.h"
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

void connect(List_relasi &LR, List_parent LP, List_child LC, string px, string cx)
{
    address_parent p = findNamaevent(LP,px);
    address_child c = findNopeserta(LC,cx);
    if(p!=NULL && c!=NULL ){

        if(info(p).jumlah<info(p).kouta_maks){
            info(c).no_tempat_duduk = info(p).jumlah + 1;
            address_relasi r = alokasi(c);
            insertLast(child(p),r);
            info(p).jumlah++;
            info(c).jenis_peserta = "reguler";

        }else{
            address_relasi r = alokasi(c);
            insertLast(child(p),r);
            info(c).jenis_peserta = "waiting_list";
        }
    }
}

void hapus_relasi(List_relasi &LR,List_parent &LP,List_child &LC,string px, string cx)
{
    address_relasi Prec,Q,P;
    address_parent X;
    int tempat_duduk;
    X = findNamaevent(LP,px);
    address_child C = findNopeserta(LC, cx);
    P = findElm(child(X), C);
    if (P == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        if(P == first(child(X))){
            tempat_duduk = info(C).no_tempat_duduk;
            //memanggil procedure deleteFirst
            deleteFirst(child(X),Q);
            info(X).jumlah--;
            info(C).jenis_peserta = "-";
            address_relasi cp = first(child(X));
            while(info(info(cp)).jenis_peserta != "waiting_list" && next(cp)!=NULL ){
                cp = next(cp);
            }
            if(info(info(cp)).jenis_peserta == "waiting_list"){
                info(info(cp)).jenis_peserta = "reguler";
                info(X).jumlah++;
                info(info(cp)).no_tempat_duduk = tempat_duduk;
            }
        }else if(next(P) == NULL){
            //memanggil procedure deleteLast
            deleteLast(LR, Q);
            info(X).jumlah--;
            info(C).jenis_peserta = "-";
            address_relasi cp = first(child(X));
            while(info(info(cp)).jenis_peserta != "waiting_list" && next(cp)!=NULL ){
                cp = next(cp);
            }
            if(info(info(cp)).jenis_peserta == "waiting_list"){
                info(info(cp)).jenis_peserta = "reguler";
                info(X).jumlah++;
                info(info(cp)).no_tempat_duduk = tempat_duduk;
            }
        }else{
            Prec = first(LR);
            while (next(Prec) != P){
                Prec = next(Prec);
            }
            //memanggil procedure deleteAfter
            deleteAfterRelasi(Prec, Q);
            info(X).jumlah--;
            info(C).jenis_peserta = "-";
            address_relasi cp = first(child(X));

            while(info(info(cp)).jenis_peserta != "waiting_list" && next(cp)!=NULL ){
                cp = next(cp);
            }

            if(info(info(cp)).jenis_peserta == "waiting_list"){
                info(info(cp)).jenis_peserta = "reguler";
                info(X).jumlah++;
                info(info(cp)).no_tempat_duduk = tempat_duduk;
            }
        }
    }
}



