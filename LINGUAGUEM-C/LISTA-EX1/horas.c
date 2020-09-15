#include <stdio.h>

/*
 Autor: Gustavo Campos
 Data: 30/09/2019
 Função: Converter em segundos um tempo dado em horas,minutos e segundos.
*/

int main ()
{
	int tempo, hora, min, seg;
	
	printf("Quantidade em horas, minutos e segundos: ");
	scanf("%d %d %d", &hora,&min,&seg);
	
	tempo=(hora*3600)+(min*60)+(seg);
	
	printf("Quantidade em segundos: corresponde a %ds\n", tempo);
	
	return 0;
}
