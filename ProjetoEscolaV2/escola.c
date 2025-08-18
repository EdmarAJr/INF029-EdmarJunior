// para abrir a pasta do projeto no shell cd ProjetoEscolaV2
// comando para executar o projeto gcc escola.c menu.c discentes.c docentes.c disciplinas.c auxiliar.c leituraEscrita.c -o escola
// comando para executar o projeto ./escola

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "escola.h"
#include "discentes.h"
#include "docentes.h"
#include "disciplinas.h"
#include "auxiliar.h"
#include "leituraEscrita.h"

extern int quantidadeDeDiscentes;
extern int quantidadeDeDocentes;
extern int quantidadeDeDisciplinas;
extern int matricula;
extern int idDocente;
extern int idDisciplina;
extern Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE];
extern Docente listaDocentes[TAMANHO_ARRAY_DOCENTE];
extern Disciplina listaDisciplinas[TAMANHO_ARRAY_DISCIPLINA];

extern char arquivoDiscentes[13];
// extern char docentes[13];
// extern char disciplinas[15];

int main(void) {
	
	lerDiscentesDeArquivo(arquivoDiscentes); 
	//lerDocentesDeArquivo(docentes); 
	//lerDisciplinasDeArquivo(disciplinas); 

	int sair = 0; 
	int opcaoMenu; 
		
	while (!sair) {
		opcaoMenu = opcaoMenuInicial ();

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
					opcaoDiscente = opcaoMenuDiscente ();

				switch (opcaoDiscente) {
					case 0: {
						sairDiscente = 1;
						break;
					}
					case 1: {
						printf("\n1 - < Cadastrar Discentes >\n");
					
						int retorno = cadastrarDiscente (quantidadeDeDiscentes, listaDiscentes);

					switch(retorno){
						case 1: {
							printf("Erro: numero de matricula ja cadastrado!\n");
							break;
						}
						case 2: {
							printf("Erro: matricula invalida. Tente novamente! \n");
							break;
						}
						case 3: {
							printf("Erro: formato do sexo invalido. Tente novamente! \n");
							break;
						}
						case 4: {
							printf("Erro: data com formato invalida. Tente novamente!\n");
							break;
						}
						case 5: {
							printf("Erro: cpf invalido!\n");
							break;
						}
						case 6: {
							printf("Erro: cpf ja cadastrado!\n");
							break;
						} 
						case 7:{
							printf("Cadastro realizado com sucesso!\n");
							quantidadeDeDiscentes++;
							break;
						}
					} 
					break;
					}
					case 2: {
					printf("2 - < Listar Discentes >\n");
					listarDiscentes (quantidadeDeDiscentes, listaDiscentes);
					break;
					}
					case 3: {
					printf("3 - < Atualizar Discente >\n");
					int retorno = atualizarDiscente (quantidadeDeDiscentes,listaDiscentes, sair);
									
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
					
					int retorno = excluirDiscente (quantidadeDeDiscentes, listaDiscentes);
					
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
					case 5:{
					int matricula;
					printf("5 - < Listar Discente por numero de matricula >\n");
					printf("Digite o numero de mastricula do discente: \n");
					scanf("%d", &matricula);
					buscarDiscentePorId (quantidadeDeDiscentes,listaDiscentes,matricula);

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
					opcaoDocente = opcaoMenuDocente ();

					switch (opcaoDocente) {
					case 0: {
						sairDocente = 1;
						break;
					}
					case 1: {
						printf("\n1 - < Cadastrar Docente >\n");
						int retorno = cadastrarDocente (quantidadeDeDocentes, listaDocentes);

						switch(retorno){
						case 1: {
							printf("Erro: numero de idDocente ja cadastrado!\n");
							break;
						}
						case 2: {
							printf("Erro: idDocente invalido. Tente novamente \n");
							break;
						}
						case 3: {
							printf("Erro: formato do sexo invalido. Tente novamente! \n");
							break;
						}
						case 4: {
							printf("Erro: data com formato invalida. Tente novamente!\n");
							break;
						}
						case 5: {
							printf("Erro: cpf invalido!\n");
							break;
						}
						case 6: {
							printf("Erro: cpf ja cadastrado!\n");
							break;
						} 
						case 7:{
							printf("Cadastro realizado com sucesso!\n");
							quantidadeDeDocentes++;
							break;
						}
						} 
						break;
					}
					case 2: {
						printf("2 - < Listar Docentes >\n");
						listarDocentes (quantidadeDeDocentes, listaDocentes);
						break;
					}
					case 3: {
						printf("3 - < Atualizar Docente >\n");
						int retorno = atualizarDocente (quantidadeDeDocentes,listaDocentes, sair);
						
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
						int retorno = excluirDocente (quantidadeDeDocentes, listaDocentes);
						
						if(retorno == 1){
							printf("\nRegistro da(o) docente excluido com sucesso!\n");
							quantidadeDeDiscentes--;
						} else if(retorno == -1 ){
							printf("Erro: numero de idDocente invalido. Tente novamente! \n");
						}else {
							printf("Erro: numero de idDocente nao encontrado!\n");
						}
						break;
					}
					case 5:{
						int idDocente;
						printf("5 - < Listar Docente por Id >\n");
						printf("Digite o id do docente: \n");
						scanf("%d", &idDocente);
						buscarDocentePorId (quantidadeDeDocentes,listaDocentes,idDocente);
						
						break;
					}
					default: {
						printf("Opcao invalida");
					}
					}
				}
				break;
			}
			case 3: {
				printf("\n<<< Modulo Disciplina >>>\n");
				int sairDisciplina = 0;
				int opcaoDisciplina;
				while (!sairDisciplina) {
					opcaoDisciplina = opcaoMenuDisciplina ();

					switch (opcaoDisciplina) {
						case 0: {
						sairDisciplina = 1;
						break;
						}
						case 1: {
							printf("\n1 - < Cadastrar Disciplina >\n");
							int retorno = cadastrarDisciplina (quantidadeDeDisciplinas, listaDisciplinas);
						
							switch(retorno){
								case 1: {
									printf("Erro: numero de idDisciplina ja cadastrado!\n");
									break;
								}
								case 2: {
									printf("Erro: idDisciplina invalido. Tente novamente! \n");
									break;
								}
								case 3: {
									printf("Erro: idDocente invalido!\n");
									break;
								}
								case 4: {
									printf("Erro: idDocente nao cadastrado ou encontrado!\n");
									break;
								}
								case 5: {
									printf("Erro: umero de matricula invalido!\n");
									break;
								}
								case 6: {
									printf("Erro: numero de matricula nao cadastrado ou encontrado!\n");
									break;
								}
								case 7: {
									printf("Cadastro realizado com sucesso!\n");
									quantidadeDeDisciplinas++;
									break;
								}
								break;
							}
						}
						case 2: {
							printf("2 - < Listar Disciplinas >\n");
							listarDisciplinas(quantidadeDeDisciplinas, listaDisciplinas);
							break;
						}
						case 3: {
							printf("3 - < Atualizar Disciplina >\n");
							int retorno = atualizarDisciplina (quantidadeDeDisciplinas,listaDisciplinas, sair);

							if(retorno == 1){
								printf("\nRegistro da disciplina atualizado com sucesso!\n");
							} else if(retorno == -1 ){
								printf("Erro: numero de idDisciplina invalido. Tente novamente! \n");
							}else {
								printf("\nErro: numero de idDisciplina nao encontrado!\n");
							}
							break;
						}
						case 4: {
							printf("4 - < Excluir Disciplina >\n");
							int retorno = excluirDisciplina (quantidadeDeDisciplinas, listaDisciplinas);

							if(retorno == 1){
								printf("\nRegistro da disciplina excluido com sucesso!\n");
								quantidadeDeDisciplinas--;
							} else if(retorno == -1 ){
								printf("Erro: Numero de idDisciplina invalido. Tente novamente! \n");
							}else {
								printf("Erro: numero de idDisciplina nao encontrado!\n");
							}
							break;
						}
						case 5: {
							printf("5 - < Listar Disciplina c/ alunos >\n");
							int retorno = listarDisciplinasComAlunos(quantidadeDeDisciplinas,listaDisciplinas);
							if(retorno == -1 ){
								printf("Erro: Numero de idDisciplina invalido. Tente novamente! \n");
							}
							break;
						}
						
						default: {
							printf("Opcao invalida");
						}
					}
				}
				break;
			}
			default: {
				printf("Opcao invalida");
			}
		}
	}

	escreverDiscentesEmArquivo(arquivoDiscentes);
	//escreverDocentesEmArquivo(docentes);
	//escreverDisciplinasEmArquivo(disciplinas);

	printf("Programa encerrado");
	return 0;
	}