#include <stdio.h> 
#include <stdlib.h>
#include "leituraEscrita.h"
#include "disciplinas.h"
#include "discentes.h"
#include "docentes.h"
#include "escola.h"
extern Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE];
extern Docente listaDocentes[TAMANHO_ARRAY_DOCENTE];
extern Disciplina listaDisciplinas[TAMANHO_ARRAY_DISCIPLINA];

extern int quantidadeDeDiscentes;
extern int quantidadeDeDocentes;
extern int quantidadeDeDisciplinas;

char linha[100];

int contadorDiscente = 0;
int contadorDocente = 0;
int contadorDisciplina = 0;

// Arquivo padrão
char arquivoDiscentes[] = "arquivoDiscentes.txt";
char arquivoDocentes[] = "arquivoDocentes.txt";
char arquivoDisciplinas[] = "arquivoDisciplinas.txt";

// Função para carregar discentes do arquivo para a memória
void lerDiscentesDeArquivo(char *nomeArquivo) {
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
    while (fscanf(arquivo, "%d;%49[^;];%c;%d/%d/%d;%14[^;];%d,\n",
        &listaDiscentes[contadorDiscente].matricula,
        listaDiscentes[contadorDiscente].nome,
        &listaDiscentes[contadorDiscente].sexo,
        &listaDiscentes[contadorDiscente].dataNascimento.dia,
        &listaDiscentes[contadorDiscente].dataNascimento.mes,
        &listaDiscentes[contadorDiscente].dataNascimento.ano,
        listaDiscentes[contadorDiscente].cpf,
        &listaDiscentes[contadorDiscente].ativo) == 8) {
        //printf("Lendo discente %d\n", contadorDiscente + 1);
        contadorDiscente++;
        quantidadeDeDiscentes = contadorDiscente;
        if (contadorDiscente >= TAMANHO_ARRAY_DISCENTE) break;
    }
    fclose(arquivo);
}

// Função para salvar discentes da memória no arquivo
void escreverDiscentesEmArquivo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = contadorDiscente; i < quantidadeDeDiscentes; i++) {
        fprintf(arquivo, "%d;%s;%c;%d/%d/%d;%s;%d,\n",
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

void lerDocentesDeArquivo(char *nomeArquivo) {
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
    while (fscanf(arquivo, "%d;%49[^;];%c;%d/%d/%d;%14[^;];%d,\n",
        &listaDocentes[contadorDocente].idDocente,
        listaDocentes[contadorDocente].nome,
        &listaDocentes[contadorDocente].sexo,
        &listaDocentes[contadorDocente].dataNascimento.dia,
        &listaDocentes[contadorDocente].dataNascimento.mes,
        &listaDocentes[contadorDocente].dataNascimento.ano,
        listaDocentes[contadorDocente].cpf,
        &listaDocentes[contadorDocente].ativo) == 8) {
        contadorDocente++;
        quantidadeDeDocentes = contadorDocente;
        if (contadorDocente >= TAMANHO_ARRAY_DOCENTE) break;
    }
    fclose(arquivo);
}

// Função para salvar discentes da memória no arquivo
void escreverDocentesEmArquivo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = contadorDocente; i < quantidadeDeDocentes; i++) {
        fprintf(arquivo, "%d;%s;%c;%d/%d/%d;%s;%d,\n",
                listaDocentes[i].idDocente,
                listaDocentes[i].nome,
                listaDocentes[i].sexo,
                listaDocentes[i].dataNascimento.dia,
                listaDocentes[i].dataNascimento.mes,
                listaDocentes[i].dataNascimento.ano,
                listaDocentes[i].cpf,
                listaDocentes[i].ativo);
    }
    fclose(arquivo);
}


void lerDisciplinasDeArquivo(char *nomeArquivo) {
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
    while (fscanf(arquivo, "%d;%d;%49[^;];%d;%d;%d;%199[^;];%d,\n",
        &listaDisciplinas[contadorDisciplina].idDisciplina,
        &listaDisciplinas[contadorDisciplina].idDocente,
        listaDisciplinas[contadorDisciplina].nome,
        &listaDisciplinas[contadorDisciplina].cargaHoraria,
        &listaDisciplinas[contadorDisciplina].vagasDisponiveis,
        &listaDisciplinas[contadorDisciplina].quantidadeDeDiscentesMatriculados, 
        linha, // string temporária para os ids dos alunos
        &listaDisciplinas[contadorDisciplina].ativo) == 8) {
        // contadorDisciplina++;
        // quantidadeDeDisciplinas = contadorDisciplina;              
        // if (contadorDisciplina >= TAMANHO_ARRAY_DISCIPLINA) break;


         // Parse dos ids dos alunos matriculados
        int idx = 0;
        char *token = strtok(linha, ",");
        while (token != NULL && idx < MAX_VAGAS) {
            listaDisciplinas[contadorDisciplina].idAlunosMatriculados[idx++] = atoi(token);
            token = strtok(NULL, ",");
        }
        listaDisciplinas[contadorDisciplina].quantidadeDeDiscentesMatriculados = idx;

        contadorDisciplina++;
        quantidadeDeDisciplinas = contadorDisciplina;              
        if (contadorDisciplina >= TAMANHO_ARRAY_DISCIPLINA) break;
    }
    fclose(arquivo);
}

// Função para salvar discentes da memória no arquivo
void escreverDisciplinasEmArquivo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    } 

    for (int i = contadorDisciplina; i < quantidadeDeDisciplinas; i++) {
        fprintf(arquivo, "%d;%d;%s;%d;%d;",
                listaDisciplinas[i].idDisciplina,
                listaDisciplinas[i].idDocente,
                listaDisciplinas[i].nome,
                listaDisciplinas[i].cargaHoraria,
                listaDisciplinas[i].vagasDisponiveis
        );        
                // Escreve a quantidade de alunos
        fprintf(arquivo, "%d;", listaDisciplinas[i].quantidadeDeDiscentesMatriculados);

        // Escreve os IDs dos alunos separados por vírgula
        for (int j = 0; j < listaDisciplinas[i].quantidadeDeDiscentesMatriculados; j++) {
            fprintf(arquivo, "%d", listaDisciplinas[i].idAlunosMatriculados[j]);
            if (j < listaDisciplinas[i].quantidadeDeDiscentesMatriculados - 1) {
                fprintf(arquivo, ",");
            }
        }

        // Escreve o campo ativo e quebra de linha
        fprintf(arquivo, ";%d,\n", listaDisciplinas[i].ativo);
    }       
    fclose(arquivo);
}   