#include <stdio.h>

/*
 Autor: Gustavo Campos
 Data: 14/10/2019
 Função: Definir em que quadrante se situa uma dada coordenada.
*/

int main ()
{
	double x, y;
	printf ("Introduza 2 valores correspondentes as coordenadas (x,y):\n");
	scanf ("%lf%lf", &x, &y);
		
	if ( x > 0 && y > 0) 
		printf ("O ponto definido por estas duas coordenadas situa-se no 1º quadrante.\n");
		
	else if ( x < 0 && y < 0 )
		printf ("O ponto definido por estas duas coordenadas situa-se no 3º quadrante.\n");
		
		
	else if ( x > 0 && y < 0 )
		printf ("O ponto definido por estas duas coordenadas situa-se no 4º quadrante.\n");
		
		
	else if ( x < 0 && y > 0 )
		printf ("O ponto definido por estas duas coordenadas situa-se no 2º quadrante.\n");
	
	else if ( x == 0 && (y < 0 || y >0) )
		printf ("O ponto definido por estas duas coordenadas situa-se no eixo y.\n");
		
		
	else if ( y == 0 && (x < 0 || x >0) )
		printf ("O ponto definido por estas duas coordenadas situa-se no eixo x.\n");	
		
	else  
		printf ("O ponto definido por estas duas coordenadas situa-se na origem.\n");
	 
		
	return 0;
} 
