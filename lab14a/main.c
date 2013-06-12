/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 14a
*/

#include <stdio.h>
#include <string.h>

// Verifica se o int numero esta no vetor numeros, retorna 1 caso verdadeiro
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
	
	if(qtdeNumeros == qtdePosicoesUsadas){ // Ja testou todos os numeros

		if(resultadoAtual == resultadoDesejado) // eh o resultado? se sim, retorna 1, se nao 0
			return 1;
		else
			return 0;

	} else { // ainda tem numeros pra testar

		for(i = 0; i < qtdeNumeros; i++){

			if(!numeroNoVetor(*posicoesUsadas, qtdePosicoesUsadas, i)){ // ja usamos o numero que esta na posiçao i do vetor numeros? se nao, usamos ele

				(*posicoesUsadas)[qtdePosicoesUsadas] = i; // marcamos a posicao i como usada

				// roda novamente com com o numero usado, somando a quantidade de expressões certas achadas
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual + numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual - numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual * numeros[i], resultadoDesejado);
				if(numeros[i] != 0) // nao da para dividir por 0
					resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual / numeros[i], resultadoDesejado);

			}

		}

	}

	return resultadoCerto; // retorna a quantidade de expressoes achadas 

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
		
		// para cada numero, comeca a testar tendo ele como primeiro numero usado e soma a quantidade de expressoes certas
		posicoesUsadas[0] = i;
		qtdeResultados += testaExpressao(numeros, qtdeNumeros, 1, &posicoesUsadas, numeros[i], resultadoAvaliacao);

	}

	printf("Existem %d expressoes.", qtdeResultados);

	return 0;

}