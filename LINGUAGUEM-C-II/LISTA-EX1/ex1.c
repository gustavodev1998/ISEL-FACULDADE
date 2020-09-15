
#include <stdio.h>


int main( int argc, char *argv[] ){
	
	
	if ( argc != 2 ) {
		
		fprintf(stderr, "%s", "Argumento Inválidos!\n");
		return 1;
	}
		
		
	 FILE *f = fopen( argv[1], "wb" );
	 
	 if ( f == NULL ) {
		 
		fprintf(stderr, "%s", "Impossivel aceder ao ficheiro!\n");
		return 2;
	 }
		
		 
	 int v;
	 while( scanf( "%d", &v ) == 1 )
	 fwrite( &v, sizeof v, 1, f );
	 
	 
	 
	
	
	 fclose( f );
	 return 0;
} 
