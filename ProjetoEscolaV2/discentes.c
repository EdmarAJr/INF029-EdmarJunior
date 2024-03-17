#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "discentes.h"
#include "menu.h"
#include "escola.h"

int cadastrarDiscentes(int quantidadeDeDiscentes, Discente listaDiscentes[]) {
	if (quantidadeDeDiscentes == TAMANHO_ARRAY_DISCENTE) {
		printf("\nQuantidade maxima de discentes alcancada!\n");
	} else {
		printf("\nInforme o numero de matricula: ");
		scanf("%d", &listaDiscentes[quantidadeDeDiscentes].matricula); 
		
		int encontrado = buscarDiscente(quantidadeDeDiscentes, listaDiscentes, listaDiscentes[quantidadeDeDiscentes].matricula); 
		 getchar();
				if(encontrado == 1){
						return encontrado;
				} else if(encontrado == -1 ){
						return encontrado;
				} else {
						printf("Informe o nome da(o) discente: ");
						fgets(listaDiscentes[quantidadeDeDiscentes].nome, 50, stdin);
						size_t ln = strlen(listaDiscentes[quantidadeDeDiscentes].nome);

						printf("Digite o sexo da(o) discente (M) ou (F): ");
						scanf(" %c", &listaDiscentes[quantidadeDeDiscentes].sexo); 
						getchar();

						// temporario
						printf("Digite o dia de nascimento: ");
						scanf("%d", &listaDiscentes[quantidadeDeDiscentes].dataNascimento.dia);

						printf("Digite o mes de nascimento: ");
						scanf("%d", &listaDiscentes[quantidadeDeDiscentes].dataNascimento.mes);

						printf("Digite o ano de nascimento: ");
						scanf("%d", &listaDiscentes[quantidadeDeDiscentes].dataNascimento.ano);
						getchar();

						printf("Digite cpf da(o) discente : ");
						fgets(listaDiscentes[quantidadeDeDiscentes].cpf, 15, stdin);
						size_t lr = strlen(listaDiscentes[quantidadeDeDiscentes].cpf);
						lr = strlen(listaDiscentes[quantidadeDeDiscentes].cpf) - 1;

						listaDiscentes[quantidadeDeDiscentes].ativo = 1;
				}
	}
}

int listarDiscentes(int quantidadeDeDiscentes, Discente listaDiscentes[]) {
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

int atualizarDiscente(int quantidadeDeDiscentes, Discente listaDiscentes[], int sair) {
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
			// case 4: {
			// 	char cpfAtualizado[15] ;
			// 	printf("Digite o novo cpf da(o) discente: ");
			// 	getchar();
			// 	fgets(cpfAtualizado, sizeof(cpfAtualizado), stdin);
			// 	strcpy(listaDiscentes[quantidadeDeDiscentes-1].cpf, cpfAtualizado);
			// 	break;
			// }
		}
	}
}

int excluirDiscente(int quantidadeDeDiscentes, Discente listaDiscentes[]) {
	int matricula;
	
	printf("\nInforme o numero de matricula: ");
	scanf("%d", &matricula); 
	 int encontrado = buscarDiscente(quantidadeDeDiscentes, listaDiscentes, matricula); 
	
		if(encontrado == 1){
				for (int i = 0; i < quantidadeDeDiscentes; i++) {
						if (matricula == listaDiscentes[i].matricula && listaDiscentes[i].ativo) {
								listaDiscentes[i].ativo = -1;
								//esta apesentando erro quando a quantidade de dicente é 1
								for (int j = i; j < quantidadeDeDiscentes - 1; j++) {
									listaDiscentes[j].matricula = listaDiscentes[j+1].matricula;
									//listaDiscentes[j].matricula = listaDiscentes[j+1].nome; //nao esta funcionando
									listaDiscentes[j].sexo = listaDiscentes[j+1].sexo;
									listaDiscentes[j].dataNascimento = listaDiscentes[j + 1].dataNascimento; //nao esta funcionando
									//listaDiscentes[j].cpf = listaDiscentes[j+1].cpf; //nao esta funcionando
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