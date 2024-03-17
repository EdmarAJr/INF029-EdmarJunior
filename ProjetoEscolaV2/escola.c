// nao escrever comentarios com acento, til ou cedilha
// usar verbos para declarar variaveis
// usar o padrao camelCase para declarar variaveis
// para abir a pasta do projeto no shell cd ProjetoEscolaV2
// comando para executar o projeto gcc escola.c menu.c discentes.c docentes.c -o escola
// comando para executar o projeto ./escola
// delecao placeholder define a posicao do array como -1
// delecao shift move o todos os itens do array para uma casa desejada e
// sobreescreve o valor
//na passagem de parametro por referencia, o valor da variavel original é não é alterado, mas se for um vetor pode ser mudado pelo endereço ex. listaDiscente[0]


// typedef struct disciplina{
//   int idDisciplina; // id da disicplina
//   int idDocente; // id do professor responsC!vel
//   char nome[500]; // nome da disciplina
//   int vagas; // total de vagas da disciplina
//   int quantidadeAlunos; //guarda a quantidade de alunos matriculados
//   int idAlunosMatriculados[vagas]; // guarda o id dos alunos matriculados na
//   disciplina.
// } Disciplina;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "escola.h"
#include "discentes.h"
#include "docentes.h"

int main(void) {

  int matricula;
  int idDocente;
  int sair = 0; 
  int opcaoMenu; 
  int quantidadeDeDiscentes = 1;  
  int quantidadeDeDocentes = 1;  

  Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE] = {
      {55, "Estudante X", 'M', {10, 10, 2000}, "123.456.789-00", 1}
  };

  Docente listaDocentes[TAMANHO_ARRAY_DOCENTE] = {
      {55, "PROFESSOR X", 'M', {10, 10, 2000}, "123.456.789-00", 1}
  };
  
  while (!sair) {
    opcaoMenu = opcaoMenuInicial();

    switch (opcaoMenu) {
      case 0: {
        printf("Finalizando Projeto Escola\n");
        sair = 1;
        break;
      }
      case 1: {
        printf("\n<<< Modulo do Discente >>>\n\n");
        int sairDiscente = 0;
        int opcaoDiscente;
        while (!sairDiscente) {
          opcaoDiscente = opcaoMenuDiscente();

          switch (opcaoDiscente) {
            case 0: {
              sairDiscente = 1;
              break;
            }
            case 1: {
              printf("\n1 - < Cadastrar Discentes >\n");
              int retorno = cadastrarDiscentes(quantidadeDeDiscentes, listaDiscentes);
                // criar uma funcao para retornar erros
                if(retorno == 1){
                    printf("Erro: numero de matricula ja cadastrado!\n");
                } else if(retorno == - 1){
                    printf("Matricula invalida. Tente novamente! \n");
                } else {
                    printf("Cadastro realizado com sucesso!\n");
                    quantidadeDeDiscentes++;
                }
              break;
            }
            case 2: {
              printf("2 - < Listar Discentes >\n");
              listarDiscentes(quantidadeDeDiscentes, listaDiscentes);
              break;
            }
            case 3: {
              printf("3 - < Atualizar Discente >\n");
              int retorno = atualizarDiscente(quantidadeDeDiscentes,  listaDiscentes, sair);
                            
              if(retorno == 1){
                  printf("Dados atualizados com sucesso!\n");
              } else if(retorno == -1 ){
                  printf("Numero de matricula invalida. Tente novamente! \n");
              } else {
                  printf("Erro ao atualizar discente. Matricula nao encontrada\n");
              }
              break;
            }
            case 4: {
              printf("4 - < Excluir Discente >\n");
              
              int retorno = excluirDiscente(quantidadeDeDiscentes, listaDiscentes);
              
              if(retorno == 1){
                printf("\nRegistro da(o) discente excluido com sucesso!\n");
                quantidadeDeDiscentes--;
              } else if(retorno == -1 ){
                  printf("Numero de matricula invalido. Tente novamente! \n");
              }else {
                printf("\nErro: numero de matricula nao encontrado!\n");
              }
              break;
            }
            default: {
              printf("Opcao invalida (Discente)");
            }
          }
        }
           break;
      }

      case 2: {
        printf("\n<<< Modulo do Docente >>>\n\n");
          int sairDocente = 0;
          int opcaoDocente;
          while (!sairDocente) {
            opcaoDocente = opcaoMenuDocente();

            switch (opcaoDocente) {
              case 0: {
                sairDocente = 1;
                break;
              }
              case 1: {
                printf("\n1 - < Cadastrar Docentes >\n");
                int retorno = cadastrarDocentes(quantidadeDeDocentes, listaDocentes);

                if(retorno == 1){
                    printf("Erro: numero de idDocente ja cadastrado!\n");
                } else if(retorno == - 1){
                    printf("IdDocente invalido. Tente novamente! \n");
                } else {
                    printf("Cadastro realizado com sucesso!\n");
                    quantidadeDeDiscentes++;
                } 
                break;
              }
              case 2: {
                printf("2 - < Listar Docentes >\n");
                listarDocentes(quantidadeDeDocentes, listaDocentes);
                break;
              }
              case 3: {
                printf("3 - < Atualizar Docente >\n");
                int retorno = atualizarDocente(quantidadeDeDocentes,  listaDocentes, sair);
                
                if(retorno == 1){
                  printf("\nRegistro da(o) docente atualizado com sucesso!\n");
                } else if(retorno == -1 ){
                    printf("Numero de idDocente invalido. Tente novamente! \n");
                }else {
                  printf("\nErro: numero de idDocente nao encontrado!\n");
                }
                break;
              }
              case 4: {
                printf("4 - < Excluir Docente >\n");
                int retorno = excluirDocente(quantidadeDeDocentes, listaDocentes);
                
                if(retorno == 1){
                    printf("\nRegistro da(o) docente excluido com sucesso!\n");
                    quantidadeDeDiscentes--;
                } else if(retorno == -1 ){
                    printf("Numero de idDocente invalido. Tente novamente! \n");
                }else {
                    printf("\nErro: numero de idDocente nao encontrado!\n");
                }
                break;
              }
              default: {
                printf("Opcao invalida (Docente)");
              }
            }
          }
        break;
      }
      case 3: {
        printf("<<< Modulo Disciplina >>>");
        break;
      }
      default: {
        printf("Opcao invalida");
      }
    }
  }
  printf("Programa encerrado");
  return 0;
}