#include"Maquina.h"
#include"RegInteiro.h"
#include"Registrador.h"
#include<stdio.h>
#include<stdlib.h>

struct Maquina{
    RegInteiro *A;
    RegInteiro *B;
    RegInteiro *C;
    RegInteiro *D;
};

Maquina* Maquina_init(){
    Maquina* maq = (Maquina*)malloc(sizeof(Maquina));
    maq->A = RegInteiro_init();
    maq->B = RegInteiro_init();
    maq->C = RegInteiro_init();
    maq->D = RegInteiro_init();
    return maq;
}

void Maquina_setA(Maquina *maq, int n){
    RegInteiro_set(maq->A,n);
}

void Maquina_setB(Maquina *maq, int n){
    RegInteiro_set(maq->B,n);
}

void Maquina_setC(Maquina *maq, int n){
    RegInteiro_set(maq->C,n);
}

void Maquina_setD(Maquina *maq, int n){
    RegInteiro_set(maq->D,n);
}

void Maquina_printRegisters(Maquina *maq){
    unsigned int A1 = Registrador_getValor(RegInteiro_getSinal(maq->A));
    unsigned int A2 = Registrador_getValor(RegInteiro_getValor(maq->A));
    unsigned int B1 = Registrador_getValor(RegInteiro_getSinal(maq->B));
    unsigned int B2 = Registrador_getValor(RegInteiro_getValor(maq->B));
    unsigned int C1 = Registrador_getValor(RegInteiro_getSinal(maq->C));
    unsigned int C2 = Registrador_getValor(RegInteiro_getValor(maq->C));
    unsigned int D1 = Registrador_getValor(RegInteiro_getSinal(maq->D));
    unsigned int D2 = Registrador_getValor(RegInteiro_getValor(maq->D));
    printf("A1\tA2\tB1\tB2\tC1\tC2\tD1\tD2\n");
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",A1,A2,B1,B2,C1,C2,D1,D2);
}

void Maquina_ArecebeAmaisB(Maquina *maq){
    Maquina_printRegisters(maq);
    printf("\n");
    while (!RegInteiro_zero(maq->B)){
        if (RegInteiro_negativo(maq->B)){
            RegInteiro_ad(maq->B);
            RegInteiro_sub(maq->A);
        } else {
            RegInteiro_sub(maq->B);
            RegInteiro_ad(maq->A);
        }
        Maquina_printRegisters(maq);
        printf("\n");
    }
}

void Maquina_ArecebeAmaisBusandoC(Maquina *maq){
    Maquina_printRegisters(maq);
    printf("\n");
    while (!RegInteiro_zero(maq->B)){
        if (RegInteiro_negativo(maq->B)){
            RegInteiro_ad(maq->B);
            RegInteiro_sub(maq->C);
        } else {
            RegInteiro_sub(maq->B);
            RegInteiro_ad(maq->C);
        }

        Maquina_printRegisters(maq);
        printf("\n");
    }

    while (!RegInteiro_zero(maq->C)){
        if (RegInteiro_negativo(maq->C)){
            RegInteiro_ad(maq->C);
            RegInteiro_sub(maq->A);
            RegInteiro_sub(maq->B);
        } else {
            RegInteiro_sub(maq->C);
            RegInteiro_ad(maq->A);
            RegInteiro_ad(maq->B);
        }

        Maquina_printRegisters(maq);
        printf("\n");
    }
}

void Maquina_ArecebeBusandoC(Maquina *maq){
    Maquina_printRegisters(maq);
    printf("\n");

    while (!RegInteiro_zero(maq->A)){
        if (RegInteiro_negativo(maq->A)){
            RegInteiro_ad(maq->A);
        } else {
            RegInteiro_sub(maq->A);
        }
        Maquina_printRegisters(maq);
        printf("\n");
    }

    while (!RegInteiro_zero(maq->B)){
        if (RegInteiro_negativo(maq->B)){
            RegInteiro_ad(maq->B);
            RegInteiro_sub(maq->C);
        } else {
            RegInteiro_sub(maq->B);
            RegInteiro_ad(maq->C);
        }

        Maquina_printRegisters(maq);
        printf("\n");
    }

    while (!RegInteiro_zero(maq->C)){
        if (RegInteiro_negativo(maq->C)){
            RegInteiro_ad(maq->C);
            RegInteiro_sub(maq->A);
            RegInteiro_sub(maq->B);
        } else {
            RegInteiro_sub(maq->C);
            RegInteiro_ad(maq->A);
            RegInteiro_ad(maq->B);
        }

        Maquina_printRegisters(maq);
        printf("\n");
    }
}

void Maquina_ArecebeAvezesBusandoCeD(Maquina *maq){
    Maquina_printRegisters(maq);
    printf("\n");
    while (!RegInteiro_zero(maq->C)){
        if (RegInteiro_negativo(maq->C)){
            RegInteiro_ad(maq->C);
        } else {
            RegInteiro_sub(maq->C);
        }
    }
    while (!RegInteiro_zero(maq->D)){
        if (RegInteiro_negativo(maq->D)){
            RegInteiro_ad(maq->D);
        } else {
            RegInteiro_sub(maq->D);
        }
    }
    while (!RegInteiro_zero(maq->A)){
        if (RegInteiro_negativo(maq->A)){
            RegInteiro_ad(maq->A);
            RegInteiro_sub(maq->C);
        } else {
            RegInteiro_sub(maq->A);
            RegInteiro_ad(maq->C);
        }

        Maquina_printRegisters(maq);
        printf("\n");
    }
    while (!RegInteiro_zero(maq->B)){
        if (RegInteiro_negativo(maq->B)){
            RegInteiro_ad(maq->B);
            RegInteiro_sub(maq->D);
        } else {
            RegInteiro_sub(maq->B);
            RegInteiro_ad(maq->D);
        }

        Maquina_printRegisters(maq);
        printf("\n");
    }
    while (!RegInteiro_zero(maq->D)){
        if (RegInteiro_negativo(maq->D)){
            RegInteiro_ad(maq->D);
            while (!RegInteiro_zero(maq->C)){
                if (RegInteiro_negativo(maq->C)){
                    RegInteiro_ad(maq->C);
                    RegInteiro_sub(maq->A);
                    RegInteiro_sub(maq->B);
                } else {
                    RegInteiro_sub(maq->C);
                    RegInteiro_ad(maq->A);
                    RegInteiro_ad(maq->B);
                }
            }
            while (!RegInteiro_zero(maq->B)){
                if (RegInteiro_negativo(maq->B)){
                    RegInteiro_ad(maq->B);
                    RegInteiro_sub(maq->C);
                } else {
                    RegInteiro_sub(maq->B);
                    RegInteiro_ad(maq->C);
                }
            }

        } else {
            RegInteiro_sub(maq->D);
            while (!RegInteiro_zero(maq->C)){
                if (RegInteiro_negativo(maq->C)){
                    RegInteiro_ad(maq->C);
                    RegInteiro_sub(maq->A);
                    RegInteiro_sub(maq->B);
                } else {
                    RegInteiro_sub(maq->C);
                    RegInteiro_ad(maq->A);
                    RegInteiro_ad(maq->B);
                }
            }
            while (!RegInteiro_zero(maq->B)){
                if (RegInteiro_negativo(maq->B)){
                    RegInteiro_ad(maq->B);
                    RegInteiro_sub(maq->C);
                } else {
                    RegInteiro_sub(maq->B);
                    RegInteiro_ad(maq->C);
                }
            }
        }

        Maquina_printRegisters(maq);
        printf("\n");
    }
    while (!RegInteiro_zero(maq->D)){
        if (RegInteiro_negativo(maq->D)){
            RegInteiro_ad(maq->D);
            RegInteiro_sub(maq->B);
        } else {
            RegInteiro_sub(maq->D);
            RegInteiro_ad(maq->B);
        }
    }
}