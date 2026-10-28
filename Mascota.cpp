#include<iostream>
#include "Mascota.h"
#include <cstring>
using namespace std;

///Constructor
Mascota::Mascota(){
    setIdMascota("");
    setIdClienteDNI("");
    setNombreMascota("");
    setEspecie("");
    setPeso(0);
    setEstado(true);
}

///Setter
void Mascota::setIdMascota(const char *_idMascota){
    strcpy(idMascota, _idMascota);
}

void Mascota::setIdClienteDNI(const char *_idClienteDNI){
    strcpy(idClienteDNI, _idClienteDNI);
}

void Mascota::setNombreMascota(const char *_nombreMascota){
    strcpy(nombreMascota, _nombreMascota);
}

void Mascota::setEspecie(const char *_especie){
    strcpy(especie,_especie);
}

void Mascota::setFechaNacimiento(Fecha _fechaNacimiento){
    fechaNacimiento = _fechaNacimiento;
}

void Mascota::setPeso(float _peso){
    peso = _peso;
}

void Mascota::setEstado(bool _estado){
    estado = _estado;
}

///Getter
const char *Mascota::getIdMascota(){
    return idMascota;
}

const char *Mascota::getIdClienteDNI(){
    return idClienteDNI;
}

const char *Mascota::getNombreMascota(){
    return nombreMascota;
}

const char *Mascota::getEspecie(){
    return especie;
}

Fecha Mascota::getFechaNacimiento(){
    return fechaNacimiento;
}

float Mascota::getPeso(){
    return peso;
}

bool Mascota::getEstado(){
    return estado;
}

///Funciones
void Mascota::cargar(){
    char _idMascota[11];
    char _idClienteDNI[9];
    char _nombreMascota[31];
    char _especie[16];
    float _peso;

    cout << "Ingrese el Id de la Mascota: ";
    cin.getline(_idMascota, 11);
    setIdMascota(_idMascota);

    cout << "Ingrese el DNI del cliente: ";
    cin.getline(_idClienteDNI, 9);
    setIdClienteDNI(_idClienteDNI);

    cout << "Ingrese el nombre de su Mascota: ";
    cin.getline(_nombreMascota, 31);
    setNombreMascota(_nombreMascota);

    cout << "Ingrese su especie: ";
    cin.getline(_especie, 16);
    setEspecie(_especie);

    cout << "Ingrese la fecha de nacimiento de la mascota: " << endl;
    fechaNacimiento.cargar();

    cout << "Peso de la mascota (kg): ";
    cin >> _peso;
    cin.ignore();
    setPeso(_peso);
}

void Mascota::cargarModificado(){
    char _idClienteDNI[9];
    char _nombreMascota[31];
    char _especie[16];
    float _peso;

    cout << "Ingrese el DNI del cliente: ";
    cin.getline(_idClienteDNI, 9);
    setIdClienteDNI(_idClienteDNI);

    cout << "Ingrese el nombre de su Mascota: ";
    cin.getline(_nombreMascota, 31);
    setNombreMascota(_nombreMascota);

    cout << "Ingrese su especie: ";
    cin.getline(_especie, 16);
    setEspecie(_especie);

    cout << "Ingrese la fecha de nacimiento de la mascota: " << endl;
    fechaNacimiento.cargar();

    cout << "Peso de la mascota (kg): ";
    cin >> _peso;
    cin.ignore();
    setPeso(_peso);
}

void Mascota::mostrar(){
    cout << endl;
    cout << "Id Mascota: " << idMascota << endl;
    cout << "DNI Cliente: " << idClienteDNI << endl;
    cout << "Nombre Mascota: " << nombreMascota << endl;
    cout << "Especie: " << especie << endl;
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.mostrar();
    cout << "Peso: " << peso << "kg "<< endl;
}
