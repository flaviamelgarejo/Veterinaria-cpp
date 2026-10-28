#pragma once
#include "Persona.h"

class Cliente : public Persona {
private:
    char DNI[9];

public:
    Cliente();

    void setDNI(const char *DNI);
    const char *getDNI();

    void cargar();
    void cargarModificado();
    void mostrar();
};
