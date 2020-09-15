#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Trabalho de Grupo 
 * Docente: Mário Simões
 * Alunos: Gustavo Campos	47576
 * 		   Tiago Cebola		47594
 * 
 * Build: gcc -std=c99 exe4.c -o exe4
 */

#define MAX_WORDS 5
#define MAX_NAME_COUNT 50
#define MAX_NAME_SIZE 255 /*Máximo de caracteres por linha pré-definido */

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
	
	int size = strlen(name) - 1;
	
	char save_string[size]; /* Array auxiliar para guardar tokens */
	
	int i = 0;
	
	aux = strtok(name, " \t");	/* Utilização da função strtok e os seus delimitadores (Espaço e Tab) */

	while ( aux != NULL ) { /* Ciclo que percorre os restantes nomes e faz uso da função upper_first para deixar no formato correto */
		
	
		upper_first(aux, lowerWords, numWords );
		
		for( int j = 0; aux[j] != 0; j++){ 
				
			save_string[i] = aux[j];
			i++;
			
		}
		
		save_string[i] = ' '; /* Adiciona espaços entre nomes */
		i++;
		
		
		aux = strtok(NULL, " \t");
		
	
	}
	
	
	save_string[--i] = '\0'; /* Terminador da String */
	strcpy(name, save_string); /* Guarda a string correta em name */
		
}
	




/*que lê, a partir da stream indicada, um nome, o qual uniformiza e armazena na string indicada apor name.
Para ler, deve usar a função fgets da biblioteca normalizada; para uniformizar o nome, deve utilizar as
funções do exercício anterior. Retorna: 1, em caso de sucesso; 0, se ocorreu end-of-file na leitura. */

int fillName(char *name, FILE *stream ) {
	
	
	char *lowerWords[MAX_WORDS];	/* Um array de ponteiros que contém as lowerWords pré-definidas */
	
	lowerWords[0] = "dos";
	lowerWords[1] = "do";
	lowerWords[2] = "da";
	lowerWords[3] = "de";
	lowerWords[4] = "e";
	
	char line_feed[] = "\n";
	
	do {
		
	if ( fgets(name, MAX_NAME_SIZE, stream) == NULL ) return 0;
	
	} 
		while ( strcmp(name, line_feed) == 0 );

		name[strlen(name) - 1] = 0;
	
		unifyName(name, lowerWords, MAX_WORDS );
	
		return 1;
    
}

int cmpchar ( const void *name1, const void *name2 ) {
	
	int x = strcmp( (char*)name1, (char*)name2 );
		
	return x;
	
}

/*que ordena o array name, por ordem alfabética crescente. O parâmetro count é o número de elementos
preenchidos no array.
Para ordenar o array, deve utilizar a função qsort da biblioteca normalizada. É necessário escrever uma
função de comparação que identifica a ordem relativa entre duas strings. Esta função é passada por
parâmetro à função qsort.
 */
void sortNames( char name[][MAX_NAME_SIZE], int count ) {
	
	qsort( (void*)name, count, sizeof *name, cmpchar );
	
	printf("Array de nomes ordenados:\n");	
	
	for ( int i = 0; i < count; i++) {

		printf("%s\n", name[i] );
		
	}
}



int main () {
	
	char names[MAX_NAME_COUNT][MAX_NAME_SIZE];
		
	int i = 0;
	
	printf("Introduza uma sequencia de nomes: ");
	while ( fillName(names[i], stdin) )	i++;

	
	sortNames(names, i);
	
	
	return 0;

}
