#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "docentes.h"
#include "menu.h"
#include "escola.h"
#include  "auxiliar.h"

Docente listaDocentes[TAMANHO_ARRAY_DOCENTE];
int quantidadeDeDocentes = 0;
int idDocente = 0;

int cadastrarDocente (int quantidadeDeDocentes, Docente listaDocentes[]) {
	if (quantidadeDeDocentes == TAMANHO_ARRAY_DOCENTE) {
		printf("\nQuantidade maxima de Docentes alcancada!\n");
	} else {
		printf("\nInforme o id do docente: ");
		scanf("%d", &listaDocentes[quantidadeDeDocentes].idDocente); 
		
		int encontrado = buscarDocente(quantidadeDeDocentes, listaDocentes, listaDocentes[quantidadeDeDocentes].idDocente); 
		getchar();

		if(encontrado == 1){
			return 1;
		} else if(encontrado == -1 ){
			return 2;
		} else {
			printf("Informe o nome da(o) docente: ");
			fgets(listaDocentes[quantidadeDeDocentes].nome, 50, stdin);
			//remover o '\n' se ele existir
			listaDocentes[quantidadeDeDocentes].nome[strcspn(listaDocentes[quantidadeDeDocentes].nome, "\n")] = '\0';

			char verificarsexo;

			printf("Digite o sexo da(o) docente (M) ou (F): ");
			scanf("%c", &verificarsexo);

			int retornoDoSexo = verificadorDeSexo(verificarsexo);
			if(retornoDoSexo == 1){
				return 3;
			} else {
				listaDocentes[quantidadeDeDocentes].sexo = verificarsexo;// ih agora giovani ???  
				getchar();	
			}
			int validarDia, validarMes, validarAno;
						
			printf("Digite o dia de nascimento: ");
            scanf("%d", &validarDia);
            
			if(validarDia <=0 || validarDia > 31){
				return 4;
            } else {
				listaDocentes[quantidadeDeDocentes].dataNascimento.dia = validarDia;
            }

            printf("Digite o mes de nascimento: ");
            scanf("%d", &validarMes);
					
			if(validarMes <=0 || validarMes > 12){
				return 4;
			} else {
				listaDocentes[quantidadeDeDocentes].dataNascimento.mes = validarMes;
			}

			printf("Digite o ano de nascimento: ");
            scanf("%d", &validarAno);
            getchar();
            
			if(validarAno <=1900 || validarMes > 2024){
                return 4;
            } else {
				listaDocentes[quantidadeDeDocentes].dataNascimento.ano =validarAno;
            }
						
			char cpf[15];
			printf("Digite cpf da(o) docente: ");
			fgets(cpf, 15, stdin);

			int retorno = validarCPF("Docente", cpf);						
			if(retorno == -1){
				return 5;
			} else if(retorno == 1){
				return 6;
			} else {
				strcpy(listaDocentes[quantidadeDeDocentes].cpf, cpf);
				listaDocentes[quantidadeDeDocentes].ativo = 1;
				return 7;
			}			
		}
	}
}

void listarDocentes (int quantidadeDeDocentes, Docente listaDocentes[]) {
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

int atualizarDocente (int quantidadeDeDocentes, Docente listaDocentes[], int sair) {
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
			case 1: {
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
		}
	}
}

int excluirDocente (int quantidadeDeDocentes, Docente listaDocentes[]) {
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
						strcpy(listaDocentes[j].nome, listaDocentes[j+1].nome); 
						listaDocentes[j].sexo = listaDocentes[j+1].sexo;
						listaDocentes[j].dataNascimento = listaDocentes[j+1].dataNascimento;
						strcpy(listaDocentes[j].cpf, listaDocentes[j+1].cpf);
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

int buscarDocentePorId (int quantidadeDeDocentes, Docente listaDocentes[], int idDocente){
	int docenteEncontrado = 0;

	if (idDocente <= 0) {
		docenteEncontrado = -1;
    	return docenteEncontrado; //nao existe 
	} else {
		for (int i = 0; i < quantidadeDeDocentes; i++) {
			if (idDocente == listaDocentes[i].idDocente && listaDocentes[i].ativo) {
				printf("Docente: %s", listaDocentes[i].nome);
				break;
			}
		}
        return docenteEncontrado;
	}
}
