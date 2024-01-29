#ifndef OPERACIONARCHIVO_H_INCLUDED
#define OPERACIONARCHIVO_H_INCLUDED

#pragma once
#include "Operacion.h"

class OperacionArchivo{
public:
    OperacionArchivo(const char* _nombreArchivo);
    bool Guardar(const Operacion &reg);
    bool Guardar(const Operacion &reg, int nroRegistro);
    int BuscarPorID(int ID);
    int ContarRegistros();
    Operacion Leer(int nroRegistro);
    bool Modificar(int ID);

private:
    char nombreArchivo[30];

};

#endif // OPERACIONARCHIVO_H_INCLUDED
