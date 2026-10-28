#pragma once
#include "Atencion.h"

class ArchivoAtencion {
private:
    char nombreArchivo[30];

public:
    ArchivoAtencion();
    bool guardarRegistro(Atencion reg);
    int contarRegistros();
    Atencion leerRegistro(int pos);
    int buscarPorId(int id);
    bool modificarRegistro(Atencion reg, int pos);
};
