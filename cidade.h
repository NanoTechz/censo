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


//Recebe os dados e cria uma cidade
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

	newCidade->left = NULL;
	newCidade->right = NULL;
	return newCidade;
}

/* inserir() – recebe dois parâmetros, um ponteiro para a árvore e o elemento a ser inserido */
void inserirCidade(CIDADE **node, CIDADE *newCidade){
	int valor_strcmp, aux_valor_strcmp;
	if((*node) == NULL){
		*node = newCidade;
	}else{
		valor_strcmp = strcmp((*node)->nome_cidade, newCidade->nome_cidade);

		if(valor_strcmp > 0){ // Nome cidade "menor" que a da raiz
			inserirCidade(&((*node)->left), newCidade);
		}else if(valor_strcmp < 0){
			inserirCidade(&((*node)->right), newCidade);
		}else{ // Senão as cidades possuem o mesmo nome , então verificar o estado
			aux_valor_strcmp = strcmp((*node)->nome_estado, newCidade->nome_estado);

			if(aux_valor_strcmp == 1){
				inserirCidade(&((*node)->left), newCidade);
			}else if(aux_valor_strcmp == -1){
				inserirCidade(&((*node)->right), newCidade);	
			} // else Cidade já exite
		}
	}
}


// Imprime os dados de uma única cidade
void imprimirCidade(CIDADE *node){
	char temp_estado[TAM_STRING];

	if(node == NULL){
		return;
	}

	str_uppercase(node->nome_estado, temp_estado);

	printf("Cidade: %s – Estado: %s.\n", node->nome_cidade, temp_estado);

	printf("Quantidade de pessoas de 10 anos ou mais de idade, por classes de rendimento nominal mensal:\n");
	
	printf("\t- Total de pessoas: %ld.\n", node->total_pessoas);

	printf("\t- Sem rendimento: %d.\n", node->qtd_pessoa_sem_rendimento);

	printf("\t- Ate 1 salario minimo: %d.\n", node->qtd_pessoas_0_1);

	printf("\t- Mais de 1 a 2 salarios minimos: %d.\n", node->qtd_pessoas_1_2);

	printf("\t- Mais de 2 a 3 salarios minimos: %d.\n", node->qtd_pessoas_2_3);

	printf("\t- Mais de 3 a 5 salarios minimos: %d.\n", node->qtd_pessoas_3_5);

	printf("\t- Mais de 5 a 10 salarios minimos: %d.\n", node->qtd_pessoas_5_10);

	printf("\t- Mais de 10 a 20 salarios minimos: %d.\n", node->qtd_pessoas_10_20);

	printf("\t- Mais de 20 salarios minimos: %d.\n\n", node->qtd_pessoas_mais_20);
}

// Imprime os dados de uma única cidade
void imprimirCidadeComPercentual(CIDADE *node){
	char temp_estado[TAM_STRING];

	if(node == NULL){
		return;
	}

	str_uppercase(node->nome_estado, temp_estado);

	printf("Cidade: %s – Estado: %s.\n", node->nome_cidade, temp_estado);

	printf("Quantidade de pessoas de 10 anos ou mais de idade, por classes de rendimento nominal mensal:\n");
	
	printf("\t- Total de pessoas: %ld.\n", node->total_pessoas);

	printf("\t- Sem rendimento: %d - %.2f%%.\n", node->qtd_pessoa_sem_rendimento, percentual(node->qtd_pessoa_sem_rendimento, node->total_pessoas));

	printf("\t- Ate 1 salario minimo: %d - %.2f%%.\n", node->qtd_pessoas_0_1, percentual(node->qtd_pessoas_0_1, node->total_pessoas));

	printf("\t- Mais de 1 a 2 salarios minimos: %d - %.2f%%.\n", node->qtd_pessoas_1_2, percentual(node->qtd_pessoas_1_2, node->total_pessoas));

	printf("\t- Mais de 2 a 3 salarios minimos: %d - %.2f%%.\n", node->qtd_pessoas_2_3, percentual(node->qtd_pessoas_2_3, node->total_pessoas));

	printf("\t- Mais de 3 a 5 salarios minimos: %d - %.2f%%.\n", node->qtd_pessoas_3_5, percentual(node->qtd_pessoas_3_5, node->total_pessoas));

	printf("\t- Mais de 5 a 10 salarios minimos: %d - %.2f%%.\n", node->qtd_pessoas_5_10, percentual(node->qtd_pessoas_5_10, node->total_pessoas));
	printf("\t- Mais de 10 a 20 salarios minimos: %d - %.2f%%.\n", node->qtd_pessoas_10_20, percentual(node->qtd_pessoas_10_20, node->total_pessoas));

	printf("\t- Mais de 20 salarios minimos: %d - %.2f%%.\n\n", node->qtd_pessoas_mais_20, percentual(node->qtd_pessoas_mais_20, node->total_pessoas));
}

// Imprime em pre ordem
void pre_ordem(CIDADE *raiz){
	if(raiz != NULL){
		imprimirCidade(raiz);
		pre_ordem(raiz->left);
		pre_ordem(raiz->right);
	}
}

// Imprime em ordem
void em_ordem(CIDADE *raiz){
	if(raiz != NULL){
		em_ordem(raiz->left);
		imprimirCidade(raiz);
		em_ordem(raiz->right);
	}
}

CIDADE * pesquisarCidade(CIDADE *root, char *nome_cidade, char *nome_estado){
	CIDADE *node;
	char temp_cidade[TAM_STRING], temp_estado[TAM_STRING], aux1[TAM_STRING], aux2[TAM_STRING];


	if(root == NULL){
		return NULL;
	}

	str_uppercase(nome_estado, temp_estado);
	str_uppercase(nome_cidade, temp_cidade);

	node = root;

	while(node != NULL){
		str_uppercase(node->nome_estado, aux2);
		str_uppercase(node->nome_cidade, aux1);

		if(strcmp(aux1, temp_cidade) < 0){
			node = node->right;
		}else if(strcmp(aux1, temp_cidade) > 0){
			node = node->left;
		}else{
			if(strcmp(aux2, temp_estado) == 0){
				return node;
			}else{
				if(strcmp(aux2, temp_estado) < 0){
					node = node->right;
				}else if(strcmp(aux2, temp_estado) > 0){
					node = node->left;
				}
			}
		}
	}

	return  NULL;
}

//Copia os dados da cidade 'B' para 'A'
void copiarCidadeAParaB(CIDADE *a, CIDADE *b){
	strcpy(a->nome_cidade, b->nome_cidade);
	strcpy(a->nome_estado, b->nome_estado);

	a->total_pessoas = b->total_pessoas;
	a->qtd_pessoa_sem_rendimento = b->qtd_pessoa_sem_rendimento;
	a->qtd_pessoas_0_1 = b->qtd_pessoas_0_1;
	a->qtd_pessoas_1_2 = b->qtd_pessoas_1_2;
	a->qtd_pessoas_2_3 = b->qtd_pessoas_2_3;
	a->qtd_pessoas_3_5 = b->qtd_pessoas_3_5;
	a->qtd_pessoas_5_10 = b->qtd_pessoas_5_10;
	a->qtd_pessoas_10_20 = b->qtd_pessoas_10_20;
	a->qtd_pessoas_mais_20 = b->qtd_pessoas_mais_20;
}

CIDADE * menorNo(CIDADE *no){
	if(no == NULL){
		return NULL;
	}else{
		if(no->left == NULL){
			return no;
		}else{
			return menorNo(no->left);
		}
	}
}

//Método para Verificar os enderecos dos nós e seus filhos
void imprimirEndereco(CIDADE *raiz){
	if(raiz != NULL){
		printf("(%p) <- %p -> (%p)\n", raiz->left, raiz, raiz->right);
		imprimirEndereco(raiz->left);
		imprimirEndereco(raiz->right);
	}
}

int removerCidade(CIDADE **raiz, char *nome_cidade, char *nome_estado){
	CIDADE *node;
	char temp_cidade[TAM_STRING], temp_estado[TAM_STRING], aux1[TAM_STRING], aux2[TAM_STRING];


	if(*(raiz) == NULL){ // pesquisa não encontrou nada
		0;
	}

	// Colocando os "textos" no mesmo formato
	str_uppercase(nome_estado, temp_estado);
	str_uppercase(nome_cidade, temp_cidade);

	str_uppercase((*raiz)->nome_estado, aux2);
	str_uppercase((*raiz)->nome_cidade, aux1);

	if(strcmp(aux1, temp_cidade) < 0){
		removerCidade(&((*raiz)->right), nome_cidade, nome_estado);
	}else if(strcmp(aux1, temp_cidade) > 0){
		removerCidade(&((*raiz)->left), nome_cidade, nome_estado);
	}else{
		if(strcmp(aux2, temp_estado) == 0){ //Encontrou a cidade para ser removida
			
			if(((*raiz)->left != NULL) && ((*raiz)->right!=NULL)){ // Verifica se o nó possuí dos filhos
				
				node = menorNo((*raiz)->right); // Pega o menor no da direita da árvore
				copiarCidadeAParaB((*raiz), node); // Copia os dados 
				removerCidade(&(*raiz)->right, (*raiz)->nome_cidade, (*raiz)->nome_estado); // Remove o menor do da esquerda da árvore

			}else{ // senão faça a exclusão normal
				node = *(raiz);

				printf("2\n");
				if((*raiz)->left == NULL){
					(*raiz) = (*raiz)->right;
				}else{
					(*raiz) = (*raiz)->left;
				}
				printf("free()\n");
				free(node);
			}

			return 1;
		}else{//Cidades com nomes == então vetificar os estados
			if(strcmp(aux2, temp_estado) < 0){
				removerCidade(&((*raiz)->right), nome_cidade, nome_estado);
			}else if(strcmp(aux2, temp_estado) > 0){
				removerCidade(&((*raiz)->left), nome_cidade, nome_estado);
			}
		}
	}
}