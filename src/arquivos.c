#include "../include/arquivos.h"
#include "../include/cadastros.h"

void salvar_registros_de_jogadores_binario(string nome_arq, no_t *lista){

    FILE *fp = NULL;

    fp = fopen(nome_arq, "wb");

    if(!fp){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while(lista){
        fwrite(lista, sizeof(no_t), 1, fp);
        lista = lista->proximo;
    }

    fclose(fp);

}
void salvar_registros_de_jogos_binario(string nome_arq, not_t *lista){

    FILE *fp = NULL;

    fp = fopen(nome_arq, "wb");


    if(!fp){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while(lista){
        fwrite(lista, sizeof(not_t), 1, fp);
        lista = lista->proximo;
    }

    fclose(fp);

}
void ler_registros_de_jogadores_binario(string nome_arq, lista_jogadores_t *lista){

    FILE *fp = NULL;

    fp = fopen("dados_jogadores.bin", "rb");

    if(!fp){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while(!feof(fp)) {
        no_t *aux = (no_t*)malloc(sizeof(no_t));
        fread(aux, sizeof(no_t), 1, fp);
        if (!feof(fp)) { 
            aux->proximo = NULL;
            insere_registro_inicio_jogadores(aux, lista);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
    
}
void ler_registros_de_jogos_binario(string nome_arq, lista_jogos_t *lista){

    FILE *fp = NULL;

    fp = fopen(nome_arq, "rb");

    if(!fp){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while(!feof(fp)) {
        not_t *aux = (not_t*)malloc(sizeof(not_t));
        fread(aux, sizeof(not_t), 1, fp);
        
        if (!feof(fp)) { 
            aux->proximo = NULL;
            insere_registro_inicio_jogos(aux, lista);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);

}
void exportar_dados_jogadores_para_arquivo_texto(string nome_arq, no_t *lista){

    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "----------------------------------\n");
    fprintf(fp, "Relatorio Completo de Jogadores\n");
    fprintf(fp, "----------------------------------\n\n");

    while(lista) {

        fprintf(fp, "Nome......................:%s\n", lista->dados.nome);
        fprintf(fp, "Idade.....................:%hhi\n", lista->dados.idade);
        fprintf(fp, "ID........................:%hhi\n", lista->dados.id);
        fprintf(fp, "Altura....................:%2.f\n", lista->dados.altura);
        fprintf(fp, "Peso......................:%2.f\n", lista->dados.peso);
        fprintf(fp, "Posicao...................:%s\n", lista->dados.posicao);
        fprintf(fp, "Venda.....................:%2.fn", lista->dados.jg_venda);
        fprintf(fp, "Aquisicao.................:%.2f\n", lista->dados.aquisicao);
        fprintf(fp, "Salario...................:%.2f\n", lista->dados.salario);
        fprintf(fp, "Status....................:%s\n", lista->dados.status);
        fprintf(fp, "Situacao..................:%s\n", lista->dados.situacao);

        lista = lista->proximo;
    }    

    fclose(fp);

}
void exportar_dados_jogos_para_arquivo_texto(string nome_arq, not_t *lista){

      FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "----------------------------------\n");
    fprintf(fp, "Relatorio Completo de jogos\n");
    fprintf(fp, "----------------------------------\n\n");

    while(lista) {
        fprintf(fp, "Time adversario.............................:%s\n", lista->dados.nome_ti);
        fprintf(fp, "Data........................................:%s\n", lista->dados.data);
        fprintf(fp, "Local.......................................:%s\n", lista->dados.local);
        fprintf(fp, "Resultado...................................:%hhi\n", lista->dados.resultado_1);
        fprintf(fp, "Resultado adveversario......................:%hhi\n", lista->dados.resultado_2);
        fprintf(fp, "Substituicao................................:%s\n", lista->dados.substituicao);
        lista = lista->proximo;
    }

    

    fclose(fp);

}
void exportar_dados_jogadores_para_arquivo_csv(string nome_arq, no_t *lista){

     FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "NOME;IDADE;ID;ALTURA;PESO;POSICAO;VENDA;AQUISICAO;SALARIO;STATUS;SITUACAO\n");

    while(lista) {
        fprintf(fp, "%s;", lista->dados.nome);
        fprintf(fp, "%hhi;", lista->dados.idade);
        fprintf(fp, "%hhi;", lista->dados.id);
        fprintf(fp, "%2.f;", lista->dados.altura);
        fprintf(fp, "%2.f;", lista->dados.peso);
        fprintf(fp, "%s;", lista->dados.posicao);
        fprintf(fp, "%2.f;", lista->dados.jg_venda);
        fprintf(fp, "%.2f;", lista->dados.aquisicao);
        fprintf(fp, "%.2f;", lista->dados.salario);
        fprintf(fp, "%.s\n", lista->dados.status);
        fprintf(fp, "%.s\n", lista->dados.situacao);
        lista = lista->proximo;
        
    }  
     

    fclose(fp); 

}
void exportar_dados_jogos_para_arquivo_csv(string nome_arq, not_t *lista){

     FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "NOME_TI;DATA;LOCAL;RESULTADO_1;RESULTADO_2;SUBSTITUICAO\n");

    while(lista) {
        fprintf(fp, "%s;", lista->dados.nome_ti);
        fprintf(fp, "%s;", lista->dados.data);
        fprintf(fp, "%s;", lista->dados.local);
        fprintf(fp, "%hhi;", lista->dados.resultado_1);
        fprintf(fp, "%hhi;", lista->dados.resultado_2);
        fprintf(fp, "%s\n", lista->dados.substituicao);
        
        lista = lista->proximo;
    }    
       

    fclose(fp); 

    
}
void exportar_dados_jogadores_para_arquivo_html(string nome_arq, no_t *lista){


    FILE *fp = fopen(nome_arq , "w");
    if(!fp){
        printf("Não foi possivel exportar o arquivo\n");
        return;
    }
    fprintf(fp , "<html> <body> <table> <tr> <td><h1>Nome do Jogador</h1></td> <td><h1>Idade do Jogador</h1></td> <td><h1>ID do Jogador</h1></td> <td><h1>Altura do Jogador</h1></td> <td><h1>Peso do Jogador</h1></td> <td><h1>Posicao do Jogador</h1></td> <td><h1>Valor de Venda do Jogador</h1></td> <td><h1>Valor de Aquisicao do Jogador</h1></td> <td><h1>Salario do Jogador</h1></td> <td><h1>Status do Jogador</h1></td> <td><h1>Situacao do Jogador</h1></td> </tr>\n");
    while(lista){
        fprintf(fp , "<tr> <td><p>%s</p></td> <td><p>%hhi</p></td> <td><p>%hhi</p></td> <td><p>%2.f</p></td> <td><p>%2.f</p></td> <td><p>%s</p></td> <td><p>%2.f</p></td> <td><p>%2.f</p></td> <td><p>%2.f</p></td> <td><p>%s</p></td> <td><p>%s</p></td> </tr>\n", lista->dados.nome, lista->dados.idade, lista->dados.id, lista->dados.altura, lista->dados.peso, lista->dados.posicao, lista->dados.jg_venda, lista->dados.aquisicao, lista->dados.salario,lista->dados.status,lista->dados.situacao);
        lista = lista->proximo;

    }
    fprintf(fp , "</table> </body> </html>");

    fclose(fp);


}
void exportar_dados_jogos_para_arquivo_html(string nome_arq, not_t *lista){

    FILE *fp = fopen(nome_arq , "w");

    if(!fp){
        printf("Não foi possivel exportar o arquivo\n");
        return;
    }
    fprintf(fp , "<html> <body> <table> <tr> <td><h1>Time Adversario</h1></td> <td><h1>Data do Jogo</h1></td> <td><h1>Local do Jogo</h1></td> <td><h1>Resultado do time no Jogo</h1></td> <td><h1>Resultado do time adversario no Jogo</h1></td> <td><h1>Substituicoes do Jogo</h1></td> </tr>\n");
    while(lista){
        fprintf(fp , "<tr> <td><p>%s</p></td> <td><p>%s</p></td> <td><p>%s</p></td> <td><p>%hhi</p></td> <td><p>%hhi</p></td> <td><p>%s</p></td> </tr>\n", lista->dados.nome_ti, lista->dados.data, lista->dados.local, lista->dados.resultado_1, lista->dados.resultado_2, lista->dados.substituicao);
       
        lista = lista->proximo;

    }
    fprintf(fp , "</table> </body> </html>");

    fclose(fp);

}