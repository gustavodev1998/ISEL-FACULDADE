#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listfiles.h"


#define MAX_FILENAME 255


/* Esta função percorre o ficheiro de texto com nome indicado por listName, obtendo os nomes
dos ficheiros MP3, armazenados um em cada linha de texto. Por cada ficheiro MP3, obtém a
informação de tag, usando a função tagRead, e adiciona-a ao conjunto de tags, usando a função
setAdd. Retorna 0, em caso de sucesso, ou -1, em caso de falha na leitura da lista. */

int listScan( char *listName, TagSet_t *data, strSet_t *sSet ){  
	
	MP3Tag_t *Tag_return;
	
	char buffer[MAX_FILENAME];
	
	
	FILE *f = fopen(listName, "r");
	if ( f == NULL ) {
		fprintf( stderr, "Erro de acesso a ficheiro\n" );
		return -1;
	}
	
	while ( fscanf(f,"%s", buffer) == 1 ) {
	
		Tag_return = tagRead(buffer, NULL, sSet);
		
		if ( Tag_return != NULL ) {
		setAdd(data, Tag_return);
		}
		
	}	
	
	return 0;
}
