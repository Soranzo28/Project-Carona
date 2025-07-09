#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"

/*
Projeto carona

Registrar uma carona
Registrar varias caronas
Editar carona
Excluir carona
Marcar carona como paga
Checar historico -> Historico Geral / Historico filtrado
Buscar

Fui Ida Volta Data Valor Pago
*/



int main(){
    FILE* arquivo = abre_arquivo();
    checa_header(arquivo);
    carona *registro;
    int opcao;
    exibir_menu();
    scanf("%d", &opcao);
    switch(opcao){
        case REGISTRAR_1:
            registro = questoes();
            fseek(arquivo, 0, SEEK_END);
            fprintf(arquivo, "%s;%s;%s;%s;%.2f;%s\n", registro->fui? "Sim" : "Nao", registro->carona_ida, registro->carona_volta, registro->data, registro->valor, (registro->pago == NAO) ? "Nao" : "-");
            fflush(arquivo);
            break;

        case REGISTRAR_N:
            break;

        case EDITAR:
            break;

        case EXCLUIR:
            break;

        case PAGAR:
            break;

        case HISTORICO:
            break;

        case BUSCAR:
            break;
        
        default:
            printf("Comando não encontrado!\n");
            break;
    }
    fclose(arquivo);
}