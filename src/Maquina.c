#include"Maquina.h"
#include"RegInteiro.h"

struct Maquina{
    RegInteiro *A;
    RegInteiro *B;
    RegInteiro *C;
    RegInteiro *D;
};

void Maquina_init(Maquina *maq){
    RegInteiro_init(maq->A);
    RegInteiro_init(maq->B);
    RegInteiro_init(maq->C);
    RegInteiro_init(maq->D);
}
void Maquina_ArecebeAmaisB(Maquina *maq){
    
}
void Maquina_ArecebeAmaisBusandoC(Maquina *maq);
void Maquina_ArecebeBusandoC(Maquina *maq);
void Maquina_ArecebeavezesBusandoCeD(Maquina *maq);