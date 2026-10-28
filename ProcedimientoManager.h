#pragma once
#include "Procedimiento.h"
#include "ArchivoProcedimiento.h"
#include "ArchivoAtencion.h"

class ProcedimientoManager {
private:
    ArchivoProcedimiento archivo;

public:
    void alta();
    void baja();
    void modificar();
    void consultaProcedimiento();
    void listadoCatalogo();
};
