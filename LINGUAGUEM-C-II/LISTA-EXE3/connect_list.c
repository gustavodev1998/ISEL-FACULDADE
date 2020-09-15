
#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "connect_list.h"
#include "list_insert.h"
#include "tagtype.h"
#include "setdata.h"


void exampleSplit1( Tnode **root, MP3Tag_t *tag ){ /* Função que separa as palavras em Tokens e insere na arvore */
	
	char sc[MAX_TIT];
	strcpy( sc, tag->title );
	char *p = strtok( sc, " \t\n" );
	
	while( p != NULL ){
		printf( "%s\n", p );
		InsertTree( root, p, tag ); /* Chamada a função de inserção a arvore */
		p = strtok( NULL, " \t\n" );
	}
	
}

void InsertTree( Tnode **root, char *word, MP3Tag_t *tag ) {

    if ( *root == NULL ) {
		
        Tnode *aux = malloc( sizeof(*aux) );	/* Inicializar a nossa arvore com 0 */
        aux->left = NULL;
        aux->right = NULL;
        aux->list = NULL;		
        aux->word = strdup(word);
        
        *root = aux; /* Iguala a raiz inicial a nova inicializada */
     
        InsertList( &( (*root)->list ), word, tag); /* Faz a inserção da lista a arvore */
   
        return ;
    }

    if ( strcmp( word, (*root)->word) == 0 ) {		/* Se a palavra ja existe insere a na lista */
		
        InsertList( &((*root)->list) , word, tag);
    }
    
    else if( strcmp( word, (*root)->word) < 0 ){	/* Se a palavra é anterior a palavra em root faz inserção no nó a esquerda */
		
		InsertTree(&(*root)->left, word, tag);
	}
	
	else{											/* Se a palavra é posterior a palavra em root faz inserção no nó a direita */
		
		InsertTree(&(*root)->right, word, tag);
	}


}

int listCount(Tnode* root) {
	
    return root == NULL ? 0 : 1 + listCount(root->right);	/* Conta a quantidade de listas na arvore desmembrada */
}

Tnode *treeSearch(Tnode *root, char *word ){
	
	if( root == NULL ){										/* Caso não encontre a palavra retorna NULL */
		return NULL;	
	}
	
	if( strcmp( word , root->word ) == 0 ){					/* Se encontrou a palavra retorna o nó */
		 return root;
	}	
		
	if( strcmp( word , root->word ) < 0 ) {		
															
		return (Tnode *) treeSearch( root->left, word );	/* Caso a palavra seja anterior a da root faz uma chamada recursiva no nó a esquerda */
	}
		
	return (Tnode *) treeSearch( root->right, word  );		/* Caso a palavra seja posterior a da root faz uma chamada recursiva no nó a direita */
	
}

void treePrint(Tnode *root) {
			 
    while ( (root->list) != NULL ) {		/* Enquanto não chegar ao fim, da print da tag e acede a proxima lista */
		
		print_camp(root->list->tag);
        root->list = root->list->next;
        
    }
    
  
}

void TreeDelete(Tnode *root) {				/* Chama recursivamente a função até aceder ao ultimo nó da arvore e a liberta */
	
	if (root == NULL) return;				
	
	TreeDelete(root->left);	
	TreeDelete(root->right);
	
	ListDelete(&root->list);
	
	free(root->word);
	free(root);

}
