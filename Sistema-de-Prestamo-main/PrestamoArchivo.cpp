#include <iostream>
#include <clocale>
#include <cstring>

#include "PrestamoArchivo.h"
using namespace std;

/*
 *RECIBE EL NOMBRE DEL ARCHIVO COMO PARAMETRO
 *LO GUARDA EN UNA VARIABLE
 *LUEGO UTILIZA ESE NOMBRE EN OTRAS FUNCIONES COMO: GUARDAR, LEER, ETC.
*/
PrestamoArchivo::PrestamoArchivo(const char *_nombreArchivo){
    strcpy(nombreArchivo, _nombreArchivo);
}

//GUARDA UN REGISTRO, AL FINAL DE TODOS LOS REGISTROS EXISTENTES.
bool PrestamoArchivo::Guardar(const Prestamo &reg){
    bool pudoEscribir;
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr){
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Prestamo), 1, p);
    fclose(p);
    return pudoEscribir;
}

//RECIBE UN REGISTRO Y REEMPLAZA SEGÚN EL LA POSICION QUE RECIBA COMO PARAMETRO.
bool PrestamoArchivo::Guardar(const Prestamo &reg, int nroRegistro){
    bool pudoEscribir;
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr){
        return false;
    }
    //LA FUNCIÓN FSEEK POSICIONA AL PUNTERO PREVIAMENTE CREADO ( " p " en este caso ) EN LA POSICION DESEADA DENTRO DEL ARCHIVO.
    fseek(p, nroRegistro * sizeof(Prestamo), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Prestamo), 1, p);
    fclose(p);
    return pudoEscribir;
}

/*
 * Busca el ID del Prestamo en el archivo de Prestamos.dat.
 * Si lo encuentra devuelve la posición del archivo del registro.
 * Si no lo encuentra devuelve -1
*/
int PrestamoArchivo::BuscarPorID(int PrestamoID){
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        return -1;
    }
    int i = 0;
    Prestamo reg;
    while(fread(&reg, sizeof(Prestamo), 1, p)){
        if(reg.getId() == PrestamoID){
        fclose(p);
        return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

//CUENTA LA CANTIDAD DE PRESTAMOS, UTIL PARA REALIZAR OPERACIONES
int PrestamoArchivo::ContarRegistros(){
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Prestamo);
}

//RECIBE COMO PARAMETRO LA POSICION EN LA QUE SE ENCUENTRA UN OBJETO DENTRO DEL ARCHIVO, SI LO UBICA DEVUELVE ESE OBJETO COMO VALOR.
Prestamo PrestamoArchivo::Leer(int pos){
    Prestamo reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        reg.setEstado(0);
        return reg;
    }
    fseek(p, pos * sizeof(Prestamo), SEEK_SET);
    fread(&reg, sizeof(Prestamo), 1, p);
    fclose(p);
    return reg;
}

//RECIBE EL ID DEL PRESTAMOS, QUE PREVIAMENTE SE VERIFICO QUE EXISTA, LUEGO OFRECE LAS OPCIONES A MODIFICAR.
bool PrestamoArchivo::Modificar(int ID){
    Prestamo reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        cout << "> Error de lectura de archivo al modificar." << endl;
        system("pause");
        system("cls");
        return false;
    }
    return true;
}
