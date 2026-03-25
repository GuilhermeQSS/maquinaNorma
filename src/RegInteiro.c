#include<stdio.h>
#include<stdlib.h>
#include"RegInteiro.h"
#include"Registrador.h"

struct RegInteiro{
    Registrador *sinal;
    Registrador *valor;
};

RegInteiro* RegInteiro_init(){
    RegInteiro *regi = (RegInteiro*)malloc(sizeof(RegInteiro));
    regi->valor = Registrador_init();
    regi->sinal = Registrador_init();
    return regi;
}

Registrador* RegInteiro_getSinal(RegInteiro *regi){
    return regi->sinal;
}

Registrador* RegInteiro_getValor(RegInteiro *regi){
    return regi->valor;
}

unsigned char RegInteiro_zero(RegInteiro *regi){
    return Registrador_zero(regi->valor);
}

unsigned char RegInteiro_negativo(RegInteiro *regi){
    return !Registrador_zero(regi->sinal);
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
        Registrador_sub(regi->sinal);
    }
}

void RegInteiro_set(RegInteiro *regi, int n){
    if(n < 0){
        Registrador_set(regi->sinal,1);
    }
    Registrador_set(regi->valor,abs(n));
}

void RegInteiro_show(RegInteiro *regi){
    printf("%d\t%d\n",Registrador_getValor(regi->sinal),Registrador_getValor(regi->valor));
}