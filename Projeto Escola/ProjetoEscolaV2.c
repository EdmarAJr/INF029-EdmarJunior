// nao escrever comentarios com acento, til ou cedilha
// usar verbos para declarar variaveis
// usar o padrao camelCase para declarar variaveis
// para abir a pasta do projeto no shell cd ProjetoEscola
// comando para executar o projeto gcc escola.c -o escola
// comando para executar o projeto ./escola
// delecao placeholder define a posicao do array como -1
// delecao shift move o todos os itens do array para uma casa desejada e
// sobreescreve o valor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "discente.h" //será usado para importar as funções de outras pastas
// define o tamanho do vetor
#define TAMANHO_ARRAY_DISCENTE 3
#define QUANTIDADE_DE_DISCENTES

// struct de data nascimento
typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

// struct de discente
typedef struct discente {
  int matricula;
  char nome[50];  // ainda estou pensando se essa eh a melhor opcao de tipo
  char sexo;
  Data dataNascimento;
  char cpf[15];  // ainda estou pensando em como fazer o cpf ser valido e se
                 // essa eh a melhor opcao de tipo
  int ativo;
} Discente;

typedef struct docente {
  int idDocente;
  char nome[50];
  char sexo;
} Docente;

// typedef struct disciplina{
//   int idDisciplina; // id da disicplina
//   int idDocente; // id do professor responsC!vel
//   char nome[500]; // nome da disciplina
//   int vagas; // total de vagas da disciplina
//   int quantidadeAlunos; //guarda a quantidade de alunos matriculados
//   int idAlunosMatriculados[vagas]; // guarda o id dos alunos matriculados na
//   disciplina.
// } Disciplina;

// Prototipos das funcoes de menu
int opcaoMenuInicial();
int opcaoMenuDiscente();
int opcaoMenuAtualizarDiscente();

// variaveis globais
int quantidaDeDiscentes = 0;  // essa variavel pode ser acessada por todas as funcoes
Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE];  // vetor do tipo Discente (struct)
                                                 // para adicionar os Discentes
int matricula;
int sair = 0;

// Prototipos de funcoes de execucao
int listarDiscentes();
int cadastrarDiscentes();
int buscarDiscente();
int atualizarDiscente();
int excluirDiscente();

// funcao main principal
int main(void) {
  // variavel para escolher a opcao do menu
  int opcaoMenu;
  // variavel para guardar a opcao sair do menu
  int sair = 0;

  while (!sair) {
    // Chama a funcao opcaoMenuInicial() e imprime na tela o menu de opcoes
    opcaoMenu = opcaoMenuInicial();

    switch (opcaoMenu) {
      case 0: {
        printf("Finalizando Projeto Escola\n");
        sair = 1;
        break;
      }
        // opcao para cadastrar discente
      case 1: {
        // imprime na tela o nome do mC3dulo
        printf("\n<<< Modudulo Discente >>>\n");
        // variavel para sair do mC3dulo
        int sairDiscente = 0;
        // variavel para escolher a opcao do menu cadastrar alino
        int opcaoDiscente;
        // imprime na tela o menu de opcoes discente
        while (!sairDiscente) {
          // Chama a funcao opcaoMenuDiscente() e imprime na tela o menu de opcoes
          opcaoDiscente = opcaoMenuDiscente();

          switch (opcaoDiscente) {
            case 0: {
              sairDiscente = 1;
              break;
            }
            case 1: {
              printf("\n1 - < Cadastrar Discentes >\n");
              cadastrarDiscentes();
              break;
            }
            case 2: {
              printf("2 - < Listar Discentes >\n\n ");
              // chama a funcao para listar a quantidade de discentes
              listarDiscentes();
              break;
            }
            case 3: {
              printf("3 - < Atualizar Discente >\n");
              // chama a funcao para atualizar o registro do discente
              atualizarDiscente();
              break;
            }
            case 4: {
              printf("4 - < Excluir Discente >\n");
              excluirDiscente();
              break;
            }
            default: {
              printf("Opcao invalida (Discente)");
            }
          }
        }
      }
        // opcao para cadastrar docente
      case 2: {
        printf("<<< Modulo Docente >>>");
        break;
      }
        // opcao para cadastrar discplina
      case 3: {
        printf("<<< Modulo Disciplina >>>");
        break;
      }
      default: {
        printf("Opcao invalida");
      }
    }
  }
  // imprime na tela quando o programa foi finalizado
  printf("Programa encerrado");
  return 0;
}

// funcao pora exibir o menu inicial
int opcaoMenuInicial() {
  int menuInicial;

  printf("Projeto escola - Disciplina INF029\n");
  printf("\n<<< Escolha entre as opcoes abaixo para inciar >>>\n");
  printf("\n0 - Sair\n");
  printf("1 - Discente\n");
  printf("2 - Docente\n");
  printf("3 - Disciplina\n");

  scanf("%d", &menuInicial);

  return menuInicial;
}

// funcao pora exibir o menu discente
int opcaoMenuDiscente() {
  int menuDiscente;

  printf("\n0 - Voltar\n");
  printf("1 - Cadastrar Discente\n");
  printf("2 - Listar Discente\n");
  printf("3 - Atualizar Discente\n");
  printf("4 - Excluir Discente\n");

  scanf("%d", &menuDiscente);

  return menuDiscente;
}

// funcao pora exibir o menu Atualizar discentes
int opcaoMenuAtualizarDiscente() {
  int menuAtualizarDiscente;
  printf("\n0 - Sair\n");
  printf("1 - Atualizar nome\n");
  printf("2 - Atualizar sexo\n");
  printf("3 - Atualizar data de nascimento\n");
  printf("4 - Atualizar cpf\n");

  scanf("%d", &menuAtualizarDiscente);
  return menuAtualizarDiscente;
}

// funcao para listar a quantidade de discentes
int listarDiscentes() {
  if (quantidaDeDiscentes == 0) {
    printf("\nErro: Nenhum registro de discente cadastrado!\n");
  } else {
    for (int i = 0; i < quantidaDeDiscentes; i++) {
      if (listaDiscentes[i].ativo == 1) {
        printf("Matricula: %d\n", listaDiscentes[i].matricula);
        printf("Nome: %s\n", listaDiscentes[i].nome);
        printf("Sexo: %c\n", listaDiscentes[i].sexo);
        printf("Data Nascimento: %d/%d/%d\n",
               listaDiscentes[i].dataNascimento.dia,
               listaDiscentes[i].dataNascimento.mes,
               listaDiscentes[i].dataNascimento.ano);
        printf("CPF: %s\n", listaDiscentes[i].cpf);
      }
    }
  }
}

// funcao para cadastrar discentes
int cadastrarDiscentes() {
  // verifica se ainda eh possivel cadastrar mais discentes
  if (quantidaDeDiscentes == TAMANHO_ARRAY_DISCENTE) {
    printf("\nQuantidade maxima de discentes alcancada!\n");
  } else {
       int encontrado = buscarDiscente(); 
        if(encontrado == 1){
            printf("Erro: numero de matricula ja cadastrado!");
        } else {
            //printf("\nDigite os dados cadastrais da(o) discente\n");

            printf("\nInforme o numero de matricula: ");
            scanf("%d", &listaDiscentes[quantidaDeDiscentes].matricula);
            getchar();

            printf("Informe o nome da(o) discente: ");
            fgets(listaDiscentes[quantidaDeDiscentes].nome, 50, stdin);
            size_t ln = strlen(listaDiscentes[quantidaDeDiscentes].nome);

            printf("Digite o sexo da(o) discente (M) ou (F): ");
            scanf(" %c", &listaDiscentes[quantidaDeDiscentes].sexo);
            getchar();

            // temporario
            printf("Digite o dia de nascimento: ");
            scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.dia);

            printf("Digite o mes de nascimento: ");
            scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.mes);

            printf("Digite o ano de nascimento: ");
            scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.ano);
            getchar();

            printf("Digite cpf da(o) discente : ");
            fgets(listaDiscentes[quantidaDeDiscentes].cpf, 15, stdin);
            size_t lr = strlen(listaDiscentes[quantidaDeDiscentes].cpf);
            lr = strlen(listaDiscentes[quantidaDeDiscentes].cpf) - 1;

            listaDiscentes[quantidaDeDiscentes].ativo = 1;
            quantidaDeDiscentes++;
        }
  }
}

// funcao para atualizar registro do discentes
int atualizarDiscente() {
  int opcaoAtualizar;
  int encontrado = buscarDiscente();  

  while (!sair) {
    // chama a funcao buscarDiscente() e guarda o resultado numa variavel

    if(encontrado == 1){
        // Chama a funcao opcaoMenuAtualizarDiscente() e imprime na tela o menu de  opcoes
        opcaoAtualizar = opcaoMenuAtualizarDiscente(); 
    }else{
        printf("\nErro: numero de matricula nao encontrado! \n");
        break;
    }

    switch (opcaoAtualizar) {
      case 0: {
        sair = 1;
        break;
      }
      case 1: {  // essa parte de atualizar ainda precisa ser aprimorada
        char nomeAtualizado[50];
        // printf("Informe o nome da(o) discente: ");
        fgets(nomeAtualizado, 50, stdin);

// Copia o nome lido para o campo nome da estrutura
        strcpy(listaDiscentes[quantidaDeDiscentes].nome, nomeAtualizado);

        // printf("Informe o nome da(o) discente: ");
        // fgets(listaDiscentes[quantidaDeDiscentes].nome, 50, stdin);

        // strcpy(listaDiscentes[quantidaDeDiscentes].nome, 50, stdin);
        // size_t ln = strlen(listaDiscentes[quantidaDeDiscentes].nome);
        break;
      }
      case 2: {
        printf("Digite o sexo da(o) discente (M) ou (F): ");

        scanf(" %c", &listaDiscentes[quantidaDeDiscentes].sexo);
        getchar();
        break;
      }
      case 3: {
        // temporario
        printf("Digite o dia de nascimento: ");
        scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.dia);

        printf("Digite o mes de nascimento: ");
        scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.mes);

        printf("Digite o ano de nascimento: ");
        scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.ano);
        getchar();
        break;
      }
      case 4: {
        printf("Digite cpf da(o) discente : ");
        fgets(listaDiscentes[quantidaDeDiscentes].cpf, 15, stdin);
        size_t ls = strlen(listaDiscentes[quantidaDeDiscentes].cpf);
        ls = strlen(listaDiscentes[quantidaDeDiscentes].cpf) - 1;
        break;
      }
    }
  }
}

// funcao para excluir registro do discentes
int excluirDiscente() {
//   int matricula;
//   printf("Digite o numero matricula da(o) discente que deseja excluir:\n");
//   scanf("%d", &matricula);

// chama a funcao buscarDiscente() e guarda o resultado numa variavel
   int encontrado = buscarDiscente();  

    if(encontrado == 1){
        // Chama a funcao opcaoMenuAtualizarDiscente() e imprime na tela o menu de  opcoes
        // busca no array o registro do estudante cujos dados sao iguais ao numero de matricula
        for (int i = 0; i < quantidaDeDiscentes; i++) {
            if (matricula == listaDiscentes[i].matricula && listaDiscentes[i].ativo) {
                listaDiscentes[i].ativo = -1;

                for (int j = i; j < quantidaDeDiscentes - 1; j++) {
                  listaDiscentes[j].matricula = listaDiscentes[j+1].matricula;
                  //listaDiscentes[j].matricula = listaDiscentes[j+1].nome; //nao está funcionando
                  listaDiscentes[j].sexo = listaDiscentes[j+1].sexo;
                  //listaDiscentes[j].dataNascimento = listaDiscentes[j + 1].dataNascimento; //nao está funcionando
                  //listaDiscentes[j].cpf = listaDiscentes[j+1].cpf; //nao está funcionando
                  listaDiscentes[j].ativo = listaDiscentes[j+1].ativo;
                }
                quantidaDeDiscentes--;
            }  
        } 
    } else{
        printf("\nErro: numero de matricula nao encontrado!\n");
    }
}

// funcao para buscar registro do discentes pela matricula
int buscarDiscente () {
  int discenteEncontrado = 0;

  printf("pesquise o numero matricula da(o) discente: ");
  scanf("%d", &matricula);

//imprime mensagem de erro no caso de numero negativo
  if (matricula < 0) {
    printf("\nErro: Matricula invalida!\n");
  } else {
    // busca no array de discentes a matricula do estudante
    for (int i = 0; i < quantidaDeDiscentes; i++) {
      if (matricula == listaDiscentes[i].matricula && listaDiscentes[i].ativo) {
        discenteEncontrado = 1;
        break;
      }
    }
        return discenteEncontrado;
  }
}