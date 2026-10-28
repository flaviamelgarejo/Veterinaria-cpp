#include <cstdio>
#include <cstring>
#include "ArchivoMascota.h"

ArchivoMascota::ArchivoMascota() {
    strcpy(nombreArchivo, "Mascotas.dat");
}

bool ArchivoMascota::guardarRegistro(Mascota reg) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == NULL) {
        return false;
    }
    fwrite(&reg, sizeof(Mascota), 1, p);
    fclose(p);
    return true;
}

int ArchivoMascota::contarRegistros() {
    int bytes;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Mascota);
}

Mascota ArchivoMascota::leerRegistro(int pos) {
    Mascota reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return reg;
    }
    fseek(p, pos * sizeof(Mascota), SEEK_SET);
    fread(&reg, sizeof(Mascota), 1, p);
    fclose(p);
    return reg;
}

int ArchivoMascota::buscarPorId(const char *id) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Mascota aux = leerRegistro(i);
        if (strcmp(aux.getIdMascota(), id) == 0) {
            return i;
        }
    }
    return -1;
}

bool ArchivoMascota::modificarRegistro(Mascota reg, int pos) {
    FILE *p = fopen(nombreArchivo,"rb+");
    if ( p == NULL) {
        return false;
    }
    fseek (p, pos * sizeof(Mascota), SEEK_SET);
    fwrite(&reg, sizeof(Mascota), 1, p);
    fclose(p);
    return true;
}