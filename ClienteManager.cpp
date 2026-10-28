#include <iostream>
#include "ClienteManager.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "ArchivoMascota.h"
#include <cstring>
using namespace std;

void ClienteManager::alta() {

    cout << "========== ALTA DEL CLIENTE ==========" << endl << endl;

    Cliente c;
    c.cargar();

    //validación DNI
    if (archivo.buscarPorDni(c.getDNI()) != -1) {
        cout << "Ya existe un cliente con ese DNI." << endl;
        return;
    }

    if (archivo.guardarRegistro(c)) {
        cout << "Cliente dado de alta correctamente." << endl;
    } else {
        cout << "No se pudo dar de alta el cliente." << endl;
    }
}

void ClienteManager::baja() {
    cout << "========== BAJA DEL CLIENTE ==========" << endl << endl;
    char dni[9];
    cout << "Ingrese el DNI a dar de baja: ";
    cin.ignore();
    cin.getline(dni, 9);

    int pos = archivo.buscarPorDni(dni);
    if (pos == -1) {
        cout << "No existe un Cliente con ese DNI." << endl;
        return;
    }

    Cliente encontrado = archivo.leerRegistro(pos);
    encontrado.setEstado(false);
    archivo.modificarRegistro(encontrado,pos);
    cout << "Cliente dado de baja correctamente." << endl;
}

void ClienteManager::modificar() {
    cout << "========== MODIFICAR CLIENTE ==========" << endl << endl;
    char dni[9];
    cout << "Ingrese el DNI del Cliente a modificar: ";
    cin.ignore();
    cin.getline(dni, 9);

    int pos = archivo.buscarPorDni(dni);
    if (pos == -1) {
        cout << "No existe un Cliente con ese DNI." << endl;
        return;
    }

    Cliente encontrado = archivo.leerRegistro(pos);
    cout << endl << "Ingrese los nuevos datos: " << endl;
    encontrado.cargarModificado();
    archivo.modificarRegistro(encontrado,pos);
    cout << "Cliente se modificó correctamente." << endl;
}

void ClienteManager::consultaCliente() {
    cout << "========== CONSULTA CLIENTE ==========" << endl << endl;
    char dni[9];
    cout << "Ingrese el DNI del Cliente a consultar: ";
    cin.ignore();
    cin.getline(dni, 9);

    int pos = archivo.buscarPorDni(dni);
    if (pos == -1) {
        cout << "No existe un Cliente con ese DNI." << endl;
        return;
    }
    Cliente encontrado = archivo.leerRegistro(pos);
    encontrado.mostrar();
}

void ClienteManager::listadoClientes() {
    cout << "========== LISTADO DE CLIENTES ==========" << endl << endl;
    int cant = archivo.contarRegistros();
    if (cant == 0) {
        cout << "No hay Clientes cargados." << endl;
        return;
    }
    for ( int i = 0; i < cant; i++) {
        Cliente aux = archivo.leerRegistro(i);
        if (aux.getEstado() == true) {
            aux.mostrar();
        }
    }
}

void ClienteManager::listadoClientesVip() {
    cout << "========== CLIENTES VIP ==========" << endl << endl;

    int cantClientes = archivo.contarRegistros();
    int cantMascotas = archivoMascota.contarRegistros();

    if (cantClientes == 0) {
        cout << "No hay Clientes cargados." << endl;
        return;
    }
    for ( int i = 0; i < cantClientes; i++) {
        Cliente aux = archivo.leerRegistro(i);
        int contador = 0;

        if (aux.getEstado() == true) {
            for (int j = 0; j < cantMascotas; j++) {
                Mascota m = archivoMascota.leerRegistro(j);
                if (strcmp(m.getIdClienteDNI(), aux.getDNI()) == 0) { //compara el dni en m -> con dni en aux
                    contador ++;
                }
            }
            if (contador > 1){
                aux.mostrar();
            }
        }

    }
}
