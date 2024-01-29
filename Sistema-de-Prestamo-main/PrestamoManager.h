#ifndef PRESTAMOMANAGER_H_INCLUDED
#define PRESTAMOMANAGER_H_INCLUDED

#include "Prestamo.h"
#include "PrestamoArchivo.h"
#include <cstring>
#include<iomanip>

class PrestamoManager{
public:
    //Orden igual al .cpp
    void Cargar();
    void Mostrar(Prestamo reg);
    void MostrarSinCuotas(Prestamo reg);
    void MostrarCantidadRegistros();
    void ListarTodos();
    void ListarTodosSinCuotas();
    int Buscar(int PrestamoID);
    void ListarPorID();
    void Eliminar();
    void Editar();
    bool OpcionesParaModificar(int IDPrestamo);
    bool ModificarMonto(int posicion);
    bool ModificarTasaInteres(int posicion);
    bool ModificarPlazo(int posicion);
    bool ModificarSistema(int posicion);

private:
    PrestamoArchivo _archivo = PrestamoArchivo("Prestamos.dat");
};


#endif // PRESTAMOMANAGER_H_INCLUDED
