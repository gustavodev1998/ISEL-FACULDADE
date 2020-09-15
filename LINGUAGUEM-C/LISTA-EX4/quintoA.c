#include <stdbool.h>
#include <stdio.h>


#define N 4


typedef int Matrix[N][N];

bool pascal_triangle(Matrix m) {
	
	int count = 1;
	
	Matrix k;

	for ( int i = 0; i < N; i++) {
		
		for ( int j = 0; j < N; j++) {
			if ( i == 0 || j == 0  )  k[i][j] = count;
			
			else 
			k[i][j] = k[i][j-1] + k[i-1][j];
			
			}
	}
	
	for( int i = 0; i < N; i++) {
		for ( int j = 0; j < N; j++) {
				if( k[i][j] != m[i][j]) return false;
		}
		
	}
	
	return true;

}


int main () {
	Matrix m = { {1,1,1,1}, {1,2,3,4}, {1,3,6,10}, {1,4,10,20} };
	
	if (pascal_triangle(m) == true)
		printf("Esta matriz corresponde a representação de um triângulo de Pascal");
		
	else
		printf("Esta matriz não corresponde a representação de um triângulo de Pascal");
	


return 0;	
}
