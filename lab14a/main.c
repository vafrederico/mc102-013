/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 14a
*/

#include <stdio.h>
#include <string.h>

// Verifica se o int numero está no vetor numeros, retorna 1 caso verdadeiro
int numeroNoVetor(int numeros[], int qtdeNumeros, int numero){

	int i;
	for(i = 0; i < qtdeNumeros; i++){
		if(numero == numeros[i])
			return 1;
	}

	return 0;

}

int testaExpressao(int numeros[], int qtdeNumeros, int qtdePosicoesUsadas, int (*posicoesUsadas)[6], int resultadoAtual, int resultadoDesejado){

	int i, resultadoCerto = 0;
	
	if(qtdeNumeros == qtdePosicoesUsadas){ // Já testou todos os números

		if(resultadoAtual == resultadoDesejado) // é o resultado? se sim, retorna 1, se não 0
			return 1;
		else
			return 0;

	} else { // ainda tem números pra testar

		for(i = 0; i < qtdeNumeros; i++){

			if(!numeroNoVetor(*posicoesUsadas, qtdePosicoesUsadas, i)){ // já usamos o número que está na posição i do vetor números? se não, usamos ele

				(*posicoesUsadas)[qtdePosicoesUsadas] = i; // marcamos a posição i como usada

				// roda novamente com com o número usado, somando a quantidade de expressões certas achadas
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual + numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual - numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual * numeros[i], resultadoDesejado);
				if(numeros[i] != 0) // não dá para dividir por 0
					resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual / numeros[i], resultadoDesejado);

			}

		}

	}

	return resultadoCerto; // retorna a quantidade de expressões achadas

}

int main(int argc, char *argv[]) {

	int qtdeNumeros;
	int resultadoAvaliacao;

	int numeros[6];
	int i;
	int posicoesUsadas[6];
	int qtdeResultados = 0;

	scanf("%d %d", &qtdeNumeros, &resultadoAvaliacao);

	for(i = 0; i < qtdeNumeros; i++){
		scanf("%d", &numeros[i]);
	}

	for(i = 0; i < qtdeNumeros; i++){
		
		// para cada número, começa a testar tendo ele como primeiro número usado e soma a quantidade de expressões certas
		posicoesUsadas[0] = i;
		qtdeResultados += testaExpressao(numeros, qtdeNumeros, 1, &posicoesUsadas, numeros[i], resultadoAvaliacao);

	}

	printf("Existem %d expressoes.", qtdeResultados);

	return 0;

}