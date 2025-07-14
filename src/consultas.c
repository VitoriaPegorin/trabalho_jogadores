#include "../include/consultas.h"
#include "../include/cadastros.h"
#include "../include/types.h"

no_t *localizar_jogador_por_nome(string nome, lista_jogadores_t *lista){

    if(lista_jogadores_vazia(lista))return NULL;

    no_t *aux = lista->cabeca;

    while(aux != NULL){
        if(strcmp(aux->dados.nome, nome) == 0){
            mostrar_dados_jogadores(aux);
            printf("\n");
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;

}
no_t *localizar_jogador_por_posicao(string posicao, lista_jogadores_t *lista){

    if(lista_jogadores_vazia(lista))return NULL;

       no_t *aux = lista->cabeca;

    while(aux != NULL){
        if(strcmp(aux->dados.posicao,posicao) == 0){
            mostrar_dados_jogadores(aux);
            printf("\n");
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;

}
not_t *localizar_jogos_realizados_pelo_nome_do_time_adversarios(string nome_ti, lista_jogos_t *lista){

    if(lista_jogos_vazia(lista))return NULL;

    not_t *aux = lista->cabeca;

    while(aux != NULL){
        if(strcmp(aux->dados.nome_ti, nome_ti) == 0){
            mostrar_dados_jogos(aux);
            printf("\n");
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;

}
no_t *localizar_jogador_com_maior_salario(lista_jogadores_t *lista){

     if(lista_jogadores_vazia(lista))return NULL;

        no_t *aux = lista->cabeca; 
        no_t *maior = aux;
    
        while(aux != NULL){
              if(aux->dados.salario > maior->dados.salario){
                maior = aux ;
            }    
            aux = aux->proximo;                                 
        }

        mostrar_dados_jogadores(maior);
        return maior;

}
void localizar_jogador_por_faixa_salarial(lista_jogadores_t*lista){

    if(lista_jogadores_vazia(lista))return;

     no_t *aux = lista->cabeca; 

        float min = 0, max = 0;
        bool encontrou = false;

            printf("Digite o menor salario e o maior salario\n");
            scanf("%f %f", &min, &max);
       
        while(aux != NULL){
            if(aux->dados.salario >= min && aux->dados.salario <= max){
                printf("Nome:=========%s\n", aux->dados.nome);
                printf("Salário:======%.2f\n\n", aux->dados.salario);
                encontrou = true;
            }
            aux = aux->proximo;

        }   

        if (!encontrou){
            printf("Nenhum jogador encontrado na faixa salarial de %.2f a %.2f\n", min, max);
        }

}

no_t *localizar_id_do_jogador(uint8_t id, lista_jogadores_t *lista){


     if(lista_jogadores_vazia(lista)){
        return NULL;
    }

    no_t *aux = lista->cabeca; 

    while(aux != NULL){
        if(aux->dados.id == id){
            return aux;
        } 

       aux = aux->proximo;
    }

       return NULL;

}
no_t *localizar_ultimo_registro_jogadores(no_t *ptr_lista){

    while (ptr_lista->proximo) {
        ptr_lista = ptr_lista->proximo;
    }
    
    return ptr_lista;

}
not_t *localizar_ultimo_registro_jogos(not_t *ptr_lista){

    while (ptr_lista->proximo) {
        ptr_lista = ptr_lista->proximo;
    }
    
    return ptr_lista;

}