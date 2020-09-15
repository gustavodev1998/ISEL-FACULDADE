#include <stdio.h>
#include <stdbool.h>


bool amicableNumbers(int n1, int n2) {
	
	int checkamicable1;
	int checkamicable2;
	
	
	for (int i = 1; i < n1; i++) 
	{
			if ( n1 % i == 0) {
			checkamicable1 += i;
			}
			
	}	
		
	for (int i = 1; i < n2; i++) 
	{
			if ( n2 % i == 0) {
			checkamicable2 += i;
			}
	
	}	
	
	if ( n1 == checkamicable2 && n2 == checkamicable1 ) {
		return 1;
	}
	else {
		return 0;
	}

}



int main () {

	int x1, x2;
	printf("Introduza dois valores inteiros: ");
	scanf("%d%d", &x1, &x2);
		
	
	if ( amicableNumbers(x1, x2) == 1 )
		printf("Os números %d e %d são amigos.\n", x1, x2);
	else {
		printf("Os números %d e %d não são amigos.\n", x1, x2);
	}
		
	return 0;
}
