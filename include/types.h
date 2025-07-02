#ifndef TYPES_H
#define TYPES_H

#define T_STR 100

typedef char string[T_STR];

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//Define o tipo dados jogadores
typedef struct dados_jogadores{
    string nome;
    unint_t id;
    unint_t idade;
    float altura;
    float peso;
    string posicao;
    float aquisicao;
    float jg_venda;
    float salario;
    string situacao;

}dados_jog_t;

typedef struct no{
    dados_jog_t dados;
    dados_jog_t *proximo;

} no_t;

typedef struct lista {
    no_t *cabeca;
    uint8_t nr_nos;
} lista_jogadores_t;

typedef struct jogadores_escalados{
    dados_jog_t *jogador;
    struct jogadores_escalados *prox;

}jogadores_escalado_t;


typedef struct jogos_realizados{
    string nome_ti;
    string data;
    string local;
    unint_t resultado_1, resultado_2;
    string substituicao;
    jogadores_escalado_t *time_escalado;

}jg_reali_t;

typedef struct not{
    jg_reali_t dados;
    jg_reali_t *proximo_2;

} not_t;

typedef struct lista {
    not_t *cabeca;
    uint8_t nr_nos;
} lista_jogos_t;



#endif