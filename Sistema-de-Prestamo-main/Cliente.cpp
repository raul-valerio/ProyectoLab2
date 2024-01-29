#include<iostream>
using namespace std;
#include "CargarCadena.h"
#include "Cliente.h"

//SETTERS
void Cliente::setId(int id){
    _id = id;
}

void Cliente::setNombre(const char *nombre){
    strcpy(_nombre,nombre);
}

void Cliente::setApellido(const char *apellido){
    strcpy(_apellido,apellido);
}

void Cliente::setDireccion(Direccion direccion){
    _direccion = direccion;
}

void Cliente::setTelefono(const char *telefono){
    strcpy(_telefono,telefono);
}

void Cliente::setSueldo(float sueldo){
    _sueldo = sueldo;
}

void Cliente::setRiesgo(int riesgo){
    _riesgo = riesgo;
}

void Cliente::setMaximoMontoAPrestar(){


    FILE * p = fopen("MontoReferencia.dat", "rb");
    if (p == nullptr){
        return;
    }

    double _montoDeterminadoPorPrestamista;

    fread(&_montoDeterminadoPorPrestamista, sizeof _montoDeterminadoPorPrestamista, 1, p);

    if(_sueldo > _montoDeterminadoPorPrestamista && _riesgo == 1){
        _maximoMontoAPrestar = _montoDeterminadoPorPrestamista * 8;
    }
    else if(_sueldo > _montoDeterminadoPorPrestamista && _riesgo == 2){
        _maximoMontoAPrestar = _montoDeterminadoPorPrestamista * 5;
    }
    else if(_sueldo > _montoDeterminadoPorPrestamista && _riesgo == 3){
        _maximoMontoAPrestar = _montoDeterminadoPorPrestamista * 3;
    }
    else{
        _maximoMontoAPrestar = _montoDeterminadoPorPrestamista * 1;
    }

    fclose(p);
}

void Cliente::descontarMaximo(double monto){
    _maximoMontoAPrestar -= monto;
}

void Cliente::setEstado(bool estado){
    _estado = estado;
}

//GETTERS
int Cliente::getId(){
    return _id;
}

const char *Cliente::getNombre(){
    return _nombre;
}

const char *Cliente::getApellido(){
    return _apellido;
}

Direccion& Cliente::getDireccion(){
    return _direccion;
}

const char *Cliente::getTelefono(){
    return _telefono;
}

float Cliente::getSueldo(){
    return _sueldo;
}

int Cliente::getRiesgo(){
    return _riesgo;
}

bool Cliente::getEstado(){
    return _estado;
}

double Cliente::getMaximoMontoAPrestar(){
    return _maximoMontoAPrestar;
}

//CONSTRUCTOR
Cliente::Cliente(){
    setId(0);
    setNombre("");
    setApellido("");
    setDireccion(_direccion);
    setTelefono("");
    setSueldo(0);
    setRiesgo(1);
    setEstado(1);
}
