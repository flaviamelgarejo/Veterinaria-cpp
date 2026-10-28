#include<iostream>
#include "Cliente.h"
#include <cstring>
using namespace std;

///Constructor
Cliente::Cliente(){
    setDNI("");
}

///Setter
void Cliente::setDNI(const char *_dni){
    strcpy(DNI, _dni);
}

///Getter
const char *Cliente::getDNI(){
    return DNI;
}

///Funciones
void Cliente::cargar(){
    char _dni[9];

    cout << "Ingrese su DNI: ";
    cin.getline(_dni, 9);
    setDNI(_dni);

    Persona::cargar();
}

void Cliente::mostrar(){
    cout << endl;
    cout << "DNI: " << DNI << endl;
    Persona::mostrar();
}

void Cliente::cargarModificado(){
    Persona::cargarModificadoP();
}
