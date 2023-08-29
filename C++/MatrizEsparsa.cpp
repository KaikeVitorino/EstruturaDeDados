////////////////////////////////////////////////
// Programa QUE IMPLEMENTA UMA MATRIZ ESPARSA //
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////
// Declarando a estrutura //
////////////////////////////

const int CONGRUENCIA_MODULO = 5; //Esta constante será usada posteriormente para calcular o resto da divisão.

////////////////////////////
// Declarando a estrutura //
////////////////////////////

//Um numero sera dividito por um modulo e sera posto na lista em que seu resto bater
//Ex: 5 % 5 = resto 0, ent ele sera posto na lista 0
//Ex2; 6 % 5 = resto 1, ent ele seta posto na lista 1

struct no{
	int numero;
	struct no *proximoNo;
};

struct diretor {
	int resto; //Resto de uma divisao, no caso vai ser por 5
	struct no *proximoNo;
	struct diretor *proximoDiretor;
};

/////////////////////////////
// Declaracao de variaveis //
/////////////////////////////

struct diretor *cabeca = NULL;

//////////////////////////////////////////////////
// Funcao para proxurar ou criar um novo diretor//
//////////////////////////////////////////////////

struct diretor* procurarOuCriarDiretor(int restoProcurado) {
    // Procura o diretor com o mesmo resto.
    struct diretor *ponteiro = cabeca;
    
    while ((ponteiro != NULL) && (ponteiro -> resto != restoProcurado)){
        ponteiro = ponteiro -> proximoDiretor;
    }
    
    // Se o diretor foi encontrado, retorna o ponteiro.
    if(ponteiro == NULL){
        // Se o diretor não foi encontrado, cria um novo.
    	struct diretor* novoDiretor = (struct diretor*) malloc(sizeof(struct diretor));
    	novoDiretor->resto = restoProcurado;
    	novoDiretor->proximoNo = NULL;
    	novoDiretor->proximoDiretor = cabeca;
    	cabeca = novoDiretor;

    	return novoDiretor; // Retorna o novo diretor.
    }

}

// Esta função cria um novo 'diretor'. 
// Ela aloca memória para um novo 'diretor', atribui o valor do 'resto' e 
// inicializa os ponteiros 'proximoNo' e 'proximoDiretor' como NULL.

////////////////////////////////
// Funcao para criar um novo no//
////////////////////////////////

struct no* novoNo(int numero) {
    struct no* novoNo = (struct no*) malloc(sizeof(struct no));
    novoNo->numero = numero;
    novoNo->proximoNo = NULL;
    return novoNo;
}

// Esta função cria um novo 'no'. 
// Ela aloca memória para um novo 'no', atribui o valor do 'numero' e inicializa o ponteiro 'proximoNo' como NULL.

////////////////////////////////////////////////
/// declarandoumas coisas q estavama faltando///
////////////////////////////////////////////////
struct diretor* criarNovoDiretor(int resto) {
    // Allocate memory for new node
    struct diretor* novoDiretor = (struct diretor*) malloc(sizeof(struct diretor));

    // Assign data to new node
    novoDiretor->resto = resto;
    novoDiretor->proximoNo = NULL;
    novoDiretor->proximoDiretor = NULL;

    return novoDiretor;
}

struct no* criarNovoNo(int numero) {
    // Allocate memory for new node
    struct no* novoNo = (struct no*) malloc(sizeof(struct no));

    // Assign data to new node
    novoNo->numero = numero;
    novoNo->proximoNo = NULL;

    return novoNo;
}

//////////////////////////////////////////////
// Funcao para adicionar um numero na lista //
//////////////////////////////////////////////

void inserir(int numero) {
    int resto = numero % CONGRUENCIA_MODULO; // Calcula o resto da divisão do número pelo módulo de congruência.
    
    struct diretor* diretorAtual = cabeca; // Cria um ponteiro para percorrer a lista de diretores.
    
    // Procura o diretor com o mesmo resto.
    while (diretorAtual != NULL && diretorAtual->resto != resto) {
        diretorAtual = diretorAtual->proximoDiretor;
    }
    
    // Se o diretor não foi encontrado, cria um novo e adiciona na lista.
    if (diretorAtual == NULL) {
        struct diretor* novoDiretor = criarNovoDiretor(resto);
        novoDiretor->proximoDiretor = cabeca;
        cabeca = novoDiretor;
        diretorAtual = novoDiretor;
    }
    
    // Cria um novo nó e adiciona na lista do diretor.
    struct no* novoNo = criarNovoNo(numero);
    novoNo->proximoNo = diretorAtual->proximoNo;
    diretorAtual->proximoNo = novoNo;
}


// Esta função adiciona um número na lista esparça. 
// Ela calcula o resto da divisão do número pelo módulo de congruência, procura o 'diretor' com o mesmo resto, 
// se não encontrar, cria um novo 'diretor' e adiciona na lista. Depois, cria um novo 'no' e adiciona na lista do 'diretor'.

//////////////////////////////////////////////
// Funcao para dar print na matriz esparsa//
//////////////////////////////////////////////

void imprimir() {
    struct diretor* diretorAtual = cabeca; // Cria um ponteiro para percorrer a lista de diretores.
    
    // Percorre a lista de diretores
    printf("=========================\n");
	printf("Resto\n");

    while (diretorAtual != NULL) {
        printf("%d->\t\a ", diretorAtual->resto);
        
        struct no *ponteiroNo = diretorAtual->proximoNo; // Cria um ponteiro para percorrer a lista de nós do diretor atual.
        
        // Percorre a lista de nós do diretor atual.
        while (ponteiroNo != NULL) {
            printf("%d\t ", ponteiroNo->numero);
            ponteiroNo = ponteiroNo->proximoNo;
        }
        
        printf("\n");
        diretorAtual = diretorAtual->proximoDiretor;
    }
}

////////////////////////////////////////////
// Funcao que remove um elemento da lista //
//////////////////////////////////////////// DiretorCrto = proximoDiretor

void remover(int parametroNumero){
    struct diretor* diretorAtual = cabeca; 
    struct no *ponteiroAnterior;
    struct no *ponteiroExcluir;
    
    while (diretorAtual != NULL && diretorAtual->resto != parametroNumero % CONGRUENCIA_MODULO) {
        diretorAtual = diretorAtual->proximoDiretor;
    }
    
    
    if (diretorAtual == NULL) {
        printf("Numero nn encontrado na matriz.\n");
        return;
    }

    if (diretorAtual -> proximoNo != NULL) {
        if (diretorAtual -> proximoNo -> numero == parametroNumero) {
            ponteiroExcluir = diretorAtual -> proximoNo;
            diretorAtual -> proximoNo = diretorAtual -> proximoNo -> proximoNo;
            free(ponteiroExcluir);
        } else {
            ponteiroAnterior = diretorAtual -> proximoNo;
            while ((ponteiroAnterior -> proximoNo != NULL) &&
                    (ponteiroAnterior -> proximoNo -> numero != parametroNumero)){
                ponteiroAnterior = ponteiroAnterior -> proximoNo;
                
            } 
            if (ponteiroAnterior -> proximoNo != NULL) {
                ponteiroExcluir = ponteiroAnterior -> proximoNo;
                ponteiroAnterior -> proximoNo = ponteiroExcluir -> proximoNo;
                free(ponteiroExcluir);
            }
        }
    }
}

//////////////////////////////////////////////
// Funcao principal de execucao do programa //
//////////////////////////////////////////////

int main(){
	int i = 0;
	
	for (i = 0 ; i < 10 ; i++){
		inserir(i);
	}
	
	imprimir();
	
	remover(7);
	
	imprimir();
}



