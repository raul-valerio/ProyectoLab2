#include<iostream>
using namespace std;

#include "OperacionMenu.h"
#include "ListarOperacionMenu.h"

void OperacionMenu::iniciar(){
    while(true){
        system("cls");
        int opcion;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "*         OPERACIONES          *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "* 1 - Nueva Operacion          *" << endl;
        //cout << "* 2 - Gestion de Pagos         *" << endl;
        cout << "* 2 - Anular Operacion         *" << endl;
        cout << "* 3 - Listar Operaciones       *" << endl;
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
            //_manager.MenuGestionCuotas();
            _manager.Eliminar();
            break;
        /*case 3:
            _manager.Eliminar();
            break;*/
        case 3:
            {
                ListarOperacionMenu listarOperacionMenu;
                listarOperacionMenu.iniciar();
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

void OperacionMenu::iniciarGestioPagos(){
   _manager.MenuGestionCuotas();
}
