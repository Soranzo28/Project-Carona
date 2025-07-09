#ifndef MENU_H
#define MENU_H

#include <stdio.h>

typedef enum {SEG, TER, QUA, QUI, SEX} dias_semana;
typedef enum{NAO, SIM, NULO} status;
typedef enum{REGISTRAR_1 = 1, REGISTRAR_N, EDITAR, EXCLUIR, PAGAR, HISTORICO, HISTORICO_GERAL, HISTORICO_FILTRADO, BUSCAR} opcoes;
typedef enum{PEDRO=1, DUDU, JOAO, PICH, SANDRO} caroneiro;

typedef struct{
    status fui;
    char carona_ida[50];
    char carona_volta[50];
    char data[11];
    float valor;
    status pago;
} carona;

typedef struct{
    int dia;
    int mes;
    int ano;
} pegar_data;

void checa_header(FILE* arquivo);
void exibir_menu();
carona* questoes();
void registra_1(FILE* arquivo);
FILE* abre_arquivo();
char* ler_data();

#endif