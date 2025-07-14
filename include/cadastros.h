#ifndef CADASTROS_H
#define CADASTROS_H

#include "types.h"
void inicializa_lista_jogadores(lista_jogadores_t *lista);
void inicializa_lista_jogos(lista_jogos_t *lista);
uint8_t gerar_ID_unico(lista_jogadores_t *lista);
no_t *cadastrar_jogadores(lista_jogadores_t *lista);
void escalar_jogadores(uint8_t *id_jogadores,lista_jogadores_t *lista);
not_t *cadastrar_jogos(lista_jogos_t *lista, lista_jogadores_t *lista_jogadores);
bool lista_jogadores_vazia(lista_jogadores_t *lista);
bool lista_jogos_vazia(lista_jogos_t *lista);
void mostrar_dados_jogadores(no_t *aux);
void mostrar_dados_jogos(not_t *aux);
void editar_venda_e_valor_de_venda_jogador(lista_jogadores_t *lista);
void insere_registro_inicio_jogadores(no_t *novo, lista_jogadores_t *lista);
void insere_registro_inicio_jogos(not_t *novo, lista_jogos_t *lista);


#endif