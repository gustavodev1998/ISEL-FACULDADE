#include <math.h>
#include <stdio.h>

/*
 Autor: Gustavo Campos
 Data: 30/09/2019
 Função: Determinar o perímetro do triângulo
*/

int main ()
{
	
	double x1,y1, x2,y2, x3,y3, p1p2, p1p3, p2p3;
	
	printf("Introduza os valores de x1 e y1: ");
	scanf("%lf %lf",&x1,&y1);
	printf("Introduza os valores de x2 e y2: ");
	scanf("%lf %lf",&x2,&y2);
	printf("Introduza os valores de x3 e y3: ");
	scanf("%lf %lf",&x3,&y3);
	
	p1p2=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	p1p3=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	p2p3=sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	
	printf("O valor do perimetro é: %.2lf\n", p1p2+p1p3+p2p3);

	return 0;
}
