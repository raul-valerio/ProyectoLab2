#include<iostream>
using namespace std;

#include "TipoPrestamoMenu.h"
#include "ListarTipoPrestamosMenu.h"

void TipoPrestamoMenu::iniciar(){
    while(true){
        system("cls");
        int opcion;
        cout << "**********************************" << endl;
        cout << "*                                *" << endl;
        cout << "*       TIPOS DE PRESTAMO        *" << endl;
        cout << "*                                *" << endl;
        cout << "**********************************" << endl;
        cout << "*                                *" << endl;
        cout << "* 1 - Nuevo tipo de prestamo     *" << endl;
        cout << "* 2 - Modificar tipo de prestamo *" << endl;
        cout << "* 3 - Eliminar tipo de prestamo  *" << endl;
        cout << "* 4 - Listar tipo de prestamo    *" << endl;
        cout << "* 0 - Volver al menu principal   *" << endl;
        cout << "*                                *" << endl;
        cout << "**********************************" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            {
                ListarTipoPrestamosMenu listarTipoPrestamosMenu;
                listarTipoPrestamosMenu.iniciar();
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
