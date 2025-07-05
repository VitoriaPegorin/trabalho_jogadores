#include <stdint.h>
#include "./include/menus.h"
#include "./include/types.h"
#include "./include/cadastro.h"
#include "./include/relatorios.h"
#include "./include/arquivo.h"
#include "./include/consultas.h"
#include "./include/utils.h"

#define SAIR 0

int main(){

    uint8_t opc, opcao, opcao_1, opcao_2, opcao_3, opcao_4, opcao_5;
    no_t *aux = NULL;
    not_t *aux_2 = NULL;
    lista_jogadores_t lista_jogadores;
    lista_jogos_t lista_jogos;
    string nome, posicao, nome_ti;

    //criar lista
    inicializa_lista_jogadores(&lista_jogadores);
    inicializa_lista_jogos(&lista_jogos);


    

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
                                printf(" Jogador cadastrado com sucesso!\n");
    
                            }
                            break;
                    }

                    case 2:{ //2.Escalar jogadores para proxima partida

                            jogadores_escalados_t *aux = escalar_jogadores(&lista_jogadores);

                            
                            
                            break;
                    }

                    case 3: { //3.Cadastrar jogos

                           not_t *aux_2 = cadastrar_jogos(&lista_jogos, &lista_jogadores);
                            insere_registro_inicio_jogos(aux_2, &lista_jogos);

                            break;

                    }
                        
                    case 0: printf("Saiu do menu cadastro");
                            break;
                          

                
                }

            }while(opcao != 0);

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


                    case 0:printf("Saiu do menu relatorios\n");
                    break;
                
                }

            }while(opcao_1 != 0);

        
        break;

        case 3://3.Consultas

        
            do{
                
                opcao_2 = menu_localizar();

                switch(opcao_2){

                    case 1: //1.Localizar jogador por nome

                        getchar();
                        printf("Qual o nome do jogador?\n");
                        fgets(nome, T_STR, stdin);
                        limparBuffer(nome);
                        to_upper(nome);

                        aux = localizar_jogador_por_nome(nome, &lista_jogadores);

                    break;

                    case 2: //2.Localizar jogador por posição

                        getchar();
                        printf("Qual a posicao do jogador?\n");
                        fgets(posicao, T_STR, stdin);
                        limparBuffer(posicao);
                        to_upper(posicao);

                        aux = localizar_jogador_por_posicao(posicao, &lista_jogadores);

                    break;

                    case 3: //3.Localizar jogos realizados pelo nome do time adversários

                        getchar();
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

                    case 0:printf("0.Saiu do menu consultas\n");
                    break;


                }

            }while(opcao_2 != 0);
                
        
        break;
        
        case 4: //Editar arquivo
                do{
                     opcao_3 = manipulacao_arquivos();

                switch(opcao_3){

                    case 1:
                    break;
                    case 2:
                    break;
                    case 3:
                    break;
                    
                    case 0:
                    break;


                }

            }while(opcao_3 != 0);

        break;

  

        case 5://Editar cadastro
  
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
                    case 0:printf("0.Saiu do menu editar");
                    break;

                     
  
  
                }

            }while(opcao_4 != 0);

        break;
        case 6:

        do{

            opcao_5 = menu_salvar_ou_exportar();

            switch(opcao_5){

                case 1: //1. Salvar jogadores em arquivo binário

                salvar_registros_de_jogadores_binario();

                    
                break;

                case 2: //2. Salvar jogos em arquivo binário

                salvar_registros_de_jogos_binario();

                break;

                case 3: //3. Ler jogadores de arquivo binário

                ler_registros_de_jogadores_binario();

                break; 

                case 4: //4. Ler jogos de arquivo binário
                
                ler_registros_de_jogos_binario();

                break;

                case 5: //5. Exportar jogadores para .txt

                exportar_dados_jogadores_para_arquivo_texto();

                break;

                case 6: //6.Exportar jogos para .txt

                exportar_dados_jogos_para_arquivo_texto();

                break;

                case 7: //7. Exportar jogadores para .csv

                exportar_dados_jogadores_para_arquivo_csv();

                break;
                
                case 8: //7. Exportar jogos para .csv

                exportar_dados_jogos_para_arquivo_csv();

                break;

                case 9://9. Exportar jogadores para .html

                exportar_dados_jogadores_para_arquivo_html();

                break;

                case 10: //10. Exportar jogos para .html

                exportar_dados_jogos_para_arquivo_html();
                
                break;
                
                case 0:printf("0.Saiu salvar");
                break;

                     
  
  
            }

            }while(opcao_5 != 0);


        break; 

    }


}while(opc != SAIR);

 liberar_lista_jogadores(&lista_jogadores);
 liberar_lista_jogos(&lista_jogos);

    return 0;
}