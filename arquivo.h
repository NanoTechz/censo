#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes do modo
#define MODO_LEITURA "rt"
#define MODO_GRAVACAO "wt"

FILE * inicializarArquivo(char *file_name, char *modo){ /* File_name: NOME DO ARQUIVO, modo:modo que o arquivo será aberto (leitura ou gravação */
	FILE *arquivo;

	arquivo = fopen(file_name, modo);

	if(arquivo == NULL){ 
		printf("Erro na leitura ou na criação do arquivo (%s).\n", file_name);
		printf("Pressione qualquer tecla para encerrar o programa.\n");
		getchar();
		exit(-1);
	}
	
	return arquivo;
}
