#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* L, No* no){
    if(L != NULL){
        if(L->proximo_no == NULL){
            L->proximo_no = no;
        }
        else{
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L){
    if(L != NULL){
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L){
    if(L != NULL){
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L) {
    if (L == NULL) {
        return NULL; // Retorna uma lista vazia
    }

    No* copia = no(L->valor, NULL); // Cria o primeiro nó da cópia
    No* atual = copia;
    L = L->proximo_no; // Avança o ponteiro da lista original

    while (L != NULL) {
        atual->proximo_no = no(L->valor, NULL); // Cria um novo nó na cópia
        L = L->proximo_no; // Avança na lista original
        atual = atual->proximo_no; // Avança na lista de cópia
    }

    return copia;
}


void lista_concatenar(No* L, No* Lc){
    lista_inserir_no(L, Lc);
}

void lista_liberar(No* L){
    if(L != NULL){
        lista_liberar(L->proximo_no);
        free(L);
    }
}

int lista_verificar_existencia(No* L, char valor_busca) {
    if (L == NULL) {
        return 0; 
    }

    if (L->valor == valor_busca) {
        return 1; 
    }

    return lista_verificar_existencia(L->proximo_no, valor_busca);
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    if (L == NULL) {
        return 0; 
    }

    int ocorrencias = 0;
    if (L->valor == valor_busca) {
        ocorrencias = 1; 
    }

    return ocorrencias + lista_verificar_ocorrencias(L->proximo_no, valor_busca);
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }

    lista_imprimir_inversa(L->proximo_no);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No* L, int i) {
    if (i < 0) {
        return; 
    }

    if (i == 0) {
        No* novo_no = no('N', L->proximo_no);
        L->proximo_no = novo_no;
    } else {
        lista_inserir_no_i(L->proximo_no, i - 1);
    }
}

void lista_remover_no_i(No* L, int i) {
    if (L == NULL || L->proximo_no == NULL) {
        return;
    }

    if (i == 0) {
        No* no_a_remover = L->proximo_no;
        L->proximo_no = no_a_remover->proximo_no;
        free(no_a_remover);
    } else {
        lista_remover_no_i(L->proximo_no, i - 1);
    }
}

void lista_remover_no(No* L, char valor_busca) {
    if (L == NULL) {
        return;
    }

    if (L->proximo_no != NULL && L->proximo_no->valor == valor_busca) {
        No* no_a_remover = L->proximo_no;
        L->proximo_no = no_a_remover->proximo_no;
        free(no_a_remover);
        lista_remover_no(L, valor_busca);
    } else {
        lista_remover_no(L->proximo_no, valor_busca);
    }
}