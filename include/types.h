#ifndef TYPES_H
#define TYPES_H

#define T_STR 100

typedef char string[T_STR];

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

//Define o tipo dados jogadores
typedef struct dados_jogadores{
    string nome;
    uint8_t idade;
    uint8_t id;
    float altura;
    float peso;
    string posicao;
    float aquisicao;
    float jg_venda;
    float salario;
    string situacao;
    string status;

}dados_jog_t;

typedef struct no{
    dados_jog_t dados;
    struct no *proximo;
} no_t;

typedef struct lista_jogadores{
    no_t *cabeca;
    uint8_t nr_nos;
}lista_jogadores_t;

typedef struct jogos_realizados{
    string nome_ti;
    string data;
    string local;
    uint8_t resultado_1, resultado_2;
    string substituicao;
    uint8_t id_jogadores[3];

}jg_reali_t;

typedef struct not{
    jg_reali_t dados;
    struct not *proximo;

} not_t;

typedef struct lista_jogos{
    not_t *cabeca;
    uint8_t nr_nos;
}lista_jogos_t;



#endif