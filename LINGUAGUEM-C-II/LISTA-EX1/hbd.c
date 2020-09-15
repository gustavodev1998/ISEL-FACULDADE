#include <stdio.h>
#include <limits.h>

/* Trabalho de Grupo 
 * Docente: Mário Simões
 * Alunos: Gustavo Campos	47576
 * 		   Tiago Cebola		47594
 * 
 * Build: gcc -std=c99 hbd.c -o hbd 
 */

#define Byte 8
#define Half_Word 16
#define Word 32
#define Double_Word 64

#define INVALID -1

/*Função que verifica a dimensão dos elementos dada pelo standard input*/
int check_arguments(char* argv){	
	if(*argv == 'b' || *argv == 'B' || *argv == 1) return Byte;
	else if(*argv == 'h' || *argv == 'H' || *argv == 2) return Half_Word;
	else if(*argv == 'w' || *argv == 'W' || *argv == 3) return Word;
	else if(*argv == 'd' || *argv == 'D' || *argv == 4) return Double_Word;
	else return INVALID;
}

/*Função que apresenta, em standard output, a representação na base 2 dos size bits de menor peso de value*/
void print_bin(unsigned long long value, int size) {
	
	int bin[size], count = 0;
	
	/*Conversão para binário dos numeros em ASCII presente em value*/
	for(int aux = size-1; aux >= 0; aux--) {	
			
		if (value % 2 == 0) bin[aux] = 0;
		else bin[aux] = 1;
		
		value = value / 2;
	}
	
	/*Apresenta ao utilizador o conteudo no array com um espaço entre grupos de oito bits e com um ponto em grupos de quatro bits*/
	while(count < size) {
			
		printf("%d", bin[count]);
		if ((count+1) % 8 == 0) printf(" ");
		else if( (count+1) % 4 == 0) printf (".");
		
		count++;
    }
    
    printf("\n");
}


int main(int argc, char *argv[]) {
	
	/*Validação em relação ao numero de argumentos passados*/
	if( argc > 3 ) {
		fprintf(stderr, "%s", "Número de argumentos inválido!\n");
		return -1;
	}
	
	int standard = -1; 
	if(argc == 2) standard = Word; /*Pré-definido como Word caso o utilizador não introduza um segundo argumento*/
	else standard = check_arguments(*(argv+2)); /*Faz uso da função check_arguments que retorna qual a dimensão dos elementos*/
	
	unsigned long long value;
	int size = standard / Byte;
	
	FILE *f = fopen( argv[1], "rb" ); /*"rb" tendo em conta que iremos ler o conteudo do ficheiro f em binário*/
	
	 if ( f == NULL ) {
		fprintf(stderr, "%s", "O ficheiro não foi encontrado!\n");
		return -1;
	 }
	 
	 /*Validação do tipo da dimensão dos elementos caso seja um input inválido*/
	 if ( standard == INVALID){
		fprintf(stderr, "%s", "Dimensão de conversão inválida!\n");
		return -1;
	}

	/*Ciclo que lê do ficheiro o seu conteudo e mostra em standard output em que cada tipo de dimensão tem um cast para evitar arrasto de sinal*/
	 while( fread(&value, size, 1, f) != 0 ){

		if(standard == Byte) printf("%02x  ", (unsigned char) value);
		else if(standard == Half_Word) printf("%04x  ", (unsigned short) value);
		else if(standard == Word) printf("%08x  ",(unsigned int) value);
		else if(standard == Double_Word) printf("%016llx  ",(unsigned long long) value);
		
		print_bin(value, standard);
	 }
		
	 fclose(f);
	 return 0;
} 


