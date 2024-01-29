#ifndef DIRECCION_H
#define DIRECCION_H
#pragma once
#include<cstring>


class Direccion{
public:
    void setCalle(const char *calle);
    void setAltura(int altura);
    void setLocalidad(const char *localidad);
    void setCodigoPostal(int codigoPostal);
    void setProvincia(const char *provincia);

    const char *getCalle();
    int getAltura();
    const char *getLocalidad();
    int getCodigoPostal();
    const char *getProvincia();

    void Cargar();
    void Mostrar();

    Direccion();

private:
    char _calle[30];
    int _altura;
    char _localidad[30];
    int _codigoPostal;
    char _provincia[30];
};


#endif // DIRECCION_H
