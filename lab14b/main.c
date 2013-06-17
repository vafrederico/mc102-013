#include <stdio.h>

void testaCaminho(char (*mapa)[100][100], int posX, int posY, int tamX, int tamY, int (*tesouros)[26]){
	int i, j;
	char atual;
	if(posX < 0 || posX > 99 || posY < 0 || posY > 99)
		return;

	atual = (*mapa)[posY][posX];
	(*mapa)[posY][posX] = '#';
	if(atual >= 'a' && atual <= 'z'){

		//printf("tesouro %c\n", atual);

		(*tesouros)[atual - 'a'] = 1;

	} else if(atual >= '1' && atual <= '9'){
		//printf("portal %c %d %d\n", atual, posX, posY);
		for(i = 0; i < tamY; i++)
			for(j = 0; j < tamX; j++)
				if((*mapa)[i][j] == atual)
					testaCaminho(mapa, j, i, tamX, tamY, tesouros);
	}

	if((*mapa)[posY + 1][posX] != '#'){

		testaCaminho(mapa, posX, posY + 1, tamX, tamY, tesouros);

	}

	if((*mapa)[posY - 1][posX] != '#'){

		testaCaminho(mapa, posX, posY - 1, tamX, tamY, tesouros);

	}

	if((*mapa)[posY][posX + 1] != '#'){
		
		testaCaminho(mapa, posX + 1, posY, tamX, tamY, tesouros);

	}

	if((*mapa)[posY][posX - 1] != '#'){
		
		testaCaminho(mapa, posX - 1, posY, tamX, tamY, tesouros);

	}

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
	scanf("%d %d %d %d", &tamY, &tamX, &posY, &posX);
	scanf("%c", &c);
	for(i = 0; i < tamY; i++){

		for(j = 0; j < tamX; j++){

			scanf("%c", &mapa[i][j]);
			
		}
		
		scanf("%c", &c);
	}
/*
	for(i = 0; i < tamY; i++){

		for(j = 0; j < tamX; j++){

			printf("%c", mapa[i][j]);
			
		}
		printf("\n");
	}*/
	testaCaminho(&mapa, posX - 1, posY - 1,  tamX, tamY, &tesouros);
/*
	for(i = 0; i < tamY; i++){

		for(j = 0; j < tamX; j++){

			printf("%c", mapa[i][j]);
			
		}
		printf("\n");
	}*/
	for(i = 0; i < 26; i++){
		if(tesouros[i]){
			printf("%c", i + 'a');
			achouTesouro = 1;
		}
	}

	if(!achouTesouro)
		printf("no treasures");
	//system("PAUSE");
	return 0;
	
}