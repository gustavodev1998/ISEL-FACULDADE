
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "connect_list.h"
#include "Tbalance.h"
#include "setdata.h"
#include "tagtype.h"
#include "tag.h"

#define BLOCK_SIZE 50 /* Tamanho adicional para uso no malloc */


/* Definição dos varios generos de musica */
char *genre_type[] = {"Blues", "Classic Rock","Country", "Dance", "Disco", "Funk", "Grunge",
	
					 "Hip-Hop", "Jazz","Metal","New Age","Oldies","Other","Pop","R&B","Rap","Reggae","Rock",
					
					 "Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack",
					 
					 "Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz+Funk","Fusion","Trance","Classical",
					 
					 "Instrumental","Acid","House","Game","Sound Clip","Gospel","Noise","AlternRock","Bass",
					 
					 "Soul","Punk","Space","Meditative","Instrumental Pop","Instrumental Rock","Ethnic","Gothic",
					
					 "Darkwave","Techno-Industrial","Electronic","Pop-Folk","Eurodance","Dream","Southern Rock","Comedy",
					
					 "Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle","Native American","Cabaret","New Wave",
					
					 "Psychadelic","Rave","Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz","Polka","Retro",
					
					 "Musical","Rock & Roll","Hard Rock","Folk","Folk-Rock","National Folk","Swing","Fast Fusion","Bebob",
					
					 "Latin","Revival","Celtic","Bluegrass","Avantgarde","Gothic Rock","Progressive Rock","Psychedelic Rock",
					
					 "Symphonic Rock","Slow Rock","Big Band","Chorus","Easy Listening","Acoustic","Humour","Speech","Chanson",
					
					 "Opera","Chamber Music","Sonata","Symphony","Booty Brass","Primus","Porn Groove","Satire","Slow Jam",
					
					 "Club","Tango","Samba","Folklore","Ballad","Poweer Ballad","Rhytmic Soul","Freestyle","Duet","Punk Rock",
					
					 "Drum Solo","A Capela","Euro-House","Dance Hall"};
					 
					 
TagSet_t *setCreate( void ) {	/* Criação e inicialização de uma struct do tipo Set */

	TagSet_t *s = malloc ( sizeof(*s) );
	s->size = 0;
	s->count = 0;
	s->data = NULL;
	s->aux = NULL;
	
	return s;
	
}


int cmpArtist (const void *a_,const void *b_) {  /* Compara por Ordem de sequencia: 1º- Artist, 2º- Title, 3º- Album */
	
	MP3Tag_t **a, **b;
	
	a = (MP3Tag_t**)a_;
	b = (MP3Tag_t**)b_;
	
	if ( strcmp( (*a)->artist, (*b)->artist) == 0 ) {
		
			if (strcmp((*a)->album, (*b)->album) == 0 ) {
				
				return ( strcmp((*a)->title, (*b)->title) );
			}

			return ( strcmp((*a)->album, (*b)->album) );
	
	}	
	
	return ( strcmp((*a)->artist, (*b)->artist) );
  
}



int cmpTitle (const void *a_,const void *b_) {	/* Compara por Ordem de sequencia: 1º- Title, 2º- Artist, 3º- Album */
	
	MP3Tag_t **a, **b;
	
	a = (MP3Tag_t**)a_;
	b = (MP3Tag_t**)b_;
	
	if ( strcmp( (*a)->title, (*b)->title) == 0 ) {
		
			if (strcmp((*a)->artist, (*b)->artist) == 0 ) {
				
				return ( strcmp((*a)->album, (*b)->album) );
			}

		return ( strcmp((*a)->artist, (*b)->artist) );
	
	}	
	
	return ( strcmp((*a)->title, (*b)->title) );
 
}



void setAdd( TagSet_t *set, MP3Tag_t *tag ){	/* Aloja dinamicamente mais espaço se necessario ao utilizar realloc */
	
	if( set->count == set->size ) {
		
		set->data = realloc(set->data, (set->size += BLOCK_SIZE) * sizeof(*set->data) );	/* Para guardar array principal */
		
	}
	
	set->data[ set->count++ ] = tag;
	
}


void setReady( TagSet_t *set){	/* Esta função prepara o descritor do conjunto para dar as respostas pretendidas, na fase de comandos. */
	
	set->aux = malloc( sizeof(*set->data) * set->count );	/* Aloja dinamicamente espaço para aux */
	
	memcpy(set->aux, set->data, (set->count) * sizeof(*set->data) );	/* Copia o conteudo de data para aux */
	qsort(set->data, set->count, sizeof(set->data), cmpArtist);			/* Ordena por ordem conforme cmpArtist */
	qsort(set->aux, set->count , sizeof(set->aux), cmpTitle);			/* Ordena por ordem conforme cmpTitle */
	
	for (int i=0; i < set->count; i++) {
		
        exampleSplit1( &(set->tree), set->aux[i] ); /* Separa em tokens as palavras para adicionar a arvore */
        
    }
    
	set->tree = treeToSortedList( set->tree, NULL);								/* Transformar a árvore binária numa árvore degenerada em lista ordenada*/
	
	set->tree = sortedListToBalancedTree( &(set->tree), listCount(set->tree->right) );						/* Transformar a lista numa árvore */
	
	
}


void setDelete( TagSet_t *set ){		/* Liberta os campos da struct MP3Tag para posteriormente a struct em si */
	

	for( int i = 0; i < set->count; ++i ){
		
		free( set->data[i]->fileName );
		free( set->data[i]);
		
	}
	
	free(set->data);
	free(set->aux);
	
	TreeDelete(set->tree);		/* Chama a função que irá libertar os campos da arvore */
	
	free(set);
	
}


void setSearch(TagSet_t *set) {
	
    char *key_word = malloc( sizeof(char) * MAX_TIT );
    
    printf("Indique a palavra a ser encontrada: ");
    scanf("%s", key_word);
    
    Tnode *aux = treeSearch( set->tree, key_word);		/* Procura na arvore se existe a palavra indicada */

    if ( aux == NULL ) printf("A palavra não foi encontrada!\n");
    
    else treePrint(aux);
      
}

void setCommand( TagSet_t *set, char *cmdLine ){	/* Verifica o stdin e demonstra o conteudo conforme o solicitado pelo utilizador */
	
	
	if ( strcmp( cmdLine, "a" ) == 0 ) {
	
		for ( int i = 0; i < set->count; i++ ) {
			
			print_camp(set->data[i]);
		}
	}
	
	if ( strcmp( cmdLine, "t" ) == 0 ) {
	
		for ( int i = 0; i < set->count; i++ ) {
			
			print_camp(set->aux[i]);
		}
		
	}
	
	if ( strcmp( cmdLine, "s" ) == 0 ) {
	
		setSearch(set);				/* CHama a função que irá procurar a palavra indicada */
		
	}
	
	if ( strcmp( cmdLine, "q" ) == 0 ) {
			
			setDelete(set);
		
	}
	
}

void print_camp( MP3Tag_t *data ) {		/* Função para imprimir todos os campos da struct MP3Tag */
	
	   printf("\nTitle: %s",data->title);
	   printf("\nArtist: %s",data->artist);
	   printf("\nAlbum: %s",data->album);
	   printf("\nYear: %d",data->year);
	   printf("\nComment: %s",data->comment);
	   printf("\nTrack: %d",data->track);
	   
	   if( data->genre < 0 || data->genre > 125 ) printf("\nUknown Genre");
	   
	   else printf("\nGenre: %s", genre_type[data->genre] );		
	   
	   printf("\nFileName: %s\n",data->fileName);
   
}


