#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tag.h"
#include "strset.h"

#define TAG_SIZE 3


void unifyName(char *name,  int numWords ) {  /* Função utilizada para retirar espaços do stdin caso exista */
	
	char *aux;
	
	int size = strlen(name) - 1;
	
	char save_string[size]; /* Array auxiliar para guardar tokens */
	
	int i = 0;
	
	aux = strtok(name, " \t");	/* Utilização da função strtok e os seus delimitadores (Espaço e Tab) */

	while ( aux != NULL ) { /* Ciclo que percorre os restantes nomes e faz uso da função upper_first para deixar no formato correto */
		
		
		for( int j = 0; aux[j] != 0; j++){ 
				
			save_string[i] = aux[j];
			i++;
			
		}
		
		aux = strtok(NULL, " \t");
		
	
	}
	
	
	save_string[--i] = '\0'; /* Terminador da String */
	strcpy(name, save_string); /* Guarda a string correta em name */
		
}

void space_remove( int point_size, char *buffer){	/* Função para limitar cada campo da struct MP3TAG */
	
	int i = point_size-1;
	
	while ( i >= 0 && buffer[i] == ' ' ) i--; /* Anda de trás para a frente a retirar os espaços */
	
	buffer[i+1] = 0; /* Terminador da string sem espaços */
	
}


MP3Tag_t *tagRead( char *filename, int *resPtr, strSet_t *sSet ) {
	
	MP3Tag_t *result = malloc( sizeof(*result) );	/* Alojar dinamicamente */
	
	FILE *f = fopen( filename, "r" );
	
	char tag_names[TAG_SIZE + 1];
	
	char TAG_NAME[] = "TAG";
	
	int point_start = -128; /* Tamanho em bytes do bloco de dados */
	
	
	if( f == NULL ){
		fprintf( stderr, "Erro de acesso a ficheiro\n" );
		
		if ( resPtr != NULL) *resPtr = -1;
		return NULL;
	}
	
	
	result->fileName = strcpy( malloc( strlen( filename ) + 1 ), filename );/* Guarda o ficheiro no campo fileName da struct */
	
	fseek(f, point_start, SEEK_END); /* Limita aos ultimos 128 bytes */
	
	fread(tag_names,  TAG_SIZE, 1, f);/* Verifica a existencia da TAG */
	
	tag_names[TAG_SIZE] = 0;
	
	if ( strcmp(TAG_NAME, tag_names) != 0 ) {
		
		if ( resPtr != NULL) *resPtr = -2;
		return NULL;
			
	}
	
	char year_conv[4];
	
	char aux[MAX_ART + 1]; // Backup do artist
	char aux_album[MAX_ALB + 1]; // Backup do album

	/* Chamar recursivamente a função setting_display para introduzir os dados na struct MP3Tag_t */
	
	
	fread(result->title, MAX_TIT, 1, f);
	space_remove( MAX_TIT, result->title);
	
	fread(aux, MAX_ART, 1, f);
	space_remove( MAX_ART, aux); 
	
	result->artist = strSearchAdd(sSet, aux);
	
	fread(aux_album, MAX_ALB, 1, f);
	space_remove( MAX_ALB, aux_album);
	
	result->album = strSearchAdd(sSet, aux_album);
	
	fread(year_conv, 4, 1, f);/* Caso especial converte em ASCII */
	sscanf(year_conv,"%hi", &result->year);
	
	
	fread(result->comment, MAX_COM, 1, f);
	space_remove( MAX_COM, result->comment);

	
	fread(&result->track, 1, 4, f);
	
	//result->track = result->comment[MAX_COM - 1]; /* Guarda o ultimo valor do campo Comment*/
	
	fread(&result->genre, 1, 1, f);
	
	
	/* Condição de Acerto */
	if ( resPtr != NULL) *resPtr = 0;
	
	return result;


}



