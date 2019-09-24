#include <stdio.h>
#include <string.h>

struct end {
	char nome[100];
	char rua[100];
	char cidade[100];
	char estado[100];
	unsigned long int cep;
} info[MAX];

void cria_lista(void)
{
	int i;
	for (i = 0; i < MAX; i++)
		info[i].nome[0] = '\0';
}

int menu(void)
{
	//system("clear"); //linux
	//system("cls"); //windows

	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Inserir um nome\n");
		printf("\t 2. Excluir um nome\n");
		printf("\t 3. Listar o arquivo\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 4);
	getchar();
	return c;
}

void ler_string(char palavra[100], int tamanho)
{
	int i = 0;
	char c;

	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';

	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}

}

int livre(void)
{
	int i;
	for (i = 0; info[i].nome[0] && i < MAX; i++) ;
	if (i == MAX)
		return -1;
	return i;
}

int buscar(char busca_nome[]){
	int i;
	for (i = 0; i < MAX; i++){
		if(strcmp(info[i].nome, busca_nome) == 0)
			return i;
	}
	return -1;
}

void insere(void)
{
	system("clear"); //linux
	//system("cls"); //windows

	// (3.0 pts) Altere essa função para inicialmente ler o nome a ser inserido
	// e verificar se ele já existe antes de inserir
	// (use a função de busca que vc deve implementar na próxima questão).
	// Se ele já existe, mostrar uma mensagem dizendo que aquele registro já existe
	// e enserar a execução da função

	int posicao;
	char generico[MAX];

	posicao = livre();
	if (posicao == -1) {
		printf("\nEstrutura Cheia!!");
		return;
	}



	printf("-- Registro %d:\n", posicao);
	printf("\t Nome: ");
	ler_string(generico, 100);

	if(buscar(generico) != -1){
		printf("\t Esse nome ja existe!\n");
		return;
	}else{
		strcpy(info[posicao].nome, generico);
	}

	printf("\t Rua: ");
	ler_string(info[posicao].rua, 100);
	printf("\t Cidade: ");
	ler_string(info[posicao].cidade, 100);
	printf("\t Estado: ");
	ler_string(info[posicao].estado, 100);
	printf("\t CEP: ");
	scanf("%lu", &info[posicao].cep);
}




void apaga(void)
{
	system("clear"); //linux
	//system("cls"); //windows

	// (3.0 pts) alterar essa função para realizar a busca do resgistro a ser apagado pelo campo nome
	// implementar uma função que retorna a posição do resgistro com aquele nome, caso encontrado,
	// e perguntar ao usuário se ele realmente deseja apagar aquele registro


	char generico[MAX];
	int posicao, escolha = 0;

	printf("\tDigite o nome a ser apagado: ");
	ler_string(generico, 100);
	printf("\n");

	if(buscar(generico) != -1){
		posicao = buscar(generico);
		printf("\tDeseja realmente apagar o registro de %s?\n", info[posicao].nome);
		printf("\t1. Apagar.\n");
		printf("\t2. Sair.\n");
		while(escolha != 1 && escolha != 2){
			printf("-- Digite sua escolha: ");
			scanf("%d", &escolha);
			if (escolha != 1 && escolha != 2) {
				printf("\tEscolha uma opcao valida!\n");
			}
		}
		if(escolha == 1)
			info[posicao].nome[0] = '\0';
	}else
		printf("\tNome nao encontrado!\n");

/*
	printf("numero do Registro: ");
	scanf("%d", &posicao);

	if (posicao >= 0 && posicao < MAX)
		info[posicao].nome[0] = '\0';
*/
}

void imprime(void)
{
	system("clear"); //linux
	//system("cls"); //windows

	// (3.0 pts) altere essa função para perguntar ao usuário se ele quer imprimir todos os registros
	// ou um registro específico, caso ele deseje um registro específico permitir a busca do registro pelo nome
	// usar a função de busca implementada anteriormente para retornar a posição e imprimir ela

	int i, escolha = 0, posicao;
	char generico[MAX];

	printf("\tO que deseja imprimir?\n");
	printf("\t1. Registro especifico\n");
	printf("\t2. Todos os registros\n");
	printf("\t3. Sair\n");

	while(escolha < 1 && escolha < 3){
		printf("-- Digite sua escolha: ");
		scanf("%d", &escolha);
		if (escolha < 1 && escolha < 3) {
			printf("\tEscolha uma opcao valida!\n");
		}
	}
	if(escolha == 1){
		printf("-- Digite o nome a ser impresso: ");
		scanf("%s",generico);

		if(buscar(generico) != -1){

			posicao = buscar(generico);
			printf("-- Registro %d:\n", posicao);
			printf("\t Nome: %s", info[posicao].nome);
			printf("\t Rua: %s", info[posicao].rua);
			printf("\t Cidade: %s", info[posicao].cidade);
			printf("\t Estado: %s\n", info[posicao].estado);
			printf("\t CEP: %lu\n", info[posicao].cep);

		}else
			printf("\tNome nao encontrado!\n");
	}

	if(escolha == 2)
		for (i = 0; i < MAX; i++)
			if (info[i].nome[0] != '\0') {
				printf("-- Registro %d:\n", i);
				printf("\t Nome: %s", info[i].nome);
				printf("\t Rua: %s", info[i].rua);
				printf("\t Cidade: %s", info[i].cidade);
				printf("\t Estado: %s\n", info[i].estado);
				printf("\t CEP: %lu\n", info[i].cep);
			}
}
