#ifndef CONSULTAS_H
#define CONSTULTAS_H

#include "types.h"

no_t *localizar_jogador_por_nome(string nome, lista_jogadores_t *lista);
no_t *localizar_jogador_por_posicao(string posicao, lista_jogadores_t *lista);
not_t *localizar_jogos_realizados_pelo_nome_do_time_adversarios(string nome_ti, lista_jogos_t *lista);
no_t *localizar_jogador_com_maior_salario(lista_jogadores_t *lista);
void localizar_jogador_por_faixa_salarial(lista_jogadores_t *lista);
no_t *localizar_id_do_jogador(uint8_t id, lista_jogadores_t *lista);
no_t *localizar_ultimo_registro_jogadores(no_t *ptr_lista);
not_t *localizar_ultimo_registro_jogos(not_t *ptr_lista);

#endif