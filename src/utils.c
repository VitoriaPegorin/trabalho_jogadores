#include "../include/utils.h"
#include "../include/types.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void limparBuffer(string str){

   *(str+strlen(str)-1) = '\0';
}

void liberar_lista_jogadores(lista_jogadores_t *lista) {
    no_t *atual = lista->cabeca;
    while (atual != NULL) {
        no_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    lista->cabeca = NULL;
    lista->nr_nos = 0;
}
/*void liberar_escalacao(jogadores_escalados_t *lista){
    jogadores_escalados_t *aux;

    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}*/
void liberar_lista_jogos(lista_jogos_t *lista){

     not_t *atual = lista->cabeca;
    while (atual != NULL) {
        not_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    lista->cabeca = NULL;
    lista->nr_nos = 0;
}

void to_upper(string str){

    for (size_t i = 0; i < strlen(str); i++){
        *(str+i) = toupper(*(str+i));
    }

}

void limpar_tela(){

    system("clear");

}
void msg_press_enter(){

    printf("\n-----------------------------------------------\n");
    printf("Pressione ENTER para retornar ao MENU RELATORIOS\n");
    getchar();

}
void msg_cabecalho(string msg){

    printf("----------------------------------------------\n");
    printf("%s\n", msg);
    printf("----------------------------------------------\n\n");

}