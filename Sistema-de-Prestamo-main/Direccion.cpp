#include<iostream>
using namespace std;
#include<cstring>
#include "Direccion.h"
#include "CargarCadena.h"

void Direccion::setCalle(const char *calle){
    strcpy(_calle,calle);
}
void Direccion::setAltura(int altura){
    _altura = altura;
}
void Direccion::setLocalidad(const char *localidad){
    strcpy(_localidad,localidad);
}
void Direccion::setCodigoPostal(int codigoPostal){
    _codigoPostal = codigoPostal;
}
void Direccion::setProvincia(const char *provincia){
    strcpy(_provincia,provincia);
}

const char *Direccion::getCalle(){
    return _calle;
}
int Direccion::getAltura(){
    return _altura;
}
const char *Direccion::getLocalidad(){
    return _localidad;
}
int Direccion::getCodigoPostal(){
    return _codigoPostal;
}
const char *Direccion::getProvincia(){
    return _provincia;
}

void Direccion::Cargar(){
    cout << "Calle: ";
    cargarCadena(_calle,29);
    cout << "Altura: ";
    cin >> _altura;
    cout << "Localidad: ";
    cargarCadena(_localidad,29);
    cout << "Codigo Postal: ";
    cin >> _codigoPostal;
    cout << "Provincia: ";
    cargarCadena(_provincia,29);
}
void Direccion::Mostrar(){
    cout << "Calle: " << _calle << endl;
    cout << "Altura: " << _altura << endl;
    cout << "Localidad: " << _localidad << endl;
    cout << "Codigo postal: " << _codigoPostal << endl;
    cout << "Provincia: " << _provincia << endl;
}

Direccion::Direccion(){
    setCalle("");
    setAltura(0);
    setLocalidad("");
    setCodigoPostal(0);
    setProvincia("");
}
