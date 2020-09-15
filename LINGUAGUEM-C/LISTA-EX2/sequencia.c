#include <stdio.h>

/*
 Autor: Gustavo Campos
 Data: 14/10/2019
 Função: Classificar uma sequência quanto a sua ordem.
*/

int main ()
{
	int input1, input2;
	double ordem= 0, anterior=0;
	
		printf("Introduza numeros inteiros naturais, terminando a sequência com 0:\n");
		scanf("%d%d", &input1, &input2);
		
		
	while (input2 != 0) {
	
		anterior++;
		
		if ( input1 < input2 )
			ordem++;
			
		else if ( input1 > input2)
			ordem += 10;
			
		else if (input1 == input2)
			ordem += 100;

		input1 = input2;
		scanf("%d", &input2);
		
		}
	
			if ( anterior == 0)
			printf ("Sequencia Invalida.\n");
					
			else if ( ordem / anterior == 1  )
			printf ("Em ordem crescente\n");
			
			else if ( ordem / anterior == 10  )
			printf ("Em ordem decrescente\n");
			
			else if ( ordem / anterior == 100)
			printf ("Todos iguais\n");
			
			else 
			printf ("Em ordem arbitrária\n");
			

	
	return 0;
	
}
