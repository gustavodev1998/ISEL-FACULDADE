
#ifndef _SETDATA_H_
#define _SETDATA_H_

#include "connect_list.h"
#include "list_insert.h"
#include "Tbalance.h"
#include "tagtype.h"
#include "tag.h"

					 
					

typedef struct{
int size; // Quantidade de elementos alojados em data.
int count; // Quantidade de elementos preenchidos em data.
MP3Tag_t **data; // Indica array, alojado dinamicamente, com ponteiros para as tags.
MP3Tag_t **aux; // Indica array, alojado dinamicamente, com ponteiros para as tags;
Tnode *tree; // Indica array, alojado dinamicamente, com ponteiros para as tags;
} TagSet_t;

TagSet_t *setCreate( void );

int cmpArtist (const void *a_,const void *b_);

int cmpTitle (const void *a_,const void *b_);

void setAdd( TagSet_t *set, MP3Tag_t *tag );

void setReady( TagSet_t *set);

void setSearch(TagSet_t *set);

void setDelete( TagSet_t *set );

void setCommand( TagSet_t *set, char *cmdLine );

void print_camp( MP3Tag_t *data );

#endif
