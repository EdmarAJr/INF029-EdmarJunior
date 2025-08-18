#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct {
	int matricula;
	char nome[50];  
	char sexo;
	Data dataNascimento;
	char cpf[15];  
	int ativo;
} Discente;

int cadastrarDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[]);
int listarDiscentes (int quantidadeDeDiscentes, Discente listaDiscentes[]);
int excluirDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[]);
int atualizarDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[], int sair);
int buscarDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[], int matricula);
int buscarDiscentePorId (int quantidadeDeDiscentes, Discente listaDiscentes[], int idDiscente);
