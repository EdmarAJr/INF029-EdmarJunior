#include <stdio.h> 
#include <stdlib.h>
#include "leituraEscrita.h"
#include "disciplinas.h"
#include "discentes.h"
#include "docentes.h"
#include "escola.h"
extern Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE];
extern int quantidadeDeDiscentes;
extern Docente listaDocentes[TAMANHO_ARRAY_DOCENTE];
extern Disciplina listaDisciplinas[TAMANHO_ARRAY_DISCIPLINA];

// char discentes[14] = "discentes.txt";
// char docentes[14] = "docentes.txt";
// char disciplinas[15] = "disciplinas.txt";

char linha[100];

// void lerDiscentesDeArquivo(char *nomeArquivo) {
// 		FILE *arquivo;
// 		arquivo = fopen(nomeArquivo, "r");
// 		if (arquivo) {
// 			while (!feof(arquivo)) {
// 				fgets(linha, sizeof(linha), arquivo);
// 			}
// 			fclose(arquivo);	
// 		} else {
// 				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
// 				return;
// 		}
// }

// void escreverDiscentesEmArquivo(char *nomeArquivo) {
// 	FILE *arquivo;
// 	arquivo = fopen(nomeArquivo, "w");
// 	if (arquivo) {
// 		while(feof(arquivo)){
// 			fputs(linha, arquivo);
// 			fgets(linha, sizeof(linha), arquivo);
// 		}
// 		fprintf(arquivo, linha);
// 		fclose(arquivo);
// 	} else{
// 		printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
// 		return;
// 	}
		
// }

// void lerDocentesDeArquivo(char *nomeArquivo) {
// 		FILE *arquivo = fopen(nomeArquivo, "r");
// 		if (arquivo == NULL) {
// 				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
// 				return;
// 		}

// 		// Lógica para ler os dados do arquivo listaDocentes

// 		fclose(arquivo);
// }

// void escreverDocentesEmArquivo(char *nomeArquivo) {
// 		FILE *arquivo = fopen(nomeArquivo, "w");
// 		if (arquivo == NULL) {
// 				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
// 				return;
// 		}

// 		// Lógica para escrever os dados dos docentes no arquivo

// 		fclose(arquivo);
// }

// void lerDisciplinasDeArquivo(char *nomeArquivo) {
// 		FILE *arquivo = fopen(nomeArquivo, "r");
// 		if (arquivo == NULL) {
// 				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
// 				return;
// 		}

// 		// Lógica para ler os dados do arquivo a estrutura listaDisciplinas

// 		fclose(arquivo);
// }

// void escreverDisciplinasEmArquivo(char *nomeArquivo) {
// 		FILE *arquivo = fopen(nomeArquivo, "w");
// 		if (arquivo == NULL) {
// 				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
// 				return;
// 		}

// 		// Lógica para escrever os dados dos disciplinas no arquivo

// 		fclose(arquivo);
// }


// Arquivo padrão
char arquivoDiscentes[] = "arquivoDiscentes.txt";
// Função para carregar discentes do arquivo para a memória
void lerDiscentesDeArquivo(char *nomeArquivo) {
	//printf("A quantidade de discentes é: %d", quantidadeDeDiscentes);
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Arquivo %s não encontrado. Criando novo...\n", nomeArquivo);
        arquivo = fopen(nomeArquivo, "w"); // cria se não existir
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo %s\n", nomeArquivo);
            return;
        }
        fclose(arquivo);
        return;
    }
	int contador = 0;
    while (fscanf(arquivo, "%d;%49[^;];%c;%d/%d/%d;%14[^;];%d\n",
                  &listaDiscentes[contador].matricula,
                  listaDiscentes[contador].nome,
                  &listaDiscentes[contador].sexo,
                  &listaDiscentes[contador].dataNascimento.dia,
                  &listaDiscentes[contador].dataNascimento.mes,
                  &listaDiscentes[contador].dataNascimento.ano,
                  listaDiscentes[contador].cpf,
                  &listaDiscentes[contador].ativo) == 8) {

        contador++;
        if (contador >= TAMANHO_ARRAY_DISCENTE) break;
    }

    fclose(arquivo);
}

// Função para salvar discentes da memória no arquivo
void escreverDiscentesEmArquivo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < quantidadeDeDiscentes; i++) {
        fprintf(arquivo, "%d;%s;%c;%d/%d/%d;%s;%d\n",
                listaDiscentes[i].matricula,
                listaDiscentes[i].nome,
                listaDiscentes[i].sexo,
                listaDiscentes[i].dataNascimento.dia,
                listaDiscentes[i].dataNascimento.mes,
                listaDiscentes[i].dataNascimento.ano,
                listaDiscentes[i].cpf,
                listaDiscentes[i].ativo);
    }

    fclose(arquivo);
}
