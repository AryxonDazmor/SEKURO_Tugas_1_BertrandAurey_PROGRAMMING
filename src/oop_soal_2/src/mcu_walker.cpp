#include "mcu_walker.hpp"
#include <iostream>

mcu_walker::mcu_walker(float cpu_speed, int memory, std::string os, std::string name, int volt, int motor_speed, int rotation) 
    : MCU(cpu_speed, memory, os, name, volt) {
    
    this->motor_speed = motor_speed;
    this->rotation = rotation;
    
    std::cout << "[KONSTRUKTOR WALKER] : Sistem gerak " << this->name << " telah diinisialisasi.\n";
}

mcu_walker::~mcu_walker() {
    std::cout << "[DESTRUKTOR WALKER] : Komponen walker " << this->name << " telah dimatikan.\n";
}

void mcu_walker::showSpek() {
    std::cout << "[SPEK MCU_WALKER] : " << this->name << "\n";
    std::cout << "- CPU      : " << this->cpu_speed << " GHz" << std::endl;
    std::cout << "- RAM      : " << this->memory << " MB" << std::endl;
    std::cout << "- OS       : " << this->os << std::endl;
    std::cout << "- Volt     : " << this->volt << " V" << std::endl;
    std::cout << "- Speed    : " << this->motor_speed << " RPM" << std::endl;
    std::cout << "- Rotation : " << this->rotation << " Deg" << std::endl;
}

void mcu_walker::rotate(int degree) {
    this->rotation = degree;
    std::cout << "[WALKER] : " << this->name << " berputar ke arah " << degree << " derajat.\n";
}

void mcu_walker::increase_speed(int add) {
    this->motor_speed += add;
    std::cout << "[WALKER] : Kecepatan motor " << this->name << " naik menjadi " << this->motor_speed << " RPM.\n";
}

void mcu_walker::ganti_os(std::string new_os) {
    this->os = new_os;
    std::cout << "[WALKER UPDATE] : " << this->name << " migrasi OS ke " << this->os << "\n";
}

void mcu_walker::nambah_volt(int penambahan_voltase) {
    this->volt += penambahan_voltase;
    std::cout << "Voltase " << this->name << " berhasil dinaikkan ke: " << this->volt << "V\n";
}