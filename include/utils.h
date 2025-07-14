#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "types.h"

void limparBuffer(string str);
void liberar_lista_jogadores(lista_jogadores_t *lista);
//void liberar_escalacao(jogadores_escalados_t *lista);
void liberar_lista_jogos(lista_jogos_t *lista);
void to_upper(string str);
void limpar_tela();
void msg_press_enter();
void msg_cabecalho(string msg);
void ordenar_em_ordem_alfabetica();//lista_t * lista_rh);


#endif