#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mostraMenu(){
  char resposta;
  printf("##### MENU ##### \n");
  printf("Este programa tem como finalidade a Verificação e a Validação de Expressões Proposicionais. \n\n");
  printf("Gostaria de saber quais preposições podem ser usadas? S ou N \n");
  printf("Para encerrar digite x \n");
  printf("################ \n");
  resposta = getchar();
  getchar();
  return resposta;
}

void mostraProposicoes(){
  printf("_____________\n\n");
  printf("Use ~ para representar a negação (~).\n");
  printf("Use & para representar a conjunção (∧).\n");
  printf("Use | para representar a disjunção (∨).\n");
  printf("Use > para representar a implicação (→)\n");
  printf("Use <> para representar a bi-implicação (↔).\n");
  printf("_____________\n\n\n\n");
}

void testaProposicao(char *proposicao){
  char opcoes[] = {'~','<>','>'};
  int j, tamanhoOpcoes;

  printf("Lendo Proposicao: %s \n", proposicao);
  tamanhoOpcoes = sizeof(opcoes);

  printf("Tamanhos %i \n\n", tamanhoOpcoes);
  printf("_____________\n\n");

  for(int j=0;j<tamanhoOpcoes;j++){


    printf("Proposicao %c \n", proposicao);
    printf("Opcao %c \n", opcoes[j]);


    if(opcoes[j] == proposicao){
    // if(!strcmp(opcoes[j], proposicao)){
      printf("Proposicao Valida! \n\n");
      return;
    }
    else {
      printf("Proposicao Invalida! \n\n");
    }
    printf("[%d]: \n", j);
  //  return
  }
}

char lerProposicao(){
  char * proposicao[61];
  printf("Insira a proposição para validar: \n");
  scanf("%s", &proposicao);
  // gets(proposicao);
  printf("Proposicao: %s \n", proposicao);
  testaProposicao(proposicao);
}




void main () {
  char resposta;
  do {
    resposta = mostraMenu();
    // resposta = getchar();
    // getchar();
    if(resposta == 'x'){
      printf("Encerrando em 3 segundos... \n");
      sleep(3);
      exit(0);
    }
    else if(resposta == 'S' || resposta == 's') {
      mostraProposicoes();
      printf("Limpando o console em 5 segundos... \n");
      sleep(5);
      system("clear");
    }
    else if (resposta == 'N' || resposta == 'n') {
      lerProposicao();
      printf("Limpando o console em 5 segundos... \n");
      sleep(5);
      system("clear");
    }
  } while (resposta != 'x');
}
