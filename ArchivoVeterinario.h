#pragma once
#include "Veterinario.h"

class ArchivoVeterinario {
private:
    char nombreArchivo[30];

public:
    ArchivoVeterinario();
    bool guardarRegistro(Veterinario reg);
    int contarRegistros();
    Veterinario leerRegistro(int pos);
    int buscarPorMatricula(const char *matricula);
    bool modificarRegistro(Veterinario reg, int pos);
};
