// nao escrever comentarios com acento, til ou cedilha
// usar verbos para declarar variaveis
// usar o padrao camelCase para declarar variaveis
// para abir a pasta do projeto no shell cd ProjetoEscola
// comando para executar o projeto gcc escola.c -o escola
// comando para executar o projeto ./escola
//delecao placeholder define a posicao do array como -1
//delecao shift move o todos os itens do array para uma casa desejada e sobreescreve o valor

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO_ARRAY_DISCENTE 3 // define o tamanho do vetor
typedef struct data {  // struct de data nascimento
  int dia;
  int mes;
  int ano;
} Data;

typedef struct discente
{ // struct de discente
  int matricula;
  char nome[50]; // ainda estou pensando se essa é a melhor opção de tipo
  char sexo;
  Data dataNascimento;
  char cpf[15]; // ainda estou pensando em como fazer o cpf ser valido e se essa é a melhor opção de tipo
  int ativo;
} Discente;

typedef struct docente{
  int idDocente;
  char nome[50];
  char sexo; 
} Docente;

// typedef struct disciplina{
//   int idDisciplina; // id da disicplina
//   int idDocente; // id do professor responsável
//   char nome[500]; // nome da disciplina
//   int vagas; // total de vagas da disciplina
//   int quantidadeAlunos; //guarda a quantidade de alunos matriculados
//   int idAlunosMatriculados[vagas]; // guarda o id dos alunos matriculados na disciplina.
// } Disciplina;

// funcao principal
int main(void)
{                                            
// vetor para adicionar os Discentes
  Discente listaDiscentes[TAMANHO_ARRAY_DISCENTE]; 
// variavel para escolher a opcao do menu
  int quantidaDeDiscentes = 0;
  int opcaoMenu;                             
  // variavel para guardar a opcao sair do menu
  int sair = 0; 

// imprime na tela o menu de opcoes
  while (!sair)
  { 
    printf("Projeto escola - Disciplina INF029\n");
    printf("\n<<< Escolha entre as opções abaixo para inciar >>>\n");
    printf("\n0 - Sair\n");
    printf("1 - Discente\n");
    printf("2 - Docente\n");
    printf("3 - Disciplina\n");
// salva a opção escolhida no menu
    scanf("%d", &opcaoMenu); 

    switch (opcaoMenu)
    {
    case 0:
    {
      printf("Finalizando Projeto Escola\n");
      sair = 1;
      break;
    }
// opcao para cadastrar discente
    case 1:
    { 
// imprime na tela o nome do módulo                                       
      printf("\n<<< Módulo Discente >>>\n"); 
// variavel para sair do módulo
      int sairDiscente = 0;                  
// variavel para escolher a opcao do menu cadastrar alino
      int opcaoDiscente;                    
// imprime na tela o menu de opcoes discente
      while (!sairDiscente)
      {
        printf("\n0 - Voltar\n");
        printf("1 - Cadastrar Discente\n");
        printf("2 - Listar Discente\n");
        printf("3 - Atualizar Discente\n");
        printf("4 - Excluir Discente\n");
        scanf("%d", &opcaoDiscente);

        switch (opcaoDiscente)
        {
        case 0:
        {
          sairDiscente = 1;
          break;
        }
         case 1:
         {
          printf("\n1 - < Cadastrar Discentes >\n");
// verifica se ainda é possível cadastrar mais discentes          
          if (quantidaDeDiscentes == TAMANHO_ARRAY_DISCENTE)
          { 
            printf("\nQuantidade maxima de discentes alcancada!\n");
          }
          else
          {
            printf("\nDigite os dados cadastrais da(o) discente\n");
         
            printf("\nInforme o numero de matricula que deseja cadastrar: ");
            scanf("%d", &listaDiscentes[quantidaDeDiscentes].matricula);
            getchar();
            printf("Informe o nome da(o) discente: ");
            fgets(listaDiscentes[quantidaDeDiscentes].nome, 50, stdin); 
            size_t ln = strlen(listaDiscentes[quantidaDeDiscentes].nome);

            printf("Digite o sexo da(o) discente (M) ou (F): ");

            scanf(" %c", &listaDiscentes[quantidaDeDiscentes].sexo);
            getchar();

            //temporário
            printf("Digite o dia de nascimento: ");
            scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.dia);

            printf("Digite o mês de nascimento: ");
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
          break;
        }
        case 2:
        {
// listar a quantidade de discentes
          printf("2 - < Listar Discentes >\n\n "); 
          if (quantidaDeDiscentes == 0)
          {
            printf("\nErro: Nenhum registro de discente cadastrado!\n");
            break;
          }
          else
          {
            for (int i = 0; i < quantidaDeDiscentes; i++)
            {
              if (listaDiscentes[i].ativo == 1)
              {
                printf("Matricula: %d\n", listaDiscentes[i].matricula);
                printf("Nome: %s\n", listaDiscentes[i].nome);
                printf("Sexo: %c\n", listaDiscentes[i].sexo);
                printf("Data Nascimento: %d/%d/%d\n", listaDiscentes[i].dataNascimento.dia, listaDiscentes[i].dataNascimento.mes, listaDiscentes[i].dataNascimento.ano);
                printf("CPF: %s\n", listaDiscentes[i].cpf);
              }
            }
          }
          break;
        }
        case 3:
        {
          printf("3 - < Atualizar Discente >\n");
          printf("Digite o numero matricula da(o) discente que deseja atualizar:\n");

          int matricula;
          scanf("%d", &matricula);

          int discenteEncontrado = 0;

          if (matricula < 0)
          {
            printf("\nErro: Matricula invalida!\n");
          }
          else
          {
            for (int i = 0; i < quantidaDeDiscentes; i++)
            {
              if (matricula == listaDiscentes[i].matricula && listaDiscentes[i].ativo)
              {
                discenteEncontrado = 1;
                break;
              }
            }
            if (!discenteEncontrado)
            {
              printf("\nErro: Registro da(o) discente nao encontrado!\n");
              break;
            }
          }
          int sair = 0;
          int opcaoAtualizar;
          
          while (!sair)
          {
            printf("\n0 - Sair\n");
            printf("1 - Atualizar nome\n");
            printf("2 - Atualizar sexo\n");
            printf("3 - Atualizar data de nascimento\n");
            printf("4 - Atualizar cpf\n");
            scanf("%d", &opcaoAtualizar);

            switch (opcaoAtualizar)
            {
            case 0:
            {
              sair = 1;
              break;
            }
            case 1:
            { //essa parte de atualizar ainda precisa ser aprimorada
              printf("Informe o nome da(o) discente: ");
              fgets(listaDiscentes[quantidaDeDiscentes].nome, 50, stdin); 
              size_t ln = strlen(listaDiscentes[quantidaDeDiscentes].nome);
              break;
            }
            case 2:
            {
              printf("Digite o sexo da(o) discente (M) ou (F): ");

              scanf(" %c", &listaDiscentes[quantidaDeDiscentes].sexo);
              getchar();
              break;
            }
            case 3:
            {
              //temporário
              printf("Digite o dia de nascimento: ");
              scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.dia);

              printf("Digite o mês de nascimento: ");
              scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.mes);

              printf("Digite o ano de nascimento: ");
              scanf("%d", &listaDiscentes[quantidaDeDiscentes].dataNascimento.ano);
              getchar();
              break;
            }
            case 4:
            {
               printf("Digite cpf da(o) discente : ");
                          fgets(listaDiscentes[quantidaDeDiscentes].cpf, 15, stdin); 
                size_t ls = strlen(listaDiscentes[quantidaDeDiscentes].cpf);

                ls = strlen(listaDiscentes[quantidaDeDiscentes].cpf) - 1; 
              break;
            }
            }
          }
        break;
        }
        case 4:
      {
        printf("4 - < Excluir Discente >\n");
        printf("Digite o numero matricula da(o) discente que deseja excluir:\n");
        int matricula;
        scanf("%d", &matricula);

// essa variável serve para verificar se o discente foi encontrado ou não
        int discenteEncontrado = 0;

// verifica se o numero de matricula eh menor que zero
        if (matricula < 0)
        {
          printf("\nErro: Matricula invalida!\n");
        }
        else
        {
// busca no array o registro do estudante cujos dados sao iguais ao numero de matricula
          for (int i = 0; i < quantidaDeDiscentes; i++)
          {
            if (matricula == listaDiscentes[i].matricula && listaDiscentes[i].ativo)
            {
              listaDiscentes[i].ativo = -1;

              for (int j = i; j < quantidaDeDiscentes - 1; j++)
              {
                listaDiscentes[j].matricula = listaDiscentes[j + 1].matricula;
                //listaDiscentes[j].matricula = listaDiscentes[j+1].nome;
                listaDiscentes[j].sexo = listaDiscentes[j + 1].sexo;
                //listaDiscentes[j].dataNascimento = listaDiscentes[j + 1].dataNascimento;
                //listaDiscentes[j].cpf = listaDiscentes[j + 1].cpf;
                listaDiscentes[j].ativo = listaDiscentes[j + 1].ativo;
              }
              quantidaDeDiscentes--;
              discenteEncontrado = 1;
              break;
            }
          }
// caso não seja encontrado o discente exibe a mensagem de erro
          if (!discenteEncontrado)
          {
            printf("\nErro: Registro da(o) discente nao encontrado!\n");
          }
          else
          {
            printf("\nRegistro da(o) discente excluido com sucesso!\n");
          }
        }
        break;
      }
        default:
        {
          printf("Opção invalida (Discente)");
        }
        }
       } 
  }
// opcao para cadastrar docente
    case 2:
    {
      printf("<<< Módulo Docente >>>");
      break;
    }
// opcao para cadastrar discplina
    case 3:
    {
      printf("<<< Módulo Disciplina >>>");
      break;
    }
    default:
    {
      printf("Opção inválida");
    }
    }
    }
  printf("Programa encerrado");
  return 0;
}
