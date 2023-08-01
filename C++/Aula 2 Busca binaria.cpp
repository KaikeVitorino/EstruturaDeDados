//////////////////////////////
/////busca binaria   /////////
//////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////
/////Variaveis desclaradas/////////
///////////////////////////////////

int vetor[10000];
int i = 0;
int inicio = 0;
int fim = 0;
int meio  = 0;
int busca = 0;

//////////////////////////////////////////////////////
/////Funcao principal de execucao de programa/////////
//////////////////////////////////////////////////////

int main() {
	//Inicializacao do do vetor
	for (i=0 ; i<10000 ; i++){
		vetor[i] = i;
	}
	
	//Definicao busca
	printf("Digite um numero  a ser buscado: ");
	scanf("%d", &busca);
	
	//Busca propriamente dita
	inicio = 0;
	fim = 9999;
	while (fim >= inicio){
		meio = ((inicio+fim)/2);
		
		if (vetor[meio == busca]){
			printf("Achei! ! !");
			return 0 ;
		} else if (vetor[meio > busca]){
			fim = (meio - 1);
		} else {
			inicio = (meio +1);
		}
	}
	printf("Se fodeu ! Nn existe !");
}
