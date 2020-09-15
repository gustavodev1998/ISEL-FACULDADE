/*
 * Trabalho de Grupo 
 * Docente: Mario Simoes
 * Alunos: Gustavo Campos	47576
 * 		   Tiago Cebola		47594
 * 
 * Build:
 * /Trabalho_Grupo3   make
 * /sample files copy/samples   ../../app ../list.txt
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tagtype.h"
#include "tag.h"
#include "setdata.h"
#include "listfiles.h"
#include "Tbalance.h"
#include "strset.h"

#define MAX_LINE 256

int main (int agrc, char *argv[]) {
	
	TagSet_t *set;
	
	strSet_t *newset;
	
	int List_Return;
	
	set = setCreate();	/* Cria uma struct do tipo TagSet */
	newset = strSetCreate();/* Cria uma struct do tipo strSet */
	
	
	List_Return = listScan(argv[1], set, newset); /* Processamento da lista de ficheiros MP3 */
	
	if ( List_Return == -1 ) {
			
		fprintf(stderr, "Tag Invalida");
		
	}
	
	setReady(set);
	
	char line[MAX_LINE];
		
	printf("Introduza uma das seguintes opções: \nt: Ordenar por titulo \na: Ordernar por artista \ns: Procurar por musica  \nq: sair\n");
	flag:
	while( fgets(line, sizeof(line), stdin) != NULL ) {
		
		unifyName( line, strlen(line) ); /* Função utilizada para retirar espaços do stdin caso exista */
		
		switch(*line){
			
			case 't':
				setCommand(set, line);
				break;
				
				
			case 'a':
				setCommand(set, line);
				break;
				
				
			case 's':
				setCommand(set, line);
				break;
				
			case 'q':
				setCommand(set, line);
				strSetDelete(newset);
				return 0;
			

			default:
				
				if ( strcmp(line, "\0") == 0 ) break;	/* Para evitar erro de print de Comando Desconhecido sem input */
				printf("Comando Desconhecido\n");
				break;
				
		}
		if ( strcmp(line, "\0") == 0) goto flag;
		printf("\nIntroduza um novo comando: ");
	
	}
	
	return 0;
}
