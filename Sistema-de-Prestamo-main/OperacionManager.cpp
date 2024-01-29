#include "OperacionManager.h"
#include "CargarCadena.h"
#include <iostream>
#include <cstring>
using namespace std;

void OperacionManager::Cargar(){

    Fecha hoy,j;
    hoy.Hoy();
    cout << "FECHA DE CARGA: ";
    hoy.Mostrar();
    int _id;
    int _idCliente;
    int _idPrestamo;
    Fecha _fechaInicio;
    Fecha _fechaFin;
    //cout << "DIFENCIA: ";
    //int dif,a,b;
    //j.Cargar();
    //a=j.CalcularDiasTotal();
    //b=hoy.CalcularDiasTotal();
    //dif=a-b;
    //cout<<dif;
//----------------------------------------ID OPERACION----------------------------------------//
    bool x = true;
    while (x){
        cout << "ID Operacion: ";
        cin >> _id;
        if (_id <= 0) {
            cout << "NO SE PUEDE ASIGAR UN ID NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
    }
    //Si Buscar(_id) devuelve -1, significa que ya existe ese id de Prestamo en "Operaciones.dat"
    while (Buscar(_id) != -1){
        cout << "> El ID de la Operacion ya se encuentra en nuestro sistema" << endl;
        cout << "> Vuelva a ingresar otro nuevamente" << endl << endl;
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
    //----------------------------------ID CLIENTE--------------------------------------------//
    x = true;
    while (x){
        cout << "ID Cliente: ";
        cin >> _idCliente;
        if (_idCliente <= 0) {
            cout << "NO SE PUEDE ASIGAR UN ID NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
    }
    //Si Buscar(_id) devuelve -1, significa que ya existe ese id de Prestamo en "Clientes.dat"
    int contador=0;
    while (_managerCliente.Buscar(_idCliente) == -1){
        cout << endl;
        cout << "> El ID del Cliente NO EXISTE en nuestro sistema" << endl;

        if(contador>=2) {
        system("cls");
        cout<<"TE AYUDAMOS, ESTOS SON LOS CLIENTES ACTIVOS"<<endl << endl;
        _managerCliente.ListarEnOperacion();
        contador=0;
        }
        cout << endl;
        cout << "> Vuelva a ingresar otro nuevamente" << endl << endl;
        system("pause");
        system("cls");
        cout << "ID CLIENTE: ";
        cin >> _idCliente;
        contador++;
        }

   //--------------------------------ID PRESTAMOS-----------------------------------------------//
   x = true;
    while (x){
        cout << "ID Prestamos: ";
        cin >> _idPrestamo;
        if (_idPrestamo <= 0) {
            cout << "NO SE PUEDE ASIGAR UN ID NEGATIVO O IGUAL A 0 - VOLVE A INGRESAR" << endl;
            x = true;
        }
        else x = false;
    }
    //Si Buscar(_id) devuelve -1, significa que ya existe ese id de Prestamo en "Prestamos.dat"
    contador=0;
    while (_managerPrestamo.Buscar(_idPrestamo) == -1){
         if(contador>=2) {
          cout<<"TE AYUDAMOS, ESTOS SON LOS PRESTAMOS ACTIVOS"<<endl;
         _managerPrestamo.ListarTodosSinCuotas();
         contador=0;
        }
        cout << "> El ID del Presstamos NO EXISTE en nuestro sistema" << endl;
        cout << "> Vuelva a ingresar otro nuevamente" << endl << endl;
        //system("pause");
        //system("cls");
        cout << "ID PRESTAMOS: ";
        cin >> _idPrestamo;
        contador++;
    }
//---------------------------------------------------------------------------------------
    Prestamo reg;
    reg = _archivoPrestamo.Leer(_archivoPrestamo.BuscarPorID(_idPrestamo)); //TRAER PRESTAMOS
    Cliente regCliente;
    regCliente = _archivoCliente.Leer(_archivoCliente.BuscarPorID(_idCliente)); //TRAER CLIENTE

    if (reg.getMonto() > regCliente.getMaximoMontoAPrestar()){
        cout << endl << "El monto del prestamo supera el maximo a prestar para el Cliente #" << regCliente.getId() << endl << endl;
        cout << "Volviendo al menu..." << endl;
        system("pause");
        return;
    }
    else{
        ///////////////FECHA INICIO y FIN////////
        cout << "FECHA DE INICIO: "<< endl;
        _fechaInicio.Cargar();
        _fechaFin.setDia(10);
        _fechaFin.setMes(_fechaInicio.getMes());
        _fechaFin.setAnio(_fechaInicio.getAnio());

        int pos = _archivoCliente.BuscarPorID(_idCliente); //BUSCAR ARCHIVO CLIENTE

        regCliente.descontarMaximo(reg.getMonto()); //DESCONTAR EL MONTO MAXIMO

        _archivoCliente.Guardar(regCliente, pos); // GUARDAR EL NUEVO MONTO MAXIMO

        _fechaFin.AgregarMes(reg.getPlazo());
        Operacion op;
        op.setPlazo(reg.getPlazo());
        op.setCuotaMonto(reg.getCuota());
        op.setId(_id);
        op.setIdCliente(_idCliente);
        op.setIdPrestamo(_idPrestamo);
        op.setFechaInicio(_fechaInicio);
        op.setFechaFin(_fechaFin);
        op.setCuotaPagada(reg.getPlazo());
        op.setCuotaPorPagar(reg.getPlazo());
        double v[60]={0};
        op.setInteres(v);
        cout << endl;
        system("cls");
        bool ok = _archivo.Guardar(op);
        if (ok){
            cout << "> El Prestamo se registro correctamente.";
            AsignarIntereses(op);
        }
        else{
            cout << "> El Prestamo no se registro correctamente.";
        }
        cout << endl;
        system("pause");
    }

}

void OperacionManager::Mostrar(Operacion reg){
    Prestamo regPrestamo;
    regPrestamo = _archivoPrestamo.Leer(_archivoPrestamo.BuscarPorID(reg.getIdPrestamo()));
    Cliente regCliente;
    regCliente = _archivoCliente.Leer(_archivoCliente.BuscarPorID(reg.getIdCliente()));

    cout << "* ------------------------------ * " << endl;
    cout << "> OPERACION #" << reg.getId() << endl;
    cout << "> NOMBRE CLIENTE        : " << regCliente.getNombre() << endl;
    cout << "> ID Cliente            : " << reg.getIdCliente() << endl;
    cout << "> ID Prestamo           : " << reg.getIdPrestamo() << endl;
    cout << "> MONTO DEL PRESTAMOS   : " << regPrestamo.getMonto() << endl;
    cout << "> Fecha de inicio       : ";
    reg.getFechaInicio().Mostrar();
    cout << "> Fecha de finalizacion : ";
    reg.getFechaFin().Mostrar();
    //cout << "> CUOTAS PAGADAS        : " << reg.getCuotaPagada() << endl;
    //cout << "> CUOTAS POR PAGAR      : " << reg.getCuotaPorPagar() << endl;
    //float x=1;
    //cout << "> % DE PAGO             : " <<std::fixed << std::setprecision(2)<<((x * reg.getCuotaPagada())/reg.getPlazo())*100 << endl;
    cout << "> VER TODAS LAS CUOTAS? S/N: " << endl;
    char confirmacion;
    cin >> confirmacion;
    if (confirmacion == 'S' || confirmacion == 's'){
             cout << endl << "          PRESTAMOS"<< endl;
    cout << "| --------------------------|" << endl; //20 MAS SI VA CON INTERES
    cout << "|CUOTAS  " << setw(4) << " | " << "   MONTO[$]   " << setw(3) << "| " /*<<"   INTERES[$]   " << setw(3) << "| " */<< endl;
    cout << "|---------------------------|" << endl;

    float valorTotalCuotas = 0;
    float valorTotalIntereses = 0;

            for(int i=0; i<reg.getPlazo(); i++){
                cout<<"|"<<"CUOTA N:"<<setw(2)<<1+i<<"|"<< setw(11)<<reg.getCuotaMonto(i)/*<<"     | "<<setw(11)<<reg.getInteres(i)*/<<endl;
                //cout<<"CUOTA N: "<<i+1<<": "<<reg.getCuotaMonto(i)<<endl;
                 cout << "|---------------------------|" << endl;
                 valorTotalCuotas += reg.getCuotaMonto(i);
            }
            cout << endl << "TOTAL RESTANTE A PAGAR: $" << valorTotalCuotas << endl<<endl;
            /*for(int i=0; i<reg.getPlazo(); i++){
                //cout<<"|"<<"CUOTA N:"<<setw(2)<<1+i<<"|"<< setw(11)<<reg.getCuotaMonto(i)/*<<"     | "<<setw(11)<<reg.getInteres(i)<<endl;
                //cout<<"CUOTA N: "<<i+1<<": "<<reg.getCuotaMonto(i)<<endl;
                 //cout << "|---------------------------|" << endl;
                 valorTotalIntereses += reg.getInteres(i);
            }
            cout << endl << "INTERES ACUMULADOS POR VENCIMIENTO: $" << valorTotalIntereses << endl << endl;*/
            system("pause");
            system("cls");
        }
        else{
            cout << endl << "> OK, NO TE MOSTRAMOS LAS CUOTAS." << endl;
            system("pause");
            system("cls");
        }
}

void OperacionManager::MostrarSinCuotas(Operacion reg){

    Prestamo regPrestamo;
    regPrestamo = _archivoPrestamo.Leer(_archivoPrestamo.BuscarPorID(reg.getIdPrestamo()));
    Cliente regCliente;
    regCliente = _archivoCliente.Leer(_archivoCliente.BuscarPorID(reg.getIdCliente()));

    cout << "* ------------------------------ * " << endl;
    cout << "> OPERACION #" << reg.getId() << endl;
    cout << "> NOMBRE CLIENTE        : " << regCliente.getNombre() << endl;
    cout << "> MONTO DEL PRESTAMOS   : " << regPrestamo.getMonto() << endl;
    //cout << "> ID Cliente            : " << reg.getIdCliente() << endl;
    //cout << "> ID Prestamo           : " << reg.getIdPrestamo() << endl;
    cout << "> Fecha de inicio       : ";
    reg.getFechaInicio().Mostrar();
    cout << "> Fecha de finalizacion : ";
    reg.getFechaFin().Mostrar();
    //cout << "> CUOTAS PAGADAS        : " << reg.getCuotaPagada() << endl;
    //cout << "> CUOTAS POR PAGAR      : " << reg.getCuotaPorPagar() << endl;
    //float x=1;
    //cout << "> % DE PAGO             : " <<std::fixed << std::setprecision(2)<<((x * reg.getCuotaPagada())/reg.getPlazo())*100 << endl;
    if(reg.getCuotaPorPagar()==0) cout << "> ESTADO FINALIZADA"<< endl;
    else cout << "> ESTADO ACTIVA"<< endl;

}

void OperacionManager::MostrarCantidadRegistros(){
    int cantidadRegistros = _archivo.ContarRegistros();
    cout << endl << "> CANTIDAD REGISTROS: " << cantidadRegistros << "." << endl;
}

void OperacionManager::ListarTodos(){
    int cantidadRegistros = _archivo.ContarRegistros();
    Operacion obj;
    cout << "   LISTADO DE OPERACIONES ACTIVAS   " << endl << endl;
    for(int i=0; i<cantidadRegistros; i++){
        obj = _archivo.Leer(i);
        if(obj.getEstado() == true){
            Mostrar(obj);
        }
    }
}

void OperacionManager::ListarTodosSinCuotas(){
    int cantidadRegistros = _archivo.ContarRegistros();
    Operacion obj;
    cout << "   LISTADO DE OPERACIONES ACTIVAS   " << endl << endl;
    for(int i=0; i<cantidadRegistros; i++){
        obj = _archivo.Leer(i);
        if(obj.getEstado() == true){
            MostrarSinCuotas(obj);
        }
    }
}

int OperacionManager::Buscar(int OperacionID){
    int cantidadRegistros = _archivo.ContarRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        Operacion reg = _archivo.Leer(i);
        if (reg.getId() == OperacionID){
            return i;
        }
    }
    return -1;
}

void OperacionManager::ListarPorID(){
    int ID, posicion;
    cout << "ID Operacion: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);

    if (posicion >= 0){
        Operacion aux = _archivo.Leer(posicion);
        Mostrar(aux);
    }
    else{
        cout <<  "> No se encontro la Operacion con ID #" << ID << endl << endl;
    }
}

void OperacionManager::AsignarIntereses(Operacion reg){
    Prestamo regPrestamo;
    regPrestamo = _archivoPrestamo.Leer(_archivoPrestamo.BuscarPorID(reg.getIdPrestamo()));

    Fecha f(10,reg.getFechaInicio().getMes(),reg.getFechaInicio().getAnio()), hoy;
    hoy.Hoy();
    double interesAcum=0;
    double sumaCuotas = 0;
    for(int i=0; i<reg.getPlazo(); i++){
        int x=1;
        f.AgregarMes(x);
        if((f.getAnio()-hoy.getAnio())<0){
            if(reg.getInteres(i)==0){
                reg.setInteres(i,(f.CalcularDiasTotal()-hoy.CalcularDiasTotal())*reg.getCuotaMonto(i)*-0.01);
            }
        }
        else if((f.getAnio()-hoy.getAnio())==0 && (f.getMes()-hoy.getMes())<0){
            if(reg.getInteres(i)==0){
                reg.setInteres(i,(f.CalcularDiasTotal()-hoy.CalcularDiasTotal())*reg.getCuotaMonto(i)*-0.01);
            }
        }
        else if((f.getAnio()-hoy.getAnio())==0 &&(f.getMes()-hoy.getMes()==0) && (f.getDia()-hoy.getDia())<0){
            if(reg.getInteres(i)==0){
                reg.setInteres(i,(f.CalcularDiasTotal()-hoy.CalcularDiasTotal())*reg.getCuotaMonto(i)*-0.01);

            }
        }
    interesAcum +=reg.getInteres(i);
    sumaCuotas += reg.getCuotaMonto(i);

    }
   int p = _archivo.BuscarPorID(reg.getId());
   _archivo.Guardar(reg,p);
}

//FUNCION PARA ELIMINAR UNA OPERACION ( BAJA LOGICA )
void OperacionManager::Eliminar(){
    int ID, posicion;
    cout << "ID Operacion: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);
    if (posicion >= 0){
        Operacion aux = _archivo.Leer(posicion);
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
        cout << endl << "> No se encontro la Operacion con ID #" << ID << endl;
        system("pause");
        system("cls");
    }
}

//---------------------------MENU GESTION DE CUOTAS--------------------------------------------------//

void OperacionManager::MenuGestionCuotas(){
    while(true){
        system("cls");
        int opcion;
        cout << "**********************************" << endl;
        cout << "*                                *" << endl;
        cout << "*       GESTION DE PAGOS         *" << endl;
        cout << "*                                *" << endl;
        cout << "**********************************" << endl;
        cout << "*                                *" << endl;
        cout << "* 1 - % de Pagos por Operacion   *" << endl;
        cout << "* 2 - Pagos por Operacion        *" << endl;
        cout << "* 3 - Pagar Cuotas               *" << endl;
        cout << "*                                *" << endl;
        cout << "* 0 - Volver al menu Operaciones *" << endl;
        cout << "*                                *" << endl;
        cout << "**********************************" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
        case 1:
            ListarTodosGestionCuotas();
            system("pause");
            break;
        case 2:
            ListarPorIDGestionCuotas();
            system("pause");
            break;
        case 3:
            Pagar();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opcion incorrecta. Seleccione nuevamente" << endl;

            break;
        }
    }
}

//-----OPCION 1 MENU
void OperacionManager::ListarTodosGestionCuotas(){
    int cantidadRegistros = _archivo.ContarRegistros();
    Operacion obj;
    cout << "    GESTION DE CUOTAS   " << endl << endl;
    for(int i=0; i<cantidadRegistros; i++){
        obj = _archivo.Leer(i);
        if(obj.getEstado() == true){
            MostrarGestionCuotas(obj);

        }
    }
}

void OperacionManager::MostrarGestionCuotas(Operacion reg){
    Prestamo regPrestamo;
    //regPrestamo = _archivoPrestamo.Leer(_archivoPrestamo.BuscarPorID(reg.getIdPrestamo()));
    //Cliente regCliente;
    //regCliente = _archivoCliente.Leer(_archivoCliente.BuscarPorID(reg.getIdCliente()));

    cout << "* ------------------------------ * " << endl;
    cout << "> OPERACION #" << reg.getId() << endl;
    //cout << "> NOMBRE CLIENTE        : " << regCliente.getNombre() << endl;
    //cout << "> ID Cliente            : " << reg.getIdCliente() << endl;
    //cout << "> ID Prestamo           : " << reg.getIdPrestamo() << endl;
    //cout << "> MONTO DEL PRESTAMOS   : " << regPrestamo.getMonto() << endl;
    //cout << "> Fecha de inicio       : ";
    //reg.getFechaInicio().Mostrar();
    //cout << "> Fecha de finalizacion : ";
    //reg.getFechaFin().Mostrar();
    cout << "> CUOTAS PAGADAS        : " << reg.getCuotaPagada() << endl;
    cout << "> CUOTAS POR PAGAR      : " << reg.getCuotaPorPagar() << endl;
    float x=1;
    cout << "> % DE PAGO             : " <<std::fixed << std::setprecision(2)<<((x * reg.getCuotaPagada())/reg.getPlazo())*100 << endl;
    double valorTotalIntereses=0;
    for(int i=0; i<reg.getPlazo(); i++){
                 valorTotalIntereses += reg.getInteres(i);
            }
    cout << ">INTERES POR" <<endl;
    cout <<"CUOTAS VENCIDAS          : $"<< valorTotalIntereses << endl;
}

//-----OPCION 2 MENU
void OperacionManager::ListarPorIDGestionCuotas(){
    int ID, posicion;
    cout << "ID Operacion: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);

    if (posicion >= 0){
        Operacion aux = _archivo.Leer(posicion);
        //AsignarIntereses(aux);
        MostrarGestionCuotasPorID(aux);
        //_archivo.Guardar(aux,posicion);
    }
    else{
        cout <<  "> No se encontro la Operacion con ID #" << ID << endl << endl;
    }
}

void OperacionManager::MostrarGestionCuotasPorID(Operacion reg){
    Prestamo regPrestamo;
    regPrestamo = _archivoPrestamo.Leer(_archivoPrestamo.BuscarPorID(reg.getIdPrestamo()));
    Cliente regCliente;
    regCliente = _archivoCliente.Leer(_archivoCliente.BuscarPorID(reg.getIdCliente()));

    cout << "* ------------------------------ * " << endl;
    cout << "> OPERACION #" << reg.getId() << endl;
    cout << "> NOMBRE CLIENTE        : " << regCliente.getNombre() << endl;
    cout << "> ID Cliente            : " << reg.getIdCliente() << endl;
    cout << "> ID Prestamo           : " << reg.getIdPrestamo() << endl;
    cout << "> MONTO DEL PRESTAMOS   : " << regPrestamo.getMonto() << endl;
    cout << "> Fecha de inicio       : ";
    reg.getFechaInicio().Mostrar();
    cout << "> Fecha de finalizacion : ";
    reg.getFechaFin().Mostrar();
    cout << "> CUOTAS PAGADAS        : " << reg.getCuotaPagada() << endl;
    cout << "> CUOTAS POR PAGAR      : " << reg.getCuotaPorPagar() << endl;
    float x=1;
    cout << "> % DE PAGO             : " <<std::fixed << std::setprecision(2)<<((x * reg.getCuotaPagada())/reg.getPlazo())*100 << endl;
    cout << "> VER TODAS LAS CUOTAS? S/N: " << endl;
    char confirmacion;
    cin >> confirmacion;
    if (confirmacion == 'S' || confirmacion == 's'){
        rlutil::setColor(rlutil::WHITE);
        cout << endl << "                           INFORME DE CUOTAS                             " << endl;
    cout << "| -------------------------------------------------------------------------------------------------|" << endl;
    cout << "|CUOTAS  " << setw(4) << " | " << "   MONTO[$]   " << setw(3) << "| " << "   FECHA VENCIMIENTO   " << setw(3) << " | " << "      ESTADO   " <<  "        | "<<setw(16) <<"   INTERES   " << setw(3) << "  | " <<endl;
    cout << "|--------------------------------------------------------------------------------------------------|" << endl;

        Fecha f(10,reg.getFechaInicio().getMes(),reg.getFechaInicio().getAnio()), hoy;
        hoy.Hoy();
        double interesAcum=0;
        double sumaCuotas = 0;
        for(int i=0; i<reg.getPlazo(); i++){
            int x=1;
            f.AgregarMes(x);
            if(reg.getCuotaMonto(i)==0){
                cout<<"|"<<"CUOTA N:"<<setw(2)<<i+1<<"|"<< setw(11);
                cout<<setw(16)<<"";
                //rlutil::setBackgroundColor(rlutil::GREY);
                rlutil::setColor(rlutil::BLUE);
                cout<<"***********PAGADA***********";
                //rlutil::setBackgroundColor(rlutil::BLACK);
                //cout<<endl;
                rlutil::setColor(rlutil::WHITE);
                cout<<setw(7)<< setw(10)<<setw(10)<<"                       |"<< setw(14)<<reg.getInteres(i);
                cout<<endl;

                cout<< "|--------------------------------------------------------------------------------------------------|"  << endl;
            }
            else{
                rlutil::setBackgroundColor(rlutil::BLACK);
                cout<<"|"<<"CUOTA N:"<<setw(2)<<i+1<<"|"<< setw(11)<<reg.getCuotaMonto(i)<<"     | ";
                rlutil::setColor(rlutil::WHITE);
                if(f.getMes()>=10){

                        cout<< setw(10);f.MostrarSinSalto();cout<<setw(7)<<" |"<< setw(10);


                }
                else{

                        cout<< setw(10);f.MostrarSinSalto();cout<<setw(8)<<"   |"<< setw(10);

                }
                if((f.getAnio()-hoy.getAnio())<0){
                     rlutil::setColor(rlutil::RED);
                     cout<<setw(14)<<"VENCIDA";
                     rlutil::setColor(rlutil::WHITE);
                     if(reg.getInteres(i)==0){
                            reg.setInteres(i,(f.CalcularDiasTotal()-hoy.CalcularDiasTotal())*reg.getCuotaMonto(i)*-0.01);
                     }
                     else cout<<setw(7)<< setw(10)<<setw(7)<<"          |"<< setw(14)<<reg.getInteres(i);

                }
                else if((f.getAnio()-hoy.getAnio())==0 && (f.getMes()-hoy.getMes())<0){
                    rlutil::setColor(rlutil::RED);
                    cout<<setw(14)<<"VENCIDA";
                    rlutil::setColor(rlutil::WHITE);
                    if(reg.getInteres(i)==0){
                            reg.setInteres(i,(f.CalcularDiasTotal()-hoy.CalcularDiasTotal())*reg.getCuotaMonto(i)*-0.01);
                     }
                     else cout<<setw(7)<< setw(10)<<setw(7)<<"          |"<< setw(14)<<reg.getInteres(i);
                }
                else if((f.getAnio()-hoy.getAnio())==0 &&(f.getMes()-hoy.getMes()==0) && (f.getDia()-hoy.getDia())<0){
                    rlutil::setColor(rlutil::RED);
                    cout<<setw(14)<<"VENCIDA";
                    rlutil::setColor(rlutil::WHITE);
                    if(reg.getInteres(i)==0){
                            reg.setInteres(i,(f.CalcularDiasTotal()-hoy.CalcularDiasTotal())*reg.getCuotaMonto(i)*-0.01);

                     }
                     else cout<<setw(7)<< setw(10)<<setw(7)<<"          |"<< setw(14)<<reg.getInteres(i);

                }
                else{
                    rlutil::setColor(rlutil::GREEN);
                    cout<<setw(15)<<"EN PLAZO";
                    rlutil::setColor(rlutil::WHITE);
                }

                cout<<endl<< "|--------------------------------------------------------------------------------------------------|" << endl;
            }


            //OTRA FORMA SERIA CON EL VECTOR
            /*if((f.CalcularDiasTotal()-hoy.CalcularDiasTotal())<0){
                interesAcum +=(f.CalcularDiasTotal()-hoy.CalcularDiasTotal())*reg.getCuotaMonto(i)*-0.01;
            //cout<<"INTERES ACUMULADOS POR VENCIMIENTO"<<cantDias<<endl;
            //system("pause");
            }*/
            interesAcum +=reg.getInteres(i);

            sumaCuotas += reg.getCuotaMonto(i);

        }
       int p = _archivo.BuscarPorID(reg.getId());
       bool ok= _archivo.Guardar(reg,p);

        rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
        cout << endl;
        cout << "VALOR TOTAL DE CUOTAS: $" << sumaCuotas << endl << endl;
        cout << "INTERES ACUMULADOS POR VENCIMIENTO: $" << interesAcum << endl << endl;
        cout << "CANTIDAD TOTAL A PAGAR: $" << sumaCuotas + interesAcum << endl << endl;
        system("pause");
        system("cls");
    }
    else{
            cout << endl << "> OK, NO TE MOSTRAMOS LAS CUOTAS." << endl;
            system("pause");
            system("cls");
    }
}

//----OPCION 3 MENU
void OperacionManager::Pagar(){
    int ID, posicion;
    cout << "ID OPERACION: ";
    cin >> ID;

    posicion = _archivo.BuscarPorID(ID);
    if (posicion < 0){
        cout << endl << "> No se encontro la Operacion con ID #" << ID << endl;
        system("pause");
        system("cls");
        return;
    }
    char opcion;
    Operacion aux = _archivo.Leer(posicion);
    system("cls");
    cout << "REGISTRO A PAGAR: " << endl;
    MostrarGestionCuotas(aux);
    if(aux.getCuotaPagada()<aux.getPlazo()){
        cout << "Desea Pagar el registro? S/N" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        if(opcion == 'n' || opcion == 'N'){
            cout << endl << "> Tu registro esta a salvo. Arrugaste." << endl;
            system("pause");
            system("cls");
            return;
        }
        else if(opcion == 's' || opcion == 'S'){
            bool quePaso = OpcionesParaModificar(posicion);
        }
        else cout<<"ERROR AL INGRESAR LA OPCION, VOLVES AL MENU GESTIO DE CUOTAS"<<endl;
    }
    else {
        cout <<endl;
        cout<<"YA PAGASTE TODAS LAS CUOTAS, VOLVES AL MENU"<<endl<<endl;
    }

}

bool OperacionManager::OpcionesParaModificar(int posicion){
    //Operacion aux = _archivo.Leer(posicion);

    bool confirmacion = false;
    do{
        int opc;
        /*Mostrar(aux);*/
        cout << endl;
        cout << "Seleccione la Cantidad de Cuotas a Pagar" << endl << endl;
        cout << "> Opcion 1 - PAGAR PROXIMA CUOTA" << endl;
        cout << "> Opcion 2 - ADELANTAR CUOTAS" << endl;
        cout << "> Opcion 3 - PAGAR INTERESES ADEUDADOS" << endl;
        cout << "* ----------------------------- * " << endl;
        cout << "> Opcion 0 - Volver hacia atras" << endl;
        cin >> opc;

        system("cls");
        switch(opc){
        case 1:
            confirmacion = PagarUnaCuota(posicion);
            break;
        case 2:
            confirmacion = PagarMasDeUnaCuota(posicion);
            break;
        case 3:
            confirmacion = PagarInteresesAdeudados(posicion);
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
    }
    while(confirmacion != true);
    system("cls");
    cout << "Modificacion con exito" << endl;
    //system("pause");
    system("cls");
}

bool OperacionManager::PagarUnaCuota(int posicion){
    Operacion aux = _archivo.Leer(posicion);

    if(aux.getCuotaPagada()<aux.getPlazo()){
        aux.setPagarUnaCuota();
        cout<<"PAGO REALIZADO CON EXITO"<<endl;
        system("pause");
    }
    else {
        cout<<"YA PAGASTE TODAS LAS CUOTAS"<<endl;
        system("pause");
    }
    _archivo.Guardar(aux, posicion);

    return true;
}

bool OperacionManager::PagarMasDeUnaCuota(int posicion){


   Operacion aux = _archivo.Leer(posicion);
   cout<<"INGRESE LA CANTIDAD DE CUOTAS A ADELANTAR"<<endl;
   int c;
   cin>>c;
   if (c < 1 || c > aux.getPlazo() || c > aux.getCuotaPorPagar()){
    cout << "NUMERO DE CUOTAS INCORRECTO"<< endl;
    return false;
   }
   else{

    for(int k=0; k<c; k++){
    if(aux.getCuotaPagada()<aux.getPlazo()){
            int cuotaAux = aux.getNumeroCuota();
            aux.setPagarMasDeUnaCuota();
            cout<<"PAGO DE LA CUOTA #" << cuotaAux << " REALIZADO CON EXITO"<<endl;
            system("pause");
        }
        else {
            cout<<"YA PAGASTE TODAS LAS CUOTAS"<<endl;
            system("pause");
        }
    }
    /*for(int j=0; j<aux.getPlazo(); j++){
        cout<<aux.getCuotaMonto(j)<<endl;
    }
    cout<<"INGRESE LA CANTIDAD DE CUOTAS A PAGAR"<<endl;
    int c;
    cin>>c;
    for(int k=0; k<c; k++){
    cout<<"INGRESE LAS CUOTAS A PAGAR"<<endl;
    int cuota;
    cin>>cuota;
            aux.setPagarMasDeUnaCuota(cuota);
            rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    }
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    //aux.setPagarMasDeUnaCuota(aux.getCuotaMonto());
    for(int i=0; i<c; i++){
        if(aux.getCuotaPagada()<aux.getPlazo()){
            aux.setPagarMasDeUnaCuota(aux.getCuotaMonto());
            cout<<"PAGO REALIZADO CON EXITO"<<endl;
            system("pause");
        }
        else {
            cout<<"YA PAGASTE TODAS LAS CUOTAS"<<endl;
            system("pause");
        }
        _archivo.Guardar(aux, posicion);
    }*/
    _archivo.Guardar(aux, posicion);

        return true;
   }
}

bool OperacionManager::PagarInteresesAdeudados(int posicion){

    Operacion aux = _archivo.Leer(posicion);

   cout<<"PAGAR LOS INTERESES DE LA CUOTA: "<<endl;
   int c;
   cin>>c;
   if(c>0 && c<=aux.getPlazo()){
        int a=0;
        int b=0;
        a=aux.getCuotaMonto((c-1));
        b=aux.getInteres((c-1));
        cout<<"MONTO DE CUOTA:"<<a<<endl;
        cout<<"MONTO DE INTERES:"<<b<<endl;
        //system("pause");
        if(a==0 && b!=0){
            aux.setInteres((c-1),0);
             _archivo.Guardar(aux, posicion);
            cout<<"INTERESES PAGADOS EXITOSAMENTE"<<endl;
            system("pause");
            return true;
        }
        else{
            if(a!=0){
                 cout << "NO PODES PAGAR LOS INTERESES SIN ANTES PAGAR LA CUOTA" << endl;
                 system("pause");
                  return false;
            }
            if(b==0){
                cout << "ESTE INTERES YA ESTA PAGADO" << endl;
                system("pause");
                return false;
            }
        }
   }
   else {
    cout << "ERROR AL INGRESAR EL DATO" << endl;
    return false;
   }

    /*//cout << aux.getIntereses();
    system("pause");
    int pos=aux.getNumeroCuotaInteres();
    cout<<pos;

    if(pos <0 || pos !=aux.getCuotaMonto(pos)){
        cout << "NO PODES PAGAR LOS INTERESES SIN ANTES PAGAR LA CUOTA" << endl;
        return false;
        system("pause");
    }
    aux.setInteres(pos-1,0);*/


    //cout << "INTERESES PAGADOS EXITOSAMENTE" << endl;
    //system("pause");


}


