#include<stdlib.h>
#include"RegInteiro.h"
#include"Registrador.h"

struct RegInteiro{
    Registrador *sinal;
    Registrador *valor;
};

void RegInteiro_init(RegInteiro *regi){
    regi = (RegInteiro*)malloc(sizeof(RegInteiro));
    Registrador_init(regi->sinal);
    Registrador_init(regi->valor);
}

unsigned char RegInteiro_zero(RegInteiro *regi){
    return Registrador_zero(regi->valor);
}

void RegInteiro_sub(RegInteiro *regi){
    if(!Registrador_zero(regi->sinal)){
        Registrador_ad(regi->valor);
    }else{
        if(!Registrador_zero(regi->valor)){
            Registrador_sub(regi->valor);
        }else{
            Registrador_ad(regi->sinal);
            Registrador_ad(regi->valor);
        }
    }
}

void RegInteiro_ad(RegInteiro *regi){
    if(Registrador_zero(regi->sinal)){
        Registrador_ad(regi->valor);
    }else{
        Registrador_sub(regi->valor);
        if(Registrador_zero(regi->valor)){
            Registrador_setZero(regi->sinal);
        }
    }
}

void RegInteiro_setZero(RegInteiro *regi){
    if(Registrador_zero(regi->sinal)){
        while(!Registrador_zero(regi->valor)){
            RegInteiro_sub(regi);
        }
    }else{
        while(!Registrador_zero(regi->sinal)){
            RegInteiro_ad(regi);
        }
    }
}
