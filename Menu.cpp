#include<iostream>
#include "Menu.h"
#include "ClienteManager.h"
#include "VeterinarioManager.h"
#include "MascotasManager.h"
#include "ProcedimientoManager.h"
#include "AtencionManager.h"
using namespace std;

void menuPrincipal(){

int opcion;

    do{
        system("cls");
        cout << "1. Clientes" << endl;
        cout << "2. Veterinarios" << endl;
        cout << "3. Mascotas" << endl;
        cout << "4. Procedimientos" << endl;
        cout << "5. Atenciones" << endl;
        cout << "6. Informes" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        system("pause");
        system("cls");

    switch(opcion){

    case 1:
        cout << "Clientes" << endl;
        menuClientes();
        break;

    case 2:
        cout << "Veterinarios" << endl;
        menuVeterinarios();
        break;

    case 3:
        cout << "Mascotas" << endl;
        menuMascotas();
        break;

    case 4:
        cout << "Procedimientos" << endl;
        menuProcedimientos();
        break;

    case 5:
        cout << "Atenciones" << endl;
        menuAtenciones ();
        break;

    case 6:
        cout << "Informes" << endl;
        menuInformes();
        break;

    case 0:
        cout << "Saliendo del sistema" << endl;
        break;
    }

}while (opcion != 0);

}

void menuClientes(){

ClienteManager clienteM;

int opcion;

    do{
        system("cls");
        cout << "1. Alta" << endl;
        cout << "2. Listar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Modificar" << endl;
        cout << "5. Baja" << endl;
        cout << "6. Clientes VIP" << endl;
        cout << "0. Volver atras" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:
            cin.ignore();
            clienteM.alta();
            system("pause");
            break;

        case 2:
            clienteM.listadoClientes();
            system ("pause");
            break;

        case 3:
            clienteM.consultaCliente();
            system ("pause");
            break;

        case 4:
            clienteM.modificar();
            system("pause");
            break;

        case 5:
            clienteM.baja();
            system ("pause");
            break;

        case 6:
            clienteM.listadoClientesVip();
            system ("pause");
            break;

        case 0:
            cout << "Volviendo atras..." << endl;
            system ("pause");
            break;
        }

    }while (opcion !=0);
}

void menuVeterinarios(){

VeterinarioManager veterinario;
int opcion;

    do{
        system("cls");
        cout << "1. Alta" << endl;
        cout << "2. Listar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Modificar" << endl;
        cout << "5. Baja" << endl;
        cout<< "6. Consulta por desempenio"<<endl;
        cout << "0. Volver atras" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:
            veterinario.alta();
            system("pause");
            break;

        case 2:
            veterinario.listadoVeterinarios();
            system ("pause");
            break;

        case 3:
            veterinario.consultaVeterinario();
            system ("pause");
            break;

        case 4:
            veterinario.modificar();
            system("pause");
            break;

        case 5:
            veterinario.baja();
            system ("pause");
            break;

        case 6:
            veterinario.consultaDesempenio();
            system ("pause");
            break;

        case 0:
            cout << "Volviendo atras..." << endl;
            system("pause");
            break;
        }

    }while (opcion !=0);
}

void menuMascotas(){

MascotasManager mascotas;
int opcion;

    do{
        system("cls");
        cout << "1. Alta" << endl;
        cout << "2. Listar" << endl;
        cout << "3. Buscar por Id de Mascota" << endl;
        cout << "4. Buscar por DNI de Cliente" << endl;
        cout << "5. Modificar" << endl;
        cout << "6. Baja" << endl;
        cout << "0. Volver atras" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:
            cin.ignore();
            mascotas.alta();
            system("pause");
            break;

        case 2:
            mascotas.listadoMascotas();
            system ("pause");
            break;

        case 3:
            mascotas.buscarPorId();
            system ("pause");
            break;

        case 4:
            mascotas.buscarPorDNICliente();
            system("pause");
            break;

        case 5:
            mascotas.modificar();
            system("pause");
            break;

        case 6:
            mascotas.baja();
            system ("pause");
            break;

        case 0:
            cout << "Volviendo atras..." << endl;
            system ("pause");
            break;
        }

    }while (opcion !=0);
}

void menuProcedimientos(){

ProcedimientoManager procedimientos;
int opcion;

    do{
        system("cls");
        cout << "1. Alta" << endl;
        cout << "2. Listar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Modificar" << endl;
        cout << "5. Baja" << endl;
        cout << "0. Volver atras" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:
            procedimientos.alta();
            system("pause");
            break;

        case 2:
            procedimientos.listadoCatalogo();
            system ("pause");
            break;

        case 3:
            procedimientos.consultaProcedimiento();
            system ("pause");
            break;

        case 4:
            procedimientos.modificar();
            system("pause");
            break;

        case 5:
            procedimientos.baja();
            system ("pause");
            break;

        case 0:
            cout << "Volviendo atras..." << endl;
            system ("pause");
            break;
        }

    }while (opcion !=0);
}

void menuAtenciones(){

AtencionManager atenciones;
int opcion;

    do{
        system("cls");
        cout << "1. Alta" << endl;
        cout << "2. Listar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Modificar" << endl;
        cout << "5. Baja" << endl;
        cout << "6. Atenciones por rango de fechas" << endl;
        cout << "0. Volver atras" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:
            cin.ignore();
            atenciones.alta();
            system("pause");
            break;

        case 2:
            atenciones.listadoAtenciones();
            system("pause");
            break;

        case 3:
            atenciones.atencionesPorFecha();
            system ("pause");
            break;

        case 4:
            atenciones.modificar();
            system("pause");
            break;

        case 5:
            atenciones.baja();
            system ("pause");
            break;

        case 6:
            atenciones.atencionesPorFecha();
            system ("pause");
            break;

        case 0:
            cout << "Volviendo atras..." << endl;
            system ("pause");
            break;
        }

    }while (opcion !=0);
}

void menuInformes(){

    AtencionManager informes;
    int opcion;

    do{
        system("cls");
        cout << "1. Recaudacion mensual" << endl;
        cout << "2. Recaudacion por veterinario" << endl;
        cout << "3. Recaudacion por procedimiento" << endl;
        cout << "4. Top 3 Procedimientos" << endl;
        cout << "0. Volver atras" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch(opcion){
        case 1:
            informes.recaudacionMensual();
            system ("pause");
            break;

        case 2:
            informes.recaudacionPorVeterinario();
            system ("pause");
            break;

        case 3:
            informes.recaudacionPorProcedimiento();
            system ("pause");
            break;

        case 4:
            informes.top3Procedimientos();
            system ("pause");
            break;

        case 0:
            cout << "Volviendo atras..." << endl;
            system ("pause");
            break;
        }

    }while (opcion !=0);


};
