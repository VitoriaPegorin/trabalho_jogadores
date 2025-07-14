#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"

void relatorio_completo_de_jogadores(lista_jogadores_t *lista);
void relatorio_de_jogadores_por_faixa_etaria(lista_jogadores_t *lista);
void relatorio_do_resultado_das_partidas(lista_jogos_t *lista);
void relatorio_de_confronto_com_times_adversarios(lista_jogos_t *lista);
void relatorio_de_todos_os_jogadores_vendidos(lista_jogadores_t *lista);
void relatorio_do_valor_do_time(lista_jogadores_t *lista);
void relatorio_do_aproveitamento_do_time(lista_jogos_t *lista);

#endif