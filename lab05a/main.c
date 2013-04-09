/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 05a
*/

#include <stdio.h>

int main (){

	/* n -> n�mero de elementos na sequencia */
	/* i -> contador tempor�rio para for's */
	/* atual -> elemento da sequencia lido no momento */
	/* anterior -> elemento lido anteriormente */
	/* dif -> diferen�a entre atual e anterior */
	/* esfinge -> se � esfinge, ent�o 1, se n�o, 0 */
	/* cont -> contador da sequencia */
	/* diferencas -> cada posi��o representa um valor de diferen�a, se ela j� apareceu, valor � 1, se n�o, valor � 0 */
	int n, i, atual, anterior, dif, esfinge, cont, diferencas[1000];
	cont = 0;
	
	/* enquanto ler N e N for diferente de 0 */
	while(scanf("%d", &n) && n != 0){
		
		/* sobe contador de sequencia */
		cont++;

		/* reseta para condi��es iniciais */
		esfinge = 1;
		for(i = 0; i < 1000; i++)
			diferencas[i] = 0;

		/* l� o primeiro elemento da sequencia para sempre se ter um anterior */
		scanf("%d", &anterior);

		/* para cada elemento seguinte */
		for(i = 1; i < n; i++){

			/* l� o elemento */
			scanf("%d", &atual);
			
			/* se ainda for uma sequencia de esfinge, verifica se obedece os crit�rios, caso contr�rio n�o � necess�rio fazer verifica��o nenhuma */
			if(esfinge == 1) {
				
				/* diferen�a entre atual e anterior */
				dif = atual-anterior;

				/* valor absoluto */
				if(dif < 0)
					dif = -dif;

				/* se a a diferen�a n�o est� entre 1 e n-1 ou j� apareceu antes, deixou de ser sequencia de esfinge */
				if(dif > n - 1 || dif == 0 || diferencas[dif] == 0){
					
					/* n�o � mais sequencia da esfinge */
					esfinge = 0;

					/* imprime onde deixou de ser esfinge */
					printf("Sequence %d is not a Sphinx's Sequence because of elements %d (value %d) and %d (value %d).\n", cont, i, anterior, i+1, atual);

				} 
				else /* se obedecer, marca a diferen�a como j� apareceu */
					diferencas[dif] = 1;

			}

			/* para a pr�xima leitura, o anterior � o atual */
			anterior = atual;

		}

		if(esfinge == 1) /* se em nenhum ponto deixou de ser esfinge, imprime na tela que � esfinge */
			printf("Sequence %d is a Sphinx's Sequence!\n", cont);
	
	}

	return 0;

}