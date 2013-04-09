/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 05a
*/

#include <stdio.h>

int main (){

	/* n -> número de elementos na sequencia */
	/* i -> contador temporário para for's */
	/* atual -> elemento da sequencia lido no momento */
	/* anterior -> elemento lido anteriormente */
	/* dif -> diferença entre atual e anterior */
	/* esfinge -> se é esfinge, então 1, se não, 0 */
	/* cont -> contador da sequencia */
	/* diferencas -> cada posição representa um valor de diferença, se ela já apareceu, valor é 1, se não, valor é 0 */
	int n, i, atual, anterior, dif, esfinge, cont, diferencas[1000];
	cont = 0;
	
	/* enquanto ler N e N for diferente de 0 */
	while(scanf("%d", &n) && n != 0){
		
		/* sobe contador de sequencia */
		cont++;

		/* reseta para condições iniciais */
		esfinge = 1;
		for(i = 0; i < 1000; i++)
			diferencas[i] = 0;

		/* lê o primeiro elemento da sequencia para sempre se ter um anterior */
		scanf("%d", &anterior);

		/* para cada elemento seguinte */
		for(i = 1; i < n; i++){

			/* lê o elemento */
			scanf("%d", &atual);
			
			/* se ainda for uma sequencia de esfinge, verifica se obedece os critérios, caso contrário não é necessário fazer verificação nenhuma */
			if(esfinge == 1) {
				
				/* diferença entre atual e anterior */
				dif = atual-anterior;

				/* valor absoluto */
				if(dif < 0)
					dif = -dif;

				/* se a a diferença não está entre 1 e n-1 ou já apareceu antes, deixou de ser sequencia de esfinge */
				if(dif > n - 1 || dif == 0 || diferencas[dif] == 0){
					
					/* não é mais sequencia da esfinge */
					esfinge = 0;

					/* imprime onde deixou de ser esfinge */
					printf("Sequence %d is not a Sphinx's Sequence because of elements %d (value %d) and %d (value %d).\n", cont, i, anterior, i+1, atual);

				} 
				else /* se obedecer, marca a diferença como já apareceu */
					diferencas[dif] = 1;

			}

			/* para a próxima leitura, o anterior é o atual */
			anterior = atual;

		}

		if(esfinge == 1) /* se em nenhum ponto deixou de ser esfinge, imprime na tela que é esfinge */
			printf("Sequence %d is a Sphinx's Sequence!\n", cont);
	
	}

	return 0;

}