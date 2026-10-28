#include<iostream>
#include "Persona.h"
#include <cstring>
using namespace std;

///Constructor
Persona::Persona(){
    setNombre("");
    setApellido("");
    setTelefono("");
    setMail("");
    setEstado(true);
}

///Setters
void Persona::setNombre(const char *_nombre){
    strcpy(nombre, _nombre);
}

void Persona::setApellido(const char *_apellido){
    strcpy(apellido, _apellido);
}

void Persona::setTelefono(const char *_telefono){
    strcpy(telefono, _telefono);
}

void Persona::setMail(const char *_mail){
    strcpy(mail, _mail);
}

void Persona::setEstado(bool _estado){
    estado = _estado;
}

///Getters
const char *Persona::getNombre(){
    return nombre;
}

const char *Persona::getApellido(){
    return apellido;
}

const char *Persona::getTelefono(){
    return telefono;
}

const char *Persona::getMail(){
    return mail;
}

bool Persona::getEstado(){
    return estado;
}

///Funciones
void Persona::cargar(){
    char _nombre[31], _apellido[31], _telefono[21], _mail[51];

    cout << "Inserte su nombre:";
    cin.getline(_nombre, 31);
    setNombre(_nombre);

    cout << "Inserte su apellido:";
    cin.getline(_apellido, 31);
    setApellido(_apellido);

    cout << "Inserte su telefono:";
    cin.getline(_telefono, 21);
    setTelefono(_telefono);

    direccion.cargar();

    cout << "Ingrese su fecha de nacimiento" << endl;
    fechaNacimiento.cargar();

    cin.ignore();
    cout << "Inserte su mail:";
    cin.getline(_mail, 51);
    setMail(_mail);
}

void Persona::cargarModificadoP(){
    char _nombre[31], _apellido[31], _telefono[21], _mail[51];

    cout << "Inserte su nombre:";
    cin.getline(_nombre, 31);
    setNombre(_nombre);

    cout << "Inserte su apellido:";
    cin.getline(_apellido, 31);
    setApellido(_apellido);

    cout << "Inserte su telefono:";
    cin.getline(_telefono, 21);
    setTelefono(_telefono);

    direccion.cargar();

    cout << "Ingrese su fecha de nacimiento" << endl;
    fechaNacimiento.cargar();

    cin.ignore();
    cout << "Inserte su mail:";
    cin.getline(_mail, 51);
    setMail(_mail);
}

void Persona::mostrar(){
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    direccion.mostrar();
    fechaNacimiento.mostrar();
    cout << "Mail: " << mail << endl;
}
