/* para compilar
gcc mainTeste.c EstruturaVetores.c -o teste
gcc main.c EstruturaVetores.c -o teste*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MAX
#define TAM 10

#include "EstruturaVetores.h"

typedef struct celula {
	int *posicao;
	int contador;
	int tamanho;
} Celula;

//vetorPrincipal eh uma variavel global??
Celula vetorPrincipal[TAM]; //vetor de celulas struct
//Celula vetorPrincipal[TAM]={NULL}; //Isso tambem funciona no lugar da funcao inicializar??

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

int verificarEstrutura(int posicao){
	int retorno = 0;
	//printf("Entrada na funcao verificar Estrutura %d\n", posicao);
	//printf("Busca real na funcao verficar Estrutura %d\n", posicao-1);
	//se o valor posicao for menor que 0 ou maior que 10 retorna -1
	if(vetorPrincipal[posicao-1].posicao != NULL){
			retorno = 1;
	}
	//se o valor posicao for entre 1 e 10 e nao existir posicao criada no vetor retorna 0, ou seja a posicao nao existe
//	printf("Retorno da funcao verificar Estrutura %d\n", retorno);
	return retorno;
}

// se posicao eh um valor valido {entre 1 e 10}
int ehPosicaoValida(int posicao){
		int retorno = 1;
		if(posicao < 1 || posicao > 10)
			return retorno = 0;
		//se o valor posicao for entre 1 e 10 e existir posicao criada no vetor retorna 1, ou seja a posicao existe
	
		// if (posicao < 1 || posicao > 10) {
		// 		retorno = POSICAO_INVALIDA;
		// }
		// else
		// 		retorno = SUCESSO;

		return retorno;
}

int verificarEspaco(int posicao){
	int retorno;
	int diferenca = vetorPrincipal[posicao-1].tamanho - vetorPrincipal[posicao-1].contador;
	
	if(diferenca > 0) {
		retorno = diferenca;
	} else {
		retorno = 0;
	}
	return retorno;
}

int verficarValor(int posicao, int valor) {
	int retorno = -1;
	// printf("posicao: %d\n", posicao);
	// printf("valor fora: %d\n", valor);
	// printf("Valor no vetor: %d\n", vetorPrincipal[posicao-1].posicao[0]);
	for (int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
		if(vetorPrincipal[posicao-1].posicao[i] == valor){
		    // printf("valor: %d\n", valor);
		    //  printf("Funcao verificarValor no vetor: %d\n", vetorPrincipal[posicao-1].posicao[i]);
            retorno = i;
		}	
	}
		//printf("retorno posicao na Funcao verificarValor: %d\n", retorno);
	return retorno;
}

int criarEstruturaAuxiliar(int posicao, int tamanho){
	//int verificar = verificarEstrutura(posicao-1);
		//int *ptr_posicao; //ponteiro para modificar o valor de posicao
		//ptr_posicao = &posicao; //guardando o valor de posicao
		int retorno = 0;
		
		//retorna -1 para invalido retorna 0 para posicao nao existente e retorna 1 para posicao existente;
		//int posicao_invalida = ehPosicaoValida(posicao);
		//int existeEstruturaAuxiliar = verificarEstrutura(posicao);
		
		//se a posicao nao existir retorna invalido
		if(!ehPosicaoValida(posicao)){
			// se posição eh um valor valido {entre 1 e 10}
			retorno = POSICAO_INVALIDA;
		} else if(tamanho < 1){
			// o tamanho nao pode ser menor que 1
			retorno = TAMANHO_INVALIDO;
		} else if(verificarEstrutura(posicao)) { //se a posicao existir retorna jah existente
			// a posicao pode jah existir estrutura auxiliar
			retorno = JA_TEM_ESTRUTURA_AUXILIAR;
		} else if(tamanho > INT_MAX){
			 	// o tamanho eh muito grande
				retorno = SEM_ESPACO_DE_MEMORIA; //perguntar para o professor o que eh esse caso
		}else{
			vetorPrincipal[posicao-1].posicao =  malloc(tamanho*sizeof(int));
			vetorPrincipal[posicao-1].contador = 0;
			vetorPrincipal[posicao-1].tamanho = tamanho;
			
			for(int i = 0; i < tamanho; i++){
				vetorPrincipal[posicao-1].posicao[i] = INT_MIN;//preenche todas com sentinela int_min
			}
			// //para conferir se o vetor foi preenchido com INT_MIN
			// printf("\n");
			// for(int i = 0; i < tamanho; i++){
			// 	printf("%d", vetorPrincipal[posicao-1].posicao[i]);
			// }
			// printf("\n");
			
			// deu tudo certo, crie
			retorno = SUCESSO;
		}
		//printf("Tamanho %d\n", tamanho);
		//printf("Retorno ENUM: \t%2d\n", SUCESSO);
		return retorno;
}
/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
		int retorno = 0;
		//int existeEstruturaAuxiliar = verificarEstrutura(posicao);
		//int temEspaco = verificarEspaco(posicao);
		//int posicao_invalida = ehPosicaoValida(posicao);
		//se posicao for negativa ou nao existir retorna invalido
		if (ehPosicaoValida(posicao)) {
			// testar se existe a estrutura auxiliar
			if (verificarEstrutura(posicao)){ //se posicao entre 1 e 10 existir retorna 1
					if (verificarEspaco(posicao)){ //se tamanho - contador for igual a 0 retorna sem espaco. Ex: tam = 3; contado = 3; 3-3 = 0; retono = sem espaco
						int cont = vetorPrincipal[posicao-1].contador;
						vetorPrincipal[posicao-1].posicao[cont] = valor;//verificar se o valor esta sendo guardado corretamente
						// printf("Funcao Inserir Contador: %d\n", vetorPrincipal[posicao-1].contador);
						// for(int i=0; i < vetorPrincipal[posicao-1].contador; i++){
						// 	printf("Funcao Inserir Numero no array: %d\n", vetorPrincipal[posicao-1].posicao[i]);
						// }
							vetorPrincipal[posicao-1].contador++;
						//printf("Tamanho: %d\n", vetorPrincipal[posicao-1].tamanho);
							retorno = SUCESSO;
					}
					else {
						retorno = SEM_ESPACO;
					}
			} else{
					retorno = SEM_ESTRUTURA_AUXILIAR;
			}
		}	else {
				retorno = POSICAO_INVALIDA;
				
		}
		// printf("Entrada posicao: %d\n", posicao);
		// printf("Entrada valor: %d\n", valor);
		// printf("Retorno: %d\n", retorno);
		// printf("Existe estrutura: %d\n", verificarEstrutura(posicao);
		// printf("Tem espaco: %d\n", verificarEspaco(posicao));
		// printf("Posicao invalida: %d\n", posicao_invalida);
		return retorno;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
		int retorno = 0;
		//int valor = -1; //verificar se esta correto
		//int existeEstruturaAuxiliar = verificarEstrutura(posicao);
		//int temEspaco = verificarEspaco(posicao);
		//int posicao_invalida = ehPosicaoValida(posicao);
		//se posicao for negativa ou nao existir retorna invalido
		// printf("vetor da funcao excluir antes  \n");
		// for(int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
		// 	printf("%d", vetorPrincipal[posicao-1].posicao[i]);
		// }
		//printf("\n");
		if (ehPosicaoValida(posicao)) { 
			// testar se existe a estrutura auxiliar
			if (verificarEstrutura(posicao)){ //se posicao entre 1 e 10 existir retorna 1
					if (verificarEspaco(posicao) == vetorPrincipal[posicao-1].tamanho){//se tamanho - contador for igual a tam retorna estrutura vazia. Ex: tam = 3; contador = 0; 3-0 = 3; retono = estrutura vazia
						retorno = ESTRUTURA_AUXILIAR_VAZIA;
					}else {
						int cont = vetorPrincipal[posicao-1].contador;
						vetorPrincipal[posicao-1].posicao[cont-1] = INT_MIN;//verificar se o valor esta sendo guardado corretamente
						vetorPrincipal[posicao-1].contador--;
						retorno = SUCESSO;

						// //para conferir os valores do vetor foram preenchido com -1
						// printf("vetor da funcao excluir depois\n");
						// for(int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
						// 	printf("%d", vetorPrincipal[posicao-1].posicao[i]);
						// }
						// printf("\n");
					}
			} else{
					retorno = SEM_ESTRUTURA_AUXILIAR;
			}
		}	else {
			retorno = POSICAO_INVALIDA;
		}

	//  printf("Contador: %d\n", vetorPrincipal[posicao-1].contador);
	//  printf("Tamanho: %d\n", vetorPrincipal[posicao-1].tamanho);
	// 	printf("Entrada posicao: %d\n", posicao);
	// 	printf("Entrada valor: %d\n", valor);
	//  printf("Retorno: %d\n", retorno);
	// 	printf("Existe estrutura: %d\n", existeEstruturaAuxiliar);
	// 	printf("Tem espaco: %d\n", temEspaco);
	// 	printf("Posicao invalida: %d\n", posicao_invalida);
		return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
	//perguntar se a funcao excluirNumeroEspecifico precisa deslocar os elementos para direita
	int retorno = 0;
	// printf("vetor da funcao excluir especifico antes  \n");
	// for(int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
	// 	if(vetorPrincipal[posicao-1].posicao[i] != INT_MIN){
	// 		printf("%d ", vetorPrincipal[posicao-1].posicao[i]);
	// 	}
	// }
	// printf("\n");
	//int existeEstruturaAuxiliar = verificarEstrutura(posicao);
	//int temEspaco = verificarEspaco(posicao);
	//int posicao_invalida = ehPosicaoValida(posicao);
	int existeValor = verficarValor(posicao, valor);
	//se posicao for negativa ou nao existir retorna invalido
	if (!ehPosicaoValida(posicao)) {
			retorno = POSICAO_INVALIDA;
	}	else {
			// testar se existe a estrutura auxiliar
			if (verificarEstrutura(posicao)){ //se posicao entre 1 e 10 existir retorna 1
					if (verificarEspaco(posicao) > 0){ //se contador for menor que o tamanho da estrutura auxiliar retorna 1
						if(existeValor < 0) {
							retorno = NUMERO_INEXISTENTE;	
						} else{
							vetorPrincipal[posicao-1].posicao[existeValor] = INT_MIN;//verificar se o valor esta sendo guardado corretamente
							vetorPrincipal[posicao-1].contador--;
							//printf("Contador: %d\n", vetorPrincipal[posicao-1].contador);
							//printf("Tamanho: %d\n", vetorPrincipal[posicao-1].tamanho);
							// printf("vetor da funcao excluir especifico depois  \n");
							// for(int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
							// 	if(vetorPrincipal[posicao-1].posicao[i] != INT_MIN){
							// 		printf("%d ", vetorPrincipal[posicao-1].posicao[i]);
							// 	}
							// }
							// printf("\n");
								retorno = SUCESSO;
						}
					}
					else {
							retorno = SEM_ESPACO;
					}
			} else{
					retorno = SEM_ESTRUTURA_AUXILIAR;
			}
	}
	// printf("Entrada posicao: %d\n", posicao);
	// printf("Entrada valor: %d\n", valor);
	// printf("Retorno: %d\n", retorno);
	// printf("Retorno da posicao do valor: %d\n", existeValor);
	// printf("Existe estrutura: %d\n", existeEstruturaAuxiliar);
	// printf("Tem espaco: %d\n", temEspaco);
	// printf("Posicao invalida: %d\n", posicao_invalida);
	return retorno;
}


/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	// printf("valorAux getDados antes: ");
	// for(int i = 0; i < 3; i++){
	// 	printf("%d ", vetorAux[i]);
	// }
	// printf("\n");
		int retorno = 0;
		// int existeEstruturaAuxiliar = verificarEstrutura(posicao);
	 //  int posicao_invalida = ehPosicaoValida(posicao);
		
		if (!ehPosicaoValida(posicao)) {
				retorno = POSICAO_INVALIDA;
		}	else {
				if(verificarEstrutura(posicao)){
						// //o vetor principal recebe os valores
						// printf("vetor da funcao getDados antes  \n");
						// for(int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
						// 	if(vetorPrincipal[posicao-1].posicao[i] != INT_MIN){
						// 		printf("%d ", vetorPrincipal[posicao-1].posicao[i]);
						// 	}
						// }
						// printf("\n");

					
					int j = 0;
					int contador = 0;//apagar, pois ehpara testar se o vetorAuxiliar estah somente sem INT_MIN e indo ate j
					//o vetor principal nesta posicao ja foi populado e tranferido para o vetor auxiliar sem os valores INT_MIN e -1
					//printf("valorAux getDados depois: ");
					for (int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
						if(vetorPrincipal[posicao-1].posicao[i] != INT_MIN){
                            vetorAux[j] = vetorPrincipal[posicao-1].posicao[i];
							//printf("%d ", vetorAux[i]);
							j++;
							contador++;
						}
					}	

					// //lista os valores  do vetor auxiliar filtrados
					// printf("vetor da funcao getDados depois  \n");
					// for(int i = 0; i < contador; i++){
					// 	printf("%d ", vetorAux[i]);				
					// }
					// printf("\n");
						retorno = SUCESSO;
				} else {
						retorno = SEM_ESTRUTURA_AUXILIAR;
            }
        }
			//printf("Entrada posicao: %d\n", posicao);
			// printf("Entrada vetor: %d\n", vetorAux[posicao-1]);
			// printf("Retorno: %d\n", retorno);
			// printf("Existe estrutura: %d\n", existeEstruturaAuxiliar);
			// printf("Posicao invalida: %d\n", posicao_invalida);
			// printf("Retorno da posicao do valor: %d\n", existeValor);
			// printf("Tem espaco: %d\n", temEspaco);
		return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	// printf("valorAux getDadosOrdenados antes: ");
	// for(int i = 0; i < 3; i++){
	// 	printf("%d ", vetorAux[i]);
	// }
	// printf("\n");
	
	int retorno = 0;
	//int existeEstruturaAuxiliar = verificarEstrutura(posicao);
	//int posicao_invalida = ehPosicaoValida(posicao);

	if (!ehPosicaoValida(posicao)) {
			retorno = POSICAO_INVALIDA;
	}	else {
			if(verificarEstrutura(posicao)){
				// printf("vetor da funcao getDadosOrdenados antes (com lixo)  \n");
				// for(int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
				// 	// if(vetorPrincipal[posicao-1].posicao[i] != INT_MIN){
				// 		printf("%d ", vetorAux[i]);				
				// 	// }
				// }
				// printf("\n");
				
				int temp, cont = 0;
				int j = 0; //serve para inserir os valores no vetor auxiliar na posicao correta
				//o vetor principal ja foi populado e copiado para o vetor auxiliar sem os valores INT_MIN
				//printf("valorAux getDadosOrdenados depois: ");
				for (int i = 0; i < vetorPrincipal[posicao-1].tamanho; i++){
					if(vetorPrincipal[posicao-1].posicao[i] != INT_MIN){
						vetorAux[j] = vetorPrincipal[posicao-1].posicao[i];
						j++;
						cont++;
						//printf("%d ", vetorAux[i]);
					}
				}
				
				//ordenacao por bolha
				//cont serve para nao percorrer o vetor auxiliar a mais
				for(int i = 0; i < cont-1; i++)
						for(int j = 0; j < cont-1; j++){
								if(vetorAux[j] > vetorAux[j+1] && (vetorAux[j] != INT_MIN || vetorAux[j+1] != INT_MIN)){//essa condicao impede que os valores de INT_MIN sejam inserido no vetor auxiliar
										temp = vetorAux[j]; //guarda o valor de j em temp se a condicao for verdadeira
										vetorAux[j] = vetorAux[j+1]; //troca o valor de j pelo valor de j+1
										vetorAux[j+1] = temp; //troca o valor de j+1 pelo valor de temp
								}
						}			
						retorno = SUCESSO;
			} else {
				retorno = SEM_ESTRUTURA_AUXILIAR;
				}
		}
		// printf("Entrada posicao: %d\n", posicao);
		// printf("Entrada vetor: %d\n", vetorAux[posicao-1]);
		// printf("Retorno: %d\n", retorno);
		// printf("Existe estrutura: %d\n", existeEstruturaAuxiliar);
		// printf("Posicao invalida: %d\n", posicao_invalida);
		// printf("Retorno da posicao do valor: %d\n", existeValor);
		// printf("Tem espaco: %d\n", temEspaco);
	return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

	// printf("valorAux getDadosDeTodas ");
	// for(int i = 0; i < 3; i++){
	// 	printf("%d ", vetorAux[i]);
	// }
	// printf("\n");

	int i = 0, j, cont = 0, k = 0;
	for(i = 0; i < TAM; i++ ){
			if(vetorPrincipal[i].posicao != NULL){ //se a estrutura for nula adiciona no contador
				//size_t tamEstrutura = sizeof(vetorPrincipal)/sizeof(vetorPrincipal[0]); //retorna o tamanho do vetor principal, mas so serve para memorias alocadas dinamicamente
					for(j = 0; j < TAM; j++){
						if(vetorPrincipal[i].posicao[j] == INT_MIN && vetorPrincipal[i].posicao[j+1] == INT_MIN) {
							break; //sai do laco se a estrutura auxiliar vazia (lembre-se que inicializa com INT_MIN)
						} else {
							vetorAux[k] = vetorPrincipal[i].posicao[j];
							k++;
							retorno = SUCESSO;
							if(!vetorPrincipal[i].posicao[j]){
								break; //sai do laco de a estrutura auxiliar estiver vazia
							} 
						}
					} 
			} 
	}
	// 	printf("Entrada posicao: %d\n", posicao);
	// 	printf("Entrada vetor: %d\n", vetorAux[posicao-1]);
	//  printf("Retorno: %d\n", retorno);
	// 	printf("Existe estrutura: %d\n", existeEstruturaAuxiliar);
	// 	printf("Posicao invalida: %d\n", posicao_invalida);
	//  printf("Retorno da posicao do valor: %d\n", existeValor);
		// printf("Tem espaco: %d\n", temEspaco);
	return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	int i = 0, j, cont = 0, k = 0, temp;
	
	for(i = 0;i < TAM; i++ ){
			if(vetorPrincipal[i].posicao != NULL){ //se a estrutura for nula adiciona no contador
				//size_t tamEstrutura = sizeof(vetorPrincipal)/sizeof(vetorPrincipal[0]); //retorna o tamanho do vetor principal
					for(j = 0; j < TAM; j++){
							if(vetorPrincipal[i].posicao[j] == INT_MIN && vetorPrincipal[i].posicao[j+1] == INT_MIN) {
								break; //sai do laco se a estrutura auxiliar vazia (lembre-se que inicializa com INT_MIN)
							} else {
									vetorAux[k] = vetorPrincipal[i].posicao[j];
									k++;
									if(!vetorPrincipal[i].posicao[j]){
									break; //sai do laco de a estrutura auxiliar estiver vazia
								} 
							}
					} 
			} else {
				cont++;
				// printf("valor de i: %d\n", i);
				// printf("Contador: %d\n", cont);
			}
	}
	for(i = 0; i < k-1; i++) {
		for(j = 0; j < k-1; j++){
			if(vetorAux[j+1]<vetorAux[j]){
				temp = vetorAux[j];
				vetorAux[j] = vetorAux[j+1];
				vetorAux[j+1] = temp;
				retorno = SUCESSO;
			}
		}
	}
	return retorno;
}


/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
		int retorno = 0;
		//int existeEstruturaAuxiliar = verificarEstrutura(posicao);
		//int temEspaco = verificarEspaco(posicao);
		//int posicao_invalida = ehPosicaoValida(posicao);
		//se posicao for negativa ou nao existir retorna invalido
		// printf("vetor da funcao excluir antes  \n");
		// for(int i = 0; i < TAM; i++){
		// 	printf("%d", vetorPrincipal[posicao-1].tamanho);
		// }
		//printf("\n");
		if (!ehPosicaoValida(posicao)) { 
			retorno = POSICAO_INVALIDA;
		}	else if(novoTamanho + vetorPrincipal[posicao-1].tamanho <= 0){
				// o tamanho nao pode ser menor que 1
				retorno = NOVO_TAMANHO_INVALIDO;
			}	else {
				// testar se existe a estrutura auxiliar
				if (verificarEstrutura(posicao)){ //se posicao entre 1 e 10 existir retorna 1
						if (!verificarEspaco(posicao)){ //se contador for igual a zero retorna 0
							if(novoTamanho > 0){
								novoTamanho = novoTamanho + vetorPrincipal[posicao-1].tamanho;
							} 
							if(novoTamanho < 0){
								novoTamanho = vetorPrincipal[posicao-1].tamanho - novoTamanho;
							} 
							vetorPrincipal[posicao-1].posicao =  malloc(novoTamanho*sizeof(int));
							vetorPrincipal[posicao-1].tamanho = novoTamanho;
							retorno = SUCESSO;
							// printf("vetor da funcao tamanho depois\n");
							// for(int i = 0; i < TAM; i++){
							// 	printf("%d", vetorPrincipal[posicao-1].tamanho);
							// }
							// printf("\n");
						}	else {
								retorno = SEM_ESPACO;
						}
				} else{
						retorno = SEM_ESTRUTURA_AUXILIAR;
				}
		}

	// printf("Contador: %d\n", vetorPrincipal[posicao-1].contador);
	// printf("Tamanho: %d\n", vetorPrincipal[posicao-1].tamanho);
	// 	printf("Entrada posicao: %d\n", posicao);
	// 	//printf("Entrada valor: %d\n", valor);
		printf("Retorno: %d\n", retorno);
	// 	printf("Existe estrutura: %d\n", existeEstruturaAuxiliar);
	// 	printf("Tem espaco: %d\n", temEspaco);
	// 	printf("Posicao invalida: %d\n", posicao_invalida);
		return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}