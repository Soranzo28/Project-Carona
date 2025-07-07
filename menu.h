#ifndef MENU_H
#define MENU_H

#include <stdio.h>

void checa_header(FILE* arquivo);
FILE* abre_arquivo();

typedef enum {SEG, TER, QUA, QUI, SEX} dias_semana;
typedef enum{NAO, SIM} status;

typedef struct{
    int dia,mes,ano;
} data;

typedef struct{
    status fui;
    char carona[50];
    data dia;
    float valor;
    status pago;
} carona;


#endif