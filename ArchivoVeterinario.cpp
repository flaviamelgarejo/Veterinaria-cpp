#include <cstdio>
#include <cstring>
#include "ArchivoVeterinario.h"

ArchivoVeterinario::ArchivoVeterinario() {
    strcpy(nombreArchivo, "Veterinarios.dat");
}

bool ArchivoVeterinario::guardarRegistro(Veterinario reg) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == NULL) {
        return false;
    }
    fwrite(&reg, sizeof(Veterinario), 1, p);
    fclose(p);
    return true;
}

int ArchivoVeterinario::contarRegistros() {
    int bytes;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Veterinario);
}

Veterinario ArchivoVeterinario::leerRegistro(int pos) {
    Veterinario reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return reg;
    }
    fseek(p, pos * sizeof(Veterinario), SEEK_SET);
    fread(&reg, sizeof(Veterinario), 1, p);
    fclose(p);
    return reg;
}

int ArchivoVeterinario::buscarPorMatricula(const char *matricula) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Veterinario aux = leerRegistro(i);
        if (strcmp(aux.getMatricula(), matricula) == 0) {
            return i;
        }
    }
    return -1;
}

bool ArchivoVeterinario::modificarRegistro(Veterinario reg, int pos) {
    FILE *p = fopen(nombreArchivo,"rb+");
    if ( p == NULL) {
        return false;
    }
    fseek (p, pos * sizeof(Veterinario), SEEK_SET);
    fwrite(&reg, sizeof(Veterinario), 1, p);
    fclose(p);
    return true;
}