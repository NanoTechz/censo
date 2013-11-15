#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../util.h"

int main(){
	char nome[] = "teste 000001";

	substituirEspacoNaString(nome);

	puts(nome);
	return 0;
}