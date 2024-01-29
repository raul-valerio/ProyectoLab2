#include<iostream>
using namespace std;
#include "ClienteMenu.h"
#include "ListarClienteMenu.h"

void ClienteMenu::iniciar(){
    while(true){
        system("cls");
        int opcion;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "*           CLIENTES           *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "* 1 - Nuevo cliente            *" << endl;
        cout << "* 2 - Baja cliente             *" << endl;
        cout << "* 3 - Modificar cliente        *" << endl;
        cout << "* 4 - Listar clientes          *" << endl;
        cout << "*                              *" << endl;
        cout << "* 0 - Volver al menu principal *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            _manager.Cargar();
            break;
        case 2:
            _manager.Eliminar();
            break;
        case 3:
            _manager.Editar();
            break;
        case 4:
            {
            ListarClienteMenu listarClienteMenu;
            listarClienteMenu.iniciar();
            }
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opcion incorrecta. Seleccione nuevamente" << endl;
            system("pause");
            break;
        }
    }
}
