#include<iostream>
#include<iomanip>
using namespace std;
#include "CargarCadena.h"
#include "Operacion.h"
#include "Prestamo.h"


//-------->//SETTERS
 void Operacion::setId(int id){
     _id=id;
 }

void Operacion::setIdCliente(int idCliente){
    _idCliente=idCliente;
}

void Operacion::setIdPrestamo(int idPrestamo){
    _idPrestamo=idPrestamo;
}

void Operacion::setFechaInicio(Fecha fechaInicio){
    _fechaInicio=fechaInicio;
}

void Operacion::setFechaFin(Fecha fechaFin){
    _fechaFin=fechaFin;
}

void Operacion::setPlazo(int plazo){
    _plazo=plazo;
}

//CARGA CUOTAS DE PRESTAMO
void Operacion::setCuotaMonto(double *cuotaMonto){
    for(int i=0; i<getPlazo();i++){
            _cuotaMonto[i]=cuotaMonto[i];
    }
}

//PAGO DE CUOTAS
void Operacion::setPagarUnaCuota(){

    for(int i=0; i<_plazo; i++){
        if(_cuotaMonto[i]!=0){
            _cuotaMonto[i]=0;
            break;
        }
    }
    /*int pos=0;
    for(int i=0; i<_plazo; i++){
            if(cuotaMonto[i] ==0){
                pos=i+1;
            }
     } //busca ultima posicion pagada
    if(pos<_plazo){
            cuotaMonto[pos]=0;
    }
    else if(pos>_plazo) cuotaMonto[_plazo]=0;*/
    _cuotaPagada++;
    _cuotaPorPagar--;
}

void Operacion::setPagarMasDeUnaCuota(){

    for(int i=_plazo-1; i>=0; i--){
        if(_cuotaMonto[i]!=0){
            _cuotaMonto[i]=0;
            break;
        }
    }

    //_cuotaMonto[cuota-1]=0;
     _cuotaPagada++;
    _cuotaPorPagar--;

}

void Operacion::setCuotaPagada(int i){
    _cuotaPagada=_plazo-i;
}

void Operacion::setCuotaPorPagar(int i){
    _cuotaPorPagar=i;
}

//CARGA INTERESES DE PRESTAMO
void Operacion::setInteres(double *interes){
     for(int i=0; i<getPlazo();i++){
            _interes[i]=interes[i];
    }
}

void Operacion::setInteres(int i,double monto){
    _interes[i]=monto;
}

void Operacion::setPagarInteres(){

    for(int i=0; i<_plazo; i++){
        if(_interes[i]!=0){
            _interes[i]=0;
            break;
        }
    }
}

void Operacion::setEstado(bool estado){
    _estado=estado;
}


//------->//GETTERS
int Operacion::getId(){
    return _id;
}

int Operacion::getIdCliente(){
    return _idCliente;
}

int Operacion::getIdPrestamo(){
    return _idPrestamo;
}

Fecha Operacion::getFechaInicio(){
    return _fechaInicio;
}

Fecha Operacion::getFechaFin(){
    return _fechaFin;
}

int Operacion::getPlazo(){
    return _plazo;
}

/*double Operacion::getIntereses(){
    return _intereses;
}*/
//CUOTAS
double* Operacion::getCuotaMonto(){
    return _cuotaMonto;
}

double Operacion::getCuotaMonto(int i){
    return _cuotaMonto[i];
}

int Operacion::getCuotaPagada(){
    return _cuotaPagada;
}

int Operacion::getCuotaPorPagar(){
    return _cuotaPorPagar;
}

int Operacion::getNumeroCuota(){
    for (int i=_plazo-1; i>=0;i--){
        if (_cuotaMonto[i] != 0){

            return i+1;

        }
    }
    return -1;
}

//INTERES
double* Operacion::getInteres(){
    return _interes;
}

double Operacion::getInteres(int i){
    return _interes[i];
}

int Operacion::getNumeroCuotaInteres(){
    for (int i=0; i<_plazo;i++){
        if (_cuotaMonto[i] == 0){
            return i;
        }
    }
    return -1;
}

bool Operacion::getEstado(){
    return _estado;
}

//CONSTRUCTOR
Operacion::Operacion(){
    setId(0);
    setIdCliente(0);
    setIdPrestamo(0);
    setFechaInicio(_fechaInicio);
    setFechaFin(_fechaFin);
    double v[60]= {0};
    setPlazo(_plazo);
    setCuotaMonto(v);
    setEstado(true);

}
