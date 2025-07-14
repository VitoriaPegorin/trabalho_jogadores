#include "../include/menus.h"
#include <stdio.h>

uint8_t menu_principal(){

uint8_t opcao;

printf("MENU PRINCIPAL\n");
printf("1.Cadastros\n");
printf("2.Relatórios\n");
printf("3.Consultas\n");
printf("4.Editar cadastro\n");
printf("5.Salvar arquivos\n");
printf("0.Sair do programa\n");
printf("-----------------\n");
scanf("%hhi", &opcao);

return opcao;

}
uint8_t menu_cadastro(){

uint8_t opcao_1;

printf("MENU DOS CADASTROS\n");
printf("1.Cadastrar jogadores\n");
printf("2.Cadastras jogos\n");
printf("0.Sair do menu cadastro\n");
printf("--------------------\n");
printf("\n");
scanf("%hhi", &opcao_1);

return opcao_1;

}
uint8_t menu_relatorios(){

uint8_t opcao_2;

printf("MENU DOS RELATÓRIOS\n");
printf("1.Relatorio completo de jogadores\n");
printf("2.Relatorio de jogadores por faixa de idade\n");
printf("3.Relatorio do resultado das partidas\n");
printf("4.Relatorio de confronto com times adversários\n");
printf("5.Relatorio de todos os jogadores vendidos\n");
printf("6.Relatorio do valor do time\n");
printf("7.Relatorio do aproveitamento do time\n");
printf("0.Sair dos relatorios\n");
printf("--------------------\n");
printf("\n");
scanf("%hhi", &opcao_2);

return opcao_2;

}

uint8_t menu_localizar(){

uint8_t opcao_3;

printf("MENU DE LOCALIZAR\n");
printf("1.Localizar jogador por nome\n");
printf("2.Localizar jogador por posição\n");
printf("3.Localizar jogos realizados pelo nome do time adversários\n");
printf("4.Localizar jogador com maior salário\n");
printf("5.Localizar jogador por faixa salárial\n");
printf("0.Sair do menu localizar\n");
printf("--------------------\n");
printf("\n");
scanf("%hhi",&opcao_3);
getchar();

return opcao_3;

}
uint8_t manipulacao_arquivos(){

}
uint8_t manipulacao_cadadastro(){

  uint8_t opcao_4;

  printf("MENU PARA ALTERACOES\n");
  printf("1.Alterar jogador para vendido e valor de venda\n");
  printf("0.Sair do menu alteracoes\n");
  printf("--------------------\n");
  printf("\n");
  scanf("%hhi",&opcao_4);
  getchar();

  return opcao_4;

}
  uint8_t menu_salvar_ou_exportar(){


    uint8_t opcao_5;

    printf("MENU DE SALVAMENTO E EXPORTAÇÃO\n");
    printf("1. Exportar jogadores para .txt\n");
    printf("2. Exportar jogos para .txt\n");
    printf("3. Exportar jogadores para .csv\n");
    printf("4. Exportar jogos para .csv\n");
    printf("5. Exportar jogadores para .html\n");
    printf("6. Exportar jogos para .html\n");
    printf("0. Saiu do menu salvar dados\n");
    printf("--------------------\n");
    printf("\n");
    scanf("%hhi", &opcao_5);
    getchar();


    return opcao_5;
  


}
