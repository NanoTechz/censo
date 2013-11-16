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

int main(){
	int opcao = 0;
	TREE *pais;
	CIDADE *aux;

	pais = (TREE *)(malloc(sizeof(TREE)));
	
	/* Loop com o fluxo principal */
	do{
		limparTELA(); // Limpa a tela do terminal
		exibirOpcoes(); /* Exibi as opções do menu */
		scanf("%d", &opcao);
		getchar(); // Pega o ENTER

		switch(opcao){
			case 1:
				limparTELA();
				aux = criarCidade(); // Cria e recebe os valors de uma nova cidade
				inserirCidade(&pais->root, aux); // Inseri o node na arvore
				
				pre_ordem(pais->root);

				gravarArvoreCidade(pais->root, DEFAULT_NAME); // Gravando a arvore inteira
				pausar("Nova cidade inserida com sucesso.");
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
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
