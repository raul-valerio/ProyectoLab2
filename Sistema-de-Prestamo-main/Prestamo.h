#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED

class Prestamo {
public:
    void setId(int id);
    void setMonto(double monto);
    void setTasaInteres(float tasaInteres);
    void setPlazo(int plazo);
    void setSistema(int sistema);
    void setCuota(int sistema, int plazo, float monto, float tasaInteres);
    void setEstado(bool estado);

    int getId();
    double getMonto();
    float getTasaInteres();
    int getPlazo();
    int getSistema();
    double getCuota(int i);
    double *getCuota();
    bool getEstado();

    Prestamo();

private:
    int _id;
    double _monto;
    float _tasaInteres;
    int _plazo; //meses
    int _sistema; //1- Frances, 2-Alemana, 3- Americano
    double _cuota[60];
    bool _estado;

};


#endif // PRESTAMO_H_INCLUDED
