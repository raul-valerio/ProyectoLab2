#include "PrestamoManager.h"
#include "CargarCadena.h"
#include <iostream>
#include <cstring>

using namespace std;

void PrestamoManager::Cargar(){
    int _id,_plazo, _sistema;
    float _monto, _tasaInteres;

    bool x = true;
    while (x){
        cout << "ID: ";
        cin >> _id;
        if (_id <= 0) {
            cout << "NO SE PUEDE ASIGAR UN ID NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
    }
    //Si Buscar(_id) devuelve -1, significa que ya existe ese id de Prestamo en "Prestamos.dat"
    while (Buscar(_id) != -1){
        cout << "> El ID del Prestamos ya se encuentra en nuestro sistema" << endl;
        cout << "> Vuelva a ingresar otro nuevamente" << endl << endl;
        system("pause");
        system("cls");
        bool x=true;
        while (x){
        cout << "ID: ";
        cin >> _id;
        if (_id <= 0) {
            cout << "NO SE PUEDE ASIGAR UN ID NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
        }
    }
    x = true;
    while (x){
        cout << "MONTO: ";
        cin >> _monto;
        if (_monto <= 0){
            cout << "NO SE PUEDE ASIGAR UN MONTO NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
    }
    x = true;
    while( x){
        cout << "TASA DE INTERES: ";
        cin >> _tasaInteres;
        if (_tasaInteres<=0){
            cout <<" NO SE PUEDE ASIGAR UNA TASA NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" <<endl;
            x = true;
        }
        else x = false;
    }
    x = true;
    while (x){
        cout << "PLAZO: ";
        cin >> _plazo;
        if (_plazo <= 0) {
            cout << "NO SE PUEDE ASIGAR UN PLAZO NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" <<endl;
            x = true;
        }
        else x = false;
    }
    x = true;
    while (x){
        cout << "SISTEMA: ";
        cin >> _sistema;
        if (_sistema == 1 || _sistema == 2 || _sistema == 3){

            x = false;
        }
        else{
            cout << "Error al asignar el sistema, los disponibles son: 1 - Frances, 2 - Alemana, 3 - Americano" << endl;
            cout << "Ingrese uno disponible nuevamente" << endl;
            x = true;
        }
    }

    Prestamo reg;
    reg.setId(_id);
    reg.setMonto(_monto);
    reg.setTasaInteres(_tasaInteres);
    reg.setPlazo(_plazo);
    reg.setSistema(_sistema);
    reg.setCuota(_sistema,_plazo,_monto,_tasaInteres);

    cout << endl;
    system("cls");
    bool ok = _archivo.Guardar(reg);
    if (ok){
        cout << "> El Prestamo se registro correctamente.";
    }
    else{
        cout << "> El Prestamo no se registro correctamente.";
    }
    cout << endl;
    system("pause");
}

void PrestamoManager::Mostrar(Prestamo reg){
    std::string vecSistemas[3] = {"Frances", "Aleman", "Americano"};
    cout << "* ------------------------------ * " << endl;
    cout << "> PRESTAMO #" << reg.getId() << endl;
    cout << "> Monto            : " << std::fixed << std::setprecision(0) << reg.getMonto() << std::endl;
    cout << "> Tasa de Interes  : " << reg.getTasaInteres() << endl;
    cout << "> Plazo            : " << reg.getPlazo() << endl;
    cout << "> Sistema          : " << vecSistemas[reg.getSistema()-1] << endl;
    cout << "> VER TODAS LAS CUOTAS? S/N: " << endl;
    char confirmacion;
    cin >> confirmacion;
    if (confirmacion == 'S' || confirmacion == 's'){
        cout << endl << "          PRESTAMOS"<< endl;
    cout << "| --------------------------|" << endl;
    cout << "|CUOTAS  " << setw(4) << " | " << "   MONTO[$]   " << setw(3) << "| " <<  endl;
    cout << "|---------------------------|" << endl;
            float acum = 0;
            for(int i=0; i<reg.getPlazo(); i++){
                cout<<"|"<<"CUOTA N:"<<setw(2)<<1+i<<"|"<< setw(11)<<reg.getCuota(i)<<"     | "<<endl;
                cout << "|---------------------------|" << endl;
                acum += reg.getCuota(i);
            }

            cout << endl << "El valor TOTAL a abonar es de: " << acum << endl;

            system("pause");
        }
        else{
            cout << endl << "> OK, NO TE MOSTRAMOS LAS CUOTAS." << endl;
            system("pause");
        }

}

void PrestamoManager::MostrarSinCuotas(Prestamo reg){
    std::string vecSistemas[3] = {"Frances", "Aleman", "Americano"};
    cout << "* ------------------------------ * " << endl;
    cout << "> PRESTAMO #" << reg.getId() << endl;
    cout << "> Monto            : " << std::fixed << std::setprecision(0) << reg.getMonto() << std::endl;
    cout << "> Tasa de Interes  : " << reg.getTasaInteres() << endl;
    cout << "> Plazo            : " << reg.getPlazo() << endl;
    cout << "> Sistema          : " << vecSistemas[reg.getSistema()-1] << endl;
}

//MUESTRA POR PANTALLA LA CANTIDAD DE REGISTROS
void PrestamoManager::MostrarCantidadRegistros(){
    int cantidadRegistros = _archivo.ContarRegistros();
    cout << endl << "> CANTIDAD REGISTROS: " << cantidadRegistros << "." << endl;
}

//LISTA TODOS LOS PRESTAMOS.
void PrestamoManager::ListarTodos(){
    int cantidadRegistros = _archivo.ContarRegistros();
    Prestamo obj;

    cout << "    LISTADO DE PRESTAMOS ACTIVOS   " << endl << endl;
    for(int i=0; i<cantidadRegistros; i++){
        obj = _archivo.Leer(i);
        if(obj.getEstado() == true){
            Mostrar(obj);
        }
    }
}

void PrestamoManager::ListarTodosSinCuotas(){
    int cantidadRegistros = _archivo.ContarRegistros();
    Prestamo obj;

    cout << "    LISTADO DE PRESTAMOS ACTIVOS   " << endl << endl;
    for(int i=0; i<cantidadRegistros; i++){
        obj = _archivo.Leer(i);
        if(obj.getEstado() == true){
            MostrarSinCuotas(obj);
        }
    }

}

//RECIBE COMO PARAMETRO EL ID DEL PRESTAMOS, SI LO ENCUENTRA, DEVUELVE LA POSICION DEL MISMO. SI NO LO ENCUENTRA DEVUELVE -1
int PrestamoManager::Buscar(int PrestamoID){
    int cantidadRegistros = _archivo.ContarRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        Prestamo reg = _archivo.Leer(i);
        if (reg.getId() == PrestamoID){
            return i;
        }
    }
    return -1;
}

void PrestamoManager::ListarPorID(){
    int ID, posicion;
    cout << "ID PRESTAMOS: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);

    if (posicion >= 0){
        Prestamo aux = _archivo.Leer(posicion);
        Mostrar(aux);
    }
    else{
        cout <<  "> No se encontro el Prestamo con ID #" << ID << endl << endl;
    }
}

//FUNCION PARA ELIMINAR UN PRESTAMOS ( BAJA LOGICA )
void PrestamoManager::Eliminar(){
    int ID, posicion;
    cout << "ID Prestamos: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);
    if (posicion >= 0){
        Prestamo aux = _archivo.Leer(posicion);
        cout << "Registro a eliminar: " << endl;
        MostrarSinCuotas(aux);

        char confirmacion;
        cout << endl << "Confirmar? S/N: ";
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's'){
            aux.setEstado(0);
            _archivo.Guardar(aux, posicion);
            cout << endl << "> Registro eliminado correctamente." << endl << endl;
            system("pause");
            system("cls");
        }
        else{
            cout << endl << "> Tu registro esta a salvo. Arrugaste." << endl;
            system("pause");
            system("cls");
        }
    }
    else{
        cout << endl << "> No se encontro el Prestamo con ID #" << ID << endl;
        system("pause");
        system("cls");
    }
}

void PrestamoManager::Editar(){
    int ID, posicion;
    cout << "ID Prestamo: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);
    if (posicion < 0){
        cout << endl << "> No se encontro el Prestamos con ID #" << ID << endl;
        system("pause");
        system("cls");
        return;
    }
    char opcion;
    Prestamo aux = _archivo.Leer(posicion);
    system("cls");
    cout << "Registro a modificar: " << endl;
    MostrarSinCuotas(aux);
    cout << "Desea modificar el registro? S/N" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    if(opcion == 'n' || opcion == 'N'){
        cout << endl << "> Tu registro esta a salvo. Arrugaste." << endl;
        system("pause");
        system("cls");
        return;
    }

    bool quePaso = OpcionesParaModificar(posicion);


}

bool PrestamoManager::OpcionesParaModificar(int posicion){
    Prestamo aux = _archivo.Leer(posicion);

    bool confirmacion = false;
    do{
        int opc;
        /*Mostrar(aux);*/
        cout << endl;
        cout << "Seleccione la opcion deseada a modificar" << endl << endl;
        cout << "> Opcion 1 - Monto" << endl;
        cout << "> Opcion 2 - Tasa de Interes" << endl;
        cout << "> Opcion 3 - Plazo" << endl;
        cout << "> Opcion 4 - Sistema" << endl;
        cout << "* ----------------------------- * " << endl;
        cout << "> Opcion 0 - Volver hacia atras" << endl;
        cin >> opc;

        system("cls");
        switch(opc){
        case 1:
            confirmacion = ModificarMonto(posicion);
            break;
        case 2:
            confirmacion = ModificarTasaInteres(posicion);
            break;
        case 3:
            confirmacion = ModificarPlazo(posicion);
            break;
        case 4:
            confirmacion = ModificarSistema(posicion);
            break;
        case 0:
            return false;
            break;
        default:
            cout << "Opcion inexistente, vuelva a ingresar otra opcion" << endl;
            system("pause");
            system("cls");
            break;
        }
    }while(confirmacion != true);
    system("cls");
    cout << "Modificacion con exito" << endl;
    system("pause");
    system("cls");
}

bool PrestamoManager::ModificarMonto(int posicion){
    Prestamo aux = _archivo.Leer(posicion);
    float monto;
    cout << "Monto anterior: " << aux.getMonto() << endl;
    cout << "Monto nuevo   : ";
    cin>>monto;

    aux.setMonto(monto);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool PrestamoManager::ModificarTasaInteres(int posicion){
    Prestamo aux = _archivo.Leer(posicion);
    float tasaInteres;
    cout << "Tasa Interes anterior: " << aux.getTasaInteres() << endl;
    cout << "Tasa Interes nuevo   : ";
    cin>>tasaInteres;

    aux.setTasaInteres(tasaInteres);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool PrestamoManager::ModificarPlazo(int posicion){
    Prestamo aux = _archivo.Leer(posicion);
    int plazo;

    cout << "Plazo anterior: " << aux.getPlazo() << endl;
    cout << "Plazo nuevo   : ";
    cin>>plazo;

    aux.setPlazo(plazo);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool PrestamoManager::ModificarSistema(int posicion){
    Prestamo aux = _archivo.Leer(posicion);
    int sistema;

    cout << "Sistema anterior: " << aux.getSistema() << endl;
    cout << "Sistema nuevo   : ";
    cin>>sistema;

    aux.setSistema(sistema);
    _archivo.Guardar(aux, posicion);

    return true;
}
