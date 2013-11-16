/* qtd_pessoas_(rendimento inicial)_(rendimento até) */
#include <string.h>

//#include "util.h"

#define TAM_STRING 50

#define FORMAT_GRAVACAO "%s %s %ld %d %d %d %d %d %d %d %d\n"
#define FORMAT_LEITURA "%s %s %ld %d %d %d %d %d %d %d %d"

typedef struct _cidade {

	char nome_cidade[TAM_STRING];
	char nome_estado[TAM_STRING];

	long int total_pessoas;
	int qtd_pessoa_sem_rendimento;
	int qtd_pessoas_0_1;
	int qtd_pessoas_1_2;
	int qtd_pessoas_2_3;
	int qtd_pessoas_3_5;
	int qtd_pessoas_5_10;
	int qtd_pessoas_10_20;
	int qtd_pessoas_mais_20;

	struct _cidade *left;
	struct _cidade *right;
} CIDADE;


typedef struct _tree{
	struct _cidade *root;
} TREE;

CIDADE * criarCidade(){
	CIDADE *newCidade;
	long int verificar;

	newCidade = (CIDADE *)(malloc(sizeof(CIDADE)));

	printf("Inserir nova cidade:\n");

	// void: inserirTexto(mensagem, variavel, tamanho_vetor);
	inserirTexto("Digite o nome da Cidade:", newCidade->nome_cidade, TAM_STRING);

	inserirTexto("Digite o nome do Estado:", newCidade->nome_estado, TAM_STRING);

	printf("Digite a quantidade de pessoas de 10 anos ou mais de idade, por classes de rendimento nominal mensal:\n");
	
	inserirNumeroLong("Total de pessoas", &newCidade->total_pessoas, 0, 2000000000);

	inserirNumero("Sem rendimento", &newCidade->qtd_pessoa_sem_rendimento, 0, 2000000000);

	inserirNumero("Ate 1 salario minimo:", &newCidade->qtd_pessoas_0_1, 0, 2000000000);

	inserirNumero("Mais de 1 a 2 salarios minimos:", &newCidade->qtd_pessoas_1_2, 0, 2000000000);

	inserirNumero("Mais de 2 a 3 salarios minimos:", &newCidade->qtd_pessoas_2_3, 0, 2000000000);

	inserirNumero("Mais de 3 a 5 salarios minimos:", &newCidade->qtd_pessoas_3_5, 0, 2000000000);

	inserirNumero("Mais de 5 a 10 salarios minimos:", &newCidade->qtd_pessoas_5_10, 0, 2000000000);

	inserirNumero("Mais de 10 a 20 salarios minimos:", &newCidade->qtd_pessoas_10_20, 0, 2000000000);

	inserirNumero("Mais de 20 salarios minimos:", &newCidade->qtd_pessoas_mais_20, 0, 2000000000);
	getchar();

	//Calculando o total de pessoas
	verificar = newCidade->qtd_pessoa_sem_rendimento + newCidade->qtd_pessoas_0_1 
		+ newCidade->qtd_pessoas_1_2 + newCidade->qtd_pessoas_2_3 + newCidade->qtd_pessoas_3_5 
		+ newCidade->qtd_pessoas_5_10 + newCidade->qtd_pessoas_10_20 + newCidade->qtd_pessoas_mais_20;

	if(verificar != newCidade->total_pessoas){
		printf("ERRO VALORES NAO BATEM.\nPREENCHA O FORMULARIO NOVAMENTE:\n");
		return criarCidade();
	}

	return newCidade;
}

/* inserir() – recebe dois parâmetros, um ponteiro para a árvore e o elemento a ser inserido */
void inserirCidade(CIDADE **node, CIDADE *newCidade){
	int valor_strcmp, aux_valor_strcmp;
	if((*node) == NULL){
		printf("Salvando.\n");
		*node = newCidade;
	}else{
		valor_strcmp = strcmp((*node)->nome_cidade, newCidade->nome_cidade);

		printf("Inicializando o salvamento.\n");

		switch(valor_strcmp){
			case 1: // Nome cidade "menor" que a da raiz
					printf("%s\n", "menor");
					inserirCidade(&((*node)->left), newCidade);
				break;
			case -1: // Nome cidade "maior" que a da raiz
					printf("%s\n", "maior");
					inserirCidade(&((*node)->right), newCidade);
				break;
			case 0: // Nome das cidades iguais -> verificar o estado
					aux_valor_strcmp = strcmp((*node)->nome_estado, newCidade->nome_estado);
					
					if(aux_valor_strcmp == 1){
						inserirCidade(&((*node)->left), newCidade);
					}else if(aux_valor_strcmp == -1){
						inserirCidade(&((*node)->right), newCidade);	
					} // else Cidade já exite
				break;
		}
	}
}

void pre_ordem(CIDADE *raiz){
	if(raiz != NULL){
		printf("%s\n ", raiz->nome_cidade);
		pre_ordem(raiz->left);
		pre_ordem(raiz->right);
	}
}


