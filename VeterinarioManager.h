#pragma once
#include "Veterinario.h"
#include "ArchivoVeterinario.h"
#include "ArchivoAtencion.h"

class VeterinarioManager {
private:
    ArchivoVeterinario archivo;
    ArchivoAtencion archivoAtencion;

public:
    void alta();
    void baja();
    void modificar();
    void consultaVeterinario();
    void listadoVeterinarios();
    void consultaDesempenio();
};
