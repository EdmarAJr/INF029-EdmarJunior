#include <stdio.h>
#include <stdlib.h>
#include "escola.h"
#include "menu.h"
#include "disciplinas.h"
#include "docentes.h"
#include "discentes.h"

extern Docente listaDocentes[TAMANHO_ARRAY_DOCENTE];
extern Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE];
extern int quantidadeDeDiscentes;  
extern int quantidadeDeDocentes;

Disciplina listaDisciplinas[TAMANHO_ARRAY_DISCIPLINA];

int quantidadeDeDisciplinas = 0;
int idDisciplina = 0;

int cadastrarDisciplina (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[]){ 

	int opcao;
	if (quantidadeDeDisciplinas == TAMANHO_ARRAY_DISCIPLINA) {
		return 2;
	} else {
		printf("\nInforme o id da disciplina: ");
		scanf("%d", &listaDisciplinas[quantidadeDeDisciplinas].idDisciplina); 
		int encontrado = buscarDisciplina(quantidadeDeDisciplinas, listaDisciplinas, 
		listaDisciplinas[quantidadeDeDisciplinas].idDisciplina); 
		getchar(); 

		if(encontrado == 1){
			return 1;
		} else if(encontrado == -1 ){
			return 2;
		} else {
			int idDocente;
			printf("Digite o id docente para a disciplina: ");
			scanf("%d", &idDocente);

			int resultado = buscarDocente (quantidadeDeDocentes, listaDocentes, idDocente);

			if(resultado == - 1){
				return 3;
			} else if (resultado == 0){
				return 4;
			} else {
				listaDisciplinas[quantidadeDeDisciplinas].idDocente = idDocente;
			}
			printf("Informe o nome da disciplina: ");
			getchar();
			fgets(listaDisciplinas[quantidadeDeDisciplinas].nome, 50, stdin);
			// remover o '\n' se ele existir
			listaDisciplinas[quantidadeDeDisciplinas].nome[strcspn(listaDisciplinas[quantidadeDeDisciplinas].nome, "\n")] = '\0';              

			printf("informe a carga horaria da disciplina: ");
			scanf("%d", &cargaHoraria);

			listaDisciplinas[quantidadeDeDisciplinas].vagasDisponiveis = MAX_VAGAS;
			
			int opcaoCadastro;

			printf("Deseja adicionar um aluno? (0 - nao o | 1 - sim): ");
			scanf("%d", &opcaoCadastro); 
			if (opcaoCadastro != 1 && opcaoCadastro != 0){
				printf("opcao invalida!\n");
					return opcaoCadastro;
			} else {
				while(opcaoCadastro != 0){
					if(listaDisciplinas[quantidadeDeDisciplinas].vagasDisponiveis == 0){
						printf("\nQuantidade maxima de discentes alcancada nesta disciplina!\n");
						break;
					} else {		
						if (opcaoCadastro == 1){
							int idDiscente;
							printf("digite o id do aluno: ");
							scanf("%d", &idDiscente);
						
							int resultado = buscarDiscente (quantidadeDeDiscentes, listaDiscentes, idDiscente); 
						
							if(resultado == -1){
								return 5;
							} else if (resultado == 0){
								return 6;
							} else if (resultado == 1){
								for(int i = 0; i < quantidadeDeDisciplinas; i++){
									listaDisciplinas[quantidadeDeDisciplinas].idAlunosMatriculados[i] = idDiscente;
									listaDisciplinas[quantidadeDeDisciplinas].vagasDisponiveis--;
									printf("Aluno adicionado!\n");
								}
							}
							printf("Deseja adicionar outro aluno? (0 - nao | 1 - sim): ");
        					scanf("%d", &opcaoCadastro);
						}
					}
				}
			}
		}
	}
	listaDisciplinas[quantidadeDeDisciplinas].ativo = 1;
	return 7;
}

void listarDisciplinas (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[]) {
	if (quantidadeDeDisciplinas == 0) {
		printf("\nErro: Nenhum registro de disciplina cadastrada!\n");
	} else {
		for (int i = 0; i < quantidadeDeDisciplinas; i++) {
			if (listaDisciplinas[i].ativo == 1) {
				printf("_____________________________________________");
				printf("\nidDisciplina: %d\n", listaDisciplinas[i].idDisciplina);
				printf("Nome: %s\n", listaDisciplinas[i].nome);
				printf("Docente: %d\n", listaDisciplinas[i].idDocente);
				buscarDocentePorId(quantidadeDeDocentes, listaDocentes, listaDisciplinas[i].idDocente);
				printf("Vagas Disponiveis: %d\n", listaDisciplinas[i].vagasDisponiveis);
				printf("_____________________________________________\n");
				
			}
		}
	}
} 

int atualizarDisciplina (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[], int sair){
	int opcaoAtualizar;
	int idDisciplina;

	while (!sair) {
		printf("\nInforme o numero de idDisciplina: ");
		scanf("%d", &idDisciplina);
		int encontrado = buscarDisciplina(quantidadeDeDisciplinas, listaDisciplinas, idDisciplina);
		
		if(encontrado == 1){
				opcaoAtualizar = opcaoMenuAtualizarDisciplina();
		} else if(encontrado == -1 ){
				printf("Numero de idDisciplina invalida. Tente novamente! \n");
		} else{
				printf("\nErro: numero de idDisciplina nao encontrado! \n");
				return 0;
		}

		switch (opcaoAtualizar) {
			case 0: {
				sair = 1;
				break;
			}
			case 1: {  
				char nomeAtualizado[50];

				printf("Informe o novo nome da Disciplina: ");
				getchar();
				fgets(nomeAtualizado, sizeof(nomeAtualizado), stdin);
				strcpy(listaDisciplinas[quantidadeDeDisciplinas].nome, nomeAtualizado);
				break;
			}
			case 2: {
				printf("Digite o novo idDocente: ");
				scanf("%d", &listaDocentes[quantidadeDeDocentes].idDocente);
				break;
			}
		}
	}
}

int excluirDisciplina (int quantidadeDeDiscentes, Disciplina listaDisciplinas[]){
	int idDisciplina;

	printf("\nInforme o numero do idDisciplina: ");
	scanf("%d", &idDisciplina); 
	
	int encontrado = buscarDisciplina(quantidadeDeDisciplinas, listaDisciplinas, idDisciplina); 

		if(encontrado == 1){
			for (int i = 0; i < quantidadeDeDisciplinas; i++) {
					if (idDisciplina == listaDisciplinas[i].idDisciplina && listaDisciplinas[i].ativo) {
						listaDisciplinas[i].ativo = -1;
						for (int j = i; j < quantidadeDeDisciplinas - 1; j++) {
							listaDisciplinas[j].idDocente = listaDisciplinas[j+1].idDocente;
							listaDisciplinas[j].idDisciplina = listaDisciplinas[j+1].idDisciplina;
							strcpy(listaDisciplinas[j].nome, listaDisciplinas[j+1].nome);
							listaDisciplinas[j].vagasDisponiveis = listaDisciplinas[j+1].vagasDisponiveis;
							for (int k = j; k < quantidadeDeDisciplinas; k++) {
								listaDisciplinas[j].idAlunosMatriculados[k] = listaDisciplinas[k+1].idAlunosMatriculados[k+1];    
							}
							listaDisciplinas[j].ativo = listaDisciplinas[j+1].ativo;
						}
						return encontrado;
					}  
			} 
		} else if(encontrado == -1 ){
			return encontrado;
		} else{
			return encontrado;
		}
}

int buscarDisciplina (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[], int idDisciplina) {
	int disciplinaEncontrada = 0;

	if (idDisciplina <= 0) {
		disciplinaEncontrada = -1;
		return disciplinaEncontrada;
	} else {
		for (int i = 0; i <  quantidadeDeDisciplinas; i++) {
			if (idDisciplina == listaDisciplinas[i].idDisciplina && listaDisciplinas[i].ativo) {
				disciplinaEncontrada = 1;
				break;
			}
		}
		return disciplinaEncontrada;
	}
}

int listarDisciplinasComAlunos (int quantidadeDeDisciplinas, Disciplina listaDisciplinas[]){
	int idParaMostarDiscplina;
	printf("digite o id da disciplina\n");
	scanf("%d", &idParaMostarDiscplina);
	int retornoDaBusca = buscarDisciplina(quantidadeDeDisciplinas,listaDisciplinas,idParaMostarDiscplina);
	if(retornoDaBusca == -1){
		printf("idDisciplina invalido");
		return -1;
	} else if (retornoDaBusca == 1){
		printf("idDisciplina valido");
		for (int i=0; i < quantidadeDeDisciplinas; i++){
			if(idParaMostarDiscplina == listaDisciplinas[i].idDisciplina){
    			//pensar na logica de contar os alunos matriculados          
				for (int k=0; k < listaDisciplinas[i].vagasDisponiveis; i++){
					buscarDiscentePorId(quantidadeDeDiscentes, listaDiscentes,idParaMostarDiscplina);
				}
			}
		}
	}
}