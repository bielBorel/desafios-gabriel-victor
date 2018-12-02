#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

//Programa salvo em C++ pois está dando erro de compilação

typedef struct contas {
	float d,c;
	char tipo[2];
	char numero[15];
} Contas;

Contas contas[1000];

int dc (int i,int n){
	
	int e, j, l, k; 
	
	char n1[15], n2[15];
	
	for (e = n; e >= 0; --e) {
		
		if (!strcmp(contas[e].tipo, "A")) {
			
			for (j = e; j < n; ++j){
			
				if (strlen(contas[e].numero) != strlen(contas[j].numero) -1)
					continue;
				
				strcpy(n1, contas[j].numero);
				
				n1[strlen(contas[e].numero)] = NULL;
				
				for (k = 0; k < strlen(contas[j].numero) -1; ++k){
					n2[k] = contas[j].numero[k + 1];
				}
				
				if (!strcmp(n1, contas[e].numero) || !strcmp(n2, contas[e].numero)) {
					contas[e].d = (contas[j].d) + (contas[e].d);
					contas[e].c = (contas[j].c) + (contas[e].c);
				}
			}
		}
	
	}

}
int main (){
	int n,i,e;

	scanf("%d",&n);
	
	for (i = 0; i < n; ++i) {
		
		scanf("%s %s",contas[i].numero, contas[i].tipo);
		
		while (contas[i].numero[0] == '0'){
			for (e = 0; e < strlen(contas[i].numero); ++e) {
				contas[i].numero[e] = contas[i].numero[e + 1]; 
			}
		}
		for (e = strlen(contas[i].numero) -1; e >= 0; --e){
			
			if (contas[i].numero[e] != '0') {
				contas[i].numero[e+1] = NULL;
				break; 
			}
		}
		
		contas[i].c = 0;
		contas[i].d = 0;
		
		if(!strcmp(contas[i].tipo,"S")) {
			printf("\nCredito e debito:\n");
			scanf("%f %f", &contas[i].c, &contas[i].d);
		}

	}
	
	dc (i, n);
	printf("\n");
	for (i = 0; i < n; ++i){
		printf("%s ", contas[i].numero);		
		printf("%.2f ", contas[i].c);
		printf("%.2f ", contas[i].d);
		printf("\n");
}
	system("pause");
	return 0;
}
