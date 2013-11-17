#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "cidade.h"
//#include "util.h"

#define MODO "a+"

FILE * inicializarArquivo(char *file_name){ /* File_name: NOME DO ARQUIVO, modo:modo que o arquivo será aberto (leitura ou gravação */
	FILE *arquivo;

	arquivo = fopen(file_name, MODO);

	if(arquivo == NULL){ 
		printf("Erro na leitura ou na criação do arquivo (%s).\n", file_name);
		printf("Pressione qualquer tecla para encerrar o programa.\n");
		getchar();
		exit(-1);
	}
	
	return arquivo;
}

//Excluiu e cria um novo arquivo
void limparArquivo(char *file_name){
	FILE *arquivo;

	arquivo = fopen(file_name, "wt");

	if(arquivo == NULL){ 
		printf("Erro na leitura ou na criação do arquivo (%s).\n", file_name);
		printf("Pressione qualquer tecla para encerrar o programa.\n");
		getchar();
		exit(-1);
	}

	//fprintf(arquivo, "\n");
	fclose(arquivo);
}

void gravarArvoreCidade(CIDADE *root, char *file_name){
	char estado_temp[TAM_STRING], cidade_temp[TAM_STRING]; //TAM_STRING cte de cidade.h
	FILE *arquivo;

	arquivo = inicializarArquivo(file_name);

	if(root != NULL){
		fseek(arquivo, 0, SEEK_END);

		strcpy(cidade_temp, root->nome_cidade);
		strcpy(estado_temp, root->nome_estado);

		//Retirando os espaços vazios para facilitar na hora da leitura
		substituirEspacoNaString(cidade_temp);
		substituirEspacoNaString(estado_temp);

		// FORMAT_GRAVACAO constante (cidade.h) que informa os parâmetros para gravação
		fprintf(arquivo, FORMAT_GRAVACAO,
				cidade_temp,
				estado_temp,
				root->total_pessoas,
				root->qtd_pessoa_sem_rendimento,
				root->qtd_pessoas_0_1,
				root->qtd_pessoas_1_2,
				root->qtd_pessoas_2_3,
				root->qtd_pessoas_3_5,
				root->qtd_pessoas_5_10,
				root->qtd_pessoas_10_20,
				root->qtd_pessoas_mais_20);

		fclose(arquivo);

		gravarArvoreCidade(root->left, file_name);
		gravarArvoreCidade(root->right, file_name);
	}
}

//Funcao que carega so dados salvos no arquivo
void carregarArquivo(CIDADE **root, char *file_name){
	CIDADE *temp;
	FILE *arquivo;

	arquivo = inicializarArquivo(file_name);

		if(arquivo){
		fseek(arquivo, 0, SEEK_SET);
		
		while(!feof(arquivo)){
			temp = (CIDADE *) malloc(sizeof(CIDADE));

			fscanf(arquivo, FORMAT_LEITURA,
				temp->nome_cidade,
				temp->nome_estado,
				&temp->total_pessoas,
				&temp->qtd_pessoa_sem_rendimento,
				&temp->qtd_pessoas_0_1,
				&temp->qtd_pessoas_1_2,
				&temp->qtd_pessoas_2_3,
				&temp->qtd_pessoas_3_5,
				&temp->qtd_pessoas_5_10,
				&temp->qtd_pessoas_10_20,
				&temp->qtd_pessoas_mais_20);

			    //Colocando os espaços vazios retirados na gravação
				voltarEspacoNaString(temp->nome_cidade);
				voltarEspacoNaString(temp->nome_estado);
				if(strlen(temp->nome_cidade) > 0){
					inserirCidade(&(*root), temp); //	Inserindo node numa raiz
				} 				
			}

		fclose(arquivo);
	}
}
