using namespace std;
#include <iostream>
#include <cstring>
#include "AtencionManager.h"

void AtencionManager::alta() {
    cout << "========== ATENCION NUEVA ==========" << endl << endl;

    Atencion a;

    //DO WHILE para validar atencion
    int idAtencion;
    do {
        cout << "Ingrese el ID de la Atencion: ";
        cin >> idAtencion;

        if (atencion.buscarPorId(idAtencion) != -1) {
            cout << "Ya existe una atencion con ese ID. Intente de nuevo." << endl;
            idAtencion = -1;   // fuerzo repetir
        }
    } while (idAtencion == -1);
    a.setIdAtencion(idAtencion);
    cin.ignore();   // limpio el enter que deja el cin >>

    // DO WHILE para validar mascota
    char idMascota[11];
    int posMascota;
    do {
        cout << "Ingrese el ID de la mascota atendida: ";
        cin.getline(idMascota, 11);

        posMascota = mascota.buscarPorId(idMascota);
        if (posMascota == -1) {
            cout << "Esa mascota no existe. Intente de nuevo." << endl;
        } else if (mascota.leerRegistro(posMascota).getEstado() == false) {
            cout << "Esa mascota esta dada de baja. Intente de nuevo." << endl;
            posMascota = -1;
        }
    } while (posMascota == -1);
    a.setIdMascota(idMascota);

    //DO WHILE para validar vete
    char matricula[11];
    int posVet;
    do {
        cout << "Ingrese la matricula del veterinario: ";
        cin.getline(matricula, 11);

        posVet = veterinario.buscarPorMatricula(matricula);
        if (posVet == -1) {
            cout << "Ese veterinario no existe. Intente de nuevo." << endl;
        } else if (veterinario.leerRegistro(posVet).getEstado() == false) {
            cout << "Ese veterinario esta dado de baja. Intente de nuevo." << endl;
            posVet = -1;
        }
    } while (posVet == -1);
    a.setMatricula(matricula);

    //DO WHILE para validar proced
    int idProcedimiento;
    int posProc;
    do {
        cout << "Ingrese el nro de procedimiento: ";
        cin >> idProcedimiento;

        posProc = procedimiento.buscarPorId(idProcedimiento);
        if (posProc == -1) {
            cout << "Ese procedimiento no existe. Intente de nuevo." << endl;
        } else if (procedimiento.leerRegistro(posProc).getEstado() == false) {
            cout << "Ese procedimiento esta dado de baja. Intente de nuevo." << endl;
            posProc = -1;
        }
    } while (posProc == -1);
    a.setIdProcedimiento(idProcedimiento);
    cin.ignore();

    a.cargarDatos();

    if (atencion.guardarRegistro(a)) {
        cout << "Atencion creada correctamente." << endl;
    } else {
        cout << "No se pudo guardar el registro." << endl;
    }
}


void AtencionManager::baja() {
    cout << "========== BAJA DE ATENCION ==========" << endl << endl;
    int idAtencion;
    cout << "Ingrese el ID de la atención a dar de baja: ";
    cin >> idAtencion;

    int pos = atencion.buscarPorId(idAtencion);
    if (pos == -1) {
        cout << "No existe un registro de atenciones con ese ID." << endl;
        return;
    }

    Atencion encontrado = atencion.leerRegistro(pos);
    encontrado.setEstado(false);
    atencion.modificarRegistro(encontrado,pos);
    cout << "Registro dado de baja correctamente." << endl;
}

void AtencionManager::modificar() {
    cout << "========== MODIFICAR ATENCION ==========" << endl << endl;

    int idAtencion;
    cout << "Ingrese el ID de la atención a modificar: ";
    cin >> idAtencion;
    cin.ignore();

    int pos = atencion.buscarPorId(idAtencion);
    if (pos == -1) {
        cout << "No existe una atención con ese ID." << endl;
        return;
    }

    Atencion encontrado = atencion.leerRegistro(pos);

    // No modificar si está dada de baja
    if (encontrado.getEstado() == false) {
        cout << "No se puede modificar una atencion dada de baja." << endl;
        return;
    }

    cout << endl << "Ingrese los nuevos datos: " << endl;

    //DO WHILE para validar mascota
    char idMascota[11];
    int posMascota;
    do {
        cout << "Ingrese el ID de la mascota atendida: ";
        cin.getline(idMascota, 11);

        posMascota = mascota.buscarPorId(idMascota);
        if (posMascota == -1) {
            cout << "Esa mascota no existe. Intente de nuevo." << endl;
        } else if (mascota.leerRegistro(posMascota).getEstado() == false) {
            cout << "Esa mascota esta dada de baja. Intente de nuevo." << endl;
            posMascota = -1;
        }
    } while (posMascota == -1);
    encontrado.setIdMascota(idMascota);

    //DO WHILE para validar veterinario
    char matricula[11];
    int posVet;
    do {
        cout << "Ingrese la matricula del veterinario: ";
        cin.getline(matricula, 11);

        posVet = veterinario.buscarPorMatricula(matricula);
        if (posVet == -1) {
            cout << "Ese veterinario no existe. Intente de nuevo." << endl;
        } else if (veterinario.leerRegistro(posVet).getEstado() == false) {
            cout << "Ese veterinario esta dado de baja. Intente de nuevo." << endl;
            posVet = -1;
        }
    } while (posVet == -1);
    encontrado.setMatricula(matricula);

    //DO WHILE para validar procedimiento
    int idProcedimiento;
    int posProc;
    do {
        cout << "Ingrese el nro de procedimiento: ";
        cin >> idProcedimiento;

        posProc = procedimiento.buscarPorId(idProcedimiento);
        if (posProc == -1) {
            cout << "Ese procedimiento no existe. Intente de nuevo." << endl;
        } else if (procedimiento.leerRegistro(posProc).getEstado() == false) {
            cout << "Ese procedimiento esta dado de baja. Intente de nuevo." << endl;
            posProc = -1;
        }
    } while (posProc == -1);
    encontrado.setIdProcedimiento(idProcedimiento);
    cin.ignore();

    encontrado.cargarDatos();

    atencion.modificarRegistro(encontrado, pos);
    cout << "El registro de atención se modificó correctamente." << endl;
}

void AtencionManager::listadoAtenciones() {
    cout << "========== LISTADO DE ATENCIONES ==========" << endl << endl;

    int cant = atencion.contarRegistros();
    if (cant == 0) {
        cout << "No hay atenciones cargadas." << endl;
        return;
    }
    for ( int i = 0; i < cant; i++) {
        Atencion aux = atencion.leerRegistro(i);
        if (aux.getEstado() == true) {
            aux.mostrar();

            cout << endl;
            cout << "-----------------------------" << endl;
            cout << endl;
        }
    }

}

void AtencionManager::atencionesPorFecha() {
    cout << "========== ATENCIONES POR RANGO DE FECHAS ==========" << endl << endl;

    int cant = atencion.contarRegistros();
    if (cant == 0) {
        cout << "No hay atenciones cargadas." << endl;
        return;
    }

    Fecha desde, hasta;
    cout << "Fecha DESDE: " << endl;
    desde.cargar();
    cout << "Fecha HASTA: " << endl;
    hasta.cargar();

    //convierto la fecha en un unico numero para comparar
    int desdeNum = desde.getAnio() * 10000 + desde.getMes() * 100 + desde.getDia();
    int hastaNum = hasta.getAnio() * 10000 + hasta.getMes() * 100 + hasta.getDia();

    for (int i = 0; i < cant; i++) {
        Atencion aux = atencion.leerRegistro(i);
        if (aux.getEstado() == true) {
            Fecha fechaAten = aux.getFechaAtencion(); //fecha a comparar
            int fechaAtenNum = fechaAten.getAnio() * 10000 + fechaAten.getMes() * 100 + fechaAten.getDia();

            if (fechaAtenNum >= desdeNum && fechaAtenNum <= hastaNum) {
                aux.mostrar();
            }
        }
    }
}

void AtencionManager::recaudacionMensual() {
    cout << "========== RECAUDACION MENSUAL ==========" << endl << endl;

    int anio;
    cout << "Ingrese el anio: ";
    cin >> anio;

    int cant = atencion.contarRegistros();
    if (cant == 0) {
        cout << "No hay atenciones cargadas." << endl;
        return;
    }

    float totales[12];
    for (int i = 0; i < 12; i++) {
        totales[i] = 0;
    }

    for (int i = 0; i < cant; i++) {
        Atencion atenAux = atencion.leerRegistro(i);
        if (atenAux.getEstado() == true) {
            Fecha fechaAux = atenAux.getFechaAtencion();
            if (fechaAux.getAnio() == anio) {
                int mes = fechaAux.getMes();
                totales[mes - 1]+= atenAux.getImporteCobrado();
            }
        }
    }

    cout << "Recaudacion del anio " << anio << ":" << endl;
    for (int i = 0; i < 12; i++) {
        cout << "Mes " << (i + 1) << ": $" << totales[i] << endl;
    }
}


void AtencionManager::recaudacionPorVeterinario() {
    cout << "========== RECAUDACION POR VETERINARIO ==========" << endl << endl;

    int cantVet = veterinario.contarRegistros();
    int cantAten = atencion.contarRegistros();

    if (cantVet == 0) {
        cout << "No hay veterinarios cargados." << endl;
        return;
    }

    for (int i = 0; i < cantVet; i++) {
        Veterinario vet = veterinario.leerRegistro(i);
        float total = 0;

        if (vet.getEstado() == true) {
            for (int j = 0; j < cantAten; j++) {
                Atencion aten = atencion.leerRegistro(j);
                if (aten.getEstado() == true &&
                    strcmp(aten.getMatricula(), vet.getMatricula()) == 0) {
                    total += aten.getImporteCobrado();
                    }
            }
            cout << "Matricula " << vet.getMatricula() << " - Total: $" << total << endl;
        }
    }
}
void AtencionManager::recaudacionPorProcedimiento() {
    cout << "========== RECAUDACION POR PROCEDIMIENTO ==========" << endl << endl;

    int cantProc = procedimiento.contarRegistros();
    int cantAten = atencion.contarRegistros();

    if (cantProc == 0) {
        cout << "No hay procedimientos cargados." << endl;
        return;
    }

    for (int i = 0; i < cantProc; i++) {
        Procedimiento proc = procedimiento.leerRegistro(i);
        float total = 0;

        if (proc.getEstado() == true) {
            for (int j = 0; j < cantAten; j++) {
                Atencion aten = atencion.leerRegistro(j);
                if (aten.getEstado() == true &&
                    aten.getIdProcedimiento() == proc.getIdProcedimiento()) {
                    total += aten.getImporteCobrado();
                    }
            }
            cout << proc.getDescripcion() << " - Total: $" << total << endl;
        }
    }
}
void AtencionManager::top3Procedimientos() {
    cout << "========== TOP 3 PROCEDIMIENTOS ==========" << endl << endl;

    const int maxCant = 100;   // tope de procedimientos

    int cantProc = procedimiento.contarRegistros();
    int cantAten = atencion.contarRegistros();

    if (cantProc == 0) {
        cout << "No hay procedimientos cargados." << endl;
        return;
    }

    int ids[maxCant];  //guardo el id de cada procedimiento
    int conteos[maxCant]; //cuantas veces se pidio c/u

    for (int i = 0; i < cantProc; i++) {
        Procedimiento proc = procedimiento.leerRegistro(i);
        ids[i] = proc.getIdProcedimiento();
        conteos[i] = 0;

        for (int j = 0; j < cantAten; j++) {
            Atencion aten = atencion.leerRegistro(j);
            if (aten.getEstado() == true &&
                aten.getIdProcedimiento() == proc.getIdProcedimiento()) {
                conteos[i]++;
                }
        }
    }

    cout << "TOP 3 PROCEDIMIENTOS MAS SOLICITADOS:" << endl;

    for (int vuelta = 0; vuelta < 3; vuelta++) {
        int posMax = 0;
        for (int i = 1; i < cantProc; i++) {
            if (conteos[i] > conteos[posMax]) {
                posMax = i;
            }
        }
        cout << (vuelta + 1) << ") Procedimiento ID " << ids[posMax]
             << " - pedido " << conteos[posMax] << " veces" << endl;
        conteos[posMax] = -1; //elimino el mayor para no volver a contarlo
    }
}
