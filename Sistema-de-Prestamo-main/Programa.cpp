#include<iostream>
using namespace std;

#include "Programa.h"
#include "ClienteMenu.h"
#include "OperacionMenu.h"
#include "PrestamoMenu.h"
#include "AjustesMenu.h"


void Programa::bienvenida(){

    FILE * p = fopen("NombreUsuario.dat", "rb");

    if (p == NULL){
    cout << "Error en la lectura del archivo" << endl;
    exit(1);
    }

    fread(_nombreUsuario, sizeof _nombreUsuario, 1, p);


    cout << "Bienvenido, " << _nombreUsuario << "!" << endl << endl;
    cout << "Este Sistema de Gestion de Prestamos, fue hecho por: " << endl << endl;
    cout << "Angel Spinazzola, Juan Pereyra y Raul Rolon" << endl << endl;
    cout << "Si queres cambiar tu nombre de usuario, podes hacerlo desde los ajustes" << endl << endl;
    system("pause");
    fclose(p);

}

void Programa::iniciar(){
    while(true){
        system("cls");
        int opcion;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "*        MENU PRINCIPAL        *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << "*                              *" << endl;
        cout << "* 1 - Operaciones              *" << endl;
        cout << "* 2 - Clientes                 *" << endl;
        cout << "* 3 - Tipos de prestamo        *" << endl;
        cout << "* 4 - Gestion de Pagos         *" << endl;
        cout << "* 5 - Ajustes                  *" << endl;
        cout << "* 6 - Guia de prestamos        *" << endl;
        cout << "*                              *" << endl;
        cout << "* 0 - Salir del programa       *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
        case 1:
            {
                OperacionMenu operacionMenu;
                operacionMenu.iniciar();
            }
            break;
        case 2:
            {
                ClienteMenu clienteMenu;
                clienteMenu.iniciar();
            }
            break;
        case 3:
            {
                PrestamoMenu prestamoMenu;
                prestamoMenu.iniciar();
            }
            break;
        case 4:
            {
                OperacionMenu operacionMenu;
                operacionMenu.iniciarGestioPagos();
            }
            break;
        case 5:
                AjustesMenu ajustesMenu;
                ajustesMenu.iniciar();
            break;
        case 6:
                GuiaPrestamos();
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

void GuiaPrestamos(){

    while (true){
        system("cls");
        int opc;
        cout << "*********************************" << endl;
        cout << "*                               *" << endl;
        cout << "* GUIA DE SISTEMAS DE PRESTAMOS *" << endl;
        cout << "*                               *" << endl;
        cout << "*********************************" << endl;
        cout << "*                               *" << endl;
        cout << "* 1 - Sistema Frances           *" << endl;
        cout << "* 2 - Sistema Aleman            *" << endl;
        cout << "* 3 - Sistema Americano         *" << endl;
        cout << "*                               *" << endl;
        cout << "* 0 - Volver al menu            *" << endl;
        cout << "*                               *" << endl;
        cout << "*********************************" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
    case 1:
        cout << "---------------" << endl;
        cout << "SISTEMA FRANCES" << endl;
        cout << "---------------" << endl;
        cout << endl;
        cout << "Este sistema se caracteriza por ser de amortizacion " << endl;
        cout << "que se realiza a traves de cuotas constantes." << endl;
        cout << endl;
        cout << "Por esta razon, es tambien conocido" << endl;
        cout << "como 'sistema de coutas fijas'." << endl;
        cout << endl;
        cout << "En resumen, al aplicar este sistema de prestamos" << endl;
        cout << "el cliente tendra que pagar lo mismo todos " << endl;
        cout << "los meses hasta liquidar su deuda." << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        system("pause");
        break;
    case 2:
        cout << "--------------" << endl;
        cout << "SISTEMA ALEMAN" << endl;
        cout << "--------------" << endl;
        cout << endl;
        cout << "Este sistema se caracteriza por ser de amortizacion" << endl;
        cout << "de capital en el que la cuota del prestamo varia" << endl;
        cout << "a lo largo de toda la vida del prestamo." << endl;
        cout << endl;
        cout << "Con este, la proporcion de capital que" << endl;
        cout << "se de en las cuotas es siempre el mismo y los intereses" << endl;
        cout << "a pagar se calculan en base a este." << endl;
        cout << endl;
        cout << "En consecuencia, este tipo de sistema de amortizacion" << endl;
        cout << "se traduce en cuotas decrecientes." << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        system("pause");
        break;
    case 3:
        cout << "-----------------" << endl;
        cout << "SISTEMA AMERICANO" << endl;
        cout << "-----------------" << endl;
        cout << endl;
        cout << "En este sistema, el prestatario se compromete a pagar" << endl;
        cout << "al prestamista una cantidad periodica formada solo por" << endl;
        cout << "los intereses del prestamo y a abonar, al final de la" << endl;
        cout << "vida de este, los intereses del ultimo anio y el capital prestado." << endl;
        cout << endl;
        cout << "En consecuencia, la persona que ha solicitado el prestamo" << endl;
        cout << "paga una anualidad constante y que incluye solo los intereses," << endl;
        cout << "pero en este caso, en el ultimo periodo, junto con la anualidad" << endl;
        cout << "se tendra que devolver todo el capital prestado inicialmente." << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        system("pause");
        break;
    case 0:
        return;
        break;
    default:
        cout << "Opcion incorrecta. Seleccione nuevamente" << endl << endl;
        system("pause");
        break;
        }
    }
}
