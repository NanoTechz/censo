#include <stdlib.h>
#include "modelo/cidade.h"
#include "modelo/estado.h"
#include "arquivo/arquivo.h"
//#include "util.h"

#define null NULL

cidade *HEAD = NULL;
cidade *final = NULL;

void criarCidades(){
	cidade *temp;
	int i;
	char *string;

	for (i = 0; i < 50; ++i)
	{
		temp = (cidade *)malloc(sizeof(cidade));
			temp->qtd_pessoa_sem_rendimento=i+1;
			temp->qtd_pessoas_0_1=i+2;
			temp->qtd_pessoas_1_2=i+3;
			temp->qtd_pessoas_2_3=i+4;
			temp->qtd_pessoas_3_5=i+5;
			temp->qtd_pessoas_5_10=i+6;
			temp->qtd_pessoas_10_20=i+7;
			temp->qtd_pessoas_mais_20=i+8;

		string = (char *)malloc(sizeof(char));	
		strcpy(string, "sajkdhkjsadhksd");	
		*(string+5)=i;

		temp->nome_cidade = string;


		string = (char *)malloc(sizeof(char));
		strcpy(string, "asdsdsdsdsdasdas");
		*(string+5)=i;

		temp->nome_estado = string;


		temp->prox =NULL;

		if(i == 0){
			
			HEAD = temp;
			final = temp;
		}else{
			final->prox = temp;
			final = temp;
		}
	}
}


void exibirLista(){
	cidade *temp;

	if(HEAD == NULL){
		printf("Lista vazia");
		return;
	}

	temp = HEAD;

	do{
		printf("Cidade %s do Estado de %s\n", temp->nome_cidade, temp->nome_estado);
		//temp= temp->prox;
	}while (temp != null);
}

void salvarCidades(FILE *arquivo){
	cidade *temp;
	if(HEAD==NULL){
		return;
	}

	temp = HEAD;

	do{
		fseek(arquivo, 0, SEEK_END);
		fwrite(&temp, sizeof(temp), 1, arquivo);
		temp=temp->prox;
	}while(temp != null);

	fclose(arquivo);
}


void lerCidades(FILE *arquivo){
	cidade *temp;

	fseek(arquivo, 0, SEEK_SET);

	while(!feof(arquivo)){
		fread(&temp, sizeof(temp), 1, arquivo);

		printf("Cidade %s do Estado de %s.\n", temp->nome_cidade, temp->nome_estado);
		printf("Endereco %p.\n", temp->prox);
	}
}

int main(){
	FILE *arquivo;
	arquivo = inicializar("teste.bd"); // Abre/Cria o arquivo
	lerCidades(arquivo);
}