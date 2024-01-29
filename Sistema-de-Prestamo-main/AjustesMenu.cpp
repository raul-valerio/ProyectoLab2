#include<iostream>
using namespace std;
#include "CargarCadena.h"
#include "AjustesMenu.h"

void AjustesMenu::iniciar(){
    while(true){
        system("cls");
        int opcion;
        cout << "*************************************" << endl;
        cout << "*                                   *" << endl;
        cout << "*             AJUSTES               *" << endl;
        cout << "*                                   *" << endl;
        cout << "*************************************" << endl;
        cout << "*                                   *" << endl;
        cout << "* 1 - Cambiar Nombre de Usuario     *" << endl;
        cout << "* 2 - Eliminar datos del programa   *" << endl;
        cout << "* 3 - Ajustar monto referencia base *" << endl;
        cout << "*                                   *" << endl;
        cout << "* 0 - Volver al menu principal      *" << endl;
        cout << "*                                   *" << endl;
        cout << "*************************************" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            NombreUsuario();
            break;
        case 2:
            EliminarDatos();
            break;
        case 3:
            EstablecerMontoReferenciaBase();
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

void EstablecerMontoReferenciaBase(){

    FILE * archivoMonto = fopen("MontoReferencia.dat", "wb");
    if(archivoMonto == nullptr){
        return;
    }

    double referencia;
    cout << "Establezca un monto de referencia para definir la cantidad que se podra otorgar a los clientes registrados : ";
    cin >> referencia;

    if (referencia <= 0){
        cout << "El monto referencia ingresado debe ser superior a 0" << endl;
        system("pause");
        system("cls");
        return;
    }

    fwrite(&referencia, sizeof referencia, 1, archivoMonto);
    fclose(archivoMonto);


    ClienteArchivo _archivoCliente("clientes.dat");
    int cantReg = _archivoCliente.ContarRegistros();

    Cliente _cliente;

    for (int i=0; i<cantReg; i++){
        _cliente = _archivoCliente.Leer(i);
        _cliente.setMaximoMontoAPrestar();
        _archivoCliente.Guardar(_cliente, i);

    }
    cout << "Configuracion con exito" << endl;
    system("pause");
    system("cls");
}

void NombreUsuario(){
    FILE * p = fopen("NombreUsuario.dat", "wb");
    if (p == NULL){
        cout << "Error en la lectura del archivo" << endl;
        exit(1);
    }

    char nuevoNombre[30];

    cout << "NUEVO NOMBRE DE USUARIO: ";
    cargarCadena(nuevoNombre,29);

    fwrite(nuevoNombre, sizeof nuevoNombre, 1, p);
    fclose(p);

    system("cls");

    cout << "NOMBRE DE USUARIO MODIFICADO CON EXITO" << endl << endl;
    system("pause");

}

void EliminarDatos(){

    char opcion;
    cout << "-------------" << endl;
    cout << "| ATENCION! |" << endl;
    cout << "-------------" << endl;
    cout << endl;
    cout << "SI CONTINUA, PERDERA TODOS LOS DATOS GUARDADOS DE SUS" << endl;
    cout << "CLIENTES, SUS TIPOS DE PRESTAMOS Y OPERACIONES ACTIVAS" << endl;
    cout << endl;
    cout << "SEGURO QUE DESEA ELIMINAR TODOS LOS DATOS DEL SISTEMA? (S/N)" << endl;
    cout << endl;
    cout << "Opcion: ";
    cin >> opcion;
    system("cls");

    if (opcion == 's' || opcion == 'S'){

        FILE * archivoClientes = fopen("Clientes.dat", "wb");
        if (archivoClientes == NULL){
            return;
        }

        fclose(archivoClientes);

        FILE * archivoPrestamos = fopen("Prestamos.dat", "wb");
        if (archivoPrestamos == NULL){
            return;
        }

        fclose(archivoPrestamos);

        FILE * archivoOperaciones = fopen("Operaciones.dat", "wb");
        if (archivoOperaciones == NULL){
            return;
        }

        fclose(archivoOperaciones);

        cout << "DATOS ELIMINADOS EXITOSAMENTE" << endl;
        cout << endl;
        system("pause");

    }

    else{

        cout << "SUS DATOS SIGUEN A SALVO" << endl;
        cout << endl;
        system("pause");

    }


}


