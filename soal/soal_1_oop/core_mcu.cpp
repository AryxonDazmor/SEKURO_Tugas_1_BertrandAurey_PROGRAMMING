#include "core_mcu.hpp"
#include <iostream>
// [TODO] : Implementasikan class robot di file cpp ini
// [TIPS] : Gunakan CoreMCU::<nama methode> untuk mengimplementasikan methodenya
// DUCE

using namespace std;

//Konstruktor
Core_MCU::Core_MCU(float cpu_speed,int memory,string os,string nama,int volt){
    this->cpu_speed = cpu_speed;
    this->memory = memory;
    this->os = os;
    this->nama = nama;
    this->volt = volt;
    cout << "[Core_MCU] : MCU Utama yang bernama " << nama << " telah dibuat\n";
}

//Destruktor
Core_MCU::~Core_MCU(){
    cout << "[Core_MCU] : MCU Utama yang bernama " << nama << " telah dihapus\n";
}
void Core_MCU::showSpek(){
    cout << "Nama : " << nama <<
            " | CPU Speed : " << cpu_speed << "GHz" <<
            " | Memory : " << memory << "GB" <<
            " | OS : " << os << endl;
}

void Core_MCU::nambah_volt(int AddVolt){
    volt += AddVolt;
    cout << "[Core_MCU] : MCU Utama yang bernama " << nama << " Telah ditambah voltasenya menjadi = " << volt << "\n";
};

void Core_MCU::ganti_os(string newos){
    os = newos;
    cout << "[Core_MCU] : MCU Utama yang bernama " << nama << " Telah diganti OS nya menjadi = " << os << "\n";  
}

string Core_MCU::get_os() {
    return os;
}

