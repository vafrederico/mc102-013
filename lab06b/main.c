/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 06b
*/

#include <stdio.h>

int main(){

	int altura, largura, numZumbi;
	/*
	supermercado:
		' ' -> 0
		'#' -> 1
	*/
	int supermercado[100][100];
	/*
	zumbi:
		pos 0: R (0), L (1)
		pos 1: Direcao N (1) , E (2) , S (3) , W (4)
		pos 2: X
		pos 3: Y
	 */
	int zumbi[100][4];
	char c, entradaL, entradaD;
	int i, j;

	scanf("%d %d", &altura, &largura);
	for (i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			
			supermercado[i][j] = 0;

		}	
	}
	scanf("%c",&c); // \n
	for(i = 0; i < altura; i++){

		for(j = 0; j < largura; j++){
			scanf("%c", &c);
			if(c == 'X'){
				supermercado[i][j] = 1;

			}

		}
		scanf("%c",&c); // \n

	}
	
	scanf("%d", &numZumbi);

	for(i = 0; i < numZumbi; i++){

		setbuf(stdin, 0);
		scanf("%c %c %d %d", &entradaL, &entradaD, &zumbi[i][2], &zumbi[i][3]);
		if(entradaL == 'R'){
			zumbi[i][0] = 0;
		} else zumbi[i][0] = 1;
		
		if(entradaD == 'N')
			zumbi[i][1] = 1;
		else if(entradaD == 'E')
			zumbi[i][1] = 2;
		else if(entradaD == 'S')
			zumbi[i][1] = 3;
		else if(entradaD == 'W')
			zumbi[i][1] = 4;

	}

	printf("-------------------\nLIDO:\n");
	for(i = 0; i < altura; i++){
		
		for(j = 0; j < largura; j++){

			if(supermercado[i][j] == 1){
				
				printf("X");

			} else {
				printf(" ");
			}

		}
		printf("\n");

	}


	for(i = 0; i < numZumbi; i++){

		printf("Zumbi %d: ", i);
		if(zumbi[i][0] == 0){
			printf("R ");
		} else printf("L ");
		
		if(zumbi[i][1] == 1)
			printf("N ");
		else if(zumbi[i][1] == 2)
			printf("E ");
		else if(zumbi[i][1] == 3)
			printf("S ");
		else if(zumbi[i][1] == 4)
			printf("W ");

		printf("(%d,%d)\n", zumbi[i][2], zumbi[i][3]);
	}
	system("PAUSE");
	return 0;

}