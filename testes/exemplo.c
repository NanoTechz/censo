#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Registro_Banda{
    char nome_banda[50];
    int data;
    int integrantes;
    int cod;
};
 
struct Registro_Banda Banda;
struct Registro_Album album[3];
 
void criar(FILE *arquivo);//Função para criar o arquivo
void inserir(FILE *arquivo);//Função para inserir dados
void exibir(FILE *arquivo);//Função para exibir dados
void pesquisar(FILE *arquivo);//Função para pesquisar dados
void creditos();//Função para informações extras
 
int main(){
    int op;
    FILE *arquivo;
    criar(arquivo);
    do{
        printf("***********************************\n");
        printf("*               MENU              *\n");
        printf("***********************************\n");
        printf("*   1 - Cadastrar Banda           *\n");
        printf("*   2 - Listar Bandas             *\n");
        printf("*   3 - Pesquisar Banda           *\n");
        printf("*   4 - Alterar Banda             *\n");//falta
        printf("*   5 - Remover Bandas            *\n");//falta
        printf("*   6 - Creditos                  *\n");
        printf("*   7 - Sair                      *\n");
        printf("***********************************\n");
        printf("\nDigite sua opcao: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                    system("cls");
                    inserir(arquivo);
                    break;
            case 2:
                    system("cls");
                    exibir(arquivo);
                    break;
            case 3:
                    system("cls");
                    pesquisar(arquivo);
                    break;
            case 4:
                    //falta
                    break;
            case 5:
                    //falta
                    break;
 
            case 6:
                    system("cls");
                    creditos();
                    break;
            default:
                    printf("Saindo!\n");
       }
    }while(op != 7);
    system("pause");
}
 
//Função para informações extras
void creditos() {
    system("cls");
    printf("\n\n\n");
    printf("\t***********************************************************\n");
    printf("\t# Insdutira Entretenimento Vorpmais   *\n");    
    printf("\t# Programa desenvolvido por: Francisco Balbino Souza       *\n");
    printf("\t# Para mais informacoes acesse o site: www.vorpmaisdesenv.com   *\n");
    printf("\t***********************************************************\n\n\n");
    printf("\t\t\tTecle <ENTER> para voltar");
    getch();
    system("cls");
}
 
//Função para pesquisar dados
void pesquisar(FILE *arquivo){
     char Nomepesquisa[50];
     fflush(stdin);
     if((arquivo = fopen("Logger.txt","rb")) == NULL){
         exit(0);
     }
     printf("\n----------------------------------------------------------\n\n");
     printf("Digite o nome da Banda que deseja pesquisar: ");
     gets(Nomepesquisa);
     printf("\n");
     fread(&Banda,sizeof(struct Registro_Banda),1,arquivo);
     if(strcmp(Nomepesquisa,Banda.nome_banda) == 0){
        printf("Nome: %s\n",Banda.nome_banda);
        printf("Data: %d\n",Banda.data);
        printf("Codigo: %d\n",Banda.cod);
     }else{
        printf("Nome nao encontrado\n");
     }
     printf("\n----------------------------------------------------------\n\n");
}
 
//Função para exibir dados
void exibir(FILE *arquivo){
    if((arquivo = fopen("Logger.txt","rb")) == NULL){
         //exit(0); Função para sair do programa em caso de erro.
        printf("Problemas na abertura do arquivo!\n");
        printf("\nTecle <ENTER> para voltar!");
        getch();
        system("cls");
        main();
 
     }
    printf("\n----------------------------------------------------------\n\n");
    printf("As Bandas cadastradas sao: \n");
    fread(&Banda,sizeof(struct Registro_Banda),1,arquivo);
    while(!feof(arquivo)){//Enquanto não chega ao fim do arquivo, lê o aquivo
        printf("Nome: %s\n",Banda.nome_banda);
        printf("Data: %d\n",Banda.data);
        printf("Codigo: %d\n\n",Banda.cod);
        fread(&Banda,sizeof(struct Registro_Banda),1,arquivo);
    }
    printf("\n----------------------------------------------------------\n\n");
    printf("Tecle <ENTER> para voltar!");
    getch();
    system("cls");
}
 
//Função para inserir dados
void inserir(FILE *arquivo){
    int tam,i;
    printf("Digite a quantidade de bandas que deseja Cadastrar: ");
    scanf("%d",&tam);
    (struct Banda*) malloc(tam*sizeof(struct Registro_Banda));//Aloca memória para a estrutura
    if((arquivo = fopen("Logger.txt","a+")) == NULL){
         exit(0);
     }
     printf("\n----------------------------------------------------------\n\n");
    for(i=0; i<tam; i++){
        fflush(stdin);
        printf("Digite o Nome da Banda: ");
        scanf("%s",&Banda.nome_banda);
        printf("Digite a data de criação da Banda: ");
        scanf("%d",&Banda.data);
        printf("Digite o codigo da Banda: ");
        scanf("%d",&Banda.cod);
        fwrite(&Banda,sizeof(struct Registro_Banda),1,arquivo);//gravadados
        printf("\n");
    }
    fclose(arquivo);
    printf("Tecle <ENTER> para voltar!");
    getch();
    system("cls");
}
 
//Função para criar o arquivo
void criar(FILE *arquivo){
     if((arquivo = fopen("banda.dat","wb")) == NULL){
         exit(0);
     }
     fclose(arquivo);
}