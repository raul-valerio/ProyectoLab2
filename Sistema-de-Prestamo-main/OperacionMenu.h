#ifndef OPERACIONESMENU_H
#define OPERACIONESMENU_H

#include "OperacionManager.h"

class OperacionMenu{
public:
    void iniciar();
    void iniciarGestioPagos();
private:
    OperacionManager _manager;
};

#endif // OPERACIONESMENU_H
