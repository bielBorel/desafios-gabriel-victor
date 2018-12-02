#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int concPrimos (int e[], char c[]) {
	
	int n = 0, i, l = 1, j = 1, m = atoi(c), auxiliar = 0, p, a = 0;
	
	
	for (n = 0; n < strlen(c); ++n) {
		if (c[n] < 48 || c[n] > 57) return j; 
	}
	
	if (e[0] == 0 || m == 1) return j;
	
	for(n = 0; n < strlen(c); ++n) {
		
		if (c[n] < 48 || c[n] > 57) return j;
		
		if (e[n] == 1 && e[n] == e[strlen(c) - 1]) {
			e[n] = (e[n - 1] * (pow(10, 1))) + e[n];
			++l;
		}
		
		if (e[n] == 1){
			e[n + 1] = (e[n] * (pow(10, 1))) + e[n + 1];
			++l;
			break;			
		}
		
		for (i = 2;i < e[n]; ++i) {
				if (e[n] % i == 0 || e[n] == 1 || e[n + 1] == 0) {
				
				if ((strlen(c)) -1 == n) {
					
					if (auxiliar == 0) return j;
					
					e[n] = (e[n - l] * (pow(10, l))) + e[n];
				
					for (a = 2; a < e[n]; ++a) {
						if (e[n] % a == 0) return j; 
					} 
				}
				
				e[n + 1] = (e[n] * (pow(10, 1))) + e[n + 1];
				++l;
				p = 1;
				break;
			}
		}
		if (p != 1) {
			l = 1;
			auxiliar = 1;
			p = 0;
		}
	}
	++j;
	return j;
}

int main () {
	int C, i, j, aux[5], resultado;
	char cadeia[5];
	scanf("%d", &C);
	
	for (i = 0; i < C; ++i){
		
		scanf("%s", cadeia);
		for(j = 0; j < strlen(cadeia); ++j) aux[j] = (cadeia[j] - 48);
		
		resultado = concPrimos(aux, cadeia);
		
		if (resultado == 1) printf("nao\n");
		if (resultado == 2) printf("sim\n");
	}
	system("pause");
	return 0;
}
