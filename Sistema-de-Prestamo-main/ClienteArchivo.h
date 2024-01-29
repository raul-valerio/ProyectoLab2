#pragma once
#include "Cliente.h"

class ClienteArchivo{
public:
    ClienteArchivo(const char* _nombreArchivo);
    bool Guardar(const Cliente &reg);
    bool Guardar(const Cliente &reg, int nroRegistro);
    int BuscarPorID(int ID);
    int ContarRegistros();
    Cliente Leer(int nroRegistro);
    bool Modificar(int ID);

private:
    char nombreArchivo[30];

};
