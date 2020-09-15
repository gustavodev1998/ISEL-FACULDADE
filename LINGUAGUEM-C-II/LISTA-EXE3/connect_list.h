
#ifndef _CONNECT_LIST_H_
#define _CONNECT_LIST_H_

#include "tagtype.h"
#include "list_insert.h"

typedef struct tnode {
	
	struct tnode *left, *right;
	struct lnode *list;
	char *word;
	
} Tnode;


void InsertTree( Tnode **root, char *word, MP3Tag_t *tag );

void exampleSplit1( Tnode **root, MP3Tag_t *tag );

Tnode *treeSearch(Tnode *root, char *word );

void treePrint(Tnode *root);

int listCount(Tnode* r);

void TreeDelete(Tnode *root);


#endif
