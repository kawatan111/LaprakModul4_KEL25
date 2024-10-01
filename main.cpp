#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

string jenis[4] = {"Jajanan", "Minuman", "Bahan Pokok", "Kecantikan"};
string jajanan[5][4] = {
    {"Chitato", "Teh Botol Sosro", "Minyak Goreng", "Sabun Muka"},
    {"Pringles", "Ultramilk", "Sabun Mandi", "Parfum"},
    {"Oreo", "Pocari Sweat", "Sikat Gigi", "Lipstick"},
    {"Lays", "Coca Cola", "Beras", "Deodorant"},
    {"Popcorn", "Oatside", "Bumbu-bumbu", "Pewarna Rambut"}};
int hjajanan[5][4] = {
    {10, 10, 10, 10},
    {10, 10, 10, 10},
    {10, 10, 10, 10},
    {10, 10, 10, 10},
    {10, 10, 10, 10}};
int indexjajanan[5][4] =
{
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34},
    {41, 42, 43, 44},
    {51, 52, 53, 54}
};
int idjajanan,total=0;
vector<int> beli;

void nota() {//Menampilkan Nota
    int d1,d2;
    for (int i = 0; i < beli.size(); i++) {
        d1 = beli[i]/10;
        d2 = beli[i]%10;
        cout << i+1 << ". ";
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++) {
                cout << jajanan[d1-1][d2-1] << " " << hjajanan[d1-1][d2-1]<<endl;
                total += hjajanan[d1-1][d2-1];
                break;
            }break;
        }
    }
    for (int i = 0; i < 25; i++) {cout<<"------";}cout<<endl;
    cout<<"Total belanja kamu adalah = "<<total<<endl;
}

void showProduct() {//Menampilkan Produk
    for (int i = 0; i < 4; i++) {
        cout << setw (32);
        cout << jenis[i] ;
    }cout<<endl;
    for (int i = 0; i < 25; i++) {cout<<"------";}cout<<endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cout
            << setw (25)
            <<jajanan[i][j]<<" "
            <<"("<< indexjajanan[i][j]<<")" << " "
            <<hjajanan[i][j]<<"k";
        }cout<<endl;
    }cout<<endl;
}
int main()
{
    int n1,n2,lagi;bool equal = false, as = true;
    cout << setw (90)<< "Selamat Datang di Toko kami silahkan pilih barang yang anda inginkan" << endl;
    showProduct();
    while (as) {
        equal = false;
        cout<< "Masukan id barang yang anda inginkan(ketik 0 jika tidak jadi)"<< endl;
        cin >> idjajanan;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                if (idjajanan == indexjajanan[i][j]) {      //Mengecek apakah idnya valid
                    equal = true;
                    beli.push_back(idjajanan);              //jika valid akan dimasukan ke nota
                    break;                                  //Jika Valid maka akan keluar dari loop pengecekan
                }else if(idjajanan == 0) {                  //Jika pelanggan tidak jadi beli
                    as = false;                             //maka langsung keluar loop
                    break;
                }
            }
            if (equal) {
                break;                                      //untuk keluar loop
            }
        }
        n1 = idjajanan/10;                                  //untuk mensplit integer
        n2 = idjajanan%10;
        if(as) {
            if (equal) {
                cout << "Selamat anda telah membeli barang : " << jajanan[n1-1][n2-1] << endl; //Menampilkan barang yang di beli
            }else{
                cout<<"Tidak Palid, masukan ulang kode"<<endl; // Menampilkan id barang tidak valid
            }
            if(equal) {
                cout<< "Apakah anda ingin beli lagi??(1 iya 0 tidak)"<< endl;
                cin >> lagi;
                if(lagi != 1) {
                    break;
                }
            }
        }

    }
    nota();                                                 //menampilkan nota
    cout<< "Terima Kasih Telah Berbelanja di Toko kami"<< endl;
    return 0;
}
