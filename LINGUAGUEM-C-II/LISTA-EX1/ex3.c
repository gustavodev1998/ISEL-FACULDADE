#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Trabalho de Grupo 
 * Docente: Mário Simões
 * Alunos: Gustavo Campos	47576
 * 		   Tiago Cebola		47594
 * 
 * Build: gcc -std=c99 exe3.c -o exe3
 */

#define MAX_WORDS 5
#define MAX_NAME 255	/*Máximo de caracteres por linha pré-definido */


/*Função que verifica se a palavra em nameWord é idêntica a alguma 
 * das strings indicadas pelos ponteiros do array lowerWords*/

int verify(char *nameWord, char *lowerWords[], int numWords ) {
		
	int size = strlen(nameWord);	
	
	for ( int i = 0; i < size ; i++ ) {		/* Ciclo inicial que coloca a string toda em minúsculo */

	nameWord[i] = tolower(nameWord[i]);
		
	}
	
	int result;	/* Váriavel que guarda o retorno da função */
	
	for (int i = 0; i < numWords; i++ ) {
		
		result = strcmp(nameWord, lowerWords[i]);
		if ( result == 0 ) return 1;	
		
	}
	
	return 0;
}


/*Função que em nameWord converte-a para a forma padrão: a primeira 
 * letra em maiúscula e as restantes para minúscula; exceção – se a 
 * palavra existir nas strings indicadas por lowerWords, deve ficar 
 * toda em minúsculas. Deve utilizar a função anterior.*/

void upper_first(char *nameWord, char *lowerWords[], int numWords ) {
	
	int i = 0;
	int save;
	save = verify( nameWord, lowerWords, numWords);
	
	if ( save == 0 ) nameWord[i] = toupper(nameWord[i]);


}

/*Função que recebendo em name um nome formado por várias palavras, 
 * separadas, antecedidas ou sucedidas por um ou vários espaços ou 
 * Tabs, reproduz a string com as palavras convertidas para a forma 
 * padrão e separadas por um espaço, sem espaços no início nem no fim.*/
 
void unifyName(char *name, char *lowerWords[], int numWords ) {
	
	char *aux;
	
	aux = strtok(name, " \t");	/* Utilização da função strtok e os seus delimitadores (Espaços e Tabs) */
	
	while ( aux != NULL ) { /* Ciclo que percorre os restantes nomes e faz uso da função upper_first para deixar no formato correto */
		
		upper_first(aux, lowerWords, numWords );
		
		printf("%s ", aux );
		
		aux = strtok(NULL, " \t");
		

	}
	
	
}



int main () {
	
	char name[MAX_NAME];
	
	char *lowerWords[MAX_WORDS];	/* Um array de ponteiros que contém as lowerWords pré-definidas */
	
	lowerWords[0] = "dos";
	lowerWords[1] = "do";
	lowerWords[2] = "da";
	lowerWords[3] = "de";
	lowerWords[4] = "e";
	
	printf("Introduza um nome: ");
	
	while ( fgets(name, MAX_NAME, stdin) != NULL) {	/* Uso da função fgets para guardar em name oque é passado pelo standard input */
		
			unifyName(name, lowerWords, MAX_WORDS );
           if( sscanf(name, "%s", name) == EOF ) break;
       
    }

	
	
	return 0;

}

