
#ifndef _LIST_INSERT_H_
#define _LIST_INSERT_H_

#include "tagtype.h"

typedef struct lnode
{
    struct lnode *next;
    MP3Tag_t *tag;

} Lnode;

void InsertList(Lnode **hp , char *word, MP3Tag_t *tag);

void ListDelete(Lnode **hp);


#endif
