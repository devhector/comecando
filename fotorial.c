#include <stdio.h>
int fatorial(int n);

int main(int argc, char *argv[])
{
	int numero = atoi(argv[1]);
	printf("Fatorial de %d igual a %d", numero, fatorial(numero));
}

int fatorial(int n){
	int fatorial=1;
	while(n>1){
		fatorial = fatorial * n;
		n = n - 1;
	}
	return fatorial;
}
