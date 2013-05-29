#include <stdio.h>

int main(){

	int tempo[1000];
	int maximoEventos, numeroEventos;
	int inicioEvento, fimEvento;
	int maximoAtingido = 0;
	int i,j;

	for(i = 0; i < 1000; i++){

		tempo[i] = 0;

	}

	scanf("%d %d", &numeroEventos, &maximoEventos);

	for(i = 0; i < numeroEventos && maximoAtingido == 0; i++){

		scanf("%d %d", &inicioEvento, &fimEvento);

		for(j = inicioEvento; j <= fimEvento && maximoAtingido == 0; j++){

			tempo[j]++;

			if(tempo[j] > maximoEventos){
				maximoAtingido = 1;
				printf("No tempo %d vai haver mais do que %d eventos ao mesmo tempo. Recuse clientes.", inicioEvento, maximoEventos);
			}
		}

	}

	if(maximoAtingido == 0)
		printf("Pode aceitar todos os clientes!");

	//system("PAUSE");
	return 0;

}