#include<iostream>
#include "Fecha.h"
using namespace std;

///Constructor
Fecha::Fecha(){
    setAnio(1900);
    setMes(1);
    setDia(1);
}

///Setters
void Fecha::setAnio(int _anio){
    if(_anio >= 1900){
        anio = _anio;
    }
}

void Fecha::setMes(int _mes){
    if(_mes > 0 && _mes <=12){
        mes = _mes;
    }
}

void Fecha::setDia(int _dia){
    if(_dia >= 1 && _dia <= 31){
        dia = _dia;
    }
}

///Getters
int Fecha::getAnio(){
    return anio;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getDia(){
    return dia;
}

///Funciones
void Fecha::cargar(){

    int diaC, mesC, anioC;
    bool diaValido;
    bool mesValido;
    bool anioValido;

    do {

        diaValido = false;
        mesValido = false;
        anioValido = false;

        cout << "Ingrese el anio: ";
        cin >> anioC;
        cout << "Ingrese el mes:";
        cin >> mesC;
        cout << "Ingrese el dia:";
        cin >> diaC;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Debe ingresar numeros." << endl;
            continue;
        }

        if (anioC >= 1900){
            anioValido = true;
        }

        if (mesC >= 1 && mesC <= 12){
            mesValido = true;
        }

        if (mesC == 2){
            if (diaC >= 1 && diaC <= 28){
                diaValido = true;
            }
        }
        else if (mesC == 4 || mesC == 6 || mesC == 9 || mesC == 11){
            if (diaC >= 1 && diaC <=30){
                diaValido = true;
            }
        }
        else if (mesC >= 1 && mesC <= 12){
            if (diaC >= 1 && diaC <= 31){
                diaValido = true;
            }
        }

        if (anioValido == false){
            cout << "El año ingresado es invalido" << endl;
        }

        if (mesValido == false){
            cout << "El mes ingresado es invalido" << endl;
        }

        if (diaValido == false){
            cout << "El dia ingresado es invalido" << endl;
        }

    }while (!anioValido || !mesValido || !diaValido);

    setDia(diaC);
    setMes(mesC);
    setAnio(anioC);
}

void Fecha::mostrar(){
    cout << dia << "/" << mes << "/" << anio << endl;
}
