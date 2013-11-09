#include <stdlib.h>
#include "modelo/cidade.h"
#include "modelo/estado.h"
#include "arquivo/arquivo.h"
#include "util.h"

#define DEFAULT_NAME "database.txt"

int main(){
	int confirmacao = 0;
	FILE *arquivo;

	/* Inicialização/Carregamento do ARQUIVO */
	arquivo = inicializar(DEFAULT_NAME);


	/* Loop com o fluxo principal */

	do{
		exibirOpcoes();
	}while(confirmacao);

	return 0;
}