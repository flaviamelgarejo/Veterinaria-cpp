#pragma once
#include "Mascota.h"

class ArchivoMascota {
private:
    char nombreArchivo[30];

public:
    ArchivoMascota();
    bool guardarRegistro(Mascota reg);
    int contarRegistros();
    Mascota leerRegistro(int pos);
    int buscarPorId(const char *id);
    bool modificarRegistro(Mascota reg, int pos);
};
