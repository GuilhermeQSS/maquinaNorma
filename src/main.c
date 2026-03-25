#include<stdio.h>
#include<string.h>
#include"Maquina.h"
#include"Entrada.h"
#include"Utils.h"


int main(){
    Maquina *maqNorma = Maquina_init();

    char entrada[TAMANHO_ENTRADA];
    input(entrada);
    while (strcmp(entrada,"quit") != 0 && strcmp(entrada,"q") != 0){
        if(strcmp(entrada,"help") == 0 || strcmp(entrada,"h") == 0){
            help();
        }else if(strcmp(entrada,"set") == 0 || strcmp(entrada,"s") == 0){
            setView(maqNorma);
        }else if(strcmp(entrada,"register") == 0 || strcmp(entrada,"r") == 0){
            Maquina_printRegisters(maqNorma);
        }else if(strcmp(entrada,"a:=a+b") == 0){
            Maquina_ArecebeAmaisB(maqNorma);
        }else if(strcmp(entrada,"a:=a+b,c") == 0){
            Maquina_ArecebeAmaisBusandoC(maqNorma);
        }else if(strcmp(entrada,"a:=b,c") == 0){
            Maquina_ArecebeBusandoC(maqNorma);
        }else if(strcmp(entrada,"a:=a*b,c&d") == 0){
            Maquina_ArecebeAvezesBusandoCeD(maqNorma);
        }else{
            printf("Digite 'help' ou 'h' para listar os comandos\n");
        }
        input(entrada);
    }
    
    return 0;
}