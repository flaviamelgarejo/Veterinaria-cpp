#include <iostream>
#include <cstring>
#include "ProcedimientoManager.h"

using namespace std;

void ProcedimientoManager::alta() {

    cout << "========== ALTA PROCEDIMIENTO ==========" << endl;

    Procedimiento p;
    p.cargar();

    if (archivo.buscarPorId(p.getIdProcedimiento()) != -1) {
        cout << "Ya existe un procedimiento con ese ID." << endl;
        return;
    }

    archivo.guardarRegistro(p);

    cout << "Procedimiento dado de alta correctamente." << endl;
}

void ProcedimientoManager::baja() {

    cout << "========== BAJA PROCEDIMIENTO ==========" << endl;

    int id;
    cout << "Ingrese ID del procedimiento: ";
    cin >> id;

    int pos = archivo.buscarPorId(id);

    if (pos == -1) {
        cout << "No existe el procedimiento." << endl;
        return;
    }

    Procedimiento p = archivo.leerRegistro(pos);

    p.setEstado(false);

    archivo.modificarRegistro(p, pos);

    cout << "Procedimiento dado de baja." << endl;
}
void ProcedimientoManager::modificar() {

    cout << "========== MODIFICAR PROCEDIMIENTO ==========" << endl;

    int id;
    cout << "Ingrese ID del procedimiento: ";
    cin >> id;

    int pos = archivo.buscarPorId(id);

    if (pos == -1) {
        cout << "No existe el procedimiento." << endl;
        return;
    }

    Procedimiento p = archivo.leerRegistro(pos);

    cout << "Ingrese nuevos datos: " << endl;
    p.cargarModificado();

    archivo.modificarRegistro(p, pos);

    cout << "Procedimiento modificado correctamente." << endl;
}

void ProcedimientoManager::consultaProcedimiento() {

    cout << "========== CONSULTA PROCEDIMIENTO ==========" << endl;

    int id;
    cout << "Ingrese ID: ";
    cin >> id;

    int pos = archivo.buscarPorId(id);

    if (pos == -1) {
        cout << "No existe el procedimiento." << endl;
        return;
    }

    Procedimiento p = archivo.leerRegistro(pos);

    p.mostrar();
}

void ProcedimientoManager::listadoCatalogo() {

    cout << "======================================" << endl;
    cout << "   CATALOGO DE PROCEDIMIENTOS" << endl;
    cout << "======================================" << endl;

    int cant = archivo.contarRegistros();

    if (cant == 0) {
        cout << "No hay procedimientos cargados." << endl;
        return;
    }

    for (int i = 0; i < cant; i++) {

        Procedimiento p = archivo.leerRegistro(i);

        if (p.getEstado()) {
            p.mostrar();
        }
    }
}
