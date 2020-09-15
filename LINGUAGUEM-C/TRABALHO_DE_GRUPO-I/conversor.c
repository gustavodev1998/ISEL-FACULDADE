/* -------------------------------------------------------
 * Conversor de unidades de comprimento
 * Autores: Eduardo Conceição e Gustavo Campos
 * Data: outubro 2019
 * 
 * Comando para build: gcc -o conversor -Wall conversor.c
 * -----------------------------------------------------*/

#include <stdio.h>

int main ()
{
	//introdução e validação de dados
	
	double real;
	int comprimento, convertida;
	
	// 1 - milímetro, 2 - centímetro, 3 - decímentro, 4 - metro, 5 - decâmetro, 6 - hectómetro, 7 - quilómetro.
	
	printf ("Insira o valor: ");
	if (scanf ("%lf", &real) != 1) {
		printf("ERRO: valor inválido\n");
		return 0;
	}
	if (real < 0) {
		printf("ERRO: valor inválido\n");
		return 0;
	}	
	printf ("1 - milímetro | 2 - centímetro | 3 - decímentro | 4 - metro | 5 - decâmetro | 6 - hectómetro | 7 - quilómetro\nInsira a unidade do valor inicial: ");
	if (scanf ("%d", &comprimento) != 1) {
		printf("ERRO: valor inválido\n");
		return 0;
	}
	if (comprimento < 1 || comprimento > 7) {
		printf("ERRO: valor inválido\n");
		return 0;
	}
	printf ("Insira a unidade para o valor final: ");
	if (scanf ("%d", &convertida) != 1) {
		printf("ERRO: valor inválido\n");
		return 0;
	}
	if (convertida < 1 || convertida > 7) {
		printf("ERRO: valor inválido\n");
		return 0;
	}
	
	//conversão
	
	double final;
	int conta;
	
	conta = (comprimento - convertida);
	
	if ( conta == 0 )
		final = real;
	
	else if ( conta == 1 ) 
			final = real * 10;
	
	else if ( conta == 2 )
			final = real * 100;
		
	else if ( conta == 3 )
			final = real * 1000;
		
	else if ( conta == 4 )
			final = real * 10000;
		
	else if ( conta == 5 )
			final = real * 100000;
		
	else if ( conta == 6 )
			final = real * 1000000;
	
	else if ( conta == -1 ) 
			final = real / 10;
	
	else if ( conta == -2 )
			final = real / 100;
		
	else if ( conta == -3 )
			final = real / 1000;
		
	else if ( conta == -4 )
			final = real / 10000;
		
	else if ( conta == -5 )
			final = real / 100000;
		
	else if ( conta == -6 )
			final = real / 1000000;
	
	//apresentação do resultado final
	//se o resultado da conversão for um número inteiro, não irá demonstrar casa decimais.
	if ( final >= 1 )
		printf("O valor convertido é: %.0lf\n", final);
	
	else printf("O valor convertido é: %lf\n", final); 		
		
	return 0;
}
