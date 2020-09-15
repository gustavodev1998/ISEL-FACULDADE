


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tbalance.h"


/* 1. Transformar a árvore binária numa árvore degenerada em lista ordenada, ligada pelo campo 
right, usando o algoritmo seguinte. */
Tnode *treeToSortedList( Tnode *r, Tnode *link ){
 Tnode * p;
 if( r == NULL ) return link;
 p = treeToSortedList( r->left, r );
 r->left = NULL;
 r->right = treeToSortedList( r->right, link );
 return p;
} 




/* 2. Conhecido o número de elementos, transformar a lista numa árvore, usando o algoritmo seguinte. */

Tnode* sortedListToBalancedTree(Tnode **listRoot, int n) {
 if( n == 0 )
 return NULL;
 Tnode *leftChild = sortedListToBalancedTree(listRoot, n/2);
 Tnode *parent = *listRoot;
 parent->left = leftChild;
 *listRoot = (*listRoot)->right;
 parent->right = sortedListToBalancedTree(listRoot, n-(n/2 + 1) );
 return parent;
}
