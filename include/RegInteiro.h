#ifndef REGINTEIRO_H
#define REGINTEIRO_H
#include"Registrador.h"

typedef struct RegInteiro RegInteiro;

RegInteiro* RegInteiro_init();
Registrador* RegInteiro_getSinal(RegInteiro *regi);
Registrador* RegInteiro_getValor(RegInteiro *regi);

unsigned char RegInteiro_zero(RegInteiro *regi);
unsigned char RegInteiro_negativo(RegInteiro *regi);
void RegInteiro_sub(RegInteiro *regi);
void RegInteiro_ad(RegInteiro *regi);
void RegInteiro_set(RegInteiro *regi, int n);
void RegInteiro_show(RegInteiro *regi);

#endif