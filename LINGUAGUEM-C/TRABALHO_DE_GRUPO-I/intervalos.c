/* ---------------------------------------------------------
 * Determinar a interseção entre intervalos
 * Autores: Eduardo Conceição e Gustavo Campos
 * Data: outubro 2019
 * 
 * Comando para build: gcc -o intervalos -Wall intervalos.c
 * -------------------------------------------------------*/

#include <stdio.h>

int main ()
{
	//introdução de valores
	
	int p1a,p1b, p2a,p2b, intervalo1, intervalo2;
	
	printf("Introduza o Intervalo I1?: ");
	if (scanf ("%d%d", &p1a,&p1b) != 2) {
		printf("ERRO: valores inválidos\n");
		return 0;
	}
	
	printf("Introduza o Intervalo I2?: ");
	if (scanf ("%d%d", &p2a,&p2b) != 2) {
		printf("ERRO: valores inválidos\n");
		return 0;
	}
	
	//Determinar se não existe interseção entre os intervalos
	if (p2a > p1b && p2a > p1a && p2b > p1a && p2b > p1b) {	
		printf ("Não há interseção.\n");
	}

	else if (p2a < p1b && p2a < p1a && p2b < p1a && p2b < p1b) {	
			printf ("Não há interseção.\n");
	}

	//Determinar somente a interseção
	else if (p1b >= p2a && p1b <= p2b && p1a <= p2a && p1a <= p2b) {
			intervalo1 = p2a;
			intervalo2 = p1b;
			printf ("Interseção de I1 com I2 = [%d,%d]\n", intervalo1, intervalo2);
	}

	else  if (p1b <= p2a && p1b >= p2b && p1a >= p2a && p1a >= p2b) {
			intervalo1 = p1b;
			intervalo2 = p2a;
			printf ("Interseção de I1 com I2 = [%d,%d]\n", intervalo1, intervalo2);
	}

	else  if (p1b <= p2a && p1b >= p2b && p1a <= p2a && p1a <= p2b) {
			intervalo1 = p2b;
			intervalo2 = p1b;
			printf ("Interseção de I1 com I2 = [%d,%d]\n", intervalo1, intervalo2);
	}

	else  if (p1b >= p2a && p1b >= p2b && p1a >= p2a && p1a <= p2b) {
			intervalo1 = p1a;
			intervalo2 = p2b;
			printf ("Interseção de I1 com I2 = [%d,%d]\n", intervalo1, intervalo2);
	}

	else  if (p1b <= p2a && p1b >= p2b && p1a <= p2a && p1a >= p2b) {
			intervalo1 = p1a;
			intervalo2 = p1b;
			printf ("Interseção de I1 com I2 = [%d,%d]\n", intervalo1, intervalo2);
	}
	
	//Determinar a interseção e se está contido
	else if (p2a <= p1b && p2a >= p1a && p2b <= p1b && p2b >= p1a)  {
			intervalo1 = p2a;
			intervalo2 = p2b;
			printf ("Interseção de I1 com I2 = [%d,%d] I2 contido em I1\n", intervalo1, intervalo2);
	}
		
	else if (p2a <= p1b && p2a <= p1a && p2b >= p1b && p2b >= p1a) {
			intervalo1 = p1a;
			intervalo2 = p1b;
			printf ("Interseção de I1 com I2 = [%d,%d] I1 contido em I2\n", intervalo1, intervalo2);
	}
	
	return 0;
}

