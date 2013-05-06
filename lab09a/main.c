#include <stdio.h>
#include <string.h>

int main(){

	/* quantidade de subcelebridades */
	int totalSubcelebridades;

	/* nome de cada subcelebridade */
	char nomeSubcelebridade[20][16];
	/* quantos conhecem a subcelebridade */
	int conhecidoSubcelebridade[20];
	/* quantos a subcelebridade conhece */
	int conheceSubcelebridade[20];
	/* há alguma subcelebridade premium */
	int existeSubcelebridadePremium = 0;

	/* leitura de nomes */
	char nome1[16], nome2[16];
	/* contador para for's */
	int i;

	/* lê quantas subcelebridades existem */
	scanf("%d", &totalSubcelebridades);

	/* para cada subcelebridade */
	for(i = 0; i < totalSubcelebridades; i++){

		/* recebe o nome de cada */
		scanf("%s", nomeSubcelebridade[i]);

		/* no inicio, a subcelebridade não conhece ninguém e não é conhecida por ninguém */
		conhecidoSubcelebridade[i] = 0;
		conheceSubcelebridade[i] = 0;

	}

	/* enquanto tiver leitura e for diferente de X X  (strlen > 1, pois nome >= 3, se = 1, nome1 = X, logo X X) */
	while(scanf("%s", nome1) && scanf("%s",nome2) && strlen(nome1) > 1){

		/* busca em cada subcelebridade os noems */
		for(i = 0; i < totalSubcelebridades; i++){

			if(strcmp(nome1, nomeSubcelebridade[i]) == 0) /* se o nome1 é o da subcelebridade, essa subcelebridade conhece a outra */
				conheceSubcelebridade[i]++;

			if(strcmp(nome2, nomeSubcelebridade[i]) == 0) /* se o nome2 é o da subcelebridade, essa subcelebridade é conhecida pela outra */
				conhecidoSubcelebridade[i]++;

		}

	}

	/* para cada uma das subcelebridades */
	for(i = 0; i < totalSubcelebridades; i++){

		if(conheceSubcelebridade[i] == 0 && conhecidoSubcelebridade[i] == totalSubcelebridades - 1){ /* está no critéria de subcelebridade premium */
			
			printf("Existe uma subcelebridade premium: %s.", nomeSubcelebridade[i]);

			/* marca que há subcelebridade premium */
			existeSubcelebridadePremium = 1;

		}

	}

	/* caso não haja subcelebridade premium */
	if(existeSubcelebridadePremium == 0)
		printf("Nenhuma subcelebridade premium.");

	return 0;

}