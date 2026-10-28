#pragma once

class Procedimiento {
private:
    int idProcedimiento;
    char descripcion[51];
    float importe;
    bool estado;

public:
    Procedimiento();

    void setIdProcedimiento(int idProcedimiento);
    void setDescripcion(const char *descripcion);
    void setImporte(float importe);
    void setEstado(bool estado);

    int getIdProcedimiento();
    const char *getDescripcion();
    float getImporte();
    bool getEstado();

    void cargar();
    void cargarModificado();
    void mostrar();
};
