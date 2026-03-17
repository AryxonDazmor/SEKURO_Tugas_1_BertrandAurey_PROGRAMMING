    #include <iostream>
    #include <vector>
    #include <map>
    using namespace std;
    // Tentukan jumlah paket maksimal yang dapat diambil. Aturan: Robot mulai dari koordinat terkecil, robot hanya bisa gerak ke kanan, robot hanya mengambil ID unik sekali
    // Karena robot selalu bergerak ke kanan dari koordinat terkecil, maka robot akan melalui semua paket
    // Karena tidak ada aturan bagi robvot untuk mengambil paket dari ID terkecil, maka untuk menghitung jumlah paket maksimal hanya memerlukan data banyaknya paket dan banyaknya id unik.
    // Maka, di kode ini tidak perlu mengetahui koordinat paket. Namun, formatnya perlu memasukkan koordinat
    int main() {
        //Input jumlah paket, koordinat, dan ID paket
        int jumlah_paket;
        cout << "Masukkan jumlah paket: ";
        cin >> jumlah_paket;
        if (jumlah_paket > 0 && jumlah_paket <= 10000) {
            std::vector<long long> kr(jumlah_paket); //koordinat
            cout << "Masukkan Koordinat paket: ";
            for (int x  = 0; x < jumlah_paket; x++) {
                cin >> kr[x];
            }
            std::vector<long long> id(jumlah_paket); //id
            cout << "Masukkan ID paket: ";
            for (int x  = 0; x < jumlah_paket; x++) {
                cin >> id[x];
            }
            std::map<long long, bool> koor_c; //Apakah ada paket dgn id ini?
            for (int x = 0; x < jumlah_paket; x++) {
                koor_c[id[x]] = true;
            }
            cout <<"Jumlah paket maksimal yang dapat diambil: " << koor_c.size() << endl;
            return 0;
            //Fin. :)
        } else {
            return 0;
        }
    }