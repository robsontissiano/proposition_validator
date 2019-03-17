#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mostraMenu(){
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
  resposta = getchar();
  getchar();
  return resposta;
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
  //printf("ok 1 \n");



  tamanhoProposicao = sizeof(proposicao);
  // printf("Lendo Proposicao: %s \n", proposicao);

  //for(int i=0;i<tamanhoProposicao;i++){
  //  printf("# Lendo Proposicao: %c \n", proposicao[i]);
  //}


  tamanhoOpcoes = sizeof(opcoes);



  //printf("_____________\n\n");
  //printf("Tamanho Opcoes %d \n\n", tamanhoOpcoes);
  //printf("Tamanho Proposicao %d \n\n", tamanhoProposicao);
  //printf("_____________\n\n");




  for(int j=0;j<tamanhoOpcoes;j++){
    //printf("ok 2 \n");
    //printf("Indice: [%d] \n", j);

    //printf("********************\n\n");
    //printf("Proposicao %c \n", proposicao[0]);
    //printf("Opcao %c \n", opcoes[j]);
    //printf("********************\n\n");


    anterior = proposicao[0];

    if (proposicao[0] != "\0"){
      if(opcoes[j] == proposicao[0]){
        //printf("ok 3 \n");
        counter = counter + 1;
        //printf("ok 4 \n");
        //printf("Proposicao Valida! \n\n");
        //return;
        //return anterior;
      }

      // else {
      //   printf("Proposicao Invalida! \n\n");
      // }
      //return anterior;
    }
  }




  if (counter == 0 ){
    //printf("ok 5 \n");
    printf("# [!!!] Proposicao  %c  Invalida! \n", anterior);
  }
  else {
    printf("# [!] Proposicao Valida! \n\n");
    //printf("ok 6 \n");
  }
  //printf("ok 7 \n");

}

char lerProposicao(){
  char * proposicao[61];
  printf("# Insira a proposição para validar: \n");
  scanf("%s", &proposicao);


  //printf("### Iniciando teste Proposicao: %c \n", proposicao[0]);
  testaProposicao(proposicao);
}




void main () {
  char resposta;
  do {
    resposta = mostraMenu();
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
