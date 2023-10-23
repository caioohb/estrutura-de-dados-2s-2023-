#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <time.h>

int main(int argc, char* argv[]) {
    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    FILE* arquivo = fopen("1kk_rand_float.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[50];
    float numero;

    clock_t inicio, fim;
    double tempo_nao_ordenado, tempo_ordenado;
    int cont = 0;

    inicio = clock();

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numero = strtof(linha, NULL);

        No* novo_no = no(numero, NULL);

        lista_inserir_no(&lista_nao_ordenada, novo_no);
        lista_inserir_no_ordenado(&lista_ordenada, novo_no);

        cont++;
    }

    fim = clock();

    tempo_nao_ordenado = (double)(fim - inicio) / CLOCKS_PER_SEC;

    rewind(arquivo);
    cont = 0;

    inicio = clock();

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        numero = strtof(linha, NULL);

        No* novo_no = no(numero, NULL);

        lista_inserir_no_ordenado(&lista_ordenada, novo_no);

        cont++;
    }

    fim = clock();

    tempo_ordenado = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo medio de insercao (nao ordenada): %.6f segundos\n", tempo_nao_ordenado / cont);
    printf("Tempo medio de insercao (ordenada): %.6f segundos\n", tempo_ordenado / cont);

    fclose(arquivo);

    lista_liberar(lista_nao_ordenada);
    lista_liberar(lista_ordenada);

    return 0;
}