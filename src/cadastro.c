#include "../include/cadastro.h"
#include "../include/consultas.h"
#include "../include/utils.h"

void inicializa_lista_jogadores(lista_jogadores_t *lista){


    lista->cabeca = NULL;
    lista->nr_nos = 0;

}
void inicializa_lista_jogos(lista_jogos_t *lista){


    lista->cabeca = NULL;
    lista->nr_nos = 0;

}
uint8_t gerar_ID_unico(lista_jogadores_t *lista){

    uint8_t id_novo;
    bool existe;

    do{
        
        id_novo = rand() % 9000 + 1000;
         existe = false;

       no_t *aux = lista->cabeca; // percorre a lista
        while (aux != NULL) {
            if (aux->dados.id == id_novo) {
                existe = true;
                break;
            }
            aux = aux->proximo;
        }
    } while (existe);

    return id_novo;
}

no_t *cadastrar_jogadores(lista_jogadores_t *lista){

    no_t *aux;

    aux = (no_t*)malloc(sizeof(no_t));

    if(!aux){

        printf("Não foi possível alocar dinamiamente'\n");
        return NULL;
    }
        //Nome
        getchar();
        printf("Qual o nome do jogador?\n");
        fgets(aux->dados.nome,T_STR, stdin);
        limparBuffer(aux->dados.nome);
        to_upper(aux->dados.nome);
       
        //Gera ID único
        aux->dados.id = gerar_ID_unico(lista); 

        //Idade
        printf("Qual a idade do jogador?\n");
        scanf("%hhi", &aux->dados.idade); 
           
        //Altura
        printf("Qual a altura do jogador?\n");
        scanf("%f", &aux->dados.altura);

        printf("Qual o peso do jogador?\n");
        scanf("%f", &aux->dados.peso);

        printf("Qual o valor de aquisição do jogador?\n");
        scanf("%f", &aux->dados.aquisicao);

        printf("Qual o valor de venda do jogador?\n");
        scanf("%f", &aux->dados.jg_venda);

        printf("Qual o salário do jogador?\n");
        scanf("%f", &aux->dados.salario);

        getchar();
        printf("Qual a posicao do jogador?\n");
        fgets(aux->dados.posicao, T_STR, stdin);
        limparBuffer(aux->dados.posicao);
        to_upper(aux->dados.posicao);

        strcpy(aux->dados.status, "ATIVO");

        strcpy(aux->dados.situacao, "JOGANDO");

        aux->proximo = NULL;
            

    printf("\nJogador cadstrado com sucesso!\n");

            
   return aux;

}
jogadores_escalados_t *escalar_jogadores(lista_jogadores_t *lista){

    uint8_t id, qtd = 0;
    char opc;
    jogadores_escalados_t *escalados = NULL;
    jogadores_escalados_t *ultimo = NULL;
    
        do{

            printf("Digite o id do jogador para localizar\n");
            scanf("%hhi", &id);

             no_t *aux = localizar_id_do_jogador(id, lista);

            if(!aux){
            printf("Jogador não encontrado!!\n");
                return NULL;

            }

            jogadores_escalados_t *novo = malloc(sizeof(jogadores_escalados_t));

                if(!novo){
                    printf("Erro ao alocar dinamicamente\n");
                return NULL;
                }

                novo->jogador = aux;
                novo->prox = NULL;

                if(escalados == NULL){
                    escalados = novo;
                } else {
                    ultimo ->prox = novo;
                }  

                ultimo = novo;
                qtd ++;

                printf("Jogador escalado com sucesso\n");

            if(qtd >= 11){
                printf("Deseja escalar mais jogadores(S/N):\n");
                scanf("%c", &opc);

                if (opc != 'S' && opc != 's') break;

            }    

    

    } while(qtd < 11 || (opc == 'S' || opc == 's'));

  
    if (qtd < 11) {
        printf("\nNúmero insuficiente de jogadores escalados. Operação cancelada.\n");
        return NULL;
    }

    printf("\nEscalação concluída com %hhi jogadores!\n", qtd);

    return escalados;

}

not_t *cadastrar_jogos(lista_jogos_t *lista, lista_jogadores_t *lista_jogadores){

    not_t *aux = lista->cabeca;

     aux = (not_t*)malloc(sizeof(not_t));

    if(!aux){

        printf("Não foi possível alocar dinamiamente'\n");
        return NULL;
    }

        printf("Antes de cadastrar o jogo eh necessário escalar jogadores.\n");
        //aux->dados.time_escalado = escalar_jogadores(lista_jogadores);

    if(aux->dados.time_escalado == NULL){
       printf("Partida não registrada nenhum jogador foi escalado.\n");
       free(aux);
       return NULL;
    }

    getchar();
        printf("Qual o nome do time adversário?\n");
        fgets (aux->dados.nome_ti, T_STR, stdin);
        limparBuffer(aux->dados.nome_ti);
        to_upper(aux->dados.nome_ti);
            
        printf("Qual foi a data do jogo?\n");
        fgets(aux->dados.data,T_STR,stdin);
        limparBuffer(aux->dados.data);
        to_upper(aux->dados.data);
            
        printf("Qual foi o local do jogo?\n");
        fgets(aux->dados.local,T_STR, stdin);
        limparBuffer(aux->dados.local);
        to_upper(aux->dados.local);

        printf("Qual foi o resultado da partida(Time e time adversário)?\n");
        scanf("%hhi", &aux->dados.resultado_1);
        scanf("%hhi", &aux->dados.resultado_2);
    
        printf("Quantas substituições foram realizadas?\n");
        fgets(aux->dados.substituicao,T_STR, stdin);
        limparBuffer(aux->dados.substituicao);
        to_upper(aux->dados.substituicao);


        aux->proximo = NULL;

        printf("Partida registrada com sucesso\n");

    return aux;


}
 bool lista_vazia(lista_jogadores_t*lista){

    if (lista->cabeca) return false;  // Lista não vazia
    
    return true; // Lista vazia
}

bool lista_jogos_vazia(lista_jogos_t *lista) {

    if (lista->cabeca) return false;  // Lista não vazia
    
    return true; // Lista vazia

}

void mostrar_dados_jogadores(no_t *aux){

    

        printf("------------------------------------------\n");
        printf("Nome:-----------------------%s\n", aux->dados.nome);
        printf("Idade:----------------------%d\n", aux->dados.idade);
        printf("ID:-------------------------%d\n", aux->dados.id);
        printf("Altura:---------------------%.2f\n", aux->dados.altura);
        printf("Peso:-----------------------%.2f\n", aux->dados.peso);
        printf("Posição:--------------------%s\n", aux->dados.posicao);
        printf("Venda:----------------------%.2f\n", aux->dados.jg_venda);
        printf("Aquisição:------------------%.2f\n",aux->dados.aquisicao);
        printf("Salário:--------------------%.2f\n",aux->dados.salario);
        printf("Status:-------------------%s\n",aux->dados.status);
        printf("Situação:-------------------%s\n",aux->dados.situacao);

        



}
void mostrar_dados_jogos(not_t *lista){

    not_t *aux = lista;

    while(aux != NULL){
        printf("---------------------------------------------\n");
        printf("Time adversário:--------------%s\n",aux->dados.nome_ti);
        printf("Data:-------------------------%s\n", aux->dados.data);                                                                
        printf("Local:------------------------%s\n", aux->dados.local);
        printf("Resultado:--------------------%d\n", aux->dados.resultado_1);
        printf("Resultado do adversário:------%d\n", aux->dados.resultado_2);
        printf("Subustituições:---------------%s\n",aux->dados.substituicao);

        aux = aux->proximo;

    }

    
}

void editar_venda_e_valor_de_venda_jogador(lista_jogadores_t *lista){

    uint8_t id;
    uint8_t novo_valor;
    string nova_situacao;
    bool encontrou = false;
    no_t *aux = lista->cabeca;
    no_t *jogador_alvo = NULL;

    printf("Digite o ID do jogador:\n");
    scanf("%hhi",&id);
    getchar();
    
    while(aux != NULL){
        if(aux->dados.id == id){
            jogador_alvo = aux;
            encontrou = true;

            printf("Situação atual %s\n",aux->dados.situacao);
            
            printf("Digite uma nova situação(JOGANDO,VENDIDO,MACHUCADO)\n");
            fgets(nova_situacao,T_STR, stdin);
            limparBuffer(nova_situacao);
            to_upper(nova_situacao);

            strcpy(jogador_alvo->dados.situacao, nova_situacao);  

            if (strcmp(nova_situacao, "JOGANDO") == 0) {
                strcpy(jogador_alvo->dados.status, "ATIVO");
            } else if (strcmp(nova_situacao, "VENDIDO") == 0 || strcmp(nova_situacao, "MACHUCADO") == 0) {
                strcpy(jogador_alvo->dados.status, "INATIVO");
            }

            break;
        }

        aux = aux->proximo;
    }

     if(!encontrou){
       printf("ID não localizado\n");
    }

    if(strcmp(nova_situacao, "VENDIDO") == 0){
        printf("Qual o valor que o jogador foi vendido?\n");
        scanf("%hhi", &novo_valor);
        jogador_alvo->dados.jg_venda = novo_valor;

        printf("Situacao atualizada com sucesso!");
  
    }

}

void insere_registro_inicio_jogadores(no_t *novo, lista_jogadores_t *lista){

   if (lista == NULL || novo == NULL) return;

    novo->proximo = lista->cabeca;  // o novo nó aponta para o antigo primeiro nó
    lista->cabeca = novo;           // o novo nó agora é o primeiro
    lista->nr_nos++;  

}
void insere_registro_inicio_jogos(not_t *novo, lista_jogos_t *lista){

   
   if (lista == NULL || novo == NULL) return;

    novo->proximo = lista->cabeca;  // o novo nó aponta para o antigo primeiro nó
    lista->cabeca = novo;           // o novo nó agora é o primeiro
    lista->nr_nos++;  

}