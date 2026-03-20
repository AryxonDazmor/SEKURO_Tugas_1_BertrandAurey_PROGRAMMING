#include "mcu_cam_controller.hpp"
#include <iostream>

int mcu_cam_controller::count_detected_obj = 0;

//[TODO]: Implementasikan kelas mcu_cam_controller dibawah ini
//fungsi: konstruktor, destruktor, showSpek(), detect_other_object(), nambah_volt()
mcu_cam_controller::mcu_cam_controller(float cpu_speed, int memory, std::string os, std::string name, int volt, std::string obj_detected) : MCU(cpu_speed, memory, os, name, volt) {
    this->obj_detected = obj_detected;
    count_detected_obj++;

    std::cout << "[KONSTRUKTOR CAM] : Komponen kamera untuk " << this->name << " siap digunakan.\n";
}

//DESTRUKTOR
mcu_cam_controller::~mcu_cam_controller() {
    std::cout << "[DESTRUKTOR] : Objek " << this->name << " telah dihapus dari memori.\n";
}

void mcu_cam_controller::showSpek() {
    std::cout << "[SPEK MCU_CAM] : " << this->name << " | [CPU] : " << this->cpu_speed << " GHz | [RAM] : " << this->memory 
         << " MB | [OS] : " << this->os << " | [Volt] : " << this->volt << "V | [Last Obj] : " << this->obj_detected 
         << " | [Total Detect] : " << count_detected_obj << "\n";
}
void mcu_cam_controller::detect_other_object(std::string obj, bool moving) {
    this->obj_detected = obj;
    count_detected_obj++;

    std::cout << "[CAM SYSTEM] : Terdeteksi " << obj << " (Status: ";
    if (moving) {
        std::cout << "Bergerak/Aktif)\n";
    } else {
        std::cout << "Diam/Statis)\n";
    }
}
void mcu_cam_controller::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
    std::cout << "Voltase " << this->name << " berhasil dinaikkan ke: " << this->volt << "V\n";
}

void mcu_cam_controller::ganti_os(std::string new_os) {
    this->os = new_os;
}