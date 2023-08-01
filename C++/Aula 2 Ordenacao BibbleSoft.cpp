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
int temp;
int troquei;

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
	
	//ordenacao propriamente dita BUBBLESOFT
	troquei = 1;
	while(troquei) {
		troquei = 0;
		
		for (i = 0 ; i<9999 ; i++){
			if (vetor[i] > vetor[i + 1]){
				temp = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i+1] = temp;
				troquei = 1;	
			}
		}
	}
	
		//Print do vetor dnv
	for (i=0 ; i<10000 ; i++){
		printf("%d\n", vetor[i]);
	}
}
