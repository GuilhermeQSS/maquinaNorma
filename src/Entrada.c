#include"Entrada.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Entrada_string(char *strDest, int strSize){
    if (fgets(strDest, strSize, stdin) != NULL) {
        if (strchr(strDest, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            strDest[strcspn(strDest, "\n")] = '\0';
        }
    }
}

void Entrada_int(int *value){
    char input[MAXINTCHARSIZE];
    Entrada_string(input,MAXINTCHARSIZE);
    (*value) = atoi(input);
}

int Entrada_intReturn(){
    char input[MAXINTCHARSIZE];
    Entrada_string(input,MAXINTCHARSIZE);
    return atoi(input);
}