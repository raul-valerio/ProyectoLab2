#ifndef CLIENTE_H
#define CLIENTE_H
#pragma once
#include "Direccion.h"

class Cliente{
public:
    void setId(int id);
    void setNombre(const char *nombre);
    void setApellido(const char *apellido);
    void setDireccion(Direccion direccion);
    void setTelefono(const char *telefono);
    void setSueldo(float sueldo);
    void setRiesgo(int riesgo);
    void setEstado(bool estado);
    void setMaximoMontoAPrestar();
    void descontarMaximo(double monto);

    int getId();
    const char *getNombre();
    const char *getApellido();
    Direccion& getDireccion();
    const char *getTelefono();
    float getSueldo();
    int getRiesgo();
    bool getEstado();
    double getMaximoMontoAPrestar();

    Cliente();

private:
    int _id;
    char _nombre[30];
    char _apellido[30];
    Direccion _direccion;
    char _telefono[30];
    float _sueldo;
    int _riesgo;
    bool _estado;
    double _maximoMontoAPrestar;
};

#endif // CLIENTE_H
