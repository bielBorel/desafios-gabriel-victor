#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void cafufa (int N, int p, int d) {
	int i;
	for (i = 1; i <= N; i++) {
		if (p == 0 || d == 0) {
			printf("%d", i);
		} else {
			if (i % p == 0 || i % d == 0 || i % 10 == p || i % 10 == d) {
				printf("cafufa");
			} else {
				printf("%d", i);
			}
		}
		if (i != N) printf(", ");
	}
	printf(".");
}

int main () {
	
	setlocale(LC_ALL, "Portuguese");
	
	int N, p, d;
	
	
	printf("BEM VINDO AO CAFUFA PREMIERE! \n \n");
	
	validateNumbers:
		printf("\nDigite a quantidade de números da contagem, e dois números \nque gerarão a palavra cafufa, respectivamente: \n");
		
		scanf("%d %d %d", &N, &p, &d);
		if (N < 0 || N > 1000 || p < 0 || p >= 10 || d < 0 || d >= 10) {
			printf("Algo está errado. Quantidade deve estar entre 1 e 1000 e os números entre 1 e 9\n");
			goto validateNumbers;
		} else if (N == 0 && p == 0 && d == 0) {
			exit(0);
		}
	
	cafufa(N, p, d);
	
	return 0;
}
