#include <stdio.h>
#include <string.h>

int main(){

	int totalSubcelebridades;

	int i;

	char nomeSubcelebridade[20][16];
	int conhecidoSubcelebridade[20];
	int conheceSubcelebridade[20];
	int existeSubcelebridade = 0;
	char nome1[16], nome2[16];

	scanf("%d", &totalSubcelebridades);

	for(i = 0; i < totalSubcelebridades; i++){

		scanf("%s", nomeSubcelebridade[i]);
		conhecidoSubcelebridade[i] = 0;
		conheceSubcelebridade[i] = 0;

	}

	while(scanf("%s", nome1) && scanf("%s",nome2) && strlen(nome1) > 1){

		for(i = 0; i < totalSubcelebridades; i++){

			if(strcmp(nome1, nomeSubcelebridade[i]) == 0)
				conheceSubcelebridade[i]++;

			if(strcmp(nome2, nomeSubcelebridade[i]) == 0)
				conhecidoSubcelebridade[i]++;

		}

	}

	for(i = 0; i < totalSubcelebridades; i++){

		//printf("Conhece: %d  Conhecido: %d  Nome: %s\n", conheceSubcelebridade[i], conhecidoSubcelebridade[i], nomeSubcelebridade[i]);
		if(conheceSubcelebridade[i] == 0 && conhecidoSubcelebridade[i] == totalSubcelebridades - 1){
			
			printf("Existe uma subcelebridade premium: %s.", nomeSubcelebridade[i]);

			existeSubcelebridade = 1;

		}

	}

	if(existeSubcelebridade == 0)
		printf("Nenhuma subcelebridade premium.");

	//system("PAUSE");

	return 0;

}