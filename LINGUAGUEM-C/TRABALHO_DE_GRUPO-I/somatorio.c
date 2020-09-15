/* -------------------------------------------------------
 * Determinar um valor aproximado de cosseno de x
 * Autores: Eduardo Conceição e Gustavo Campos
 * Data: outubro 2019
 * 
 * Comando para build: gcc -o somatorio -Wall somatorio.c
 * -----------------------------------------------------*/

#include <stdio.h>

int main () 
{
	//introdução e validação de dados
	
	int n = 1, i, k;
	float x;
	float valor_total = 1;
	float auxqu = 1;
	int auxdiv = 1;

	printf ("Introduza o valor de x em radianos: ");
	if (scanf ("%f", &x) != 1) {
		printf("ERRO: valor inválido\n");
		return 0;
	}

	printf ("Introduza o valor de termos do somatorio: ");
	if (scanf ("%d", &k) != 1) {
		printf("ERRO: valor inválido\n");
		return 0;
	}
	
	if (k < 0) {
		printf("ERRO: valor inválido\n");
		return 0;
	}

	//cálculo do valor de cosseno de x
	while (n < k)
	{
		i= 2 * n;
		
		while (i > 0)
		{
			auxqu = auxqu * x;
			auxdiv = auxdiv * i;
			i = i - 1;
		}
		
		float aux = auxqu/auxdiv;
		
		if (n % 2 == 0)
			valor_total = valor_total + aux;
		
		else  valor_total = valor_total - aux;

		auxqu = 1; 
		auxdiv = 1;
		n = n + 1;
	}
	//apresentação do resultado
	printf("O valor de cosseno de %f é aproximadamente: %f\n", x, valor_total);
	return 0;
}
