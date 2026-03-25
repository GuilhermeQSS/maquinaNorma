#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef struct Registrador Registrador;

Registrador* Registrador_init();
unsigned int Registrador_getValor(Registrador *reg);

unsigned char Registrador_zero(Registrador *reg);
void Registrador_sub(Registrador *reg);
void Registrador_ad(Registrador *reg);
void Registrador_set(Registrador *reg, int n);

#endif