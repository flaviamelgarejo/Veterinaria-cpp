#include <cstdio>
#include <cstring>
#include "ArchivoProcedimiento.h"

ArchivoProcedimiento::ArchivoProcedimiento() {
    strcpy(nombreArchivo, "Procedimientos.dat");
}

bool ArchivoProcedimiento::guardarRegistro(Procedimiento reg) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == NULL) {
        return false;
    }
    fwrite(&reg, sizeof(Procedimiento), 1, p);
    fclose(p);
    return true;
}

int ArchivoProcedimiento::contarRegistros() {
    int bytes;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Procedimiento);
}

Procedimiento ArchivoProcedimiento::leerRegistro(int pos) {
    Procedimiento reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return reg;
    }
    fseek(p, pos * sizeof(Procedimiento), SEEK_SET);
    fread(&reg, sizeof(Procedimiento), 1, p);
    fclose(p);
    return reg;
}

int ArchivoProcedimiento::buscarPorId(int id) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Procedimiento aux = leerRegistro(i);
        if (aux.getIdProcedimiento() == id) {
            return i;
        }
    }
    return -1;
}

bool ArchivoProcedimiento::modificarRegistro(Procedimiento reg, int pos) {
    FILE *p = fopen(nombreArchivo,"rb+");
    if ( p == NULL) {
        return false;
    }
    fseek (p, pos * sizeof(Procedimiento), SEEK_SET);
    fwrite(&reg, sizeof(Procedimiento), 1, p);
    fclose(p);
    return true;
}
