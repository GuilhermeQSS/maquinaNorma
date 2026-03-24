#ifndef REGINTEIRO_H
#define REGINTEIRO_H

typedef struct RegInteiro RegInteiro;

unsigned char RegInteiro_zero(RegInteiro *reg);
void RegInteiro_sub(RegInteiro *reg);
void RegInteiro_ad(RegInteiro *reg);
void RegInteiro_setZero(RegInteiro *reg);

#endif