#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void checa_header(FILE* arquivo){
    char* cmp = "Fui;Carona;Data;Dia;Valor;Pago";
    fseek(arquivo, 0, SEEK_SET);
    char buffer[500];
    fgets(buffer, sizeof(buffer), arquivo);
    if (strcmp(buffer, cmp) != 0){
        printf("Cabeçalho não presente!\n");
        rewind(arquivo);
        //Fui Carona Data Dia Valor Pago
        fprintf(arquivo, "Fui;Carona;Data;Dia;Valor;Pago");
        printf("Cabeçalho preenchido!\n");
        return;
    }
    printf("Cabeçalho presente!\n");
    return;
}

FILE* abre_arquivo(){
    FILE *arquivo = fopen("database.csv", "r+");
    if (!arquivo){
        arquivo = fopen("database.csv", "w+");
        printf("Arquivo DATABASE criado com sucesso!\n");
        arquivo = freopen("database.csv", "r+", arquivo);
    }

    if (arquivo){
        printf("Arquivo aberto com sucesso!\n");
        return arquivo;
    }
    else{
        printf("Falha na abertura do arquivo!\n");
        exit(1);
    }
}