#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * inicializar(char *file_name);

void salvarCidade(FILE *arquivo, char *valor_linha);

void deletarCidade(FILE *arquivo, char *nome_cidade);