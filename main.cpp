#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

int main()
{
    List_parent LP;
    address_parent AP;
    Data_event dataP;
    string nama;
    List_relasi LR;
    address_relasi R;
    int pilihanMenuEvent;
    List_child LC;
    address_child AC;
    Data_peserta dataC;

    createList(LC);

    createList(LP);


    dataP.nama_event = "EVENT4";
    dataP.jenis_event = "BOLA";
    dataP.tgl = "06";
    dataP.tempat = "Tangerang";
    dataP.kouta_maks = 10;
    dataP.jumlah = 0;
    newElm_data(dataP, AP);
    insertFirst(LP,AP);

    dataP.nama_event = "EVENT3";
    dataP.jenis_event = "Basket";
    dataP.tgl = "07";
    dataP.tempat = "Bogor";
    dataP.kouta_maks = 2;
    dataP.jumlah = 0;
    newElm_data(dataP, AP);
    insertFirst(LP,AP);



    printInfo(LP);


    cout<<endl;



    dataC.nama_peserta = "budi";
    dataC.no_peserta = "001";
    dataC.no_tempat_duduk = 2;
    newElm_data(dataC, AC);
    insertFirst(LC,AC);

    dataC.nama_peserta = "andi";
    dataC.no_peserta = "002";
    dataC.no_tempat_duduk = 2;
    newElm_data(dataC, AC);
    insertFirst(LC,AC);

    dataC.nama_peserta = "udin";
    dataC.no_peserta = "003";
    dataC.no_tempat_duduk = 0;
    newElm_data(dataC, AC);
    insertFirst(LC,AC);

    dataC.nama_peserta = "edi";
    dataC.no_peserta = "004";
    dataC.no_tempat_duduk = 0;
    newElm_data(dataC, AC);
    insertFirst(LC,AC);

    printInfo(LC);
    cout<<"Setelah Relasi"<<endl;

/*
    AP = findNamaevent(LP,"EVENT4");
    AC = findNopeserta(LC,"001");
    R = alokasi(AC);
    insertFirst(child(AP),R);

    AP = findNamaevent(LP,"EVENT4");
    AC = findNopeserta(LC,"004");
    R = alokasi(AC);
    insertFirst(child(AP),R);

    printInfo(LP);
    deleteLast(child(AP),R);
    printInfo(LP);
*/
    cout<<endl;


    connect(LR, LP, LC, "EVENT3", "001");

    connect(LR, LP, LC, "EVENT3", "002");
    connect(LR, LP, LC, "EVENT3", "003");

    connect(LR, LP, LC, "EVENT4", "004");


    cout<<endl;
    cout<<endl;


    cout<<"setelah diskonek"<<endl;

    hapus_relasi(child(AP),LP,LC,"EVENT3","002");

    printInfo(LP);

    printInfo(LC);
    /*
    string x;
    int pilihan = selectMenu();
    while(pilihan != 0){
        switch(pilihan){
        case 1:
            cout<<endl;
            cout<<"Menu Event"<<endl;
            pilihanMenuEvent = selectMenuParents();
            cout<<"Kembali ke menu utama? (Y/N) :";
            cin>>x;
            break;
        case 2:
            cout<<"Pilihan 2"<<endl;
            break;
        }
        if(x == "Y"){
            cout<<endl;
            pilihan = selectMenu();

        }else{
            pilihan = 0;
        }
    };
*/
    return 0;
}
