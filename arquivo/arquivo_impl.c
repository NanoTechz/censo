#include "arquivo.h"

FILE * inicializar(char *file_name){
	FILE *arquivo;

	arquivo = fopen(file_name, "a+t");

	if(arquivo == NULL){
		printf("Erro na leitura ou na criação do arquivo (%s).\n", file_name);
		printf("Pressione qualquer tecla para encerrar o programa.\n");
		getchar();
		exit(-1);
	}

	printf("Arquivo inicializado.\n");
	
	return arquivo;
}