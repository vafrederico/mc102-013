/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 14a
*/

#include <stdio.h>
#include <string.h>

// Verifica se o int numero est� no vetor numeros, retorna 1 caso verdadeiro
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
	
	if(qtdeNumeros == qtdePosicoesUsadas){ // J� testou todos os n�meros

		if(resultadoAtual == resultadoDesejado) // � o resultado? se sim, retorna 1, se n�o 0
			return 1;
		else
			return 0;

	} else { // ainda tem n�meros pra testar

		for(i = 0; i < qtdeNumeros; i++){

			if(!numeroNoVetor(*posicoesUsadas, qtdePosicoesUsadas, i)){ // j� usamos o n�mero que est� na posi��o i do vetor n�meros? se n�o, usamos ele

				(*posicoesUsadas)[qtdePosicoesUsadas] = i; // marcamos a posi��o i como usada

				// roda novamente com com o n�mero usado, somando a quantidade de express�es certas achadas
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual + numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual - numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual * numeros[i], resultadoDesejado);
				if(numeros[i] != 0) // n�o d� para dividir por 0
					resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual / numeros[i], resultadoDesejado);

			}

		}

	}

	return resultadoCerto; // retorna a quantidade de express�es achadas

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
		
		// para cada n�mero, come�a a testar tendo ele como primeiro n�mero usado e soma a quantidade de express�es certas
		posicoesUsadas[0] = i;
		qtdeResultados += testaExpressao(numeros, qtdeNumeros, 1, &posicoesUsadas, numeros[i], resultadoAvaliacao);

	}

	printf("Existem %d expressoes.", qtdeResultados);

	return 0;

}