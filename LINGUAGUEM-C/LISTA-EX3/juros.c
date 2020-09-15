#include <stdio.h>

double calc_juros(int total_anos, double mi, double tax) {
	
	int i = 0;
	double start = mi;
	double aux;
	
	while ( i < total_anos ) {
		
		aux = start * tax;
		start = start + aux;
		i++;
		
	}
	
	return start;
}



int main () {

	double montante;
	double taxa_anual;
	int anos;

	
	printf ("Introduza um montante inicial:\n");
	scanf ("%lf", &montante);
	
	printf ("Introduza quanto anos deseja que o seu montante fique investido:\n");
	scanf ("%d", &anos);
	
	printf ("Introduza uma taxa anual em percentagem:\n");
	scanf ("%lf", &taxa_anual);
	
	taxa_anual = taxa_anual / 100;
	
	double x = calc_juros(anos, montante, taxa_anual);
	
	printf ("Para um montante inicial de %.2lf somando os juros compostos: %.2lf dá um total de %.2lf\n", montante,x-montante,x);
	
	return 0;
}
