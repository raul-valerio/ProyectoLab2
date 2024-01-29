#include<iostream>
using namespace std;

#include "ListarClienteMenu.h"

void ListarClienteMenu::iniciar(){
    while(true){
        system("cls");
        int opcion;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "*       LISTAR CLIENTES        *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "* 1 - Clientes activos         *" << endl;
        cout << "* 2 - Cliente por ID           *" << endl;
        cout << "*                              *" << endl;
        cout << "* 0 - Volver al menu Clientes  *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            _manager.ListarTodos();
            system("pause");
            break;
        case 2:
            _manager.ListarPorID();
            system("pause");
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
