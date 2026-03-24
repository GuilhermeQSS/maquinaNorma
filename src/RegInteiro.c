#include"RegInteiro.h"
#include"Registrador.h"

struct RegInteiro{
    Registrador *sinal;
    Registrador *valor;
};

unsigned char RegInteiro_zero(RegInteiro *reg){
    return Registrador_zero(reg->valor);
}

void RegInteiro_sub(RegInteiro *reg){
    if(!Registrador_zero(reg->sinal)){
        Registrador_ad(reg->valor);
    }else{
        if(!Registrador_zero(reg->valor)){
            Registrador_sub(reg->valor);
        }else{
            Registrador_ad(reg->sinal);
            Registrador_ad(reg->valor);
        }
    }
}

void RegInteiro_ad(RegInteiro *reg){
    if(Registrador_zero(reg->sinal)){
        Registrador_ad(reg->valor);
    }else{
        Registrador_sub(reg->valor);
        if(Registrador_zero(reg->valor)){
            Registrador_setZero(reg->sinal);
        }
    }
}

void RegInteiro_setZero(RegInteiro *reg){
    if(Registrador_zero(reg->sinal)){
        while(!Registrador_zero(reg->valor)){
            RegInteiro_sub(reg);
        }
    }else{
        while(!Registrador_zero(reg->sinal)){
            RegInteiro_ad(reg);
        }
    }
}
