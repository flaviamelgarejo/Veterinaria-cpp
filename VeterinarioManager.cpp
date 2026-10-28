#include <iostream>
#include "VeterinarioManager.h"
#include <cstring>
using namespace std;

void VeterinarioManager::alta() {
    cout << "========== ALTA VETERINARIO ==========" << endl;

    Veterinario v;
    v.cargar();

    // Busca si la matricula ya existe físicamente en el archivo
    int pos = archivo.buscarPorMatricula(v.getMatricula());

    if (pos != -1) {
        Veterinario existente = archivo.leerRegistro(pos);

        // Si existe y está activo, no se permite duplicar matrícula
        if (existente.getEstado() == true) {
            cout << "Ya existe un veterinario activo con esa Matricula." << endl;
            return;
        }

        // Si existe pero estaba dado de baja, se reactiva con los nuevos datos
        v.setEstado(true);
        archivo.modificarRegistro(v, pos);

        cout << "Veterinario reactivado correctamente." << endl;
        return;
    }

    // Si no existe físicamente, se guarda como nuevo
    if (archivo.guardarRegistro(v)) {
        cout << "Veterinario dado de alta correctamente." << endl;
    } else {
        cout << "No se pudo dar de alta el veterinario." << endl;
    }
}

void VeterinarioManager::baja() {
    cout << "========== BAJA DEL VETERINARIO ==========" << endl << endl;

    char matricula[11];

    cout << "Ingrese la Matricula a dar de baja: ";
    cin.ignore();
    cin.getline(matricula, 11);

    int pos = archivo.buscarPorMatricula(matricula);

    if (pos == -1) {
        cout << "No existe un veterinario con esa Matricula." << endl;
        return;
    }

    Veterinario encontrado = archivo.leerRegistro(pos);

    // Si ya estaba dado de baja, no se vuelve a modificar
    if (encontrado.getEstado() == false) {
        cout << "El veterinario ya estaba dado de baja." << endl;
        return;
    }

    // Baja lógica: no se borra del archivo, solo cambia estado a false
    encontrado.setEstado(false);
    archivo.modificarRegistro(encontrado, pos);

    cout << "Veterinario dado de baja correctamente." << endl;
}

void VeterinarioManager::modificar() {
    cout << "========== MODIFICAR VETERINARIO ==========" << endl << endl;

    char matricula[11];

    cout << "Ingrese la Matricula del veterinario a modificar: ";
    cin.ignore();
    cin.getline(matricula, 11);

    int pos = archivo.buscarPorMatricula(matricula);

    if (pos == -1) { /// VALIDACION
        cout << "No existe un veterinario con esa Matricula." << endl;
        return;
    }

    Veterinario encontrado = archivo.leerRegistro(pos);

    // No se permite modificar un veterinario dado de baja
    if (encontrado.getEstado() == false) {
        cout << "No se puede modificar un veterinario dado de baja." << endl;
        return;
    }

    cout << endl << "Ingrese los nuevos datos: " << endl;

    encontrado.cargarModificado();

    archivo.modificarRegistro(encontrado, pos);

    cout << "Veterinario se modifico correctamente." << endl;
}

void VeterinarioManager::consultaVeterinario() {
    cout << "========== CONSULTA VETERINARIO ==========" << endl << endl;

    char matricula[11];

    cout << "Ingrese la matricula del veterinario a consultar: ";
    cin.ignore();
    cin.getline(matricula, 11);

    int pos = archivo.buscarPorMatricula(matricula);

    if (pos == -1) {
        cout << "No existe un veterinario con esa Matricula." << endl;
        return;
    }

    Veterinario encontrado = archivo.leerRegistro(pos);

    // Existe físicamente, pero está inactivo
    if (encontrado.getEstado() == false) {
        cout << "El veterinario existe, pero esta dado de baja." << endl;
        return;
    }

    encontrado.mostrar();
}
void VeterinarioManager::listadoVeterinarios() {
    cout << "========== LISTADO DE VETERINARIOS ==========" << endl << endl;
    int cant = archivo.contarRegistros();
    if (cant == 0) {
        cout << "No hay veterinario cargados." << endl;
        return;
    }
    for ( int i = 0; i < cant; i++) {
        Veterinario aux = archivo.leerRegistro(i);
        if (aux.getEstado() == true) {
            aux.mostrar();
        }
    }
}

void VeterinarioManager::consultaDesempenio() {

    cout << "===== CONSULTA DE DESEMPENIO =====" << endl;

    char matricula[11];

    cout << "Ingrese la matricula: ";
    cin.ignore();
    cin.getline(matricula,11);

    int posVet = archivo.buscarPorMatricula(matricula);

    if(posVet == -1){
        cout << "No existe un veterinario con esa matricula." << endl;
        return;
    }

    Veterinario vet = archivo.leerRegistro(posVet);

    cout << endl;
    vet.mostrar();

    cout << endl;
    cout << "===== HISTORIAL DE ATENCIONES =====" << endl;

    int cant = archivoAtencion.contarRegistros();

    bool encontro = false;

    for(int i=0; i<cant; i++){

        Atencion a = archivoAtencion.leerRegistro(i);

        if(a.getEstado() &&
           strcmp(a.getMatricula(), matricula) == 0){

            a.mostrar();
            cout << endl;

            encontro = true;
        }
    }

    if(!encontro){
        cout << "Este veterinario no posee atenciones registradas." << endl;
    }
}
