#include <stdlib.h>
#include <stdio.h>

int set (int placar_xing, int placar_ovo) {
	int total_xing, total_ovo, i, e, s[placar_xing + placar_ovo], p[placar_xing + placar_ovo];
	
	for(i = 0; i < placar_xing + placar_ovo; ++i) scanf("%d %d", &s[i], &p[i]);
	
	total_xing = 0;
	total_ovo = 0;
	
	for (e = 0; e < i; ++e) {
		
		if(s[e] != -1 && p[e] != -1) {
			if(s[e] > p[e]) --placar_xing;
			else --placar_ovo;
			
			total_xing += s[e];
			total_ovo += p[e];	
		}
		
		if (s[e] == -1 && p[e]== -1) {
			total_xing += 20;
			total_ovo += 18;
			--placar_xing;
		}
		
		if (s[e]== -1 && p[e] != -1) {
			
			if (p[e] <= 9) { 
			
				total_xing += 11;
				total_ovo += p[e];
				--placar_xing;
			
			} else {
				
				if(placar_xing < 1) {
					total_xing += p[e] - 2;
					total_ovo += p[e];
					--placar_ovo;
				} else {
					total_xing += p[e] + 2;
					total_ovo += p[e];
					--placar_xing;
				}
			}
		}
		
		if(s[e] != -1 && p[e] == -1) {
			
			if (s[e] <= 9) {
			
				total_ovo += 11;
				total_xing += s[e];
				--placar_ovo;
			
			} else {
			
				if(placar_ovo < 1) {
					total_ovo += s[e] - 2;
					total_xing += s[e];
					--placar_xing;
				} else {
					total_ovo += s[e] + 2;
					total_xing += s[e];
					--placar_ovo;
				}
			}
			
		}
	}
	
	printf("\n%d %d \n\n", total_xing, total_ovo);
	return 0;
}

int main () {
	
	int  xing, ovo, partidas, i;
	
	scanf("%d", &partidas);
	
	for (i = 1;i <= partidas; ++i){
		
		scanf("%d %d", &xing, &ovo);
		
		set(xing, ovo);
	}
	
	system("pause");
	return 0;
}
