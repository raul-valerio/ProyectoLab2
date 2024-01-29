#include <iostream>
#include <clocale>
#include <cstring>
#include "OperacionArchivo.h"
using namespace std;

/*
 *RECIBE EL NOMBRE DEL ARCHIVO COMO PARAMETRO
 *LO GUARDA EN UNA VARIABLE
 *LUEGO UTILIZA ESE NOMBRE EN OTRAS FUNCIONES COMO: GUARDAR, LEER, ETC.
*/
OperacionArchivo::OperacionArchivo(const char *_nombreArchivo){
    strcpy(nombreArchivo, _nombreArchivo);
}

//GUARDA UN REGISTRO, AL FINAL DE TODOS LOS REGISTROS EXISTENTES.
bool OperacionArchivo::Guardar(const Operacion &reg){
    bool pudoEscribir;
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr){
        return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(Operacion), 1, p);
    fclose(p);
    return pudoEscribir;
}

//RECIBE UN REGISTRO Y REEMPLAZA SEGÚN EL LA POSICION QUE RECIBA COMO PARAMETRO.
bool OperacionArchivo::Guardar(const Operacion &reg, int nroRegistro){
    bool pudoEscribir;
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr){
        return false;
    }
    //LA FUNCIÓN FSEEK POSICIONA AL PUNTERO PREVIAMENTE CREADO ( " p " en este caso ) EN LA POSICION DESEADA DENTRO DEL ARCHIVO.
    fseek(p, nroRegistro * sizeof(Operacion), SEEK_SET);
    pudoEscribir = fwrite(&reg, sizeof(Operacion), 1, p);
    fclose(p);
    return pudoEscribir;
}

/*
 * Busca el ID del Operacion en el archivo de Clientes.dat.
 * Si lo encuentra devuelve la posición del archivo del registro.
 * Si no lo encuentra devuelve -1
*/
int OperacionArchivo::BuscarPorID(int OperacionID){
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        return -1;
    }
    int i = 0;
    Operacion reg;
    while(fread(&reg, sizeof(Operacion), 1, p)){
        if(reg.getId() == OperacionID){
        fclose(p);
        return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

//CUENTA LA CANTIDAD DE OPERACIONES, UTIL PARA REALIZAR OPERACIONES
int OperacionArchivo::ContarRegistros(){
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Operacion);
}

//RECIBE COMO PARAMETRO LA POSICION EN LA QUE SE ENCUENTRA UN OBJETO DENTRO DEL ARCHIVO, SI LO UBICA DEVUELVE ESE OBJETO COMO VALOR.
Operacion OperacionArchivo::Leer(int pos){
    Operacion reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        reg.setEstado(0);
        return reg;
    }
    fseek(p, pos * sizeof(Operacion), SEEK_SET);
    fread(&reg, sizeof(Operacion), 1, p);
    fclose(p);
    return reg;
}

//RECIBE EL ID DE CLIENTE, QUE PREVIAMENTE SE VERIFICO QUE EXISTA, LUEGO OFRECE LAS OPCIONES A MODIFICAR.
bool OperacionArchivo::Modificar(int ID){
    Operacion reg;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr){
        cout << "> Error de lectura de archivo al modificar." << endl;
        system("pause");
        system("cls");
        return false;
    }
    return true;

}
