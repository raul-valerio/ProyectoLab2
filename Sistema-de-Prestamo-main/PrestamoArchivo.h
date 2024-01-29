#ifndef PRESTAMOARCHIVO_H_INCLUDED
#define PRESTAMOARCHIVO_H_INCLUDED

#include "Prestamo.h"

class PrestamoArchivo {

public:
    PrestamoArchivo (const char* _nombreArchivo);
    bool Guardar(const Prestamo &reg);
    bool Guardar(const Prestamo &reg, int nroRegistro);
    int BuscarPorID(int ID);
    int ContarRegistros();
    Prestamo Leer(int nroRegistro);
    bool Modificar(int ID);

private:
    char nombreArchivo[30];

};




#endif // PRESTAMOARCHIVO_H_INCLUDED
