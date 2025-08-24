#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escola.h"

#define MAX_VAGAS 40  

typedef struct disciplina{
	int idDisciplina; 
	int idDocente; 
	char nome[500];
	int cargaHoraria; 
	int vagasDisponiveis; 
	int quantidadeDeDiscentesMatriculados; 
	int idAlunosMatriculados[MAX_VAGAS];
	int ativo; 
} Disciplina;

int cadastrarDisciplina (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[]);
void listarDisciplinas (int quantidadeDeDisciplinas,Disciplina listaDisciplinas[]);
int atualizarDisciplina (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[], int sair);
int excluirDisciplina (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[]);
int buscarDisciplina (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[], int idDisciplina);
int listarDisciplinasComAlunos(int quantidadeDeDisciplinas,Disciplina listaDisciplinas[]);
