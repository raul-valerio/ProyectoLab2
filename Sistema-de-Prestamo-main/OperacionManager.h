#ifndef OPERACIONMANAGER_H_INCLUDED
#define OPERACIONMANAGER_H_INCLUDED

#include "Operacion.h"
#include "OperacionArchivo.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "ClienteManager.h"
#include "Prestamo.h"
#include "PrestamoArchivo.h"
#include "PrestamoManager.h"
#include <cstring>
#include "rlutil.h"


class OperacionManager{
public:
    //Orden igual al .cpp
    void Cargar();
    void Mostrar(Operacion reg);
    void MostrarSinCuotas(Operacion reg);
    void MostrarCantidadRegistros();
    void ListarTodos();
    void ListarTodosSinCuotas();
    int Buscar(int PrestamoID);
    void ListarPorID();
    void AsignarIntereses(Operacion reg);
    void Eliminar();

    void MenuGestionCuotas();
    void ListarTodosGestionCuotas();
    void MostrarGestionCuotas(Operacion reg);

    void ListarPorIDGestionCuotas();
    void MostrarGestionCuotasPorID(Operacion reg);

    void Pagar();
    bool OpcionesParaModificar(int posicion);
    bool PagarUnaCuota(int posicion);
    bool PagarMasDeUnaCuota(int posicion);
    bool PagarInteresesAdeudados(int posicion);

private:
    OperacionArchivo _archivo = OperacionArchivo("Operaciones.dat");
    ClienteManager _managerCliente;
    ClienteArchivo _archivoCliente = ClienteArchivo("Clientes.dat");
    PrestamoManager _managerPrestamo;
    PrestamoArchivo _archivoPrestamo=PrestamoArchivo("Prestamos.dat");
};

#endif // OPERACIONMANAGER_H_INCLUDED
