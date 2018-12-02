#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//algoritmo de Euclides
int auxMDC (int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

//Calcula o MMC
int calcMMC (int n, int frequencia[]) {
	int resultadoMMC = frequencia[0];
	
	int i;
	
	for (i = 1; i < n; i++) {
		resultadoMMC *= frequencia[i] / auxMDC(resultadoMMC, frequencia[i]);
	}
	
	return resultadoMMC;
}

int main () {
	
	setlocale(LC_ALL, "Portuguese");
	
	int obstaculos, i, resultadoInstante;
	char cont;
	printf("----------------------------\n");
	printf("|   Jogo do TIRO AO ALVO   | \n");
	printf("----------------------------\n");
	do {
		validateObstaculo:
			printf("Digite o número de obstáculos: \n");
			scanf("%d", &obstaculos);
			if (obstaculos < 0 || obstaculos > 50) {
				printf("Número inválido! Digite novamente entre 0 e 50: \n");
				goto validateObstaculo;
			} else if (obstaculos == 0) {
				printf("\n ");
				exit(0);	
			}
		
		int frequencia[obstaculos];
		
		printf("Digite a frequência de cada obstáculo: \n");
		
		validateFrequencia:
			for (i = 0; i < obstaculos; i++) {
				scanf("%d", &frequencia[i]);
				if (frequencia[i] <= 0 || frequencia[i] > 60) {
					printf("O número %d é invalido. Digite novamente a sequência! \n", frequencia[i]);
					goto validateFrequencia;	
				}
			}
		
		resultadoInstante = calcMMC(obstaculos, frequencia);
		
		printf("\n O menor instante de tempo é: %d", resultadoInstante);
		printf("\n\n Deseja continuar? (S/N) \n");
		
		scanf(" %c", &cont);	
		
		cont = toupper(cont);
		fflush(stdin);
	
	} while (cont != 'N');
	
	return 0;
}
