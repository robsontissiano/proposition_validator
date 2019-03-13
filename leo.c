#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostraMenu(){
  printf("##### MENU ##### \n");
  printf("Este programa tem como finalidade a Verificação e a Validação de Expressões Proposicionais. \n\n");
  printf("Gostaria de saber quais preposições podem ser usadas? S ou N \n");
  printf("Para encerrar digite x \n");
  printf("################ \n");
}

void mostraProposicoes(){
  printf("Use ~ para representar a negação ().\n");
  printf("Use & para representar a conjunção (∧).\n");
  printf("Use | para representar a disjunção (∨).\n");
  printf("Use > para representar a implicação (→)\n");
  printf("Use <> para representar a bi-implicação (↔).\n\n\n\n");
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
  printf("Favor inserir o proposição para que seja feita a validação: \n");
  // scanf("%s", &proposicao);
  gets(proposicao);
  printf("Proposicao: %s \n", proposicao);
  testaProposicao(proposicao);
}









void main () {
  char resposta;
  do {
    mostraMenu();
    resposta = getchar();
    getchar();
    if(resposta == 'S' || resposta == 's') {
      mostraProposicoes();
    }
    else if (resposta == 'N' || resposta == 'n') {
      lerProposicao();
    }
    else {
      if(resposta != 'x'){
        printf(" Limpando o console em 5 segundos... \n");
        sleep(5);
        system("clear");
      }
    }
  } while (resposta != 'x');
}
