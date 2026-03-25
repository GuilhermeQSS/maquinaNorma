#include<stdio.h>
#include<string.h>
#include"Maquina.h"
#include"Entrada.h"

#define TAMANHO_ENTRADA 10

void input(char *entrada){
    printf(">");
    Entrada_string(entrada, TAMANHO_ENTRADA);
    strlwr(entrada);
}

int main(){
    Maquina *maqNorma;
    Maquina_init(maqNorma);

    char entrada[TAMANHO_ENTRADA];

    input(entrada);
    while (strcmp(entrada,"quit") != 0 && strcmp(entrada,"q") != 0){
        if(strcmp(entrada,"set") == 0 || strcmp(entrada,"s") == 0){

        }else if(strcmp(entrada,"register") == 0 || strcmp(entrada,"r") == 0){
            
        }else{
            printf("Type 'help' for more information\n");
        }
        input(entrada);
    }
    
    return 0;
}