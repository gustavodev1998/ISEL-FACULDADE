#include <stdio.h>
#include <stdbool.h>
#define MAX_PRIMES 1024*1024

bool check_prime ( int x) {	
	
	int vezes = 0;
	
		for ( int i = 1; i <= x && vezes <= 3; i++) 
			{	
			if ( x % i == 0 ) 
				vezes++;
			}
				
		if ( vezes == 2 ) {
		return 1;
		} 
		
		else {
		return 0;
		}
}


int main () {

	int nprimos;
	
	printf ("Introduza quantos numeros primos que deseja:\n");
	scanf ("%d", &nprimos);
			
		
	int prime_numbers[MAX_PRIMES];
	int total_primes = 0;
	int max_line = 0;
	
	for (int x = 2; total_primes < nprimos; x++) {
		
		if ( check_prime(x) == 1 ) {
			prime_numbers[total_primes] =  x;
			printf("%7d ", prime_numbers[total_primes]);
			total_primes++;
			max_line++;
			
			if (max_line == 16 ) {
				printf("\n");
				max_line = 0;
			}
		}
		
	}

	printf("\n");
	
	return 0;
}
