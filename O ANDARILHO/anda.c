#include <stdio.h>
#include <stdlib.h>

int passos (int num, int passos, int count) {
	int d;
	if (count % 2 == 0) {
		d = num - passos;
	} else {
		d = num + passos;
	}
	return d;
}

int main () {
	int a, N, e, i, qtd, p;
	scanf("%d", &N);
	
	if (N == 0) return 0;
	
	e = 0;
	a = 0;
	p = 0;
	
	for (i = 0; i <= N; ++i){
		scanf("%d", &qtd);
		e = passos(e, qtd, i);
		
		if (e < p) p = e;
		if (e > a) a = e;
	}
	p *= -1;
	
	if (a < p) a = p;
	
	printf("%d \n", a);
	system("pause");
	
	return 0;
}
