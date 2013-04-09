/*	Seu nome
	RA: Seu RA
	Turma: Sua turma
	Lab 05b
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
	
	char m[140], p[140], mAtual;

	int minusculoParaMaiusculo = 'a' - 'A';

	int tamP, tamM, i, j, pos, soma, achou, error;
	gets(p);
	tamP = strlen(p);
	
	for( i = 0; i < tamP; i++)
		if(p[i] > 'Z')
			p[i] = p[i] - minusculoParaMaiusculo;

	gets(m);
	tamM = strlen(m);
	
	pos = 0;
	achou = 0;
	error = 1;
//	printf("tamP: %d tamM: %d\n", tamP, tamM);

	for( i = 0; i < tamM; i++){
//		printf("%d (%c) - %d (%c), %d/%d\n",pos, m[pos], i, m[i], i-pos,tamP);
		if( i - pos == tamP ){

			mAtual = m[pos];
			if(mAtual > 'Z')
				mAtual = mAtual - minusculoParaMaiusculo;

			soma = (mAtual - p[0]);
			if(soma < 0)
				soma += 26;

			achou = 1;
			for(j = 1; j < tamP; j++){
				
				
				mAtual = m[j + pos];
				if(mAtual > 'Z')
					mAtual = mAtual - minusculoParaMaiusculo;
				
				mAtual -= soma;

				if(mAtual > 'Z')
					mAtual -= 26;
				else if(mAtual < 'A')
					mAtual += 26;

					//printf("%d: %c == %c (%d / %d)\n", j + pos, mAtual, p[j], soma, (mAtual - p[j]));

				if( mAtual != p[j] )
					achou = 0;
				
			}

			if(achou == 1) {

	//printf("%d %c %d\n", pos, m[pos], achou);
				for(j = 0; j < tamM; j++){

					mAtual = m[j];

					if((mAtual >= 'A' && mAtual <='Z') || (mAtual >= 'a' && mAtual <='z')){
						mAtual -= soma;
						if(( m[j] <= 'Z' && mAtual > 'Z') || mAtual > 'z')
							mAtual -= 26;
						else if(mAtual < 'A' || (m[j] >= 'a' && mAtual < 'a'))
							mAtual += 26;
					}
					printf("%c", mAtual);

				}

				printf("\n");
				
				error = 0;

			}

			pos++;

		}
		
	}
	
	if(error == 1)
		printf("ERROR\n");

	return 0;

}