#pragma once
#include "Procedimiento.h"

class ArchivoProcedimiento {
private:
    char nombreArchivo[30];

public:
    ArchivoProcedimiento();
    bool guardarRegistro(Procedimiento reg);
    int contarRegistros();
    Procedimiento leerRegistro(int pos);
    int buscarPorId(int id);
    bool modificarRegistro(Procedimiento reg, int pos);
};
