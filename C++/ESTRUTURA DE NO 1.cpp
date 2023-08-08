//  '*' DECLARA O PONTEIRO E O PONTEIRO APONTA PARA OUTRO ENDERECO
//int*Ponteiro;

// '&' ENDERECA A VARIAVEL NORMAL (Nn para o ponteiro)
//char *c;
//&c = c;

// malloc = memory allocation = abre uma area de memoria
// malloc(sizeof(struct no *));

// Para apontar um ponteiro para um numero, por uma seta ->
// cabeca -> numero = 10;
// cabeca -> proximo = NULL;

//Teste 1
//	cabeca = (struct no *) malloc(sizeof(struct no *));
//	cabeca -> numero = 10;
//	cabeca -> proximo = NULL;
//	printf("endereco do proprio ponteiro: %d\n", cabeca); //Da o endereco do proprio ponteiro
//	printf("numero/caractere q ele aponta: %d\n", cabeca -> numero); //Da o numero/caractere q ele aponta
//	printf("endereco de memoria do numero q ele aponta: %d\n", *cabeca); //Da o endereco de memoria do numero q ele aponta

//////////////////////////////////////////
// Programa de liksta encadeada simples //
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////
// Definicao da estruturado NO //
/////////////////////////////////

struct no{
	int numero;
		struct no *proximo;
};

///////////////////////
// Declarar variavel //
///////////////////////

struct no *cabeca;

//////////////////////////////////////
// Funcao que insere um NO na lista //
//////////////////////////////////////

void inserir(int parametroNumero) {
	//Criar um novo NO
		struct no *novoNo = NULL;
		novoNo = (struct no *) malloc(sizeof(struct no *));
		novoNo -> numero = parametroNumero;
		novoNo -> proximo = NULL;
		
	if (cabeca == NULL) {
		cabeca = novoNo;
	} else {
		// Procurar ultimo elemnto da lista
		struct no *ponteiro = cabeca; //Ponteiro apontando pára o msm lugar q a cabeca aponta
		while (ponteiro -> proximo != NULL) { //Ponteiro apontando para o proximo,se proximo for diferente de NULL
			ponteiro = ponteiro -> proximo;       //    ele continua ate achar o Null
		}
		
		//Apontar o ultimo para o novo
		ponteiro -> proximo = novoNo;
	}
}

////////////////////////////////////////////////
// fUNCAO que da print nos elementos da lista //
////////////////////////////////////////////////

void imprimir() {
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

////////////////////////////////////////////
// Funcao que remove um elemento da lista //
////////////////////////////////////////////

void remover(int parametroNumero){
	struct no *ponteiroAnterior;
	struct no *ponteiroExcluir;
	
	if (cabeca != NULL) {
		if (cabeca -> numero == parametroNumero) {
			ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
			free(ponteiroExcluir);
		} else {
			ponteiroAnterior = cabeca;
			while ((ponteiroAnterior -> proximo != NULL) &&
					(ponteiroAnterior -> proximo -> numero != parametroNumero)){
				ponteiroAnterior = ponteiroAnterior -> proximo;
				
			} 
			if (ponteiroAnterior -> proximo != NULL) {
				ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
				free(ponteiroExcluir);
			}
		}
	}
}

//////////////////////////////////
// fUNCAO PRINCIPAL DE EXECUCAO //
//////////////////////////////////

int main(){
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	
	remover(9);
	
	imprimir();

}

