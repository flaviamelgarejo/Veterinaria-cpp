#pragma once

class Fecha {
private:
    int dia, mes, anio;

public:
    Fecha();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();

    void cargar();
    void mostrar();
};
