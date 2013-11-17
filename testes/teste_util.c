#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../util.h"

int main(){
	char nome[] = "teste 000001", lol, aux[20];
	puts(nome);

	substituirEspacoNaString(nome);
	puts(nome);

	voltarEspacoNaString(nome);
	puts(nome);

	printf("%d\n", strcmp("a", "z"));
	printf("%d\n", strcmp("A", "a"));

	str_uppercase(nome, aux);
	printf("%d\n %s\n", strcmp("TESTE 000001",  aux), aux);
	printf("%c", toupper('0'));

	return 0;
}