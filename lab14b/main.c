/*	Gustavo Torrente Goncalves
	RA: 146375
	Turma: Q
	Lab 14b
*/

#include <stdio.h>

void testaCaminho(char (*mapa)[100][100], int posX, int posY, int tamX, int tamY, int (*tesouros)[26]){

	char atual;
	
	/* está dentro do vetor? */
	if(posX < 0 || posX > 99 || posY < 0 || posY > 99)
		return;

	/* salvamos o que tem em nossa posição e marcamos ela como parede para não andar mais por ela */
	atual = (*mapa)[posY][posX];
	(*mapa)[posY][posX] = '#';

	if(atual >= 'a' && atual <= 'z'){

		/* se estivermos em um tesouro, marcamos a posição do vetor tesouro referente a letra no alfabeta com 1 */
		(*tesouros)[atual - 'a'] = 1;

	} else if(atual >= '1' && atual <= '9'){
		
		int i, j;
		
		/* se estivermos em um portal, procura a saida do portal e procura-se tesouros a partir da saida */
		for(i = 0; i < tamY; i++)
			for(j = 0; j < tamX; j++)
				if((*mapa)[i][j] == atual)
					testaCaminho(mapa, j, i, tamX, tamY, tesouros);

	}

	/* procura nos quatro lados se encontra algo que não seja uma parede, se achar, procura-se tesouros a partir desse lugar */
	if((*mapa)[posY + 1][posX] != '#')
		testaCaminho(mapa, posX, posY + 1, tamX, tamY, tesouros);

	if((*mapa)[posY - 1][posX] != '#')
		testaCaminho(mapa, posX, posY - 1, tamX, tamY, tesouros);

	if((*mapa)[posY][posX + 1] != '#')		
		testaCaminho(mapa, posX + 1, posY, tamX, tamY, tesouros);

	if((*mapa)[posY][posX - 1] != '#')		
		testaCaminho(mapa, posX - 1, posY, tamX, tamY, tesouros);

}

int main(){

	char mapa[100][100];
	int tamX, tamY;
	int posX;
	int posY;
	int tesouros[26];
	int i, j;
	char c;
	int achouTesouro = 0;

	for(i = 0; i < 26; i++)
		tesouros[i] = 0;

	/* leitura da entrada, salvando as informações e montando o mapa na matriz. utiliza-se o char c para ler o \n */
	scanf("%d %d %d %d", &tamY, &tamX, &posY, &posX);
	scanf("%c", &c);

	for(i = 0; i < tamY; i++){

		for(j = 0; j < tamX; j++){

			scanf("%c", &mapa[i][j]);
			
		}
		
		scanf("%c", &c);
	}

	/* começa a procurar tesouros a partir da posição inicial */
	testaCaminho(&mapa, posX - 1, posY - 1,  tamX, tamY, &tesouros);

	for(i = 0; i < 26; i++){
		if(tesouros[i]){
			/* se houver um tesouro na posição i, imprime seu correspondente no alfabeto e marca que foi achado pelo menos um tesouro */
			printf("%c", i + 'a');
			achouTesouro = 1;
		}
	}

	/* se não achou nenhum tesouro */
	if(!achouTesouro)
		printf("no treasures");

	printf("\n");
	return 0;
	
}