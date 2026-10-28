#include <cstdio>
#include <cstring>
#include "ArchivoCliente.h"

//constructor
ArchivoCliente::ArchivoCliente() {
    strcpy(nombreArchivo, "Clientes.dat");
}

//metodos
bool ArchivoCliente::guardarRegistro(Cliente reg) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == NULL) {
        return false;
    }
    fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return true;
}

int ArchivoCliente::contarRegistros() {
    int bytes;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Cliente);
}

Cliente ArchivoCliente::leerRegistro(int pos) {
    Cliente reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        return reg;
    }
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}

int ArchivoCliente::buscarPorDni(const char *dni) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Cliente aux = leerRegistro(i);
        if (strcmp(aux.getDNI(), dni) == 0) {
            return i;
        }
    }
    return -1;
}

bool ArchivoCliente::modificarRegistro(Cliente reg, int pos) {
    FILE *p = fopen(nombreArchivo,"rb+");
    if ( p == NULL) {
        return false;
    }
    fseek (p, pos * sizeof(Cliente), SEEK_SET);
    fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return true;
}

