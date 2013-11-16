#include <stdio.h>
#include <string.h>

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

/* 
 * Voltar a string ao seu estado original.
 */
void voltarEspacoNaString(char *texto){
	substituirCaracter(texto, 32, '_');
}

void limparTELA(){
	#ifdef _WIN32
		system("cls");
	#endif

	#ifdef __linux__
		system("clear");
	#endif
}


// Retira a quebra de linha no final do vetor
void tirarQuebraLinha(char *texto){
	int length = strlen(texto);

	if(*(texto + (length-1)) == '\n'){
		*(texto + (length-1)) = '\0';
	}
}

// Funcao para aux. na entrada de textos
void inserirTexto(char *msg, char *texto, int tamanho){
	printf("\t%s\n", msg);
	fgets(texto,tamanho, stdin);
	tirarQuebraLinha(texto);

	//validar entrada
	if(strlen(texto) <=0 ){
		printf("VALOR INVALIDO!\nDigite novamente:\n");
		inserirTexto(msg, texto, tamanho);
	}
}

// Funcao para aux. na entrada de numeros
void inserirNumero(char *msg, int *valor, int minimo, int maximo){
	printf("\t%s\n", msg);
	scanf("\t%d", valor);

	//validar entrada
	if((*valor < minimo) || (*valor > maximo)){
		printf("VALOR INVALIDO!\nDigite novamente um valor entre [%d, %d]:\n", minimo, maximo);
		inserirNumero(msg, valor, minimo, maximo);
	}
}

void inserirNumeroLong(char *msg, long int *valor, long int minimo, long int maximo){
	printf("\t%s\n", msg);
	scanf("\t%ld", valor);

	//validar entrada
	if((*valor < minimo) || (*valor > maximo)){
		printf("VALOR INVALIDO!\nDigite novamente um valor entre [%ld, %ld]:\n", minimo, maximo);
		inserirNumeroLong(msg, valor, minimo, maximo);
	}
}

void pausar(char *msg){
	printf("%s\nPressione ENTER para continuar o programa.\n", msg);
	getchar();
}