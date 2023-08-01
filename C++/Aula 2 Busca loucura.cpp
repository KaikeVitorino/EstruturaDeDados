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
time_t t;
int busca;
int achei;

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
	
	//Definicao pesquisa
	printf("Digite um numero  a ser buscado: ");
	scanf("%d", &busca);
	
	//Busca propriamente dita
	achei = -1;
	for(i=0 ; i<10000 ; i++){
		if(vetor[i] == busca){
			achei = i;
		
		}
	}
	
	if (achei == -1){
		printf("Se fodeu! Nn existe");
	} else {
		printf("Achei na posicao %d", achei);
	}
}
