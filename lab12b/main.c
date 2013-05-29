/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 06b
*/

#include <stdio.h>
#include <string.h>

typedef struct {

	char nome[30];
	int MaxClockSpeed;
	int MaxBusSpeed;
	int IntroductionYear;
	int TransistorCount;
	int DataWidth;
	int ManufacturingProcess;
	int DieSize;
	int MaxTDP;

} carta;

void subirCartas(carta (*Pilha)[30], int qtde){

	int i;
	for(i = 0; i < qtde; i++){

		*Pilha[i] = *Pilha[i + 1];
	}

}

int main(int argc, char *argv[]) {

    char nomearqin[20], nomearqout[20];

	carta Me[30];
	carta Jose[30];
	int qtdeCartaMe;
	int qtdeCartaJose;
 	int vezDeJogar;
 	int rodadasJogadas;
 	int caracteristica;
 	int ganhador;
	int i;
	FILE* fEntrada = fopen(nomearqin, "rb");
	FILE* fSaida = fopen(nomearqout, "wb");

    strcpy(nomearqin, argv[1]);
    strcpy(nomearqout, argv[2]);
    
	fscanf(fEntrada, "%d %d %d", &qtdeCartaMe, &qtdeCartaJose, &vezDeJogar);
	printf("\n ------------------------------------------------------------- \n");
	for(i = 0; i < qtdeCartaMe; i++){
		fscanf(fEntrada, "%s %d %d %d %d %d %d %d %d", Me[i].nome, &(Me[i]).MaxClockSpeed, &(Me[i]).MaxBusSpeed, &(Me[i]).IntroductionYear, &(Me[i]).TransistorCount, &(Me[i]).DataWidth, &(Me[i]).ManufacturingProcess, &(Me[i]).DieSize, &(Me[i]).MaxTDP);
		printf("%s %d %d %d %d %d %d %d %d\n", Me[i].nome, Me[i].MaxClockSpeed, Me[i].MaxBusSpeed, Me[i].IntroductionYear, Me[i].TransistorCount, Me[i].DataWidth, Me[i].ManufacturingProcess, Me[i].DieSize, Me[i].MaxTDP);
	}
	printf("\n ------------------------------------------------------------- \n");
	for(i = 0; i < qtdeCartaJose; i++){
		fscanf(fEntrada, "%s %d %d %d %d %d %d %d %d", Jose[i].nome, &Jose[i].MaxClockSpeed, &Jose[i].MaxBusSpeed, &Jose[i].IntroductionYear, &Jose[i].TransistorCount, &Jose[i].DataWidth, &Jose[i].ManufacturingProcess, &Jose[i].DieSize, &Jose[i].MaxTDP);
		//printf("%s %d %d %d %d %d %d %d %d\n", Jose[i].nome, Jose[i].MaxClockSpeed, Jose[i].MaxBusSpeed, Jose[i].IntroductionYear, Jose[i].TransistorCount, Jose[i].DataWidth, Jose[i].ManufacturingProcess, Jose[i].DieSize, Jose[i].MaxTDP);
	}

	scanf("%d", &rodadasJogadas);
	for(i = 0; i < rodadasJogadas; i++){
		printf("\n ------------------------------------------------------------- \n");
		scanf("%d", &caracteristica);
		//printf("%s %d %d %d %d %d %d %d %d\n", Me[0].nome, Me[0].MaxClockSpeed, Me[0].MaxBusSpeed, Me[0].IntroductionYear, Me[0].TransistorCount, Me[0].DataWidth, Me[0].ManufacturingProcess, Me[0].DieSize, Me[0].MaxTDP);
		//printf("%s %d %d %d %d %d %d %d %d\n", Jose[0].nome, Jose[0].MaxClockSpeed, Jose[0].MaxBusSpeed, Jose[0].IntroductionYear, Jose[0].TransistorCount, Jose[0].DataWidth, Jose[0].ManufacturingProcess, Jose[0].DieSize, Jose[0].MaxTDP);
		switch(caracteristica){

			case 1:
				if(Me[0].MaxClockSpeed > Jose[0].MaxClockSpeed)
					ganhador = 1;
				else ganhador = 2;
				break;
			case 2:
				if(Me[0].MaxBusSpeed > Jose[0].MaxBusSpeed)
					ganhador = 1;
				else ganhador = 2;
				break;
			case 3:
				if(Me[0].IntroductionYear < Jose[0].IntroductionYear)
					ganhador = 1;
				else ganhador = 2;
				break;
			case 4:
				if(Me[0].TransistorCount > Jose[0].TransistorCount)
					ganhador = 1;
				else ganhador = 2;
				break;
			case 5:
				if(Me[0].DataWidth > Jose[0].DataWidth)
					ganhador = 1;
				else ganhador = 2;
				break;
			case 6:
				if(Me[0].ManufacturingProcess < Jose[0].ManufacturingProcess)
					ganhador = 1;
				else ganhador = 2;
				break;
			case 7:
				if(Me[0].DieSize < Jose[0].DieSize)
					ganhador = 1;
				else ganhador = 2;
				break;
			case 8:
				if(Me[0].MaxTDP < Jose[0].MaxTDP)
					ganhador = 1;
				else ganhador = 2;
				break;

		}

		printf("%d\n", ganhador);
		if(ganhador == 1) {

			Me[qtdeCartaMe] = Me[0];
			Me[qtdeCartaMe+1] = Jose[0];
			qtdeCartaMe++;
			qtdeCartaJose--;

		} else {

			Jose[qtdeCartaJose] = Jose[0];
			Jose[qtdeCartaJose+1] = Me[0];
			qtdeCartaMe--;
			qtdeCartaJose++;

		}

		subirCartas(&Me, qtdeCartaMe);
		subirCartas(&Jose, qtdeCartaJose);

	}

	if(rodadasJogadas % 2 != 0){
		if(vezDeJogar == 1)
			vezDeJogar = 2;
		else
			vezDeJogar = 1;
	}

	printf("\n ------------------------------------------------------------- \n");
	fprintf(fSaida, "%d %d %d\n", qtdeCartaMe, qtdeCartaJose, vezDeJogar);
	//printf("%d %d %d\n", qtdeCartaMe, qtdeCartaJose, vezDeJogar);
	for(i = 0; i < qtdeCartaMe; i++){
		fprintf(fSaida, "%s %d %d %d %d %d %d %d %d\n", Me[i].nome, Me[i].MaxClockSpeed, Me[i].MaxBusSpeed, Me[i].IntroductionYear, Me[i].TransistorCount, Me[i].DataWidth, Me[i].ManufacturingProcess, Me[i].DieSize, Me[i].MaxTDP);
		//printf("%s %d %d %d %d %d %d %d %d\n", Me[i].nome, Me[i].MaxClockSpeed, Me[i].MaxBusSpeed, Me[i].IntroductionYear, Me[i].TransistorCount, Me[i].DataWidth, Me[i].ManufacturingProcess, Me[i].DieSize, Me[i].MaxTDP);
	}
	for(i = 0; i < qtdeCartaJose; i++){
		fprintf(fSaida, "%s %d %d %d %d %d %d %d %d\n", Jose[i].nome, Jose[i].MaxClockSpeed, Jose[i].MaxBusSpeed, Jose[i].IntroductionYear, Jose[i].TransistorCount, Jose[i].DataWidth, Jose[i].ManufacturingProcess, Jose[i].DieSize, Jose[i].MaxTDP);
		//printf("%s %d %d %d %d %d %d %d %d\n", Jose[i].nome, Jose[i].MaxClockSpeed, Jose[i].MaxBusSpeed, Jose[i].IntroductionYear, Jose[i].TransistorCount, Jose[i].DataWidth, Jose[i].ManufacturingProcess, Jose[i].DieSize, Jose[i].MaxTDP);
	}

	return 0;

}