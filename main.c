#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"

/*
Projeto carona
*/

int main(){
    FILE* arquivo = abre_arquivo();
    checa_header(arquivo);
    carona teste;
    struct tm *tempo;
    time_t now;
    now = time(NULL);
    printf("%ld\n", now);
    char* formated_time = ctime(&now);
    printf("%s\n", formated_time);

    tempo = localtime(&now);
    printf("Dia: %d\nMes: %d\nAno: %d", tempo->tm_mday, tempo->tm_mon, tempo->tm_year+1900);
}