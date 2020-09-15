#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "strset.h"



#define HASH_SIZE 100
#define MAX_LINE 100

/*
Esta função cria, em alojamento dinâmico, o descritor para o conjunto de strings. Retorna o
endereço do descritor criado.
*/

strSet_t *strSetCreate( void ) {
	
	strSet_t *h = malloc( sizeof(*h) );
	h->size = HASH_SIZE;
	h->table = calloc( h->size, sizeof h->table[0] ); // ponteiros a NULL
	return h;
}	
	
	
/* Retorna um indice para guardar a variavel em strSearchAdd */
int hash( strSet_t *hp, char *word ){
	unsigned s = 0;
	for( int i = 0; word[i] != 0; ++i )
		s += word[i] << ( i % (sizeof (int) * CHAR_BIT) );
	return s % hp->size;
}	


/* Procura dentro da Hash Table a string indicada por word */
char *hListSearch( HLnode *head, char *word ){
	
	for( HLnode *p = head; p != NULL; p = p->next ){	// Percorre ate o final da Hash Table
		
		if( strcmp( p->data, word ) == 0 )
			return p->data;
			
	}
	
	return NULL;
}
/*
Esta função procura no conjunto set a string indicada. Se não existir, cria-a em alojamento
dinâmico e adiciona-a ao conjunto. Retorna o endereço da string armazenada no conjunto.
*/

char *strSearchAdd( strSet_t *set, char *word ) {
	
	int i = hash( set, word );
	if( hListSearch( set->table[i], word ) != NULL ) return (set->table[i]->data);
		
	else {
		
		HLnode *n = malloc( sizeof(*n) );
		n->next = set->table[i];
		n->data = strdup(word);
		set->table[i] = n;
		
	}
	
	return (set->table[i]->data);
}
	

void TableDelete( HLnode *table ) {

	if ( table == NULL) return ;
	
	TableDelete( table->next );	/* Chama recursivamente até chegar a ultima lista */
	free(table->data);
		
	free(table);			
}

/*	
Esta função elimina o conjunto de strings set, libertando a memória de alojamento
dinâmico usada pelo descritor e pelas strings.
*/
	
void strSetDelete( strSet_t *set ) {
	
	if ( set == NULL ) return;
	
	for(int i = 0; i < set->size; i++){

	TableDelete( *(set->table + i) );
	
	}

	free(set->table);
	free(set);
	
	
}






