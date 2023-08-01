//////////////////////////////
/////ORDENACAO DIRETA/////////
//////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////
/////Variaveis desclaradas/////////
///////////////////////////////////

int vetor[10000];
int i = 0;
int j = 0;
time_t t;

//////////////////////////////////////////////////////
/////Funcao principal de execucao de programa/////////
//////////////////////////////////////////////////////

int main() {
	//Inicializacao da aleatoriedade
	srand((unsigned) time(&t));
	
	//Inicializacao do do vetor
	for (i=0 ; i<10000 ; i++){
		vetor[i] = (rand() % 10000);
	}
	
	//Print do vetor
	for (i=0 ; i<10000 ; i++){
		printf("%d\n", vetor[i]);
	}
	
	//ordenacao propriamente dita
	for(i=0 ;i<9999 ; i++) { //DO PRIMEIRO AO PENULTIMO
		for (j = (i+1) ; j < 10000 ; j++){ //DO PROXIMO AO ULTIMO
			if (vetor[j] < vetor[i]) {
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
		//Print do vetor dnv
	for (i=0 ; i<10000 ; i++){
		printf("%d\n", vetor[i]);
	}
}
