#include<stdio.h>
#include<stdlib.h>
#include"Registrador.h"

struct Registrador{
    unsigned int valor;
};

Registrador* Registrador_init(){
    Registrador *reg = (Registrador*)malloc(sizeof(Registrador));
    reg->valor = 0;
    return reg;
}

unsigned int Registrador_getValor(Registrador *reg){
    return reg->valor;
}

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

void Registrador_set(Registrador *reg, int n){
    if(n < reg->valor){
        while (n != reg->valor){
            Registrador_sub(reg);
        }
    }else{
        while (n != reg->valor){
            Registrador_ad(reg);
        }
    }
}
