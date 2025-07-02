#include "../include/cadastro.h"


dados_jog_t *cadastrar_jogadores(dados_jog_t *lista){

    dados_jog_t *aux;

    aux = (dados_jog_t*)malloc(sizeof(dados_jog_t));

    if(!aux){

        printf("Não foi possível alocar dinamiamente'\n");
        return lista;
    }

        printf("Qual o nome do jogador?\n");
        fgets(aux->nome,T_STR, stdin);
        limparBuffer(aux->nome);

        printf("Qual o ID do jogador\n");
        scanf("%d", &aux->id);

        printf("Qual a idade do jogador?\n");
        scanf("%d", &aux->idade); 
            
        printf("Qual a altura do jogador?\n");
        scanf("%f", &aux->altura);

        printf("Qual o peso do jogador?\n");
        scanf("%f", &aux->peso);

        printf("Qual o valor de aquisição do jogador?\n");
        scanf("%f", &aux->aquisicao);

        printf("Qual o valor de venda do jogador?\n");
        scanf("%f", &aux->jg_venda);

        printf("Qual o salário do jogador?\n");
        scanf("%f", &aux->salario);

        printf("Qual a posicao do jogador?\n");
        fgets(aux->posicao, T_STR, stdin);
        limparBuffer(aux->posicao);

        strcpy(aux->situacao, "ativo");

        aux->proximo = lista;
        lista = aux;
            

    printf("\nJogador cadstrado com sucesso!\n");

            
   return lista;

}
dados_jog_t *escalar_jogadores(dados_jog_t *lista_jogadores){

    unin_t id;
    dados_jog_t *escalados = NULL;
    dados_jog_t *ultimo = NULL;
    dados_jog_t aux;

    while(1){
        printf("Digite o ID do jogador que deseja escalar, (ou -1 da encerrar)\n");
        scanf("%d", &id);

        if(id == -1) break;

        dados_jog_t *jogador = buscar_id_do_jogador(id, lista_jogadores);

        if(!jogador){
           printf("Jogador não encontrado!!\n");
            return;
        }

        aux = (dados_jog_t*)malloc(sizeof(dados_jog_t));

        if(!aux){
            printf("Erro ao alocar dinamicamente\n");
            break;
        }

        *aux = *jogador;
        aux ->proximo = NULL;


        if(escalados == NULL){
            escalados = aux;
        } else {
            ultimo ->proximo = aux;
        }  

        ultimo = aux;

    }

    if(escalados == NULL){
        printf("nenhum jogador escalado\n");
    }

    return escalados;

    //if (strcmp(aux->status, "ativo") == 0)
    // Pode escalar

}
jg_reali_t *cadastrar_jogos(dados_jog_t *lista_jogadores){
    jg_reali_t *aux;

     aux = (jg_reali_t*)malloc(sizeof(jg_reali_t));

    if(!aux){

        printf("Não foi possível alocar dinamiamente'\n");
        return NULL;
    }

        printf("Antes de cadastrar o jogo eh necessário escalar jogadores.\n");
        aux->escalados = escalar_jogadores(lista_jogadores);

    if(escaldos == NULL){
       printf("Partida não registrada nenhum jogador foi escalado.\n");
       return NULL;
    }


        printf("Qual o nome do time adversário?\n");
        fgets (aux->nome_ti, T_STR, stdin);
        limparBuffer(aux->nome_ti);
            
        printf("Qual foi a data do jogo?\n");
        fgets(aux->data,T_STR,stdin);
        limparBuffer(aux->data);
            
        printf("Qual foi o local do jogo?\n");
        fgets(aux->local,T_STR, stdin);
        limparBuffer(aux->local);

        printf("Qual foi o resultado da partida(Time e time adversário)?\n");
        scanf("%d", &aux->resultado_1);
        scanf("%d", &aux->resultado_2);
    
        printf("Quantas substituições foram realizadas?\n");
        fgets(aux->substituicao,T_STR, stdin);
        limparBuffer(aux->substituicao);


        aux->proximo_2 = NULL;

    return lista_jogadores;

    //verificar funcao
}
bool lista_vazia(dados_jog_t *lista){

    if(lista == NULL){
        return true;
    }

    return false;

}
void printf_jogadores(dados_jog_t *aux){

    printf("------------------------------------------\n");
    printf("Nome:-----------------------%s\n", aux->nome);
    printf("Idade:----------------------%d\n", aux->idade);
    printf("ID:-------------------------%d\n", aux->id);
    printf("Altura:---------------------%.2f\n", aux->altura);
    printf("Peso:-----------------------%.2f\n", aux->peso);
    printf("Posição:--------------------%s\n", aux->posicao);
    printf("Venda:----------------------%.2f\n", aux->jg_venda);
    printf("Aquisição:------------------%.2f\n",aux->aquisicao);
    printf("Salário:--------------------%.2f\n",aux->salario);
    printf("Situação:-------------------%s\n",aux->situacao);

}
void printf_jogos(jg_reali_t *aux){

    printf("---------------------------------------------\n");
    printf("Time adversário:--------------%s\n",aux->nome_ti);
    printf("Data:-------------------------%s\n", aux->data);                                                                
    printf("Local:------------------------%s\n", aux->local);
    printf("Resultado:--------------------%d\n", aux->resultado_1);
    printf("Resultado do adversário:------%d\n", aux->resultado_2);
    printf("Subustituições:---------------%s\n",aux->substituicao);

}
