#include <stdio.h>	
#include <math.h>

/*
 Autor: Gustavo Campos
 Data: 14/10/2019
 Função: Classificar triângulos quanto aos seus ângulos.
*/

int main()
{	
	int a, b, c;
	
	printf("Insira 3 valores que correspondem respectivamente aos 3 lados do triangulo (AB, BC, AC):\n");
	scanf ("%d%d%d", &a, &b, &c);
	
		int maiorlado = 0;

		if  ( a > b && a > c  ) 
			maiorlado = 1;
			
		else if ( b > a && b > c ) 
			maiorlado = 11;
		
		else {
			maiorlado = 111;
			 }
			
		if ( maiorlado == 1 && ( a > ( b + c ) ) )
			printf ("Erro: O maior lado (AB) é superior a soma dos menores lados (BC+AC)\n");
			
		else if  ( maiorlado == 11 && ( b > ( a + c ) ) )
			printf ("Erro: O maior lado (BC) é superior a soma dos menores lados (AB+AC)\n");
		
		else if ( maiorlado == 111 && ( c > ( a + b ) ) )
			printf ("Erro: O maior lado (AC) é superior a soma dos menores lados (AB+BC)\n");
			
		else 
		{
			
	float A, B, C;
	const float pi= 3.14159265;
	
	A= acos ((pow(a,2) + pow(c,2) - pow(b,2)) / (2*c*a))*180/pi;
	B= acos ((pow(b,2) - pow(c,2) + pow(a,2)) / (2*b*a))*180/pi;
	C= acos ((pow(b,2) + pow(c,2) - pow(a,2)) / (2*b*c))*180/pi;	



	if ( A== 90 || B == 90 || C == 90 )
	printf ("O triângulo é retângulo.\n");

	else if ( A < 90 && B < 90 && C < 90 )
	printf ("O triângulo é acutângulo.\n");

	
	else if ( A > 90 || B > 90 || C > 90 )
	printf ("O triângulo é obtusangulo.\n");

			}


		
	return 0;
}
