#include<iostream>
#include<iomanip>

using namespace std;
#include "CargarCadena.h"
#include "Prestamo.h"
#include "Cuota.h"

//SETTERS
void Prestamo::setId(int id){
        _id = id;
}

void Prestamo::setMonto(double monto){
    _monto = monto;
}

void Prestamo::setTasaInteres(float tasaInteres){
    _tasaInteres = tasaInteres;
}

void Prestamo::setPlazo(int plazo){
    _plazo = plazo;
}

void Prestamo::setSistema(int sistema){
    _sistema = sistema;
}

void Prestamo::setCuota(int sistema, int plazo, float monto, float tasaInteres){
  if(sistema==1){
    cuotaSistemaFrances(monto,tasaInteres,plazo,_cuota);
  }
  if(sistema==2){
    cuotaSistemaAleman(monto,tasaInteres,plazo,_cuota);
  }
  if(sistema==3){
    cuotaSistemaAmericano(monto,tasaInteres,plazo,_cuota);
  }

}

void Prestamo::setEstado(bool estado){
    _estado = estado;
}

//GETTERS
int Prestamo::getId(){
    return _id;
}

double Prestamo::getMonto(){
    return _monto;
}

float Prestamo::getTasaInteres(){
    return _tasaInteres;
}

int Prestamo::getPlazo(){
    return _plazo;
}

int Prestamo::getSistema(){
    return _sistema;
}

double Prestamo::getCuota(int i){
    return _cuota[i];
}

double* Prestamo::getCuota(){
 return _cuota;
}

bool Prestamo::getEstado(){
    return _estado;
}

//CONSTRUCTOR
Prestamo::Prestamo(){
    setId(0);
    setTasaInteres(0);
    setMonto(0);
    setPlazo(1);
    setEstado(1);

}
