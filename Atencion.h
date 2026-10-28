#pragma once
#include "Fecha.h"

class Atencion {
private:
    int idAtencion;
    Fecha fechaAtencion;
    char idMascota[11];
    char matricula[11];
    int idProcedimiento;
    float importeCobrado;
    char observaciones[101];
    bool estado;

public:
    Atencion();

    void setIdAtencion(int idAtencion);
    void setFechaAtencion(Fecha fechaAtencion);
    void setIdMascota(const char *idMascota);
    void setMatricula(const char *matricula);
    void setIdProcedimiento(int idProcedimiento);
    void setImporteCobrado(float importeCobrado);
    void setObservaciones(const char *observaciones);
    void setEstado(bool estado);

    int getIdAtencion();
    Fecha getFechaAtencion();
    const char *getIdMascota();
    const char *getMatricula();
    int getIdProcedimiento();
    float getImporteCobrado();
    const char *getObservaciones();
    bool getEstado();

    void cargar();
    void cargarDatos();
    void mostrar();
};
