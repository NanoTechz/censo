typedef struct _estado{
	char *nome;

	struct estado *prox;
	struct _cidade *lista;
}estado;