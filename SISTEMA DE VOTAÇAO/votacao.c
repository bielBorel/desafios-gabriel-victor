#include <stdio.h>
#include <locale.h>

typedef struct candidato {
    const char nome;
    int votos;
} Candidato;

Candidato candidato[4] = { 
  {'A', 0},
  {'B', 0},
  {'C', 0},
  {'D', 0}
};

//calcula percentual
float calcPercent(int votos, int total) {
	float res = (float) votos / total * 100;
	if (votos == 0) return 0;
	else return res;
}
//ver quem venceu
void vencendor(Candidato c[]) {
	int i, maior = 0;
	char n;
	for (i = 0; i < 4; i++) {
		if (c[i].votos > maior) {
			maior = c[i].votos;
			n = c[i].nome;
		} 
	}
	printf("----------------------------------------\n");
	printf("O vencendor foi o candidato '%c' com %d votos\n", n, maior);
	printf("----------------------------------------\n");
}


int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	int nulo = 0 , branco = 0, voto, votosInvalidos, votosValidos = 0, total, i;
	char cont = 's';
	while(cont != 'n') {
		printf ("Escolha um dos numeros abaixo para realizar a sua votação:");
		printf ("\n\n 1 - candidato A");
		printf ("\n 2 - candidato B");
		printf ("\n 3 - candidato C");
		printf ("\n 4 - candidato D");
		printf ("\n 6 - Voto Nulo");
		printf ("\n 0 - Branco\n\n");	
		scanf("%d",&voto);

		switch(voto) {
			case 0: {
				nulo++;
				break;
			}
			case 1: case 2: case 3: case 4: {
				candidato[voto - 1].votos++;
				votosValidos++;
				break;
			}
			case 6: {
				branco++;
				break;
			}
			default: {
				printf("Não existe\n");
				break;
			}
		}
	    printf("------------------------------------\n\n");
		printf("continuar a votação? (s/n)? \n");
	    scanf(" %c", &cont);
	    printf("\n------------------------------------\n");
	}
	//
	votosInvalidos = branco + nulo;
	total = votosValidos + votosInvalidos;
	//
	printf("------------------------------------\n\n");
	printf("Votos Válidos: %.2f %% \n", calcPercent(votosValidos, total));
	printf("\n------------------------------------\n");
	//
	for (i = 0; i < 4; i++) {
    	printf("------------------------------------\n");
    	printf("O candidato '%c' teve: %.2f %% dos votos válidos \n", candidato[i].nome, calcPercent(candidato[i].votos, votosValidos));
 	}
	//
 	printf("------------------------------------\n\n");
	printf("Votos nulos e brancos: %.2f %% \n", calcPercent(votosInvalidos, total));
	printf("\n------------------------------------\n");
	
	vencendor(candidato);
	

}
