#include <iostream>
#include <cstring>

#include <cmath>

using namespace std;
#include "Cuota.h"


void cuotaSistemaAmericano(float monto, float tasa, int plazoMes,double *v){


float tasaMensual=((tasa/100)/12);

int contador=0;

 for (int i = 0; i <plazoMes; i++) {

        float intereses = monto * tasaMensual;
        float cuotaMensual = intereses;
        contador++;
        v[i] = cuotaMensual;
        if(contador==plazoMes){
                float intereses = monto * tasaMensual;
                float cuotaMensual = intereses + monto;
                v[i] = cuotaMensual;
        }

}
}
void cuotaSistemaFrances (float monto, float tasa, int plazoMes, double *v){


float tasaMensual=((tasa/100)/12);

double couta;
double a=0;
double b=0;

a=monto*tasaMensual*pow((1+tasaMensual),plazoMes);
b=pow((1+tasaMensual),plazoMes)-1;
couta=a/b;

for(int i=0; i<plazoMes; i++){
    v[i]= couta;
    //cout<<"CUOTA N: "<<i+1<<": "<<v[i]<<endl;
    }
}


void cuotaSistemaAleman(float monto, float tasa, int plazoMes,double *v){

float tasaMensual=((tasa/100)/12);
float cuotaCapital = monto / plazoMes;

for (int i = 0; i < plazoMes; i++) {
        float intereses = monto * tasaMensual; // Intereses del mes
        float cuotaTotal = cuotaCapital + intereses;
        v[i] = cuotaTotal;
        monto -= cuotaCapital; // Reducci�n del capital restante
    }

}
