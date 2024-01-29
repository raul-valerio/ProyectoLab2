#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED

#include "Fecha.h"
#include "Prestamo.h"

class Operacion {
    public:
        void setId(int id);
        void setIdCliente(int idCliente);
        void setIdPrestamo(int idPrestamo);
        void setFechaInicio(Fecha fechaInicio);
        void setFechaFin(Fecha fechaFin);
        void setPlazo(int plazo);
        //CUOTAS
        void setCuotaMonto(double *cuotaMonto);
        void setPagarUnaCuota();
        void setPagarMasDeUnaCuota();
        void setCuotaPagada(int i);
        void setCuotaPorPagar(int i);
        //INTERES
        void setInteres(double *interes);
        void setInteres(int i,double monto);
        void setPagarInteres();
        void setEstado(bool estado);


        int  getId();
        int getIdCliente();
        int getIdPrestamo();
        Fecha getFechaInicio();
        Fecha getFechaFin();
        int getPlazo();
        //CUOTAS
        double *getCuotaMonto();
        double getCuotaMonto(int i);
        int getCuotaPagada();
        int getCuotaPorPagar();
        int getNumeroCuota();
        //INTERES
        double *getInteres();
        double getInteres(int i);
        int getNumeroCuotaInteres();

        bool getEstado();

        Operacion();

    private:
        int _id;
        int _idCliente;
        int _idPrestamo;
        Fecha _fechaInicio;
        Fecha _fechaFin;
        int _plazo;
        double _cuotaMonto[60];
        int _cuotaPagada;
        int _cuotaPorPagar;
        double _interes[60];
        bool _estado;
};

#endif // OPERACION_H_INCLUDED
