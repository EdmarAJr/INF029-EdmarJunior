#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escola.h"
#include "menu.h"
#include "discentes.h"
#include "auxiliar.h"
#include "leituraEscrita.h"
extern char arquivoDiscentes[13];


Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE];

int quantidadeDeDiscentes = 0; 
int matricula = 0;

int cadastrarDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[]) {
	if (quantidadeDeDiscentes == TAMANHO_ARRAY_DISCENTE) {
		printf("\nQuantidade maxima de discentes alcancada!\n");
	} else {
		printf("\nInforme o numero de matricula: ");
		scanf("%d", &listaDiscentes[quantidadeDeDiscentes].matricula); 
		
		int encontrado = buscarDiscente(quantidadeDeDiscentes, listaDiscentes, listaDiscentes[quantidadeDeDiscentes].matricula); 
		getchar();
		
		if(encontrado == 1){
			return 1;
		} else if(encontrado == -1 ){
			return 2;
		} else {
			printf("Informe o nome da(o) discente: ");
			fgets(listaDiscentes[quantidadeDeDiscentes].nome, 50, stdin);
			// remover o '\n' se ele existir
			listaDiscentes[quantidadeDeDiscentes].nome[strcspn(listaDiscentes[quantidadeDeDiscentes].nome, "\n")] = '\0';

			char verificarsexo;

			printf("Digite o sexo da(o) discente (M) ou (F): ");
            scanf("%c", &verificarsexo);

			int retornoDoSexo = verificadorDeSexo(verificarsexo);

			if(retornoDoSexo == 1){
				return 3;
      }  else{
				listaDiscentes[quantidadeDeDiscentes].sexo = verificarsexo; 
				getchar();
			}

			int validarDia, validarMes, validarAno;

			printf("Digite o dia de nascimento (DD): ");
			scanf("%d", &validarDia);

			if(validarDia <=0 || validarDia > 31){
				return 4;
			} else {
				listaDiscentes[quantidadeDeDiscentes].dataNascimento.dia = validarDia;
			}

			printf("Digite o mes de nascimento (MM): ");
			scanf("%d", &validarMes);
			if(validarMes <=0 || validarMes > 12){
				return 4;
			} else {
				listaDiscentes[quantidadeDeDiscentes].dataNascimento.mes = validarMes;
			}

            printf("Digite o ano de nascimento (AAAA): ");
            scanf("%d", &validarAno);
            getchar();
            if(validarAno <=1900 || validarMes > 2024){
				return 4;
            } else {
				listaDiscentes[quantidadeDeDiscentes].dataNascimento.ano =validarAno;
			}

			char cpf[15];
			printf("Digite cpf da(o) discente: ");
			fgets(cpf, 15, stdin);

			int retorno = validarCPF("Discente", cpf);						
			if(retorno == -1){
				return 5;
			} else if(retorno == 1){
				return 6;
			}	else {
				strcpy(listaDiscentes[quantidadeDeDiscentes].cpf, cpf);
				listaDiscentes[quantidadeDeDiscentes].ativo = 1;
				return 7;
			}			
		}
		quantidadeDeDiscentes++;
	}
}

void listarDiscentes (int quantidadeDeDiscentes, Discente listaDiscentes[]) {
		if (quantidadeDeDiscentes == 0) {
		printf("\nErro: Nenhum registro de discente cadastrado!\n\n");
	} else {
		for (int i = 0; i < quantidadeDeDiscentes; i++) {
			if (listaDiscentes[i].ativo == 1) {
					printf("_____________________________________________");
					printf("\nMatricula: %d\n", listaDiscentes[i].matricula);
					printf("Nome: %s\n", listaDiscentes[i].nome);
					printf("Sexo: %c\n", listaDiscentes[i].sexo);
					printf("Data Nascimento: %d/%d/%d\n",
							listaDiscentes[i].dataNascimento.dia,
							listaDiscentes[i].dataNascimento.mes,
							listaDiscentes[i].dataNascimento.ano);
					printf("CPF: %s\n", listaDiscentes[i].cpf);
					printf("_____________________________________________\n");
					
			}
		}
	 }
}

int atualizarDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[], int sair) {
	int opcaoAtualizar;

	while (!sair) {
		int matricula;
		printf("\nInforme o numero de matricula: ");
		scanf("%d", &matricula); 
		int encontrado = buscarDiscente(quantidadeDeDiscentes, listaDiscentes, matricula); 
		
		if(encontrado == 1){
				opcaoAtualizar = opcaoMenuAtualizarDiscente(); 
		} else if(encontrado == -1 ){
					return encontrado;
			} else{
					return encontrado;
		}

		switch (opcaoAtualizar) {
			case 0: {
				sair = 1;
				break;
			}
			case 1: {  
				char nomeAtualizado[50];

				printf("Informe o novo nome da(o) discente: ");
				getchar();
				fgets(nomeAtualizado, sizeof(nomeAtualizado), stdin);
				strcpy(listaDiscentes[quantidadeDeDiscentes-1].nome, nomeAtualizado);
				break;
			}
			case 2: {
				printf("Digite o novo sexo da(o) discente (M) ou (F): ");
				scanf(" %c", &listaDiscentes[quantidadeDeDiscentes-1].sexo);
				getchar();
				break;
			}
			case 3: {
				// temporario
				printf("Digite o novo dia de nascimento: ");
				scanf("%d", &listaDiscentes[quantidadeDeDiscentes-1].dataNascimento.dia);

				printf("Digite o novo mes de nascimento: ");
				scanf("%d", &listaDiscentes[quantidadeDeDiscentes-1].dataNascimento.mes);

				printf("Digite o novo ano de nascimento: ");
				scanf("%d", &listaDiscentes[quantidadeDeDiscentes-1].dataNascimento.ano);
				getchar();
				break;
			}
		}
	}
}

int excluirDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[]) {
	int matricula;
	
	printf("\nInforme o numero de matricula: ");
	scanf("%d", &matricula); 
	int encontrado = buscarDiscente(quantidadeDeDiscentes, listaDiscentes, matricula); 
	
	if(encontrado == 1){
		for (int i = 0; i < quantidadeDeDiscentes; i++) {
			if (matricula == listaDiscentes[i].matricula && listaDiscentes[i].ativo) {
				listaDiscentes[i].ativo = -1;
				for (int j = i; j < quantidadeDeDiscentes - 1; j++) {
					listaDiscentes[j].matricula = listaDiscentes[j+1].matricula;
					strcpy(listaDiscentes[j].nome, listaDiscentes[j+1].nome); 
					listaDiscentes[j].sexo = listaDiscentes[j+1].sexo;
					listaDiscentes[j].dataNascimento = listaDiscentes[j+1].dataNascimento;
					strcpy(listaDiscentes[j].cpf, listaDiscentes[j+1].cpf);
					listaDiscentes[j].ativo = listaDiscentes[j+1].ativo;
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

int buscarDiscente (int quantidadeDeDiscentes, Discente listaDiscentes[], int matricula) {
	int discenteEncontrado = 0;
	
	if (matricula <= 0) {
		discenteEncontrado = -1;
		return discenteEncontrado;
	} else {
		for (int i = 0; i < quantidadeDeDiscentes; i++) {
			if (matricula == listaDiscentes[i].matricula && listaDiscentes[i].ativo) {
				discenteEncontrado = 1;
				break;
			}
		} 
		return discenteEncontrado;
	}
}

int buscarDiscentePorId (int quantidadeDeDiscentes, Discente listaDiscentes[], int idDiscente){
int discenteEncontrado = 0;

	if (idDiscente <= 0) {
		discenteEncontrado = -1;
		return discenteEncontrado; //nao existe 
	} else {
		for (int i = 0; i < quantidadeDeDiscentes; i++) {
			if (idDiscente == listaDiscentes[i].matricula && listaDiscentes[i].ativo) {
				printf("Nome: %s", listaDiscentes[i].nome);
				break;
			}
		}
		return discenteEncontrado;
	}
}