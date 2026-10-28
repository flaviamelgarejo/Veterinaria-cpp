#pragma once
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "ArchivoMascota.h"

class ClienteManager {
private:
    ArchivoCliente archivo;
    ArchivoMascota archivoMascota;

public:
    void alta();
    void baja();
    void modificar();
    void consultaCliente();
    void listadoClientes();
    void listadoClientesVip();
};
