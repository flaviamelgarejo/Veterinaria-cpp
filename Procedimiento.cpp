#include<iostream>
#include "Procedimiento.h"
#include <cstring>
using namespace std;

///Constructor
Procedimiento::Procedimiento(){
    setIdProcedimiento(0);
    setDescripcion("");
    setImporte(0);
    setEstado(true);
}

///Setters
void Procedimiento::setIdProcedimiento(int _idProcedimiento){
    idProcedimiento = _idProcedimiento;
}

void Procedimiento::setDescripcion(const char *_descripcion){
    strcpy(descripcion, _descripcion);
}

void Procedimiento::setImporte(float _importe){
    importe = _importe;
}

void Procedimiento::setEstado(bool _estado){
    estado = _estado;
}

///Getters
int Procedimiento::getIdProcedimiento(){
    return idProcedimiento;
}

const char *Procedimiento::getDescripcion(){
    return descripcion;
}

float Procedimiento::getImporte(){
    return importe;
}

bool Procedimiento::getEstado(){
    return estado;
}

///Funciones
void Procedimiento::cargar(){
    int _idProcedimiento;
    char _descripcion[51];
    float _importe;

    cout << "Ingrese el ID del procedimiento: ";
    cin >> _idProcedimiento;
    setIdProcedimiento(_idProcedimiento);

    cout << "Descripcion del procedimiento: ";
    cin.ignore();
    cin.getline(_descripcion,51);
    setDescripcion(_descripcion);

    cout << "Importe cobrado: ";
    cin >> _importe;
    setImporte(_importe);
}

void Procedimiento::mostrar(){
    cout << endl;
    cout << "ID Procedimiento: " << idProcedimiento << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Importe: " << importe << endl;
}

void Procedimiento::cargarModificado() {
    char _descripcion [51];
    float _importe;

    cout << "Descripcion del procedimiento: ";
    cin.ignore();
    cin.getline(_descripcion,51);
    setDescripcion(_descripcion);

    cout << "Importe cobrado: ";
    cin >> _importe;
    setImporte(_importe);

}
