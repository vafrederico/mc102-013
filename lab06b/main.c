/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 06b
*/

#include <stdio.h>

int main(){

	/*
	altura		-> qtde de linhas
	largura		-> qtde de colunes
	numZumbi	-> numero de zumbis
	tempo		-> tempo que será rodado
	numSemZumbi -> qtde de espaços em que não se passaram zumbis
	i, j, t 	-> contadores para for's
	 */
	int altura, largura, numZumbi,tempo, numSemZumbi = 0, i, j, t;

	/*
	supermercado (matriz do supermercado), relação char -> valor:
		' ' -> 0
		'X' -> 1
		'#' -> 2
	*/
	int supermercado[100][100];

	/*
	zumbi  (matriz com os zumbis presentes), o que cada posição significa e seus valores possiveis:
		pos 0: R (0), L (1)
		pos 1: Direcao N (1) , E (2) , S (3) , W (4)
		pos 2: linha
		pos 3: coluna
	 */
	int zumbi[100][4];
	
	/*
	c, entradaL, entradaD 	-> char para leitura
	 */
	char c, entradaL, entradaD;
	
	/* lê dimensões */
	scanf("%d %d", &altura, &largura);

	/* inicia posições necessárias */
	for (i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			
			supermercado[i][j] = 0;

		}	
	}

	scanf("%c",&c); /* tirar o \n da entrada */

	/* lê caractere por caractere as linhas do supermercado */
	for(i = 0; i < altura; i++){

		for(j = 0; j < largura; j++){

			scanf("%c", &c);
			if(c == 'X'){ /* se for uma parede ou prateleira do supermercado, marcar */
				supermercado[i][j] = 1;

			}

		}
		scanf("%c",&c); /* tirar o \n da entrada */

	}
	
	/* lê a qtde de zumbis */
	scanf("%d", &numZumbi);

	/* lê cada zumbi */
	for(i = 0; i < numZumbi; i++){

		scanf("%c",&c); /* tirar o \n da entrada */

		/* lê L, D, X e Y */
		scanf("%c %c %d %d", &entradaL, &entradaD, &zumbi[i][2], &zumbi[i][3]);

		/* marcar se é destro ou canhoto */
		if(entradaL == 'R'){
			zumbi[i][0] = 0;
		} else zumbi[i][0] = 1;
		
		/* marcar onde está olhando */
		if(entradaD == 'N')
			zumbi[i][1] = 1;
		else if(entradaD == 'E')
			zumbi[i][1] = 2;
		else if(entradaD == 'S')
			zumbi[i][1] = 3;
		else if(entradaD == 'W')
			zumbi[i][1] = 4;

		/* marcar a posição inicial do zumbi como posição em que um zumbi já passou */
		supermercado[zumbi[i][2]][zumbi[i][3]] = 2;

	}

	/* lê a qtde de tempos que serão processados */
	scanf("%d", &tempo);

	/* processa os tempos */
	for(t = 0; t < tempo; t++){
		for(i = 0; i < numZumbi; i++){ /* para cada zumbi */

			/* tiver que virar */
			if((zumbi[i][1] == 1 && supermercado[zumbi[i][2] - 1][zumbi[i][3]] == 1) || 
				(zumbi[i][1] == 2 && supermercado[zumbi[i][2]][zumbi[i][3] + 1] == 1) ||  
				(zumbi[i][1] == 3 && supermercado[zumbi[i][2] + 1][zumbi[i][3]] == 1) || 
				(zumbi[i][1] == 4 && supermercado[zumbi[i][2] ][zumbi[i][3] - 1] == 1)){

				/* vira somando ou subtraindo baseado se é destro ou canhoto */
				if(zumbi[i][0] == 0)
					zumbi[i][1]++;
				else
					zumbi[i][1]--;

				/* se passou de W, ou de N, deu a volta, então subtrai ou soma */
				if(zumbi[i][1] > 4)
					zumbi[i][1] -= 4;
				else if(zumbi[i][1] < 1)
					zumbi[i][1] += 4;
					
			} else {

				/* move o zumbi de posição */
				if(zumbi[i][1] == 1) zumbi[i][2] -= 1;
				if(zumbi[i][1] == 2) zumbi[i][3] += 1;
				if(zumbi[i][1] == 3) zumbi[i][2] += 1;
				if(zumbi[i][1] == 4) zumbi[i][3] -= 1;
				
				/* marca a posição em que ficar como passou um zumbi */
				supermercado[zumbi[i][2]][zumbi[i][3]] = 2;

			}
				
		}
	}

	/* imprimir zumbis: para cada zumbi */
	for(i = 0; i < numZumbi; i++){

		printf("Zumbi %d: ", i+1);

		/* imprime x,y */
		printf("(%d, %d, ", zumbi[i][2], zumbi[i][3]);

		/* para onde está virado */
		if(zumbi[i][1] == 1)
			printf("N");
		else if(zumbi[i][1] == 2)
			printf("E");
		else if(zumbi[i][1] == 3)
			printf("S");
		else if(zumbi[i][1] == 4)
			printf("W");

		printf(")\n");
	}

	printf("\n");

	/* desenha supermercado */
	for(i = 0; i < altura; i++){
		
		for(j = 0; j < largura; j++){

			if(supermercado[i][j] == 1){ /* parede ou prateleira */
				
				printf("X");

			} else if(supermercado[i][j] == 0){ /* não passou zumbi */
				printf(" ");
				numSemZumbi+=1;
			} else /* passou zumbi */
				printf("#");

		}
		printf("\n");

	}

	printf("\n");

	/* imprime qtde de espaços em que não passou zumbi */
	printf("%d\n", numSemZumbi);

	return 0;

}