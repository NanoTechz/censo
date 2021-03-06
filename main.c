#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "util.h"
#include "cidade.h"
#include "arquivo.h"

#define DEFAULT_NAME "database.dat"

/**
 * arquivo.h
 * arquvo com funções para manipular o arquivo
 *
 * cidade.h
 * arquivo com a struct
 *
 * util.h
 * arquivo com funções "utéis" para a execução do sistema,
 * criado principalmente para deixar o arquivo main limpo.
 *
 */

void exibirOpcoes();
void relatorio();

int main(){
	int opcao = 0, temp;
	TREE *pais;
	CIDADE *aux;
	char nome_cidade[TAM_STRING], nome_estado[TAM_STRING];

	pais = (TREE *)(malloc(sizeof(TREE)));

	carregarArquivo(&pais->root, DEFAULT_NAME); // Carrega os dados salvos no arquivo 
	
	/* Loop com o fluxo principal */
	do{
		limparTELA(); // Limpa a tela do terminal
		exibirOpcoes(); /* Exibi as opções do menu */
		scanf("%d", &opcao);
		getchar(); // Pega o ENTER

		switch(opcao){
			case 1: //Add
				limparTELA();
				aux = criarCidade(); // Cria e recebe os valors de uma nova cidade
				inserirCidade(&pais->root, aux); // Inseri o node na arvore

				limparArquivo(DEFAULT_NAME);
				gravarArvoreCidade(pais->root, DEFAULT_NAME); // Gravando a arvore inteira
				pausar("Nova cidade inserida com sucesso.");
				break;
			case 2: //Pesquisar
				limparTELA();

				printf("Consulta:\n");
				inserirTexto("Insira o nome da cidade a ser consultada:", nome_cidade, TAM_STRING);
				inserirTexto("Insira o estado em que a cidade pertence:", nome_estado, TAM_STRING);

				aux = pesquisarCidade(pais->root, nome_cidade, nome_estado);

				if(aux != NULL){
					limparTELA();
					printf("A consulta retornou:\n");
					imprimirCidadeComPercentual(aux);
				}else{
					printf("Cidade não encontrada.");
				}
				pausar("");
				break;
			case 3://Excluir
				limparTELA();

				printf("Exclusao:\n");
				inserirTexto("Insira o nome da cidade a ser consultada:", nome_cidade, TAM_STRING);
				inserirTexto("Insira o estado em que a cidade pertence:", nome_estado, TAM_STRING);

				temp = removerCidade(&pais->root, nome_cidade, nome_estado);

				if(temp == 1){
					limparArquivo(DEFAULT_NAME);
					gravarArvoreCidade(pais->root, DEFAULT_NAME); // Gravando a arvore inteira

					printf("Arquivo removido com sucesso.\n");
				}else{
					printf("Cidade não foi removida.");
				}
				pausar("");
				break;
			case 4: // Função oculta
				imprimirEndereco(pais->root);
				pausar("");
				break;
			case 5://Listar Cidades
				limparTELA();
				printf("Relacao de cidades ordenada por nome:\n");
				em_ordem(pais->root);
				pausar("");
				break;
			case 6: //Gerar relatório
				limparTELA();
				relatorio(pais->root);
				pausar("");
				break;
			case 7://Sair
				return 0;
				break;
			default:
				pausar("OPCAO INVALIDA."); // PAUSA O PROGRAMA
			break;
		}

	}while(1);

	return 0;
}

void exibirOpcoes(){ /* Opções do menu */
	printf("Menu de opções:\n");
	printf("\t1) Cadastrar os dados de rendimento de uma cidade\n");
	printf("\t2) Consultar os dados de uma cidade\n");
	printf("\t3) Excluir uma cidade\n");
	printf("\t5) Mostrar a relação de cidades ordenada por nome\n");
	printf("\t6) Gerar relatório de cidades\n");
	printf("\t7) Sair do programa\n");
}

void relatorio(CIDADE *raiz){
	int opcao;
	TREE *raizTemp;

	raizTemp=(TREE *)(malloc(sizeof(TREE)));
	raizTemp->root = NULL;

	printf("Relatorio:\n");
	printf("\t1) Relacao das cidades por ordem crescente de percentual de pessoas sem rendimento\n");
	printf("\t2) Relacao das cidades por ordem crescente de percentual de pessoas ate 2 salarios minimos\n");
	printf("\t3) Relacao das cidades por ordem crescente de percentual de pessoas acima de 20 salarios minimos\n");
	printf("\t4) Cancelar.\n");

	scanf("%d", &opcao);
	getchar(); // Pega o ENTER

	switch(opcao){
		case 1:
				realocarArvore(raiz, &raizTemp->root, RELACAO_SR);
			break;
		case 2:
				realocarArvore(raiz, &raizTemp->root, RELACAO_ATE_2S);
			break;
		case 3:
				realocarArvore(raiz, &raizTemp->root, RELACAO_ACIMA_20s);
			break;
	}

	if((opcao > 0) && (opcao < 4)){
		em_ordemComPercentual(raizTemp->root);
		freeArvore(raizTemp->root);
	}
	
}