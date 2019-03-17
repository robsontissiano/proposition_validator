#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostraMenu(){
  char resposta;
  printf("############################# MENU ###################################### \n");
  printf("#                                                                       # \n");
  printf("# Este programa tem como finalidade a Verificação                       # \n");
  printf("# E a Validação de Expressões Proposicionais.                           # \n");
  printf("#                                                                       # \n");
  printf("# Gostaria de saber quais preposições podem ser usadas? Digite S ou N   # \n");
  printf("#                                                                       # \n");
  printf("# Para encerrar digite x                                                # \n");
  printf("#                                                                       # \n");
  printf("######################################################################### \n");
}

void mostraProposicoes(){
  printf("____________________________________________________\n\n");
  printf("# Use ~ para representar a negação (~)                \n");
  printf("# Use & para representar a conjunção (∧)              \n");
  printf("# Use | para representar a disjunção (∨)              \n");
  printf("# Use > para representar a implicação (→)             \n");
  printf("# Use <> para representar a bi-implicação (↔)         \n");
  printf("____________________________________________________\n\n\n\n");
}

void testaProposicao(char *proposicao){
  char opcoes[] = {'~','<>','>'};
  char variaveis[] = {'p','q','r','s'};
  char anterior, tipo_anterior;
  int j, i, tamanhoOpcoes, tamanhoProposicao, counter;

  counter=0;

  tamanhoProposicao = sizeof(proposicao);

  tamanhoOpcoes = sizeof(opcoes);

  for(int j=0;j<tamanhoOpcoes;j++){
    if (proposicao[0] != "\0"){
      if(opcoes[j] == proposicao[0]){
        counter = counter + 1;
      }
    }
  }

  if (counter == 0 ){
    printf("# [!!!] Proposicao  %c  Invalida! \n", anterior);
  }
  else {
    printf("# [!] Proposicao Valida! \n\n");
  }
}

char lerProposicao(){
  char * proposicao[61];
  printf("# Insira a proposição para validar: \n");
  scanf("%s", &proposicao);
  testaProposicao(proposicao);
}

void main () {
  char resposta;
  do {
    mostraMenu();
    scanf("%s", &resposta);

    if(resposta == 'x'){
      printf("# Encerrando em 3 segundos... \n");
      sleep(3);
      exit(0);
    }
    else if(resposta == 'S' || resposta == 's') {
      mostraProposicoes();
    }
    else if (resposta == 'N' || resposta == 'n') {
      lerProposicao();
    }
    printf("# Limpando o console em 5 segundos... \n");
    sleep(5);
    system("clear");
  } while (resposta != 'x');
}
