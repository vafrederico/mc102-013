/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 05b
*/

#include <stdio.h>
int main (){
	
	/*
	m -> texto m lido da entrada
	p -> texto p lido da entrada
	mAtual -> caractere de m sendo utilizado no momento
	minusculoParaMaiusculo -> valor subtraido de uma caractere minuscula para virar maiuscula (tabela ASCII)
	tamP -> tamanho de p
	tamM -> tamanho de M
	i, j -> contadores
	pos -> posi��o de �n�cio de um bloco de caracteres a serem testados
	soma -> o quanto foi somado entre as primeiras caracteres de p e do bloco de texto de m, para se descifrar a mensagem
	achou -> se achou um jeito de descifrar, 1, se n�o, 0
	error -> se n�o achou nenhum jeito, 1, se n�o, 0
	 */
	char m[140], p[140], mAtual;
	int minusculoParaMaiusculo = 'a' - 'A';
	int tamP, tamM, i, j, pos, soma, achou, error;

	for( i = 0; i < 140; i++ ){ // Reseta m e p
		m[i] = '\0';
		p[i] = '\0';
	}

	/* L� p */
	gets(p);

	/* L� m */
	gets(m);
	
	/* tamanho = -1 para saber se j� foi determinado */
	tamP = -1;
	tamM = -1;
	for( i = 0; i < 140 ; i++){

		if(m[i] == '\0' && tamM == -1) // se � um caractere n�o escrito por cima de \0 e n�o foi determinado o tamanho
			tamM = i;
	
		if(p[i] == '\0' && tamP == -1) // se � um caractere n�o escrito por cima de \0 e n�o foi determinado o tamanho
			tamP = i;

	}

	/* Converte toda min�scula em p (p[i] > 'Z') para mai�scula para facilitar */
	for( i = 0; i < tamP; i++)
		if(p[i] > 'Z')
			p[i] = p[i] - minusculoParaMaiusculo;

	/* no come�o, o bloco de texto a se comparar est� no 0, n se achou nenhum jeito */
	pos = 0;
	achou = 0;
	error = 1;

	for( i = 0; i < tamM; i++){ /* para cada caractere de M (percorrer m de ponta a ponta) */
		if( i - pos == tamP ){ /* se temos o bloco de texto entre pos e i tem o tamanho de p, verificamos se � um jeito de descifrar */

			/* O bloco de texto come�a em m[pos] e termina em m[i]; */
			/* Obt�m-se o valor da diferen�a entre o primeiro caractere do bloco de texto (passado para mai�sculo) e de p */
			
			/* Converte o primeira caractere do bloco de texto para mai�scula caso seja min�scula */
			mAtual = m[pos];
			if(mAtual > 'Z')
				mAtual = mAtual - minusculoParaMaiusculo;

			/* Obtemos a diferen�a entre os caracteres */
			soma = (mAtual - p[0]);
			/* Se for negativo, d� a volta no alfabeto */
			if(soma < 0)
				soma += 26;

			/* Marca como achado um jeito de decifrar */
			achou = 1;

			for(j = 1; j < tamP; j++){ /* para cada caractere de P e do bloco de texto a partir da segunda caractere */
				
				/* pega o caractere no bloco de texto */
				mAtual = m[j + pos];

				/* converte para mai�scula */
				if(mAtual > 'Z')
					mAtual = mAtual - minusculoParaMaiusculo;
				
				/* usamos a diferen�a entre caracteres obtida anteriormente para decifrar este caractere */
				mAtual = mAtual - soma;

				/* D� a volta no alfabeto caso necess�rio */
				if(mAtual > 'Z')
					mAtual -= 26;
				else if(mAtual < 'A')
					mAtual += 26;

				/* Se o caractere decifrado n�o � igual o caractere em p, n�o � um jeito de decifrar. */
				if( mAtual != p[j] )
					achou = 0;
				
			}

			/* Se realmente � um jeito de decifrar */
			if(achou == 1) {

				for(j = 0; j < tamM; j++){ /* para cada caractere de m */

					/* pegamos o caractere */
					mAtual = m[j];

					/* se o caractere � letra, deciframos */
					if((mAtual >= 'A' && mAtual <='Z') || (mAtual >= 'a' && mAtual <='z')){

						/* decifra o caractere */
						mAtual -= soma;

						/* d� a volta no alfabeto caso necess�rio */
						if(( m[j] <= 'Z' && mAtual > 'Z') || mAtual > 'z')
							mAtual -= 26;
						else if(mAtual < 'A' || (m[j] >= 'a' && mAtual < 'a'))
							mAtual += 26;

					}

					/* imprimimos o caractere */
					printf("%c", mAtual);

				}

				/* ao final do texto decifrado, quebramos a linha */
				printf("\n");
				
				/* como achamos um jeito de decifrar, marca que n�o h� erro de decifra��o */
				error = 0;

			}

			/* o bloco come�a uma posi��o a frente, assim verificando cada bloco de texto de tamanho igual ao tamanho de p */
			pos++;

		}
		
	}
	
	/* Se n�o achar nenhum jeito de decifrar, error continuar� como 1, logo imprimimos ERROR */
	if(error == 1)
		printf("ERROR\n");

	return 0;

}