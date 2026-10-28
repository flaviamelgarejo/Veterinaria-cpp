#include<iostream>
#include "Atencion.h"
#include <cstring>
using namespace std;

///Constructor
Atencion::Atencion(){
    setIdAtencion(0);
    setIdMascota("");
    setMatricula("");
    setIdProcedimiento(0);
    setImporteCobrado(0);
    setObservaciones("");
    setEstado(true);
}

///Setters
void Atencion::setIdAtencion(int _idAtencion){
    idAtencion = _idAtencion;
}

void Atencion::setFechaAtencion(Fecha _fechaAtencion){
    fechaAtencion = _fechaAtencion;
}

void Atencion::setIdMascota(const char *_idMascota){
    strcpy(idMascota, _idMascota);
}

void Atencion::setMatricula(const char *_matricula){
    strcpy(matricula, _matricula);
}

void Atencion::setIdProcedimiento(int _idProcedimiento){
    idProcedimiento = _idProcedimiento;
}

void Atencion::setImporteCobrado(float _importeCobrado){
    importeCobrado = _importeCobrado;
}

void Atencion::setObservaciones(const char *_observaciones){
    strcpy(observaciones, _observaciones);
}

void Atencion::setEstado(bool _estado){
    estado = _estado;
}

///Getters
int Atencion::getIdAtencion(){
    return idAtencion;
}

Fecha Atencion::getFechaAtencion(){
    return fechaAtencion;
}

const char *Atencion::getIdMascota(){
    return idMascota;
}

const char *Atencion::getMatricula(){
    return matricula;
}

int Atencion::getIdProcedimiento(){
    return idProcedimiento;
}

float Atencion::getImporteCobrado(){
    return importeCobrado;
}

const char *Atencion::getObservaciones(){
    return observaciones;
}

bool Atencion::getEstado(){
    return estado;
}

///Funciones
void Atencion::cargar(){
    int _idAtencion, _idProcedimiento;
    float _importeCobrado;
    char _idMascota[11];
    char _matricula[11];
    char _observaciones[101];

    cout << "Ingrese el ID de la Atencion: " << endl;
    cin >> _idAtencion;
    setIdAtencion(_idAtencion);

    cout << "Ingrese la fecha de la Atencion: " << endl;
    fechaAtencion.cargar();
    cin.ignore();

    cout << "Ingrese el ID de la mascota atendida: " << endl;
    cin.getline(_idMascota, 11);
    setIdMascota(_idMascota);

    cout << "Ingrese la matricula del veterinario: " << endl;
    cin.getline(_matricula, 11);
    setMatricula(_matricula);

    cout << "Ingrese el nro de procedimiento: " << endl;
    cin >> _idProcedimiento;
    setIdProcedimiento(_idProcedimiento);

    cout << "Ingrese el importe a cobrar: " << endl;
    cin >> _importeCobrado;
    setImporteCobrado(_importeCobrado);

    cout << "Redacte las observaciones (si son necesarias): " << endl;
    cin.ignore();
    cin.getline(_observaciones, 101);
    setObservaciones(_observaciones);
}

void Atencion::mostrar(){
    cout << endl;
    cout << "ID Atencion: " << idAtencion << endl;

    cout << "Fecha de la atencion: ";
    fechaAtencion.mostrar();
    cout << endl;

    cout << "ID Mascota: " << idMascota << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "ID Procedimiento: " << idProcedimiento << endl;
    cout << "Importe: " << importeCobrado << endl;
    cout << "Observaciones: " << observaciones << endl;
}

void Atencion::cargarDatos(){
    float _importeCobrado;
    char _observaciones [101];

    cout << "Ingrese la fecha de la Atencion: " << endl;
    fechaAtencion.cargar();
    cin.ignore();

    cout << "Ingrese el importe a cobrar: " << endl;
    cin >> _importeCobrado;
    setImporteCobrado(_importeCobrado);

    cout << "Redacte las observaciones (si son necesarias): " << endl;
    cin.ignore();
    cin.getline(_observaciones, 101);
    setObservaciones(_observaciones);
}
