#include <stdio.h>
#include <string.h>

void exibirOpcoes(){ /* Opções do menu */
	printf("\nMenu de opções:\n");
	printf("\t1) Cadastrar os dados de rendimento de uma cidade\n");
	printf("\t2) Consultar os dados de uma cidade\n");
	printf("\t3) Excluir uma cidade\n");
	printf("\t5) Mostrar a relação de cidades ordenada por nome\n");
	printf("\t6) Gerar relatório de cidades\n");
	printf("\t7) Sair do programa\n");
}

void substituirCaracter(char *texto, char novo, char velho){
	int i, j;

	i = strlen(texto);

	if(i <= 0){
		return;
	}

	for (j= 0; j < i; ++j)
	{
		if(*(texto + j) == velho){
			*(texto + j) = novo;
		}
	}
}

/* Função para substituir os espaços em branco na "string" para 
 * facilitar na leitura com fscanf() 
 */
void substituirEspacoNaString(char *texto){
	substituirCaracter(texto, '_', 32);
}