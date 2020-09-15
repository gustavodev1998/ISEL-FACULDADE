#include <stdio.h>
#include <stdbool.h>


void show_array_range (int vals[], int start, int end, bool growing) {

	if( start > end ) {
		int aux = end;
		end = start;
		start = aux;
	}
	
	

	if (growing) {
		for ( int i = start-1; i < end; i++) {
			printf ("%d\n", vals[i]);
		}


	}else {
		for (int j = end-1; j >= start-1; j--) {	
				printf ("%d\n", vals[j]);
		}

	}

}


