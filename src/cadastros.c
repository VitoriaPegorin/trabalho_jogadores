#include "../include/cadastros.h"
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

       no_t *aux = lista->cabeca; 
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

        //Peso
        printf("Qual o peso do jogador?\n");
        scanf("%f", &aux->dados.peso);

        //Aquisicao
        printf("Qual o valor de aquisição do jogador?\n");
        scanf("%f", &aux->dados.aquisicao);

        //valor de venda
        printf("Qual o valor de venda do jogador?\n");
        scanf("%f", &aux->dados.jg_venda);

        //salario
        printf("Qual o salário do jogador?\n");
        scanf("%f", &aux->dados.salario);

        //posicao
        getchar();
        printf("Qual a posicao do jogador?\n");
        fgets(aux->dados.posicao, T_STR, stdin);
        limparBuffer(aux->dados.posicao);
        to_upper(aux->dados.posicao);

        //status
        strcpy(aux->dados.status, "ATIVO");

        //situacao
        strcpy(aux->dados.situacao, "JOGANDO");

        aux->proximo = NULL;
            

    printf("\nJogador cadstrado com sucesso!\n\n");

            
   return aux;

}

void escalar_jogadores(uint8_t *id_jogadores,lista_jogadores_t *lista){

    uint8_t id = 0, qtd = 0;
    no_t *aux = NULL;
    
        while(lista != NULL){

            do{
                printf("Digite o id do jogador para localizar\n");
                scanf("%hhi", &id);
                getchar();

                aux = localizar_id_do_jogador(id, lista);

                if(aux != NULL && strcmp(aux->dados.status, "ATIVO") == 0){
                    id_jogadores[qtd++] = aux->dados.id;
                    printf("Jogador %s escalado com sucesso\n", aux->dados.nome);
                                           
                }else{
                    printf("Jogador  %s,nao encontrado ou está INATIVO. Escolha outro.\n", aux->dados.nome);
                    aux = NULL;
                }
               
            }while(!aux);
                
            if(qtd == 3){
               printf("\nEscalação concluída com %hhi jogadores!\n", qtd);
               break;
            } 

            aux = aux->proximo;
        }


}

not_t *cadastrar_jogos(lista_jogos_t *lista, lista_jogadores_t *lista_jogadores){

    not_t *aux = lista->cabeca;

     aux = (not_t*)malloc(sizeof(not_t));

    if(!aux){

        printf("Não foi possível alocar dinamiamente'\n");
        return NULL;
    }

        printf("Antes de cadastrar o jogo eh necessário escalar jogadores.\n");
        escalar_jogadores(aux->dados.id_jogadores, lista_jogadores);
        
   
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
    
        getchar();
        printf("Quantas substituições foram realizadas?\n");
        fgets(aux->dados.substituicao,T_STR, stdin);
        limparBuffer(aux->dados.substituicao);
        to_upper(aux->dados.substituicao);


        aux->proximo = NULL;

        printf("\nJogo registrado com sucesso\n\n");

    return aux;

}
 bool lista_jogadores_vazia(lista_jogadores_t*lista){

    if (lista->cabeca) return false;  
    
    return true; 
}

bool lista_jogos_vazia(lista_jogos_t *lista) {

    if (lista->cabeca) return false; 
    
    return true; 

}

void mostrar_dados_jogadores(no_t *aux){

    printf("\n");
    printf("Nome:-----------------------%s\n", aux->dados.nome);
    printf("Idade:----------------------%d\n", aux->dados.idade);
    printf("ID:-------------------------%d\n", aux->dados.id);
    printf("Altura:---------------------%.2f\n", aux->dados.altura);
    printf("Peso:-----------------------%.2f\n", aux->dados.peso);
    printf("Posição:--------------------%s\n", aux->dados.posicao);
    printf("Venda:----------------------%.2f\n", aux->dados.jg_venda);
    printf("Aquisição:------------------%.2f\n",aux->dados.aquisicao);
    printf("Salário:--------------------%.2f\n",aux->dados.salario);
    printf("Status:---------------------%s\n",aux->dados.status);
    printf("Situação:-------------------%s\n",aux->dados.situacao);

}
void mostrar_dados_jogos(not_t *lista){
   
    printf("\n");
    printf("Time adversário:--------------%s\n",lista->dados.nome_ti);
    printf("Data:-------------------------%s\n", lista->dados.data);                                                                
    printf("Local:------------------------%s\n", lista->dados.local);
    printf("Resultado:--------------------%d\n", lista->dados.resultado_1);
    printf("Resultado do adversário:------%d\n", lista->dados.resultado_2);
    printf("Subustituições:---------------%s\n", lista->dados.substituicao);
    
}

void editar_venda_e_valor_de_venda_jogador(lista_jogadores_t *lista){

    uint8_t id = 0;
    float novo_valor = 0;
    string nova_situacao;
    bool encontrou = false;
    no_t *aux = lista->cabeca;

    printf("Digite o ID do jogador:\n");
    scanf("%hhi",&id);
    getchar();
    
    while(aux != NULL){
        if(aux->dados.id == id){
            printf("Jogador %s.Situação atual %s\n",aux->dados.nome, aux->dados.situacao);
            encontrou = true;
        

            printf("Digite uma nova situação(JOGANDO,VENDIDO,MACHUCADO)\n");
            fgets(nova_situacao,T_STR, stdin);
            limparBuffer(nova_situacao);
            to_upper(nova_situacao);

            strcpy(aux->dados.situacao, nova_situacao);  

            if (strcmp(nova_situacao, "JOGANDO") == 0) {
                strcpy(aux->dados.status, "ATIVO");
            } else if (strcmp(nova_situacao, "VENDIDO") == 0 || strcmp(nova_situacao, "MACHUCADO") == 0) {
                strcpy(aux->dados.status, "INATIVO");
            }

            if(strcmp(nova_situacao, "VENDIDO") == 0){
                printf("Qual o valor que o jogador foi vendido?\n");
                scanf("%f", &novo_valor);
                aux->dados.jg_venda = novo_valor;
        
            }

            printf("\nSituacao atualizada com sucesso!\n\n");
            break;
        }
        aux = aux->proximo;
    }

    if(!encontrou){
        printf("ID não localizado\n");
     
    }
 
}
   

void insere_registro_inicio_jogadores(no_t *novo, lista_jogadores_t *lista){

    lista->nr_nos++;

    if(lista_jogadores_vazia(lista)){
        lista->cabeca = novo;
        
    } else {
        no_t *ultima = localizar_ultimo_registro_jogadores(lista->cabeca);
        ultima->proximo = novo;
    }
}
void insere_registro_inicio_jogos(not_t *novo, lista_jogos_t *lista){

    lista->nr_nos++;

    if(lista_jogos_vazia(lista)){
        lista->cabeca = novo;
        
    } else {
        not_t *ultima = localizar_ultimo_registro_jogos(lista->cabeca);
        ultima->proximo = novo;
    }  

}
