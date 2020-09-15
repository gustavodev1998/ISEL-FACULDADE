
#ifndef _TBALANCE_H_
#define _TBALANCE_H_

#include "connect_list.h"


Tnode *treeToSortedList( Tnode *r, Tnode *link );
Tnode* sortedListToBalancedTree(Tnode **listRoot, int n);

#endif
