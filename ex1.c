#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include "minha_bib.h"


// (1 pt) altere a organização do programa de maneira a deixar apenas a função principal (main()) no arquivo ex1.c
// e a estrutura e funções utilizadas em uma bibilioteca chamada minha_bib.h 

int main()
{
	int escolha;

	cria_lista();
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere();
			break;
		case 2:
			apaga();
			break;
		case 3:
			imprime();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	return 0;
}
