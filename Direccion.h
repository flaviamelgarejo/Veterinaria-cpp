#pragma once

class Direccion {
private:
    char calle[31];
    int numero;
    char localidad[31];
    char codPostal[11];

public:
    Direccion();

    void setCalle(const char *calle);
    void setNumero(int numero);
    void setLocalidad(const char *localidad);
    void setCodPostal(const char *codPostal);

    const char *getCalle();
    int getNumero();
    const char *getLocalidad();
    const char *getCodPostal();

    void cargar();
    void mostrar();
};
