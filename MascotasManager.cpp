#include <iostream>
#include <cstring>
#include "MascotasManager.h"
using namespace std;

void MascotasManager::alta() {
    Mascota m;
    m.cargar();

    if (archivo.buscarPorId(m.getIdMascota()) != -1) {
        cout << "Ya existe una mascota con ese ID." << endl;
        return;
    }

    if (archivo.guardarRegistro(m)) {
        cout << "Mascota dada de alta correctamente." << endl;
    } else {
        cout << "No se pudo dar de alta la mascota." << endl;
    }
}

void MascotasManager::baja(){
    char idMascota[11];

    cout << "========== BAJA DE MASCOTA ==========" << endl << endl;
    cout << "Ingrese el ID de la mascota a dar de baja: ";
    cin.ignore();
    cin.getline(idMascota, 11);

    int pos = archivo.buscarPorId(idMascota);

    if(pos == -1){
        cout << "No existe una mascota con ese ID." << endl;
        return;
    }

    Mascota encontrada = archivo.leerRegistro(pos);
    encontrada.setEstado(false);

    if(archivo.modificarRegistro(encontrada, pos)){
        cout << "Mascota dada de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo dar de baja la mascota." << endl;
    }
}

void MascotasManager::modificar(){
    char idMascota[11];

    cout << "========== MODIFICAR MASCOTA ==========" << endl << endl;
    cout << "Ingrese el ID de la mascota a modificar: ";

    cin.ignore();
    cin.getline(idMascota, 11);

    int pos = archivo.buscarPorId(idMascota);
    if(pos == -1){
        cout << "No existe una mascota con ese ID." << endl;
        return;
    }

    Mascota encontrada = archivo.leerRegistro(pos);
    if(encontrada.getEstado() == false){///VALIDACIONES
        cout << "No se puede modificar una mascota dada de baja." << endl;
        return;
    }
    cout << endl << "Ingrese los nuevos datos:" << endl;

    encontrada.cargarModificado();
    if(archivo.modificarRegistro(encontrada, pos)){
        cout << "Mascota modificada correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar la mascota." << endl;
    }
}

void MascotasManager::listadoMascotas(){

    int cantidad = archivo.contarRegistros();

    if(cantidad == 0){
        cout << "No hay mascotas registradas." << endl;
        return;
    }

    for(int i = 0; i < cantidad; i++){

        Mascota aux = archivo.leerRegistro(i);

        if(aux.getEstado() == true){

            aux.mostrar();

            cout << endl;
            cout << "------------------------" << endl;
            cout << endl;
        }
    }
}

void MascotasManager::buscarPorId(){

    char idMascota[11];

    cout << "Ingrese el ID de la mascota: ";
    cin.ignore();
    cin.getline(idMascota, 11);

    int pos = archivo.buscarPorId(idMascota);

    if(pos == -1){
        cout << "No existe una mascota con ese ID." << endl;
        return;
    }

    Mascota encontrada = archivo.leerRegistro(pos);

    if(encontrada.getEstado()){
        encontrada.mostrar();
    }
    else{
        cout << "La mascota existe, pero esta dada de baja." << endl;
    }
}

void MascotasManager::buscarPorDNICliente(){

    char dni[9];
    bool encontrado = false;

    cout << "Ingrese el DNI del cliente: ";

    cin.ignore();
    cin.getline(dni, 9);

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        Mascota aux = archivo.leerRegistro(i);

        if(strcmp(aux.getIdClienteDNI(), dni) == 0){

            if(aux.getEstado()){

                aux.mostrar();

                cout << endl;
                cout << "------------------------" << endl;
                cout << endl;

                encontrado = true;
            }
        }
    }

    if(!encontrado){
        cout << "No se encontraron mascotas para ese DNI." << endl;
    }
}
