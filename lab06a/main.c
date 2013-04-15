/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 06a
*/

#include <stdio.h>
#include <math.h>

int main(){

	/*
	terreno	-> matriz contendo os lotes do terreno, sendo seu valor quantos irrigadores irrigam aquele lote
	altura	-> altura do terreno
	largura	-> largura do terreno
	i, j 	-> Contador para for's
	A		-> Area irrigada pelo irrigador
	iLote	-> Posição i do irrigador (lote)
	jLote	-> Posição j do irrigador (lote)
	lotes	-> Quantos lotes para cada direção i e j serão irrigados ((raiz quadrada de A - 1)/2)
	efetivo	-> Se o projeto é efetivo, valor é 1, caso contrário, 0
	 */
	
	int terreno[101][101];
	int altura, largura;
	int i, j, A, iLote, jLote, lotes, efetivo;

	/* Lê a altura e largura do terreno */
	scanf("%d %d", &altura, &largura);

	/* Inicializa as posições que serão utilizadas */
	for(i = 0; i <= altura; i++){

		for(j = 0; j <= largura; j++){

			terreno[i][j] = 0;

		}

	}

	/* Enquanto tiver leitura de i, j, e A, e não for 0,0,0 */
	while(scanf("%d %d %d", &iLote, &jLote, &A) && (iLote != 0 || jLote != 0 || A != 0)){

		/* Obtém quantos lotes na direção i e j serão irrigados */
		lotes = (sqrt(A) - 1)/2;

		/* Cada lote irrigado */
		for(i = iLote - lotes; i <= iLote + lotes; i++){

			for(j = jLote - lotes; j <= jLote + lotes; j++){

				/* Está dentro da matriz terreno */
				if(i >= 0 && i <= 100 && j >= 0 && j <= 100)
					terreno[i][j]++;

			}

		}

	}

	/* No início todos são efetivos */
	efetivo = 1;

	/* Verifica se algum lote é subirrigado, se sim, imprime e marca como não-efetivo */
	for(i = 1; i <= altura; i++){

		for(j = 1; j <= largura; j++){

			if(	terreno[i][j] == 0 ){
				
				printf("Sub: (%d, %d)\n", i, j);
				
				efetivo = 0;

			}

		}

	}

	/* Verifica se algum lote é superirrigado, se sim, imprime e marca como não-efetivo */
	for(i = 1; i <= altura; i++){

		for(j = 1; j <= largura; j++){

			if(	terreno[i][j] > 1 ){

				printf("Super: (%d, %d)\n", i, j);

				efetivo = 0;

			}

		}

	}

	/* Se for efetivo, imprime */
	if(efetivo == 1)
		printf("Projeto efetivo.");

	return 0;

}