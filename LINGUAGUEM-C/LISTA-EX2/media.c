#include <stdio.h>

/*
 Autor: Gustavo Campos
 Data: 14/10/2019
 Função: Calcular a media entre os valores intermédios.
*/

int main ()
{	
	float num1, num2, num3, num4, maior, menor, media;
	
	printf ("Introduza quatro valores:\n");
	scanf ("%f%f%f%f", &num1, &num2, &num3, &num4);
		
		
		// Determinar o maior valor.
		if ( num1 >= num2 && num1 >= num3 && num1 >= num4 )
			maior = num1;
		
		else if ( num2 >= num1 && num2 >= num3 && num2 >= num4 )
			maior = num2;
			
		else if ( num3 >= num1 && num3 >= num2 && num3 >= num4 )
			maior = num3;
			
		else {
			maior = num4;
			 }
	
		// Determinar o menor valor.
		if ( num1 <= num2 && num1 <= num3 && num1 <= num4 )
			menor = num1;
		
		else if ( num2 <= num1 && num2 <= num3 && num2 <= num4 )
			menor = num2;
	
		else if ( num3 <= num1 && num3 <= num2 && num3 <= num4 )
			menor = num3;

		else {
			menor = num4;
			 }


	media = ( num1 + num2 + num3 + num4 - maior - menor ) / 2;


	printf ("A media entre os dois valores intermedios é de: %.2f\n", media);


	return 0;
}
