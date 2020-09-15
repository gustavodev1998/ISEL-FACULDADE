

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_insert.h"


void InsertList(Lnode **hp , char *word, MP3Tag_t *tag) {


    if ( *hp == NULL) {		/* Verifica se o headpointer está vazio */
		
        Lnode *aux = malloc( sizeof(*aux) );	
        aux->next = NULL;
        aux->tag = tag;
        *hp = aux;			/* Iguala o ponteiro alocado dinamicamente a hp */
    }
    
    else {
		
        InsertList( &( (*hp)->next ), word, tag);	/* Chama recursivamente a função enquanto houver tags */
        
    }

}

void ListDelete(Lnode **hp) {
	
	if (hp == NULL) return ;
	
	ListDelete(&(*hp)->next);	/* Chama recursivamente até chegar a ultima lista */
	
	free(*hp);				
}



