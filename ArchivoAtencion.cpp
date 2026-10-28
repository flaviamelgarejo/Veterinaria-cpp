#include <cstdio>
#include <cstring>
#include "Atencion.h"
#include "ArchivoAtencion.h"

ArchivoAtencion::ArchivoAtencion() {
    strcpy(nombreArchivo, "Atenciones.dat");
}

bool ArchivoAtencion::guardarRegistro(Atencion reg) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == NULL) {
        return false;
    }
    fwrite(&reg, sizeof(Atencion), 1, p);
    fclose(p);
    return true;
}

int ArchivoAtencion::contarRegistros() {
    int bytes;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Atencion);
}

Atencion ArchivoAtencion::leerRegistro(int pos) {
    Atencion reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return reg;
    }
    fseek(p, pos * sizeof(Atencion), SEEK_SET);
    fread(&reg, sizeof(Atencion), 1, p);
    fclose(p);
    return reg;
}

int ArchivoAtencion::buscarPorId(int id) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Atencion aux = leerRegistro(i);
        if (aux.getIdAtencion() == id) {
            return i;
        }
    }
    return -1;
}

bool ArchivoAtencion::modificarRegistro(Atencion reg, int pos) {
    FILE *p = fopen(nombreArchivo,"rb+");
    if ( p == NULL) {
        return false;
    }
    fseek (p, pos * sizeof(Atencion), SEEK_SET);
    fwrite(&reg, sizeof(Atencion), 1, p);
    fclose(p);
    return true;
}
