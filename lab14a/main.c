/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 14a
*/

#include <stdio.h>
#include <string.h>

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
	if(qtdeNumeros == qtdePosicoesUsadas){
		if(resultadoAtual == resultadoDesejado)
			return 1;
		else
			return 0;
	} else {
		for(i = 0; i < qtdeNumeros; i++){
			if(!numeroNoVetor(*posicoesUsadas, qtdePosicoesUsadas, i)){
				(*posicoesUsadas)[qtdePosicoesUsadas] = i;
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual + numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual - numeros[i], resultadoDesejado);
				resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual * numeros[i], resultadoDesejado);
				if(numeros[i] != 0)
					resultadoCerto += testaExpressao(numeros, qtdeNumeros, qtdePosicoesUsadas + 1, posicoesUsadas, resultadoAtual / numeros[i], resultadoDesejado);

			}
		}
	}
	return resultadoCerto;

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
			
		posicoesUsadas[0] = i;
		qtdeResultados += testaExpressao(numeros, qtdeNumeros, 1, &posicoesUsadas, numeros[i], resultadoAvaliacao);

	}

	printf("Existem %d expressoes.", qtdeResultados);

	return 0;

}