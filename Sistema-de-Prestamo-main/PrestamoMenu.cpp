#include<iostream>
using namespace std;
#include "PrestamoMenu.h"
#include "ListarPrestamoMenu.h"

void PrestamoMenu::iniciar(){
    while(true){
        system("cls");
        int opcion;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "*           PRESTAMOS          *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "* 1 - Nuevo Prestamo           *" << endl;
        cout << "* 2 - Baja Prestamos           *" << endl;
        cout << "* 3 - Modificar Prestamos      *" << endl;
        cout << "* 4 - Listar Prestamos         *" << endl;
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
            ListarPrestamoMenu listarPrestamoMenu;
            listarPrestamoMenu.iniciar();
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
