#include "../include/relatorios.h"
#include "../include/cadastros.h"
#include "../include/utils.h"

void relatorio_completo_de_jogadores(lista_jogadores_t *lista){

     if (lista_jogadores_vazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }

    no_t *aux = lista->cabeca;

    printf("RELATORIO JOGADORES\n");

    while (aux != NULL) {
        mostrar_dados_jogadores(aux);
        printf("\n");   
        aux = aux->proximo;
    }
}
void relatorio_de_jogadores_por_faixa_etaria(lista_jogadores_t *lista){

    uint8_t idade_max = 0, idade_min = 0;

    printf("Digite a idade minima e a idade maxima\n");
    scanf("%hhi", &idade_min);
    scanf("%hhi", &idade_max);

    for(no_t *aux = lista->cabeca; aux != NULL; aux = aux->proximo){
        if(aux->dados.idade >= idade_min && aux->dados.idade <= idade_max){
           mostrar_dados_jogadores(aux);
                                      
        }
        printf("\n"); 
    }

}
void relatorio_do_resultado_das_partidas(lista_jogos_t *lista){

    if (lista_jogos_vazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }

         printf("RELATORIO DE JOGOS\n");

    for(not_t *aux = lista->cabeca; aux != NULL; aux = aux->proximo){
        mostrar_dados_jogos(aux);
        printf("Jogadores escalados (IDs)\n\n: ");
        for (int i = 0; i < 11; i++) {
            if (aux->dados.id_jogadores[i] != 0) {  // verifica se o ID é válido
                printf("%hhi ", aux->dados.id_jogadores[i]);
            }
        }    
        printf("\n"); 
    }   
}
void relatorio_de_confronto_com_times_adversarios(lista_jogos_t * lista){

    string nome_ti;      
    bool encontrou = false;   
    uint8_t qtd = 0;                     
             
    getchar();
    printf("Qual o nome do time adversario?\n");
    fgets(nome_ti,T_STR,stdin);
    limparBuffer(nome_ti);
    to_upper(nome_ti);
                                                                                                    
    for(not_t *aux = lista->cabeca; aux != NULL; aux = aux->proximo){                        
        if(strcmp(nome_ti, aux->dados.nome_ti)== 0){                                
           encontrou = true;
            qtd++;
        }                                                                                             
    }              
        if(encontrou){
            printf("O time jogou contra %s\n o total de %d\n\n",nome_ti,qtd);

        }             
        if(!encontrou){
        
            printf("Sem confronto com %s\n\n",nome_ti);
        }


}
void relatorio_de_todos_os_jogadores_vendidos(lista_jogadores_t *lista){

    bool encontrou = false;

            printf("RELATORIO DE JOGADORES VENDIDOS\n");
    for(no_t *aux = lista->cabeca; aux != NULL; aux = aux->proximo){
        if(strcmp(aux->dados.situacao,"VENDIDO") == 0){
            encontrou = true;  
            mostrar_dados_jogadores(aux);
        }   
        printf("\n");                                                                                                                       
    }
        
        if(!encontrou){
          printf("Não tem jogadores vendidos\n\n");
        }

}
void relatorio_do_valor_do_time(lista_jogadores_t *lista){

    float total_venda = 0;

    for(no_t *aux = lista->cabeca; aux != NULL; aux = aux->proximo){
        if(strcmp(aux->dados.status, "ATIVO") == 0){
            total_venda += aux->dados.jg_venda;
        }
                            
    }                     
        printf("\n====== RELATORIO: VALOR DE VENDA DO TIME ======\n");
        printf("O valor do time eh %.2f\n", total_venda);
        printf("==============================================\n\n");


}
void relatorio_do_aproveitamento_do_time(lista_jogos_t *lista){

    uint8_t vitorias = 0, derrotas = 0; 

    for(not_t *aux = lista->cabeca; aux != NULL; aux = aux->proximo){
        if(aux->dados.resultado_1 > aux->dados.resultado_2){
            vitorias+=1;
        }
        else if(aux->dados.resultado_2 > aux->dados.resultado_1){
                derrotas+=1;
        }
    }

    printf("\n====== RELATORIO: APROVEITAMENTO DO TIME ======\n");
    printf("Partidas ganhas %d\n", vitorias);
    printf("Partidas perdidas %d\n", derrotas);
    printf("==============================================\n\n");

}