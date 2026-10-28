#pragma once
#include "Persona.h"

class Veterinario : public Persona {
private:
    char matricula[11];

public:
    Veterinario();

    void setMatricula(const char *matricula);
    const char *getMatricula();

    void cargar();
    void cargarModificado();
    void mostrar();
};
