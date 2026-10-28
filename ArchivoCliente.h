#pragma once
#include "Cliente.h"

class ArchivoCliente {

private:
    char nombreArchivo [30];

public:
    ArchivoCliente();
    bool guardarRegistro(Cliente reg);
    int contarRegistros();
    Cliente leerRegistro(int pos);
    int buscarPorDni(const char * dni);
    bool modificarRegistro(Cliente reg, int pos);
};

