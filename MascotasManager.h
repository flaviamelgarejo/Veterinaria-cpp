#pragma once
#include "Mascota.h"
#include "ArchivoMascota.h"
#include "ArchivoCliente.h"

class MascotasManager {
private:
    ArchivoMascota archivo;

public:
    void alta();
    void baja();
    void modificar();
    void listadoMascotas();
    void buscarPorId();
    void buscarPorDNICliente();
};
