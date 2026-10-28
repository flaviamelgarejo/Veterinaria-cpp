#include<iostream>
#include "Direccion.h"
#include <cstring>
using namespace std;

///Constructor
Direccion::Direccion(){
    setCalle("");
    setNumero(0);
    setLocalidad("");
    setCodPostal("");
}

///Setters
void Direccion::setNumero(int _numero){
    if (_numero >= 0){
        numero = _numero;
    }
}

void Direccion::setCodPostal(const char *_codPostal){
    strcpy(codPostal, _codPostal);
}

void Direccion::setCalle(const char *_calle){
    strcpy(calle, _calle);
}

void Direccion::setLocalidad(const char *_localidad){
    strcpy(localidad, _localidad);
}

///Getters
int Direccion::getNumero(){
    return numero;
}

const char *Direccion::getCodPostal(){
    return codPostal;
}

const char *Direccion::getCalle(){
    return calle;
}

const char *Direccion::getLocalidad(){
    return localidad;
}

///Funciones
void Direccion::cargar(){
    int _numero;
    char _codPostal[11];
    char _calle[31];
    char _localidad[31];

    cout << "Ingrese su calle: ";
    cin.getline(_calle, 31);
    setCalle(_calle);

    cout << "Ingrese el numero: ";
    cin >> _numero;
    cin.ignore();
    setNumero(_numero);

    cout << "Ingrese la localidad: ";
    cin.getline(_localidad,31);
    setLocalidad(_localidad);

    cout << "Ingrese el codigo postal: ";
    cin.getline(_codPostal, 11);
    setCodPostal(_codPostal);
}

void Direccion::mostrar(){
    cout << "Calle: " << calle << endl;
    cout << "Numero: " << numero << endl;
    cout << "Localidad: " << localidad << endl;
    cout << "Codigo Postal: " << codPostal << endl;
}
