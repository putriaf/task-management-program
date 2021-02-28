/*
Submission for Final Project
Data Structure

TASK MANAGEMENT PROGRAM

Group members :
1. Alifa Hafida Anwar (140810190018)
2. Putri Ainur Fitri (140810190052)
3. Theodorik Marcus F.L (1408101900)
*/

#include <iostream>
using namespace std;

struct Element{     //struct elemen
    string nama;
    int tgl;
    int bln;
    int thn;
    Element* next;
};
typedef Element arrayElement[100];  //array untuk membantu proses sorting data pertama kali input
typedef Element* pointer;       //pointer untuk linked list
typedef pointer Stack;          //alias pointer untuk stack

void inputData(arrayElement& new_element, int& n){ //input data untuk pertama kali (sebelum masuk menu) dengan array
    cout<< "Banyak data yang akan dimasukkan : "; cin >>n;  //banyaknya looping data
    for(int i=0;i<n;i++){
        cin.ignore();
        cout<<"Nama Tugas : "; cin>>new_element[i].nama;
        cout<<"Deadline : (DD-MM-YYYY)"<< endl;
        cout<<"Tanggal : "; cin>>new_element[i].tgl;
        cout<<"Bulan : "; cin>>new_element[i].bln;
        cout<<"Tahun : "; cin>>new_element[i].thn;
    }
    cout << "Data berhasil dimasukkan"<<endl;
}
void sorting(arrayElement& data, int& n){   //sorting data input yang pertama, sebelum dimasukkan ke dalam stack
    Element temp;                               //sorting data dari deadline paling jauh ke paling dekat(besar ke kecil)
    for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if(data[i].thn<data[j].thn){ //tahun lebih kecil
                    temp=data[i];      //lakukan swap
                    data[i]=data[j];
                    data[j]=temp;
                }
                else if(data[i].thn==data[j].thn){ //tahun sama
                    if(data[i].bln<data[j].bln){     //bulan lebih kecil
                    temp=data[i];           //lakukan swap
                    data[i]=data[j];
                    data[j]=temp;
                    }
                    else if(data[i].bln==data[j].bln){  //bulan sama
                        if(data[i].tgl<data[j].tgl){    //tanggal lebih kecil
                        temp=data[i];       //lakukan swap
                        data[i]=data[j];
                        data[j]=temp;
                        }
                     //kalau tanggal sama atau lebih besar dibiarkan
                    }
            }
                else{}  //tahun lebih besar, dibiarkan
        }
    }
}
//setelah data awal disorting dari deadline jauh ke deadline paling dekat, dimasukkan ke dalam stack
//data dengan deadline paling jauh akan masuk ke dalam stack terlebih dahulu, sehingga deadline paling dekat berada di tumpukan paling atas
void createStack(Stack& Top){
    Top = NULL;
}

void createElement(pointer& pBaru, Element& data){
    pBaru = new Element;
    pBaru->nama = data.nama;
    pBaru->tgl = data.tgl;
    pBaru->bln = data.bln;
    pBaru->thn = data.thn;
    pBaru->next = NULL;
}

void tambahElement(pointer& pBaru){
    pBaru = new Element;
    cout<< "Nama Tugas : "; cin>> pBaru->nama;
    cout<< "Detail Deadline Tugas (DD-MM-YYYY)"<<endl;
    cout<< "Tanggal : "; cin>> pBaru->tgl;
    cout<< "Bulan   : "; cin>> pBaru->bln;
    cout<< "Tahun   : "; cin>> pBaru->thn;
    pBaru->next = NULL;
}

bool isEmpty(Stack Top){    //mengecek apakan stack kosong
    if(Top==NULL){
        return true;
    }
    else{
        return false;
    }
}

void peek(Stack Top){   //mengecek isi stack paling atas(top)
    cout << "Nama Tugas : "<<Top->nama<< endl;
    cout << "Deadline : "<<Top->tgl;
    cout<<" - "<<Top->bln<<" - "<<Top->thn<< endl;
}

void push(Stack& Top, pointer pBaru){   //memasukkan data kedalam stack
    cout<< "Push Stack"<< endl;
    if(isEmpty(Top)){
        Top=pBaru;
    }
    else {
        pBaru->next = Top;
        Top = pBaru;
    }
}
void pushTambahData(Stack& Top, pointer pBaru){   //memasukkan data kedalam stack
    cout<< "Push Stack"<< endl;
    pointer pBantu, before;
    pBantu=Top;
    if(isEmpty(Top)){
        Top=pBaru;
    }
    else if(Top->next==NULL){
                 if(pBaru->thn<Top->thn){ //tahun lebih kecil
                pBaru->next = Top;
                Top = pBaru;
                }
                else if(pBaru->thn==Top->thn){ //tahun sama
                    if(pBaru->bln<Top->bln){     //bulan lebih kecil
                    pBaru->next = Top;
                    Top = pBaru;
                    }
                    else if(pBaru->bln==Top->bln){  //bulan sama
                        if(pBaru->tgl<Top->tgl){    //tanggal lebih kecil
                        pBaru->next = Top;
                        Top = pBaru;
                        }
                        else{
                            Top->next=pBaru;
                        }
                    }
                    else{
                            Top->next=pBaru;
                    }
                }
                else{Top->next=pBaru;}  

    }
    else{
        while(pBantu!=NULL){
                if(pBaru->thn<pBantu->thn){ //tahun lebih kecil
                    if(pBantu==Top){
                    pBaru->next = Top;
                    Top = pBaru;
                    break;
                    }
                    else{
                    pBaru->next = pBantu;
                    before->next = pBaru;
                    break;
                    }
                }
                else if(pBaru->thn==pBantu->thn){ //tahun sama
                    if(pBaru->bln<pBantu->bln){     //bulan lebih kecil
                        if(pBantu==Top){
                        pBaru->next = Top;
                        Top = pBaru; 
                        break;
                        }
                        else{
                        pBaru->next = pBantu;
                        before->next = pBaru;
                        break;
                        }
                    }
                    else if(pBaru->bln==pBantu->bln){  //bulan sama
                        if(pBaru->tgl<=pBantu->tgl){    //tanggal lebih kecil
                            if(pBantu==Top){
                            pBaru->next = Top;
                            Top = pBaru;
                            break; 
                            }
                            else{
                            pBaru->next = pBantu;
                            before->next = pBaru;
                            break;
                            }
                        }
                        else{
                            if(pBantu->next==NULL){
                            pBantu->next=pBaru;
                            pBantu=pBaru->next;
                            }
                            else{
                            before=pBantu;
                            pBantu=pBantu->next;
                            }
                        }
                    }
                    else{
                        if(pBantu->next==NULL){
                        pBantu->next=pBaru;
                        pBantu=pBaru->next;
                        }
                        else{
                        before=pBantu;
                        pBantu=pBantu->next;
                        }
                    }
                }
                else{
                    if(pBantu->next==NULL){
                        pBantu->next=pBaru;
                        pBantu=pBaru->next;
                    }
                    else{
                        before=pBantu;
                        pBantu=pBantu->next;
                    }
                }
            }
    }
}
void pop(Stack& Top, pointer& pHapus){  //menghapus data dalam stack yang paling atas
    cout<< "Pop Stack"<< endl;
    if(isEmpty(Top)){
        cout<< "Stack Underflow"<< endl;
        pHapus = NULL;
    }
    else if(Top->next=NULL){
        pHapus = Top;
        Top = NULL;
    }
    else {
        pHapus = Top;
        Top = Top->next;
        pHapus->next = NULL;
    }
}

void traversal(Stack Top){  //cetak stack
    pointer pBantu = Top;
    if (isEmpty(Top)){
        cout<< "Stack Kosong!"<< endl;
    }
    else {
        cout<< "------ Daftar Tugas -----"<< endl;
        cout<< "Terurut berdasarkan deadline terdekat"<< endl;
        do{
            cout<< "Nama Tugas : "<<pBantu->nama<<endl;
            cout<< "Deadline : "<<pBantu->tgl<<"-";
            cout<< pBantu->bln<<"-";
            cout<< pBantu->thn<<endl;
            pBantu=pBantu->next;
        }while(pBantu != NULL);
    }
}

int main(){
    char jawab;
    pointer p;
    Element e;
    arrayElement a;
    int n, pilih;
    Stack s;
    createStack(s);
    inputData(a, n);
    sorting(a, n);
    for(int i=0;i<n;i++){
        e=a[i];
        createElement(p, e);
        push(s, p);
    }
    
    do{
        cout<< "-----------------------[ Main Menu ]----------------------"<<endl;
        cout<< "---                  1. Tambah Data Tugas              ---"<< endl;
        cout<< "---                  2. Update Data Tugas              ---"<< endl;
        cout<< "---                  3. Cetak Daftar Tugas             ---"<< endl;
        cout<< "---     4. Tampilkan Tugas Dengan Deadline Terdekat    ---"<< endl;
        cout<< "---                     5. Exit Program                ---"<< endl;
        cout<< "----------------------------------------------------------"<< endl;
        cout<< "Masukkan pilihan menu yang Anda inginkan (1-5) : "; cin>> pilih;

        switch(pilih){
            case 1:
            system("pause"); system("cls");
            cout<< "(||) Tambah Data Tugas"<< endl;
            cout<< "Masukkan detail data baru yang ingin Anda masukkan"<< endl;
            tambahElement(p);
            pushTambahData(s, p);
            break;

            case 2 :
            system("pause"); system("cls");
            cout<< "(||) Ubah Data Tugas"<< endl;
            break;

            case 3 :
            system("pause"); system("cls");
            cout<< "(||) Cetak Daftar Tugas"<< endl;
            traversal(s);
            break;

            case 4 :
            system("pause"); system("cls");
            cout<< "(||) Peek"<< endl;
            cout<< "Menampilkan Data Tugas Dengan Deadline Terdekat"<< endl;
            peek(s);
            break;

            case 5 :
            return 0;
            break;

            default :
            cout<< "Pilihan menu yang Anda masukkan salah!"<< endl;
            cout<< "Silakan ulangi..."<< endl;
            break;
        }
        cout<< "Apakah Anda ingin kembali ke menu? (Y/N)"; cin>>jawab;
    }
    while (jawab == 'Y' || jawab == 'y');
    return 0;
}