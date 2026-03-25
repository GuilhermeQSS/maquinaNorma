#ifndef REGINTEIRO_H
#define REGINTEIRO_H

typedef struct RegInteiro RegInteiro;

void RegInteiro_init(RegInteiro *regi);
unsigned char RegInteiro_zero(RegInteiro *regi);
void RegInteiro_sub(RegInteiro *regi);
void RegInteiro_ad(RegInteiro *regi);
void RegInteiro_setZero(RegInteiro *regi);

#endif