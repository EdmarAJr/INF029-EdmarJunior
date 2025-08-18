#include <stdio.h> 
#include <stdlib.h>
#include "leituraEscrita.h"
#include "disciplinas.h"
#include "discentes.h"
#include "docentes.h"
#include "escola.h"

char discentes[14] = "discentes.txt";
char docentes[14] = "docentes.txt";
char disciplinas[15] = "disciplinas.txt";

char linha[100];

void lerDiscentesDeArquivo(char *nomeArquivo) {
		FILE *arquivo;
		arquivo = fopen(nomeArquivo, "r");
		if (arquivo) {
			while (!feof(arquivo)) {
				fgets(linha, sizeof(linha), arquivo);
			}
			fclose(arquivo);	
		} else {
				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
				return;
		}
}

void escreverDiscentesEmArquivo(char *nomeArquivo) {
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "w");
	if (arquivo) {
		while(feof(arquivo)){
			fputs(linha, arquivo);
			fgets(linha, sizeof(linha), arquivo);
		}
		fprintf(arquivo, linha);
		fclose(arquivo);
	} else{
		printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
		return;
	}
		
}

void lerDocentesDeArquivo(char *nomeArquivo) {
		FILE *arquivo = fopen(nomeArquivo, "r");
		if (arquivo == NULL) {
				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
				return;
		}

		// Lógica para ler os dados do arquivo listaDocentes

		fclose(arquivo);
}

void escreverDocentesEmArquivo(char *nomeArquivo) {
		FILE *arquivo = fopen(nomeArquivo, "w");
		if (arquivo == NULL) {
				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
				return;
		}

		// Lógica para escrever os dados dos docentes no arquivo

		fclose(arquivo);
}

void lerDisciplinasDeArquivo(char *nomeArquivo) {
		FILE *arquivo = fopen(nomeArquivo, "r");
		if (arquivo == NULL) {
				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
				return;
		}

		// Lógica para ler os dados do arquivo a estrutura listaDisciplinas

		fclose(arquivo);
}

void escreverDisciplinasEmArquivo(char *nomeArquivo) {
		FILE *arquivo = fopen(nomeArquivo, "w");
		if (arquivo == NULL) {
				printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
				return;
		}

		// Lógica para escrever os dados dos disciplinas no arquivo

		fclose(arquivo);
}