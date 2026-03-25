#ifndef MAQUINA_H
#define MAQUINA_H

typedef struct Maquina Maquina;

Maquina* Maquina_init();
void Maquina_setA(Maquina *maq, int n);
void Maquina_setB(Maquina *maq, int n);
void Maquina_setC(Maquina *maq, int n);
void Maquina_setD(Maquina *maq, int n);

void Maquina_printRegisters(Maquina *maq);
void Maquina_ArecebeAmaisB(Maquina *maq);
void Maquina_ArecebeAmaisBusandoC(Maquina *maq);
void Maquina_ArecebeBusandoC(Maquina *maq);
void Maquina_ArecebeAvezesBusandoCeD(Maquina *maq);

#endif
