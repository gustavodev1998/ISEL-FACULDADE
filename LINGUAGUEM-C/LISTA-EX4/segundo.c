#include <stdio.h>
#include <stdbool.h>



void invertArray (int vals[], int size) {
	int inverso[size];
	int f = 0;
	
	for ( int i = size-1; i >= 0; i--) {
		inverso[f] = vals[i];
		printf("%d ", inverso[f]);
		f++;
	}
	vals = inverso;


}

