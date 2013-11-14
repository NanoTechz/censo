#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * inicializarArquivo(char *file_name){
	FILE *arquivo;

	arquivo = fopen(file_name, "a+b");

	if(arquivo == NULL){
		printf("Erro na leitura ou na criação do arquivo (%s).\n", file_name);
		printf("Pressione qualquer tecla para encerrar o programa.\n");
		getchar();
		exit(-1);
	}

	printf("Arquivo inicializado.\n");
	
	return arquivo;
}
