#pragma once
#include "Direccion.h"
#include "Fecha.h"

class Persona {
protected:
    char nombre[31];
    char apellido[31];
    char telefono[21];
    char mail[51];
    Direccion direccion;
    Fecha fechaNacimiento;
    bool estado;

public:
    Persona();

    void setNombre(const char *nombre);
    void setApellido(const char *apellido);
    void setTelefono(const char *telefono);
    void setMail(const char *mail);
    void setEstado(bool estado);

    const char *getNombre();
    const char *getApellido();
    const char *getTelefono();
    const char *getMail();
    bool getEstado();

    void cargar();
    void cargarModificadoP();
    void mostrar();
};
