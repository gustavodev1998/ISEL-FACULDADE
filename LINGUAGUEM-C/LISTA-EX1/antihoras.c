#include <stdio.h>

/*
 Autor: Gustavo Campos
 Data: 30/09/2019
 Função: Converter em horas, minutos e segundos uma dada quantidade de segundos.
*/

int main ()
{
	int tempo, horas, min, seg, tempo_inicial;
	
	printf("Quantidade em segundos: ");
	scanf("%d", &tempo);
	
	tempo_inicial=tempo;
	horas = tempo / 3600;
	tempo = tempo % 3600;
	
	min = tempo / 60;
	tempo = tempo % 60;
	
	seg = tempo;
	
	printf("%d segundos correspondem a %dh, %dm e %ds\n", tempo_inicial, horas, min, seg);

	
	return 0;
}
