#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia);
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);
    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);
 //------------------------------------------------------------------------------
    printf("\nVerifica a existencia de 'E': %d", lista_verificar_existencia(n0, 'E'));
    printf("\nOcorrencias de 'C': %d", lista_verificar_ocorrencias(n0, 'C'));

    printf("\nLista inversa: ");
    fflush(stdout);
    lista_imprimir_inversa(n0);

    printf("\nInserir 'N' na posicao 3:\n");
    fflush(stdout);
    lista_inserir_no_i(n0, 3);
    lista_imprimir(n0);

    printf("\nRemover no na posicao 2:\n");
    lista_remover_no_i(n0, 2);
    lista_imprimir(n0);

    printf("\nRemover ocorrencias de 'C':\n");
    lista_remover_no(n0, 'C');
    lista_imprimir(n0);

    lista_liberar(n0);
    n0 = NULL;
}