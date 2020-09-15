#include <stdbool.h>
#include <stdio.h>




void rotateRight (int vals[], int size) {
	
	int aux[size];
	int k = 1;
	aux[0] = vals[size-1];
	for ( int i = 0; i < size; i++) {
		aux[k] = vals[i];
		k++;
	}
	for(int i=0; i<size;i++){
		printf("%d ",aux[i]);
	}
	

}
