#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"
#include <string>
#include <iomanip>
class ClienteManager{
public:
    //Orden igual al .cpp
    void Cargar();
    void Mostrar(Cliente reg);
    void MostrarCantidadRegistros();
    void ListarTodos();
    void ListarEnOperacion();
    int Buscar(int ClienteID);
    void ListarPorID();
    void Eliminar();
    void Editar();
    bool OpcionesParaModificar(int IDCliente);
    bool ModificarNombre(int posicion);
    bool ModificarApellido(int posicion);
    bool ModificarTelefono(int posicion);
    bool ModificarProvincia(int posicion);
    bool ModificarLocalidad(int posicion);
    bool ModificarCodigoPostal(int posicion);
    bool ModificarCalle(int posicion);
    bool ModificarAltura(int posicion);
    bool ModificarSueldo(int posicion);
    bool ModificarRiesgo(int posicion);
private:
    ClienteArchivo _archivo = ClienteArchivo("Clientes.dat");
};


