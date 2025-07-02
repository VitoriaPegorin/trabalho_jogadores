#ifndef CONSULTAS_H
#define CONSTULTAS_H


dados_jog_t *localizar_jogador_por_nome(string nome, dados_jog_t *lista);
dados_jog_t *localizar_jogador_por_posicao(string posicao, dados_jog_t *lista);
jg_reali_t *localizar_jogos_realizados_pelo_nome_do_time_adversarios(string nome_ti, jg_reali_t *lista);
dados_jog_t *localizar_jogador_com_maior_salario(dados_jog_t *lista);
void localizar_jogador_por_faixa_salarial(dados_jog_t *lista);
dados_jog_t *localizar_id_do_jogador(unin_t id, dados_jog_t *lista);

#endif