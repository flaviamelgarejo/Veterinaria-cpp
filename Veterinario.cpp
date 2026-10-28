#include<iostream>
#include "Veterinario.h"
#include <cstring>
using namespace std;

///Constructor
Veterinario::Veterinario(){
    setMatricula("");
}

///Setter
void Veterinario::setMatricula(const char *_matricula){
    strcpy(matricula, _matricula);
}

///Getter
const char *Veterinario::getMatricula(){
    return matricula;
}

///Funciones
void Veterinario::cargar(){
    char _matricula[11];

    cin.ignore();
    cout << "Ingrese le nro de matricula: ";
    cin.getline(_matricula, 11);
    setMatricula(_matricula);

    Persona::cargar();
}

void Veterinario::mostrar(){
    cout << endl;
    cout << "Matricula nro: " << matricula << endl;
    Persona::mostrar();
}

void Veterinario::cargarModificado(){
    Persona::cargarModificadoP();
}
