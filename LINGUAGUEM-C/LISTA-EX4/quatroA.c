#include <stdbool.h>
#include <stdio.h>


#define LINES 25
#define COLS 25

typedef int Matrix[LINES][COLS];


void matrixCross(Matrix m) { 

int count = 1;

	for(int i = 0; i < LINES; i++) {
		for ( int j = 0; j < COLS; j++) {
				if (i==j)  m[i][j] = count;
				else if (j == LINES -1 -i) m[i][j] = count;
				else m[i][j] = 0;
		}
		
	}

}

int main () {
	Matrix k;
	matrixCross(k);
	for (int i =0; i < LINES; i++){
		for ( int j = 0; j< COLS;j++){
			printf("%d  ", k[i][j]);
			
		}
		printf("\n");
	}

return 0;	
}
