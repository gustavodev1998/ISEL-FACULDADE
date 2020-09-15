/* ---------------------------------------------------
 * Determinar relações entre valores
 * Autores: Eduardo Conceição e Gustavo Campos
 * Data: outubro 2019
 * 
 * Comando para build: gcc -o valores -Wall valores.c
 * -------------------------------------------------*/
 
#include <stdio.h>

int main ()
{
	//introdução de dados
	
	int v1, v2, v3;
	
	printf("introduza três valores inteiros: ");
	if (scanf("%d%d%d", &v1, &v2, &v3) != 3) {
		printf("ERRO: valores inválidos\n");
		return 0;
	}
	
	//determinar diferentes
	
	int dif = 0;
	
	if (v1 != v2)
		dif += 1;
	if (v2 != v3)
		dif += 1;
	if (v1 != v3)
		dif += 1;
		
	//determinar pares
	
	int par = 0;
	
	if (v1 % 2 == 0)
		par += 1;
	if (v2 % 2== 0)
		par += 1;
	if (v3 % 2== 0)
		par += 1;
		
	//determinar ímpares
	
	int impar = 0;
	
	if (v1 % 2 != 0)
		impar += 1;
	if (v2 % 2 != 0)
		impar += 1;
	if (v3 % 2 != 0)
		impar += 1;
		
	//determinar dois menores
	
	int men1, men2;
	
	if (v1 >= v2 && v1 >= v3) {
		men1 = v2;
		men2 = v3;		
	}
	else if (v2 >= v1 && v2 >= v3) {
		men1 = v1;
		men2 = v3;		
	}
	else if (v3 >= v1 && v3 >= v2) {
		men1 = v1;
		men2 = v2;		
	}
		
	//calcular média	
		
	double media;
	
	media = (double)(v1 + v2 + v3)/3;
	
	//apresentação de resultados		
		
	printf("Diferentes: %d\n", dif);
	printf("Pares: %d\n", par);
	printf("Ímpares: %d\n", impar);
	printf("Dois menores: %d %d\n", men1, men2);
	printf("Média: %.2lf\n", media); 
		
	return 0;
}
