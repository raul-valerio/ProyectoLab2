#include "ClienteManager.h"
#include "CargarCadena.h"
#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

void ClienteManager::Cargar(){
    char _nombre[30], _apellido[30], _telefono[30], _calle[30], _localidad[30], _provincia[30];
    int _id, _riesgo, _altura, _codigoPostal;
    float _sueldo;


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
    //Si Buscar(_id) devuelve -1, significa que ya existe ese ID de cliente en "Clientes.dat"
    while(Buscar(_id) != -1){
        cout << "> El ID de cliente ya se encuentra en nuestro sistema" << endl;
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

    cout << "NOMBRE: ";
    cargarCadena(_nombre, 29);

    cout << "APELLIDO: ";
    cargarCadena(_apellido, 29);

    cout << "TELEFONO: ";
    cargarCadena(_telefono, 29);

    x = true;
    while (x){
        cout << "SUELDO: ";
        cin >>_sueldo;
        if (_sueldo <= 0) {
            cout << "NO SE PUEDE ASIGAR UN SUELDO NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
    }
    x = true;
    while (x){
        cout << "RIESGO: ";
        cin >> _riesgo;
        if (_riesgo == 1 || _riesgo == 2 || _riesgo == 3){
            x = false;
        }
        else{
            cout << "El riesgo debe estar dentro del rango disponible ( 1:, 2:, 3: )" << endl;
            //system("pause");
            //system("cls");
            x = true;
        }
    }

    cout << "DIRECCION" << endl;
    cout << "Calle: ";
    cargarCadena(_calle,29);

    x = true;
    while (x){
        cout << "Altura: ";
        cin >> _altura;
        if (_altura <= 0) {
            cout << "NO SE PUEDE ASIGAR UNA ALTURA NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
    }

    cout << "Localidad: ";
    cargarCadena(_localidad,29);

    cout << "Codigo postal: ";
    cin >> _codigoPostal;

    while (_codigoPostal <= 0){
        cout << "El codigo postal debe ser superior a 0" << endl;
        //system("pause");
        //system("cls");
        cout << "Codigo postal: ";
        cin >> _codigoPostal;
    }

    cout << "Provincia: ";
    cargarCadena(_provincia,29);

    Cliente reg;
    Direccion _direccion;
    reg.setId(_id);
    reg.setNombre(_nombre);
    reg.setApellido(_apellido);
    reg.setTelefono(_telefono);
    reg.setSueldo(_sueldo);
    reg.setRiesgo(_riesgo);
    reg.setMaximoMontoAPrestar();
    _direccion.setCalle(_calle);
    _direccion.setAltura(_altura);
    _direccion.setLocalidad(_localidad);
    _direccion.setCodigoPostal(_codigoPostal);
    _direccion.setProvincia(_provincia);

    reg.setDireccion(Direccion(_direccion));

    cout << endl;

    bool ok = _archivo.Guardar(reg);
    if (ok){
        cout << "> El cliente se registro correctamente.";
    }
    else{
        cout << "> El cliente no se registro correctamente.";
    }
    cout << endl;
    system("pause");
}

void ClienteManager::Mostrar(Cliente reg){
    cout << "* ------------------------------ * " << endl;
    cout << "> CLIENTE #" << reg.getId() << endl;
    cout << "> Nombre           : " << reg.getNombre() << endl;
    cout << "> Apellido         : " << reg.getApellido() << endl;
    cout << "> Telefono         : " << reg.getTelefono() << endl;
    cout << "> Sueldo           : " << reg.getSueldo() << endl;
    cout << "> Riesgo           : " << reg.getRiesgo() << endl;
    cout << "> Provincia        : " << reg.getDireccion().getProvincia() << endl;
    cout << "> Localidad        : " << reg.getDireccion().getLocalidad() << endl;
    cout << "> Codigo postal    : " << reg.getDireccion().getCodigoPostal() << endl;
    cout << "> Calle            : " << reg.getDireccion().getCalle() << endl;
    cout << "> Altura           : " << reg.getDireccion().getAltura() << endl;
    cout << "> Maximo permitido : " << fixed << setprecision(0) <<  reg.getMaximoMontoAPrestar() << endl;
}

//MUESTRA POR PANTALLA LA CANTIDAD DE REGISTROS
void ClienteManager::MostrarCantidadRegistros(){
    int cantidadRegistros = _archivo.ContarRegistros();
    cout << endl << "> CANTIDAD REGISTROS: " << cantidadRegistros << "." << endl;
}

//LISTA TODOS LOS CLIENTES.
void ClienteManager::ListarTodos(){
    int cantidadRegistros = _archivo.ContarRegistros();
    Cliente obj;
    cout << "    LISTADO DE CLIENTES ACTIVOS   " << endl << endl;
    for(int i=0; i<cantidadRegistros; i++){
        obj = _archivo.Leer(i);
        if(obj.getEstado() == true){
            Mostrar(obj);
        }
    }
}

void ClienteManager::ListarEnOperacion(){
    int cantidadRegistros = _archivo.ContarRegistros();
    Cliente obj;
    for(int i=0; i<cantidadRegistros; i++){
        obj = _archivo.Leer(i);
        if(obj.getEstado() == true){
            int id = obj.getId();
            cout << "ID: " << id << endl;
        }
    }
}

//RECIBE COMO PARAMETRO EL ID DEL CLIENTE, SI LO ENCUENTRA, DEVUELVE LA POSICION DEL MISMO. SI NO LO ENCUENTRA DEVUELVE -1
int ClienteManager::Buscar(int ClienteID){
    int cantidadRegistros = _archivo.ContarRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        Cliente reg = _archivo.Leer(i);
        if (reg.getId() == ClienteID){
            return i;
        }
    }
    return -1;
}

void ClienteManager::ListarPorID(){
    int ID, posicion;
    cout << "ID Cliente: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);

    if (posicion >= 0){
        Cliente aux = _archivo.Leer(posicion);
        Mostrar(aux);
    }
    else{
        cout <<  "> No se encontro el cliente con ID #" << ID << endl << endl;
    }
}

//FUNCION PARA ELIMINAR UN CLIENTE ( BAJA LOGICA )
void ClienteManager::Eliminar(){
    int ID, posicion;
    cout << "ID Cliente: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);
    if (posicion >= 0){
        Cliente aux = _archivo.Leer(posicion);
        cout << "Registro a eliminar: " << endl;
        Mostrar(aux);

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
        cout << endl << "> No se encontro el cliente con ID #" << ID << endl;
        system("pause");
        system("cls");
    }
}

void ClienteManager::Editar(){
    int ID, posicion;
    cout << "ID Cliente: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);
    if (posicion < 0){
        cout << endl << "> No se encontro el cliente con ID #" << ID << endl;
        system("pause");
        system("cls");
        return;
    }
    char opcion;
    Cliente aux = _archivo.Leer(posicion);
    system("cls");
    cout << "Registro a modificar: " << endl;
    Mostrar(aux);
    cout << "Desea modificar el registro? S/N" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    if(opcion == 'n' || opcion == 'N'){
        cout << endl << "> Tu registro esta a salvo. Arrugaste." << endl;
        system("pause");
        system("cls");
        return;
    }
    system("cls");
    bool quePaso = OpcionesParaModificar(posicion);


}

bool ClienteManager::OpcionesParaModificar(int posicion){
    Cliente aux = _archivo.Leer(posicion);

    bool confirmacion = false;
    do{
        int opc;
        Mostrar(aux);
        cout << endl << "Seleccione la opcion deseada a modificar" << endl << endl;
        cout << "> Opcion 1 - Nombre" << endl;
        cout << "> Opcion 2 - Apellido" << endl;
        cout << "> Opcion 3 - Telefono" << endl;
        cout << "> Opcion 4 - Sueldo" << endl;
        cout << "> Opcion 5 - Riesgo" << endl;
        cout << "> Opcion 6 - Provincia" << endl;
        cout << "> Opcion 7 - Localidad" << endl;
        cout << "> Opcion 8 - Codigo Postal" << endl;
        cout << "> Opcion 9 - Calle" << endl;
        cout << "> Opcion 10 - Altura" << endl;
        cout << "* ----------------------------- * " << endl;
        cout << "> Opcion 0 - Volver hacia atras" << endl;
        cin >> opc;

        system("cls");
        switch(opc){
        case 1:
            confirmacion = ModificarNombre(posicion);
            break;
        case 2:
            confirmacion = ModificarApellido(posicion);
            break;
        case 3:
            confirmacion = ModificarTelefono(posicion);
            break;
        case 4:
            confirmacion = ModificarSueldo(posicion);
            break;
        case 5:
            confirmacion = ModificarRiesgo(posicion);
            break;
        case 6:
            confirmacion = ModificarProvincia(posicion);
            break;
        case 7:
            confirmacion = ModificarLocalidad(posicion);
            break;
        case 8:
            confirmacion = ModificarCodigoPostal(posicion);
            break;
        case 9:
            confirmacion = ModificarCalle(posicion);
            break;
        case 10:
            confirmacion = ModificarAltura(posicion);
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
    return true;
}

bool ClienteManager::ModificarNombre(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    char nombre[30];
    cout << "Nombre anterior: " << aux.getNombre() << endl;
    cout << "Nombre nuevo   : ";
    cargarCadena(nombre, 29);

    aux.setNombre(nombre);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarApellido(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    char apellido[30];
    cout << "Apellido anterior: " << aux.getApellido() << endl;
    cout << "Apellido nuevo   : ";
    cargarCadena(apellido, 29);

    aux.setApellido(apellido);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarTelefono(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    char telefono[30];

    cout << "Numero de telefono anterior: " << aux.getTelefono() << endl;
    cout << "Numero de telefono nuevo   : ";
    cargarCadena(telefono, 29);

    aux.setTelefono(telefono);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarProvincia(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    char provincia[30];

    cout << "Provincia anterior: " << aux.getDireccion().getProvincia() << endl;
    cout << "Provincia nueva   : ";
    cargarCadena(provincia, 29);

    aux.getDireccion().setProvincia(provincia);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarLocalidad(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    char localidad[30];

    cout << "Localidad anterior: " << aux.getDireccion().getLocalidad() << endl;
    cout << "Localidad nueva   : ";
    cargarCadena(localidad, 29);

    aux.getDireccion().setLocalidad(localidad);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarCodigoPostal(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    int codigoPostal;

    cout << "Calle anterior: " << aux.getDireccion().getCodigoPostal() << endl;
    cout << "Calle nueva   : ";
    cin >> codigoPostal;

    aux.getDireccion().setCodigoPostal(codigoPostal);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarCalle(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    char calle[30];

    cout << "Calle anterior: " << aux.getDireccion().getCalle() << endl;
    cout << "Calle nueva   : ";
    cargarCadena(calle, 29);

    aux.getDireccion().setCalle(calle);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarAltura(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    int altura;

    cout << "Altura anterior: " << aux.getDireccion().getAltura() << endl;
    cout << "Altura nueva   : ";
    cin >> altura;

    aux.getDireccion().setAltura(altura);
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarSueldo(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    float sueldo;

    cout << "Sueldo anterior: " << aux.getSueldo() << endl;
    cout << "Sueldo nuevo   : ";
    cin >> sueldo;



    aux.setSueldo(sueldo);
    aux.setMaximoMontoAPrestar();
    _archivo.Guardar(aux, posicion);

    return true;
}

bool ClienteManager::ModificarRiesgo(int posicion){
    Cliente aux = _archivo.Leer(posicion);
    int riesgo;

    cout << "Riesgo anterior: " << aux.getRiesgo() << endl;
    cout << "Riesgo nuevo   : ";
    cin >> riesgo;

    aux.setRiesgo(riesgo);
    aux.getMaximoMontoAPrestar();
    _archivo.Guardar(aux, posicion);

    return true;
}


