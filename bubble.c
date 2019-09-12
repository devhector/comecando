#include <stdio.h>
#define TAM 10000
int main()
{
float vetor[TAM], aux;
int i, j, k, n;

printf("\nDigite o numero de valores: ");
scanf("%d", &n);

if ((n > TAM) || (n < 1) )
printf("\nerro: o tamanho deve estar entre 1 e %d\n", TAM);
else {
// lê os valores
for (i = 0; i < n; i++) {
printf("\nDigite a %d.o valor: ", i+1);
scanf("%f", &vetor[i]);
}
// para todos os valores do vetor
for (k = 1; k < n; k++) {
// encontra o seu lugar no vetor
for (j = 0; j < n - k; j++) {
if (vetor[j] > vetor[j + 1]) {
aux = vetor[j];
vetor[j] = vetor[j + 1];
vetor[j + 1] = aux;
}
}
}
for (i = 0; i < n; i++) {
printf("\n%.2f \n",vetor[i]);
}

}

return 0;
}
