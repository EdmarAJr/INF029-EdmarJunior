#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "auxiliar.h"
#include "discentes.h"
#include "docentes.h"
#include "escola.h"

extern Docente listaDocentes[TAMANHO_ARRAY_DOCENTE];
extern Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE];
extern int quantidadeDeDiscentes;  
extern int quantidadeDeDocentes;


int buscarDiscenteCPF (char cpf[]);
int buscarDocenteCPF (char cpf[]);

int validarCPF(char categoria[], char cpf[]) {
		// Remover o caractere de nova linha de fgets
		if (cpf[strlen(cpf) - 1] == '\n') {
				cpf[strlen(cpf) - 1] = '\0';
		}
	
		if (strlen(cpf) < 11) {
				printf("O CPF precisa ter 11 digitos\n");
				return -1;
		} else {
				if(categoria == "Discente"){
					buscarDiscenteCPF(cpf);
				} else{
					buscarDocenteCPF(cpf);
				}
			
				// Remover caracteres de pontuação do CPF se houver
				char cpfLimpo[11];
				int i = 0, j = 0;
				while (cpf[i]) {
						if (isdigit(cpf[i])) {
								cpfLimpo[j++] = cpf[i];
						}
						i++;
				}
				cpfLimpo[j] = '\0';

				// Validar o CPF
				int digito1 = 0, digito2 = 0;
				int cpf_numerico[11];
				int peso = 10;

				// Converte caracteres para inteiros e armazena em um array
				for (i = 0; i < 11; i++) {
						if (isdigit(cpfLimpo[i])) {
								cpf_numerico[i] = cpfLimpo[i] - '0';
						} else {
								return -1;
						}
				}

				// Calcula o primeiro dígito verificador
				for (i = 0; i < 9; i++) {
						digito1 += cpf_numerico[i] * peso;
						peso--;
				}
				digito1 = 11 - (digito1 % 11);
				if (digito1 > 9) {
						digito1 = 0;
				}

				// Calcula o segundo dígito verificador
				peso = 11;
				for (i = 0; i < 10; i++) {
						digito2 += cpf_numerico[i] * peso;
						peso--;
				}
				digito2 = 11 - (digito2 % 11);
				if (digito2 > 9) {
						digito2 = 0;
				}

				// Verifica se os dígitos calculados são iguais aos dígitos fornecidos
				if (digito1 == cpf_numerico[9] && digito2 == cpf_numerico[10]) {
						return 0;
				} else {
						return -1;
				}
		}

		return 0;
}

int buscarDiscenteCPF (char cpf[]){
	int cpfEncontradoDiscente = 0;
	
	for (int i = 0; i < quantidadeDeDiscentes; i++) {
		if (cpf == listaDiscentes[i].cpf && listaDiscentes[i].ativo) {
				cpfEncontradoDiscente = 1;
				return cpfEncontradoDiscente;
		}
	}
}

int buscarDocenteCPF (char cpf[]){
int cpfEncontradoDocente = 0;

	for (int i = 0; i < quantidadeDeDocentes; i++) {
		if (cpf == listaDocentes[i].cpf && listaDocentes[i].ativo) {
				cpfEncontradoDocente = 1;
				return cpfEncontradoDocente;
		}
	}
}

int verificadorDeSexo(char verificarsexo) {
	if (verificarsexo == 77 || verificarsexo == 70) {
		return 0;
	} else {
		return 1;
	}
}
