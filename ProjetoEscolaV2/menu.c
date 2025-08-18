#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int opcaoMenuInicial() {
int menuInicial;

	printf("Projeto escola - Disciplina INF029\n");
	printf("\n<<< Escolha entre as opcoes abaixo para iniciar >>>\n");
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
	printf("2 - Listar Discentes\n");
	printf("3 - Atualizar Discente\n");
	printf("4 - Excluir Discente\n");
	printf("5 - Listar Discente por Id\n");
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
	printf("Escolha uma opcao: ");

	scanf("%d", &menuAtualizarDiscente);
	
	return menuAtualizarDiscente;
}

int opcaoMenuDocente(){
	int menuDocente;
	
	printf("\n0 - Voltar\n");
	printf("1 - Cadastrar Docente\n");
	printf("2 - Listar Docentes\n");
	printf("3 - Atualizar Docente\n");
	printf("4 - Excluir Docente\n");
	printf("5 - Listar Docente por Id\n");
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
	printf("Escolha uma opcao: ");

	scanf("%d", &menuAtualizarDocente);
	
	return menuAtualizarDocente;
}

int opcaoMenuDisciplina() {
	int menuDisciplinas;

	printf("\n0 - Sair\n");
	printf("1 - Cadastrar disciplina\n");
	printf("2 - Listar discplinas\n");
	printf("3 - Atualizar disciplina\n");  
	printf("4 - Excluir disciplina\n");
	printf("5 - Listar Disciplinas c/ discente\n");
	printf("Escolha uma opcao: ");

	scanf("%d", &menuDisciplinas);

	return menuDisciplinas;
}

int opcaoMenuAtualizarDisciplina() {
	int menuAtualizarDisciplina;

	printf("\n0 - Sair\n");
	printf("1 - Atualizar nome\n");
	printf("2 - Atualizar id Docente\n");
	printf("Escolha uma opcao: ");

	scanf("%d", &menuAtualizarDisciplina);

	return menuAtualizarDisciplina;
}