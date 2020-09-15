#include <stdio.h>
#include <math.h>

const float pi= 3.14159265;

void exercicio1() {
	
		int i;
		
		printf (" x	sin(x)		cos(x)		tg(x)\n" );
		for( i=0; i <= 360; i += 15) 
		{		
			float conv = ( (i * pi) / 180 );
			
			double seno, cosseno, tangente;
			
			seno = sin (conv);
			cosseno = cos (conv);
			tangente = tan (conv);
			if (tangente < -5) {
		
			printf (" %d:	%.5lf  	%.5lf 	Infinite", i, seno, cosseno);
			printf("\n");
			
			}
			else {
		
			printf (" %d:	%.5lf  	%.5lf 	%.5lf", i, seno, cosseno, tangente);
			printf("\n");
			
			}
		}
	
}


int main () {
	
	
	exercicio1();

	return 0;
}
