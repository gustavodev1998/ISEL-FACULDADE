
#ifndef _STRSET_H_
#define _STRSET_H_



typedef struct hlnode{
	struct hlnode *next;
	char *data;
} HLnode;

typedef struct{
	int size;
	HLnode **table;
} strSet_t;


strSet_t *strSetCreate( void );

int hash( strSet_t *head, char *word );

char *hListSearch( HLnode *head, char *word );

char *strSearchAdd( strSet_t *set, char *word );

void TableDelete( HLnode *table );

void strSetDelete( strSet_t *set );


#endif
