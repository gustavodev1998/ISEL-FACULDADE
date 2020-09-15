/* -----------------------------------------------
 * Calcular a duração de um turno
 * Autores: Eduardo Conceição e Gustavo Campos
 * Data: outubro 2019
 * 
 * Comando para build: gcc -o turno -Wall turno.c
 * ---------------------------------------------*/

#include <stdio.h>

int main ()
{
	//introdução de dados (entrada)
	
	int he, me, se;
	
	printf("introduza o tempo de entrada: ");
	if (scanf("%d%d%d", &he, &me, &se) != 3) {
		printf("ERRO: tempo inválido\n");
		return 0;
	}
	//validação de dados (entrada)
	
	if (he < 0 || he > 23)
		printf("ERRO: tempo inválido (horas)\n");
	if (me < 0 || me > 59)
		printf("ERRO: tempo inválido (minutos)\n");
	if (se < 0 || se > 59)
		printf("ERRO: tempo inválido (segundos)\n");
	if ((he < 0 || he > 23) || (me < 0 || me > 59) || (se < 0 || se > 59))
		return 0;
	
	//introdução de dados (saída)
	
	int hs, ms ,ss;
	
	printf("introduza o tempo de saída: ");
	if (scanf("%d%d%d", &hs, &ms, &ss) != 3) {
		printf("ERRO: tempo inválido\n");
		return 0;
	}
	//validação de dados (saída)	
	
	if (hs < 0 || hs > 23)
		printf("ERRO: tempo inválido (horas)\n");
	if (ms < 0 || ms > 59)
		printf("ERRO: tempo inválido (minutos)\n");
	if (ss < 0 || ss > 59)
		printf("ERRO: tempo inválido (segundos)\n");
	if ((hs < 0 || hs > 23) || (ms < 0 || ms > 59) || (ss < 0 || ss > 59))
		return 0;
		
	//conversão em segundos (entrada)
	int te;	
	te = he * 3600 + me * 60 + se;
	
	//conversão em segundos (saída)
	int ts;	
	ts = hs * 3600 + ms * 60 + ss;
	
	//duração do turno
	int dt;
	
	if (te > ts || te == ts)
		ts += 86400; //86400 segundos correspondem a 24 horas
		
	dt = ts - te;
	
	//reconversão
	int hd, md, sd;
	
	hd = dt/3600;
	dt = dt%3600;
	
	md = dt/60;
	dt = dt%60;
	
	sd = dt;
	
	//apresentação do resultado final	
	
	printf("duração do turno: %dh %dm %ds\n", hd, md, sd);
	
	return 0;
}
