#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../arquivo.h"

#define FILENAME "teste.dat"
#define TAM 50
#define QTD 50
#define null NULL

typedef struct _teste
{
	char nome[50];
	int id;

	struct _teste *next;
} teste;

teste *first = NULL;
teste *last = NULL;

teste * criarNo(int i){
	teste *no;

	no = (teste *)(malloc(sizeof(teste)));
	strcpy(no->nome, "nome_teste");
	no->id = i;
	no->next = null;

	return no;
}

void gerarLista(){
	int i;
	teste *no;

	for (i = 0; i < QTD; ++i)
	{
		if(i == 0){
			first = criarNo(i+1);
			last = first;
		}else{
			no = criarNo(i+1);
			last->next = no;
			last = no;
		}
	}
}

void imprimirNo(teste *no){
	printf("Nome: %s\n\t%d\n", no->nome, no->id);
}

void imprimirLista(){
	teste *no;

	no = first;

	do{
		imprimirNo(no);
		no = no->next;
	}while(no != null);
}

void gravar(FILE *arquivo){
	int i, resultado;
	teste *no;

	if(first == null){
		return;
	}

	no = first;

	if(arquivo){
		do
			{
				fseek(arquivo, 0, SEEK_END);
				fprintf(arquivo, "%d ", no->id);
				fputs(no->nome, arquivo);
				fprintf(arquivo, "\n");
				no = no->next;
			} while (no != null);

			fclose(arquivo);	
	}
}

void ler(FILE *arquivo){
	teste *no;
	int id;
	char nome[TAM];

	if(arquivo){
		fseek(arquivo, 0, SEEK_SET);
		
		while(!feof(arquivo)){
			no = (teste *) malloc(sizeof(teste));
			fscanf(arquivo, "%d %s", &id, nome);
			no->id = id;
			strcpy(no->nome, nome);
			imprimirNo(no);

			free(no);
		}

		fclose(arquivo);
	}
}

int main(){
	FILE *arquivo;
	int opcao;

	do{
		printf("Escolha:\n");
		printf("1 - Gravar Lista No arquivo\n");
		printf("2 - Ler arquivo\n");		
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1 :
				gerarLista();
				arquivo = inicializarArquivo(FILENAME, MODO_GRAVACAO);
				gravar(arquivo);
				break;
			case 2 : 
				arquivo = inicializarArquivo(FILENAME, MODO_LEITURA);
				ler(arquivo);
				break;
			default :
				printf("Opcao invalida.\n");
				exit(0);
				break;
		}	
	}while(1);

	fclose(arquivo);
	return 0;
}