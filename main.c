#include <stdio.h>
#include <stdint.h>

#include "./include/types.h"
#include "./include/menus.h"
#include "./include/relatorios.h"
#include "./include/consultas.h"
#include "./include/cadastros.h"
#include "./include/arquivos.h"
#include "./include/utils.h"

#define SAIR 0

int main(){

    uint8_t opc, opcao, opcao_1, opcao_2, opcao_3, opcao_4, opcao_5;
    no_t *aux = NULL;
    not_t *aux_2 = NULL;
    lista_jogadores_t lista_jogadores;
    lista_jogos_t lista_jogos;
    string nome, posicao, nome_ti, nome_arq;

    //criar lista
    inicializa_lista_jogadores(&lista_jogadores);
    inicializa_lista_jogos(&lista_jogos);

    ler_registros_de_jogadores_binario("dados_jogadores.bin", &lista_jogadores);
    ler_registros_de_jogos_binario("dados_jogos.bin", &lista_jogos);


do{
    opc = menu_principal();

    switch(opc){

        case 1:// 1.Cadastros

            do{

                opcao = menu_cadastro();

                switch(opcao){

                    
                    case 1: { //1.Cadastrar jogadores

                            srand(time(NULL));

                            no_t *novo = cadastrar_jogadores(&lista_jogadores);

                            if (localizar_id_do_jogador(novo->dados.id, &lista_jogadores) != NULL) {
                                printf("  Jogador com ID %d já existe! Cadastro cancelado.\n", novo->dados.id);
                                free(novo); // Libera a memória do jogador não inserido
                            } else {
                                insere_registro_inicio_jogadores(novo, &lista_jogadores);
                               
    
                            }
                            break;
                    }

                    

                    case 2: { //2.Cadastrar jogos

                           not_t *aux_2 = cadastrar_jogos(&lista_jogos, &lista_jogadores);
                            insere_registro_inicio_jogos(aux_2, &lista_jogos);
                           

                            break;

                        }
                    
                        
                    case 0: printf("Saiu do menu cadastro\n\n");
                            break;
                          
                
                }

            }while(opcao != SAIR);

        break;

        case 2:  //2.Relatórios
        
            do{

                opcao_1 = menu_relatorios();
                 
                switch(opcao_1){

                    case 1: //1.Relatorio completo de jogadores

                            relatorio_completo_de_jogadores(&lista_jogadores);

                    break;

                    case 2: //2.Relátório de jogadores por faixa de idade

                            relatorio_de_jogadores_por_faixa_etaria(&lista_jogadores);

                    break;
                    
                    case 3: //3.Relatorio do resultado das partidas

                            relatorio_do_resultado_das_partidas(&lista_jogos);
                    break;

                    case 4: //4.Relatorio de confronto com times adversários

                            relatorio_de_confronto_com_times_adversarios(&lista_jogos);
                    break;

                    case 5: //5.Relátório de todos os jogadores vendidos

                            relatorio_de_todos_os_jogadores_vendidos(&lista_jogadores);
                    break;

                    case 6: //6.Relátório do valor do time

                            relatorio_do_valor_do_time(&lista_jogadores);
                    break;

                    case 7: //7.Relátório do aproveitamento do time

                            relatorio_do_aproveitamento_do_time(&lista_jogos);

                    break;


                    case 0:printf("Saiu do menu relatorios\n\n");
                    break;
                
                }

            }while(opcao_1 != SAIR);

        
        break;

        case 3://3.Consultas

        
            do{
                
                opcao_2 = menu_localizar();

                switch(opcao_2){

                    case 1: //1.Localizar jogador por nome

                        
                        printf("Qual o nome do jogador?\n");
                        fgets(nome, T_STR, stdin);
                        limparBuffer(nome);
                        to_upper(nome);

                        aux = localizar_jogador_por_nome(nome, &lista_jogadores);

                    break;

                    case 2: //2.Localizar jogador por posição

                        
                        printf("Qual a posicao do jogador?\n");
                        fgets(posicao, T_STR, stdin);
                        limparBuffer(posicao);
                        to_upper(posicao);

                        aux = localizar_jogador_por_posicao(posicao, &lista_jogadores);

                    break;

                    case 3: //3.Localizar jogos realizados pelo nome do time adversários

                        
                        printf("Qual o nome do time adversario?\n");
                        fgets(nome_ti, T_STR, stdin);
                        limparBuffer(nome_ti);
                        to_upper(nome_ti);

                        aux_2 = localizar_jogos_realizados_pelo_nome_do_time_adversarios(nome_ti, &lista_jogos);

                    break;

                    case 4: //4.Localizar jogador com maior salário

                            aux = localizar_jogador_com_maior_salario(&lista_jogadores);

                    break;

                    case 5: //5.Localizar jogador por faixa salárial

                            localizar_jogador_por_faixa_salarial(&lista_jogadores);

                    break;

                    case 0:printf("0.Saiu do menu consultas\n\n");
                    break;


                }

            }while(opcao_2 != SAIR);
                
        
        break;

        case 4://Editar cadastro
  
            do{

                opcao_4 = manipulacao_cadadastro();

                switch(opcao_4){

                    case 1: //1.Alterar situacao do jogador

                        editar_venda_e_valor_de_venda_jogador(&lista_jogadores);
                    break;

                    case 2:
                    break;
                    case 3:
                    break;
                    case 0:printf("0.Saiu do menu editar\n\n");
                    break;

  
                }

            }while(opcao_4 != SAIR);

        break;
        case 5:

        do{

            opcao_5 = menu_salvar_ou_exportar();

            switch(opcao_5){


                case 1: //1. Exportar jogadores para .txt
                
                msg_cabecalho("EXPORTAR DADOS JOGADORES PARA .TXT\n");
                limpar_tela();
                printf("Digite o nome do arquivo (extensao.txt)");
                fgets(nome_arq, T_STR, stdin);
                limparBuffer(nome_arq);

                exportar_dados_jogadores_para_arquivo_texto(nome_arq, lista_jogadores.cabeca);

                
                break;

                case 2: //2.Exportar jogos para .txt

                msg_cabecalho("EXPORTAR DADOS JOGOS PARA .TXT\n");
                limpar_tela();
                printf("Digite o nome do arquivo (extensao.txt)");
                fgets(nome_arq, T_STR, stdin);
                limparBuffer(nome_arq);

                exportar_dados_jogos_para_arquivo_texto(nome_arq, lista_jogos.cabeca);

                break;

                case 3: //3. Exportar jogadores para .csv

                msg_cabecalho("EXPORTAR DADOS JOGADORES PARA .CSV\n");
                limpar_tela();
                printf("Digite o nome do arquivo (extensao.csv)");
                fgets(nome_arq, T_STR, stdin);
                limparBuffer(nome_arq);

                exportar_dados_jogadores_para_arquivo_csv(nome_arq, lista_jogadores.cabeca);

                break;
                
                case 4: //4. Exportar jogos para .csv
                limpar_tela();
                msg_cabecalho("EXPORTAR DADOS JOGOS PARA .CSV\n");
                printf("Digite o nome do arquivo (extensao.csv)");
                fgets(nome_arq, T_STR, stdin);
                limparBuffer(nome_arq);
                exportar_dados_jogos_para_arquivo_csv(nome_arq, lista_jogos.cabeca);

               
                break;

                case 5://5. Exportar jogadores para .html
                limpar_tela();
                msg_cabecalho("EXPORTAR DADOS JOGADORES PARA .HTML\n");
                printf("Digite o nome do arquivo (extensao.html)");
                fgets(nome_arq, T_STR, stdin);
                limparBuffer(nome_arq);
                exportar_dados_jogadores_para_arquivo_html(nome_arq, lista_jogadores.cabeca);
                
                break;

                case 6: //6. Exportar jogos para .html

                msg_cabecalho("EXPORTAR DADOS JOGOS PARA .HTML\n");
                limpar_tela();
                printf("Digite o nome do arquivo (extensao.html)");
                fgets(nome_arq, T_STR, stdin);
                limparBuffer(nome_arq);

                exportar_dados_jogos_para_arquivo_html(nome_arq, lista_jogos.cabeca);
                
                
                break;
                
                case 0:printf("0.Saiu do menu salvar\n\n");
                break;
  
            }

            }while(opcao_5 != SAIR);


        break; 

    }


}while(opc != SAIR);

if (!lista_jogadores_vazia(&lista_jogadores)) {
    salvar_registros_de_jogadores_binario("dados_jogadores.bin", lista_jogadores.cabeca);
}

if (!lista_jogos_vazia(&lista_jogos)) {
    salvar_registros_de_jogos_binario("dados_jogos.bin", lista_jogos.cabeca);
}

while(lista_jogadores.cabeca != NULL){
    liberar_lista_jogadores(&lista_jogadores);

}
while(lista_jogos.cabeca != NULL){
    liberar_lista_jogos(&lista_jogos);

}

    return 0;
}