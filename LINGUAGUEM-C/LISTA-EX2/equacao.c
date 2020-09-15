#include <stdio.h>
#include <math.h>

/*
 Autor: Gustavo Campos
 Data: 14/10/2019
 Função: Calcular as raizes de uma equação do 2º grau.
*/

int main ()
{	
	double a, b, c, delta, raiz1, raiz2;
	
	printf ("Relativamente a uma equação do 2º grau introduza os correspondentes coeficientes a, b, c:\n");
	scanf ("%lf%lf%lf", &a, &b, &c);
	
	delta = ( ( b*b) - ( 4*a*c) );
	
	if ( delta > 0 ) {
	
		raiz1 = ( (-b) + sqrt(delta) ) / ( 2*a);
		raiz2 = ( (-b) - sqrt(delta) ) / ( 2*a);

		printf ("As raizes desta equação são: %.2lf e %.2lf.\n", raiz1, raiz2);

	}
	
	else if (delta==0) { 
		printf("Só há uma solução %.2lf.\n", -b/(2*a));
		}
		
	else {
	printf ("Não existem raizes desta equação.\n");
		 }
	
	
				
	return 0;
}
