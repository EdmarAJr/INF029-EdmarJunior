#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} DataDocente;

typedef struct docente {
	int idDocente;
	char nome[50];
	char sexo;
	DataDocente dataNascimento;
	char cpf[15];  
	int ativo;
} Docente;

int cadastrarDocente (int quantidadeDeDocentes, Docente listaDocentes[]);
int listarDocentes (int quantidadeDeDocentes, Docente listaDocentes[]);
int excluirDocente (int quantidadeDeDocentes, Docente listaDocentes[]);
int atualizarDocente (int quantidadeDeDocentes, Docente listaDocentes[], int sair);
int buscarDocente (int quantidadeDeDocentes, Docente listaDocentes[], int idDocente);
int buscarDocentePorId (int quantidadeDeDocentes, Docente listaDocentes[], int idDocente);