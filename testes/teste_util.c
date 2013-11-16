#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../util.h"

int main(){
	char nome[] = "teste 000001", lol;
	puts(nome);

	substituirEspacoNaString(nome);
	puts(nome);

	voltarEspacoNaString(nome);
	puts(nome);

	printf("%d\n", strcmp("a", "z"));

	return 0;
}