#include <stdbool.h>
#include <stdio.h>


#define N 25


typedef int Matrix[N][N];

bool pascal_triangle(Matrix m) {
	
	int count = 1;

	for ( int i = 0; i < N; i++) {
		
		for ( int j = 0; j <= N; j++) {
			if ( i == 0 || j == 0  )  m[i][j] = count;
			
			else 
			m[i][j] = m[i][j-1] + m[i-1][j];
			
			}
	}

}


int main () {
	Matrix k;
	pascal_triangle(k);
	for (int i =0; i < N; i++){
		for ( int j = 0; j< N;j++){
			printf("%d  ", k[i][j]);
			
		}
		printf("\n");
	}

return 0;	
}
