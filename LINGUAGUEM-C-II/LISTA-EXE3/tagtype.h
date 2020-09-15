
#ifndef _TAGTYPE_H_
#define _TAGTYPE_H_

#define MAX_TIT 30
#define MAX_ART 30
#define MAX_ALB 30
#define MAX_COM 30


typedef struct{
char title[MAX_TIT + 1];
char *artist;
char *album;
short year;
char comment[MAX_COM + 1];
char track;
char genre;
char *fileName; // Aponta string com o nome do ficheiro, em alojamento dinâmico.
} MP3Tag_t;




#endif
