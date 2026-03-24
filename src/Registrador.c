#include"Registrador.h"

struct Registrador{
    unsigned int valor;
};

unsigned char Registrador_zero(Registrador *reg){
    return reg->valor == 0;
}

void Registrador_sub(Registrador *reg){
    if(!Registrador_zero(reg)){
        reg->valor = reg->valor-1;
    }
}

void Registrador_ad(Registrador *reg){
    reg->valor = reg->valor+1;
}

void Registrador_setZero(Registrador *reg){
    while(!Registrador_zero(reg)){
        Registrador_sub(reg);
    }
}
