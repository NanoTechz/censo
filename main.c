#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cidade.h"
#include "arquivo.h"
#include "util.h"

#define DEFAULT_NAME "database.txt"


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

int main(){
	int confirmacao = 0;
	FILE *arquivo;

	/* Inicialização/Carregamento do ARQUIVO */
	arquivo = inicializarArquivo(DEFAULT_NAME);


	/* Loop com o fluxo principal */
	do{
		exibirOpcoes(); /* Exibi as opções do menu */
	}while(confirmacao);

	return 0;
}