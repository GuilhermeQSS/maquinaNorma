#ifndef REGISTRADOR_H
#define REGISTRADOR_H

typedef struct Registrador Registrador;

unsigned char Registrador_zero(Registrador *reg);
void Registrador_sub(Registrador *reg);
void Registrador_ad(Registrador *reg);
void Registrador_setZero(Registrador *reg);

#endif