#pragma once
#include "Atencion.h"
#include "ArchivoAtencion.h"
#include "ArchivoMascota.h"
#include "ArchivoVeterinario.h"
#include "ArchivoProcedimiento.h"


class AtencionManager {
private:
    ArchivoAtencion atencion;
    ArchivoMascota mascota;
    ArchivoProcedimiento procedimiento;
    ArchivoVeterinario veterinario;
public:
    void alta();
    void baja();
    void modificar();
    void listadoAtenciones();
    void atencionesPorFecha();
    void recaudacionMensual();
    void recaudacionPorVeterinario();
    void recaudacionPorProcedimiento();
    void top3Procedimientos();
};


