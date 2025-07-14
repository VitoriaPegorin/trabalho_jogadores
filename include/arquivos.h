#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

void salvar_registros_de_jogadores_binario(string nome_arq, no_t *lista);
void salvar_registros_de_jogos_binario(string nome_arq, not_t *lista);
void ler_registros_de_jogadores_binario(string nome_arq,lista_jogadores_t *lista);
void ler_registros_de_jogos_binario(string nome_arq, lista_jogos_t *lista);
void exportar_dados_jogadores_para_arquivo_texto(string nome_arq, no_t *lista);
void exportar_dados_jogos_para_arquivo_texto(string nome_arq, not_t *lista);
void exportar_dados_jogadores_para_arquivo_csv(string nome_arq, no_t *lista);
void exportar_dados_jogos_para_arquivo_csv(string nome_arq, not_t *lista);
void exportar_dados_jogadores_para_arquivo_html(string nome_arq, no_t *lista);
void exportar_dados_jogos_para_arquivo_html(string nome_arq, not_t *lista);

#endif