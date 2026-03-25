#include"Utils.h"
#include<stdio.h>
#include<string.h>
#include"Entrada.h"
#include"Maquina.h"

void input(char *entrada){
    printf(">");
    Entrada_string(entrada, TAMANHO_ENTRADA);
    strlwr(entrada);
    removerEspacos(entrada);
}

int inputInt(){
    printf("Valor>");
    return Entrada_intReturn();
}

void setView(Maquina *maq){
    char entrada[TAMANHO_ENTRADA];
    printf("Registrador");
    input(entrada);
    if(strcmp(entrada,"a") == 0){
        Maquina_setA(maq,inputInt());
    }else if(strcmp(entrada,"b") == 0){
        Maquina_setB(maq,inputInt());
    }else if(strcmp(entrada,"c") == 0){
        Maquina_setC(maq,inputInt());
    }else if(strcmp(entrada,"d") == 0){
        Maquina_setD(maq,inputInt());
    }else{
        printf("Não existe registrador nomeado como %s",entrada);
    }
}

void help(){
    printf("\nComandos disponiveis\n");
    printf("--------------------\n");
    printf("\nBasicos\n");
    printf("quit/q - Sai do programa\n");
    printf("set/s - Atribui um valor a um registrador de inteiro\n");
    printf("register/r - Exibe o valor atual de todos os registradores\n");
    printf("\nMacros\n");
    printf("a:=a+b\n");
    printf("a:=a+b,c\n");
    printf("a:=b,c\n");
    printf("a:=a*b,c&d\n");
}

void removerEspacos(char *str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}