#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "docentes.h"
#include "menu.h"
#include "escola.h"

int cadastrarDocentes(int quantidadeDeDocentes, Docente listaDocentes[]) {
	if (quantidadeDeDocentes == TAMANHO_ARRAY_DOCENTE) {
		printf("\nQuantidade maxima de Docentes alcancada!\n");
	} else {
		printf("\nInforme o id do docente: ");
		scanf("%d", &listaDocentes[quantidadeDeDocentes].idDocente); 
		 int encontrado = buscarDocente(quantidadeDeDocentes, listaDocentes, listaDocentes[quantidadeDeDocentes].idDocente); 
		 getchar();
				if(encontrado == 1){
						printf("Erro: id ja cadastrado!\n");
				} else if(encontrado == -1 ){
						printf("IdDocente invalido. Tente novamente! \n");
				} else {
						printf("Informe o nome da(o) docente: ");
						fgets(listaDocentes[quantidadeDeDocentes].nome, 50, stdin);
						size_t ln = strlen(listaDocentes[quantidadeDeDocentes].nome);

						printf("Digite o sexo da(o) docente (M) ou (F): ");
						scanf(" %c", &listaDocentes[quantidadeDeDocentes].sexo); 
						getchar();

						// temporario
						printf("Digite o dia de nascimento: ");
						scanf("%d", &listaDocentes[quantidadeDeDocentes].dataNascimento.dia);

						printf("Digite o mes de nascimento: ");
						scanf("%d", &listaDocentes[quantidadeDeDocentes].dataNascimento.mes);

						printf("Digite o ano de nascimento: ");
						scanf("%d", &listaDocentes[quantidadeDeDocentes].dataNascimento.ano);
						getchar();

						printf("Digite cpf da(o) docente: ");
						fgets(listaDocentes[quantidadeDeDocentes].cpf, 15, stdin);
						size_t lr = strlen(listaDocentes[quantidadeDeDocentes].cpf);
						lr = strlen(listaDocentes[quantidadeDeDocentes].cpf) - 1;

						listaDocentes[quantidadeDeDocentes].ativo = 1;
						return 1;
				}
	}
}

int listarDocentes(int quantidadeDeDocentes, Docente listaDocentes[]) {
	if (quantidadeDeDocentes == 0) {
		printf("\nErro: Nenhum registro de docente cadastrado!\n");
	} else {
		for (int i = 0; i < quantidadeDeDocentes; i++) {
			if (listaDocentes[i].ativo == 1) {
				printf("_____________________________________________");
				printf("\nidDocente: %d\n", listaDocentes[i].idDocente);
				printf("Nome: %s\n", listaDocentes[i].nome);
				printf("Sexo: %c\n", listaDocentes[i].sexo);
				printf("Data Nascimento: %d/%d/%d\n",
							 listaDocentes[i].dataNascimento.dia,
							 listaDocentes[i].dataNascimento.mes,
							 listaDocentes[i].dataNascimento.ano);
				printf("CPF: %s\n", listaDocentes[i].cpf);
				printf("_____________________________________________\n");
			}
		}
	}
}

int atualizarDocente(int quantidadeDeDocentes, Docente listaDocentes[], int sair) {
	int opcaoAtualizar;
	int idDocente;
	
	while (!sair) {
		printf("\nInforme o numero de idDocente: ");
		scanf("%d", &idDocente); 
		int encontrado = buscarDocente(quantidadeDeDocentes, listaDocentes, idDocente); 

		if(encontrado == 1){
				opcaoAtualizar = opcaoMenuAtualizarDocente(); 
		} else if(encontrado == -1 ){
				printf("Numero de idDocente invalido. Tente novamente! \n");
		} else{
				printf("\nErro: numero de idDocente nao encontrado! \n");
				return 0;
		}

		switch (opcaoAtualizar) {
			case 0: {
				sair = 1;
				break;
			}
			case 1: {  // essa parte de atualizar ainda precisa ser aprimorada pois chama a funcao buscar e ja exibe erro
				char nomeAtualizado[50];

				printf("Informe o novo nome da(o) Docente: ");
				getchar();
				fgets(nomeAtualizado, sizeof(nomeAtualizado), stdin);
				strcpy(listaDocentes[quantidadeDeDocentes-1].nome, nomeAtualizado);

				break;
			}
			case 2: {
				printf("Digite o novo sexo da(o) Docente (M) ou (F): ");
				scanf(" %c", &listaDocentes[quantidadeDeDocentes-1].sexo);
				getchar();
				break;
			}
			case 3: {
				// temporario
				printf("Digite o novo dia de nascimento: ");
				scanf("%d", &listaDocentes[quantidadeDeDocentes-1].dataNascimento.dia);

				printf("Digite o novo mes de nascimento: ");
				scanf("%d", &listaDocentes[quantidadeDeDocentes-1].dataNascimento.mes);

				printf("Digite o novo ano de nascimento: ");
				scanf("%d", &listaDocentes[quantidadeDeDocentes-1].dataNascimento.ano);
				getchar();
				break;
			}
			// case 4: {
			// 	char cpfAtualizado[15] ;
			// 	printf("Digite o novo cpf da(o) Docente: ");
			// 	getchar();
			// 	fgets(cpfAtualizado, sizeof(cpfAtualizado), stdin);
			// 	strcpy(listaDocentes[quantidadeDeDocentes-1].cpf, cpfAtualizado);

			// 	break;
			// }
		}
	}
}

int excluirDocente(int quantidadeDeDocentes, Docente listaDocentes[]) {
	int idDocente;
	printf("\nInforme o numero de idDocente: ");
	scanf("%d", &idDocente); 
	int encontrado = buscarDocente(quantidadeDeDocentes, listaDocentes, idDocente); 

		if(encontrado == 1){
				for (int i = 0; i < quantidadeDeDocentes; i++) {
						if (idDocente == listaDocentes[i].idDocente && listaDocentes[i].ativo) {
								listaDocentes[i].ativo = -1;

								for (int j = i; j < quantidadeDeDocentes - 1; j++) {
									listaDocentes[j].idDocente = listaDocentes[j+1].idDocente;
									//listaDocentes[j].idDocente = listaDocentes[j+1].nome; //nao esta funcionando
									listaDocentes[j].sexo = listaDocentes[j+1].sexo;
									//listaDocentes[j].dataNascimento = listaDocentes[j + 1].dataNascimento; //nao esta funcionando
									//listaDocentes[j].cpf = listaDocentes[j+1].cpf; //nao esta funcionando
									listaDocentes[j].ativo = listaDocentes[j+1].ativo;
								}
						}  
				} 
		} else if(encontrado == -1 ){
				return encontrado;
		}	else{
			return encontrado;
		}
}

int buscarDocente (int quantidadeDeDocentes, Docente listaDocentes[], int idDocente) {
   int docenteEncontrado = 0;

	if (idDocente <= 0) {
		docenteEncontrado = -1;
		return docenteEncontrado;
	} else {
		for (int i = 0; i < quantidadeDeDocentes; i++) {
			if (idDocente == listaDocentes[i].idDocente && listaDocentes[i].ativo) {
				docenteEncontrado = 1;
				break;
			}
		}
				return docenteEncontrado;
	}
}
