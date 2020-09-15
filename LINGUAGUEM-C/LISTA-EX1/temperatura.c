#include <stdio.h>

/*
 Autor: Gustavo Campos
 Data: 30/09/2019
 Função: Converter o número de graus fahrenheit em graus celsius
*/

int main ()
{
	float temp, celsius;
	
	printf("Indique a temperatura em graus fahrenheit: ");
	scanf("%f", &temp);
	
	celsius = (temp - 32) * 5 / 9 ;
	printf("A temperatura em graus celsius é de %.2f\n.", celsius);

	return 0;
}
