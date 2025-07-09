#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"


void checa_header(FILE* arquivo){
    char* cmp = "Fui;Ida;Volta;Data;Valor;Pago\n";
    fseek(arquivo, 0, SEEK_SET);
    char buffer[500];
    fgets(buffer, sizeof(buffer), arquivo);
    if (strcmp(buffer, cmp) != 0){
        printf("Cabeçalho não presente!\n");
        rewind(arquivo);
        //Fui Carona Data Dia Valor Pago
        fprintf(arquivo, "Fui;Ida;Volta;Data;Valor;Pago\n");
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

void exibir_menu(){
    printf("=============================================\n");
    printf("              SISTEMA DE CARONAS              \n");
    printf("=============================================\n");
    printf("1. Registrar uma carona\n");
    printf("2. Registrar várias caronas\n");
    printf("3. Editar carona\n");
    printf("4. Excluir carona\n");
    printf("5. Marcar carona como paga\n");
    printf("6. Checar histórico\n");
    printf("7. Buscar carona\n");
    printf("0. Sair\n");
    printf("=============================================\n");
    printf("Escolha uma opção: ");
}

static char* ida_volta(int opcao){
    char *nome;
    switch(opcao){
        case PEDRO:
            nome = "Pedro";
            break;
        case DUDU:
            nome = "Dudu";
            break;
        case JOAO:
            nome = "Joao";
            break;
        case PICH:
            nome = "Pich";
            break;
        case SANDRO:
            nome = "Sandro";
            break;
        default:
            nome = "Não registrado";
            break;
    }
    return nome;
}

char* ler_data(){
    char opcao;
    char *data = malloc(sizeof(char)*11);
    if (!data){
        printf("ERRO AO ALOCAR MEMORIA!\n");
        exit(1);
    }
    time_t now = time(NULL);
    struct tm *hoje = localtime(&now);
    printf("Deseja cadastrar com o dia de hoje (s/n)?\n>");
    scanf(" %c", &opcao);
    if (opcao == 'S' || opcao == 's'){
        sprintf(data, "%d/%d/%d", hoje->tm_mday, hoje->tm_mon+1, hoje->tm_year+1900);
        return data;
    }
    pegar_data data_manual;
    printf("Informe o dia da carona\n>");
    scanf("%d", &data_manual.dia);
    printf("Informe o mês da carona\n>");
    scanf("%d", &data_manual.mes);
    data_manual.ano = hoje->tm_year+1900;
    
    if (data_manual.dia > 30){data_manual.dia = 30;}
    if (data_manual.dia < 1){data_manual.dia = 1;}
    if (data_manual.mes > 12){data_manual.mes = 12;}
    if (data_manual.mes < 1){data_manual.mes = 1;}

    sprintf(data, "%d/%d/%d", data_manual.dia, data_manual.mes, data_manual.ano);
    return data;
}

carona* questoes(){
    carona *registro;
    registro = malloc(sizeof(carona));
    if (!registro){
        printf("ERRO AO REGISTRAR NOVA CARONA\n");
        exit(1);
    }
    char *buffer;
    char resposta_char[50];
    int resposta_int;
    //Fui Carona Data Dia Valor Pago
    printf("Eu fui (s/n)?\n>");
    scanf(" %s", resposta_char);
    registro->fui = (resposta_char[0] == 'S' || resposta_char[0] == 's') ? SIM : NAO;

    buffer = ler_data();
    strcpy(registro->data, buffer);
    free(buffer);
    if (!registro->fui){
        strcpy(registro->carona_ida, "-");
        strcpy(registro->carona_volta, "-");
        registro->pago = NULO;
        registro->valor = 0;
        return registro;
    }

    printf("Foi com quem?\n[1] Pedro\n[2] Dudu\n[3] Joao\n[4] Pich\n[5] Sandro\n>");
    scanf("%d", &resposta_int);
    buffer = ida_volta(resposta_int);
    strcpy(registro->carona_ida, buffer);
    printf("Voltou com a mesma pessoa (s/n)?\n>");
    scanf(" %s", resposta_char);
    if (resposta_char[0] == 'S' || resposta_char[0] == 's'){
        strcpy(registro->carona_volta, buffer);
    }
    else{
        printf("Voltou com quem?\n[1] Pedro\n[2] Dudu\n[3] Joao\n[4] Pich\n[5] Sandro\n>");
        scanf("%d", &resposta_int);
        buffer = ida_volta(resposta_int);
        strcpy(registro->carona_volta, buffer);
    }
    registro->pago = NAO;
    registro->valor = 5;
    return registro;
}