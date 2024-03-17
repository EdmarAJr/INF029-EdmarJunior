#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int opcaoMenuInicial() {
  int menuInicial;

  printf("Projeto escola - Disciplina INF029\n");
  printf("\n<<< Escolha entre as opcoes abaixo para inciar >>>\n");
  printf("\n0 - Sair\n");
  printf("1 - Discente\n");
  printf("2 - Docente\n");
  printf("3 - Disciplina\n");
  printf("Escolha uma opcao: ");

  scanf("%d", &menuInicial);

  return menuInicial;
}

int opcaoMenuDiscente() {
  int menuDiscente;

  printf("\n0 - Voltar\n");
  printf("1 - Cadastrar Discente\n");
  printf("2 - Listar Discente\n");
  printf("3 - Atualizar Discente\n");
  printf("4 - Excluir Discente\n");
  printf("Escolha uma opcao: ");

  scanf("%d", &menuDiscente);

  return menuDiscente;
}

int opcaoMenuAtualizarDiscente() {
  int menuAtualizarDiscente;
  
  printf("\n0 - Sair\n");
  printf("1 - Atualizar nome\n");
  printf("2 - Atualizar sexo\n");
  printf("3 - Atualizar data de nascimento\n");
  //printf("4 - Atualizar cpf\n");
  printf("Escolha uma opcao: ");

  scanf("%d", &menuAtualizarDiscente);
  
  return menuAtualizarDiscente;
}

int opcaoMenuDocente(){
  int menuDocente;
  
  printf("\n0 - Voltar\n");
  printf("1 - Cadastrar Docente\n");
  printf("2 - Listar Docente\n");
  printf("3 - Atualizar Docente\n");
  printf("4 - Excluir Docente\n");
  printf("Escolha uma opcao: ");

  scanf("%d", &menuDocente);

  return menuDocente;
}

int opcaoMenuAtualizarDocente() {
  int menuAtualizarDocente;
  
  printf("\n0 - Sair\n");
  printf("1 - Atualizar nome\n");
  printf("2 - Atualizar sexo\n");
  printf("3 - Atualizar data de nascimento\n");
  //printf("4 - Atualizar cpf\n");
  printf("Escolha uma opcao: ");

  scanf("%d", &menuAtualizarDocente);
  
  return menuAtualizarDocente;
}