#include<iostream>
#include <ctime>
using namespace std;
#include "Fecha.h"

int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}

void Fecha::setAnio(int anio){
        if(anio > 1900 && anio < 2050){
            _anio = anio;
        }
        else{
            _anio = 2000;
        }
}
void Fecha::setMes(int mes){
        if (mes > 0 && mes < 13){
            _mes = mes;
        }
        else{
            _mes = 1;
        }
}
void Fecha::setDia(int dia){
    int maxDia = 0;

    if (_mes == 1 || _mes == 3 || _mes == 5 || _mes == 7 || _mes == 8 || _mes == 10 || _mes == 12) {
        maxDia = 31;
    }
    else if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11) {
        maxDia = 30;
    }
    else if (_mes == 2) {
        maxDia = (esBiciesto()) ? 29 : 28;
    }

    if (dia >= 1 && dia <= maxDia) {
        _dia = dia;
    }
    else{
        _dia = 1;
    }
}

bool Fecha::esBiciesto(){
    if (_anio % 4 == 0){
        return true;
    }
    else{
        return false;
    }
}

void Fecha::Cargar(){
    int dia,mes,anio;
    cout << "Dia: ";
    cin >> dia;
    setDia(dia);
    cout << "Mes: ";
    cin >> mes;
    setMes(mes);
    cout << "Anio: ";
    cin >> anio;
    setAnio(anio);
}
void Fecha::Mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}

void Fecha::MostrarSinSalto(){
    cout << _dia << "/" << _mes << "/" << _anio;
}


void Fecha::AgregarMes(int meses) {
    const int mesesPorAnio = 12;

    // Calcular nuevos meses y años
    int nuevosMeses = _mes - 1 + meses;
    int aniosAdicionales = nuevosMeses / mesesPorAnio;

    // Actualizar año y mes
    _anio += aniosAdicionales;
    _mes = 1 + (nuevosMeses % mesesPorAnio);

    // Manejo de año bisiesto
    if (_mes == 2 && _dia == 29 && (_anio % 4 == 0 && (_anio % 100 != 0 || _anio % 400 == 0))) {
        _dia = 28; // Ajustar al último día de febrero en años bisiestos
    }
}

void Fecha::Hoy(){
     time_t t = time(NULL);
    struct tm *f = localtime(&t);
    _dia = (*f).tm_mday; // Indirecciona f y accede a tm_mday
    _mes = f->tm_mon + 1; // Indirecciona f y accede a tm_mon
    _anio = f->tm_year + 1900;

}

bool Fecha::esBisiesto(int anio) {
        return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

int Fecha::ObtenerDiasEnElMes(int mes, int anio){
        if (mes == 2) {
            return esBisiesto(anio) ? 29 : 28;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            return 30;
        } else {
            return 31;
        }
}

int Fecha::CalcularDiasTotal() {
        const int diasPorAnio = 365;
        int totalDias = 0;

        // Calcular los días desde el año 2000 hasta la fecha actual
        for (int i = 2000; i < _anio; ++i) {
            totalDias += esBisiesto(i) ? diasPorAnio + 1 : diasPorAnio;
        }

        // Calcular los días del año actual hasta la fecha actual
        for (int i = 1; i < _mes; ++i) {
            totalDias += ObtenerDiasEnElMes(i, _anio);
        }

        // Sumar los días del mes actual
        totalDias += _dia;

        return totalDias;
}

Fecha::Fecha(){
    setAnio(2000);
    setMes(1);
    setDia(1);
}
Fecha::Fecha(int dia, int mes, int anio){
    setAnio(anio);
    setMes(mes);
    setDia(dia);
}
