
#ifndef _TAG_H_
#define _TAG_H_

#include "tagtype.h"
#include "strset.h"

MP3Tag_t *tagRead( char *filename, int *resPtr, strSet_t *sSet );

void space_remove( int point_size, char *buffer);

void unifyName(char *name,  int numWords );

#endif
