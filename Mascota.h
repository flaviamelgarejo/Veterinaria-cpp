#pragma once
#include "Fecha.h"

class Mascota {
private:
    char idMascota[11];
    char idClienteDNI[9];
    char nombreMascota[31];
    char especie[16];
    Fecha fechaNacimiento;
    float peso;
    bool estado;

public:
    Mascota();

    void setIdMascota(const char *idMascota);
    void setIdClienteDNI(const char *idClienteDNI);
    void setNombreMascota(const char *nombre);
    void setEspecie(const char *especie);
    void setFechaNacimiento(Fecha fechaNacimiento);
    void setPeso(float peso);
    void setEstado(bool estado);

    const char *getIdMascota();
    const char *getIdClienteDNI();
    const char *getNombreMascota();
    const char *getEspecie();
    Fecha getFechaNacimiento();
    float getPeso();
    bool getEstado();

    void cargar();
    void cargarModificado();
    void mostrar();
};
