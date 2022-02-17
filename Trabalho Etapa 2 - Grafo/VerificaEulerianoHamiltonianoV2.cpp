/*
*
*	Grafos - CICLO HAMILTONIANO em C
*	Kelvin Salton do Prado - 2015
*
*                      -----------------------------------
*                      |                                 |
*   (A)---------------(B)-------------(E)---------------(F)
*    |                 |               |                 |
*    |                 |               |                 |
*    |                 |               |                 |
*   (C)---------------(D)---------------                 |
*                      |                                 |
*                      -----------------------------------
*
*	6 Vértices
*	9 Arestas
*/

#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICES 4 // MÁXIMO DE VÉRTICES DO GRAFO, SE FOR ALTERAR O GRAFO PRECISA ALTERAR ESTA VARIÁVEL TAMBÉM
#define MAX_ARESTAS (MAX_VERTICES * (MAX_VERTICES-1)) // CALCULA O NÚMERO MÁXIMO DE ARESTAS QUE O GRAFO PODERÁ TER

using namespace std;

// Estrutura que define cada Vértice do Grafo
typedef struct NO{
	char id;
	int nroVizinhos;
	struct NO* vizinhos[MAX_ARESTAS];
	bool visitado;
}*VERTICE;

VERTICE solucao[MAX_VERTICES]; // Array que irá guardar a solução do ciclo hamiltoniano

// Cria Vértice e retorna
VERTICE criaVertice(char id){
	VERTICE novoVertice = (VERTICE) malloc( sizeof(NO) ); // Aloca um novo Vértice
	novoVertice->id = id;
	novoVertice->nroVizinhos = 0;
	novoVertice->visitado = false;
	for (int i = 0; i < MAX_ARESTAS; i++){
		novoVertice->vizinhos[i] = NULL;
	}
	return novoVertice;
}

//bool cicloEuleriano()

// Liga os vértices passados como parâmetro
bool ligaVertices(VERTICE v1, VERTICE v2){
	int aux = 0;
	while(v1->vizinhos[aux] != NULL){ // Busca a primeira posição 'vazia'(NULL) dos vizinhos
		aux++;
	}
	v1->vizinhos[aux] = v2; // Adiciona o novo vizinho a lista de vizinhos
	aux = 0;
	while(v2->vizinhos[aux] != NULL){ // Busca a primeira posição 'vazia'(NULL) dos vizinhos
		aux++;
	}
	v2->vizinhos[aux] = v1; // Adiciona o novo vizinho a lista de vizinhos
	v1->nroVizinhos++; // Incrementa o número de vizinhos
	v2->nroVizinhos++; // Incrementa o número de vizinhos
}

bool cicloHamiltonianoAuxiliar(int aux){

	if( aux == MAX_VERTICES ){
		for (int i = 0; i < solucao[aux-1]->nroVizinhos; i++){
			if( solucao[aux-1]->vizinhos[i] == solucao[0] ){
				return true;
			}
		}
		return false;
	}

	VERTICE s = solucao[aux-1]; // Auxiliar para simplificar o código

	for (int i = 0; i < s->nroVizinhos; i++){ // Percorre todos os vizinhos do vértice de posição aux-1 no array solução
		if( s->vizinhos[i]->visitado == false ){
			s->vizinhos[i]->visitado = true;
			solucao[aux] = s->vizinhos[i];
			if( cicloHamiltonianoAuxiliar(aux+1) == true ){
				return true;
			}
			s->vizinhos[i]->visitado = false;
		}
	}

	return false;
}

bool cicloHamiltoniano(VERTICE grafo[MAX_VERTICES]){
	grafo[0]->visitado = true; // Marca a posição inicial como visitada
	solucao[0] = grafo[0]; // Array que irá guardar a solução do ciclo
	return cicloHamiltonianoAuxiliar(1);
}

int main(){

    // Grafo conjunto de vértices em um array
	VERTICE GRAFO[MAX_VERTICES];
	/*GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');
	GRAFO[4] = criaVertice('E');
	GRAFO[5] = criaVertice('F');*/

	/*//N euleriano
	GRAFO[0] = criaVertice('B');
	GRAFO[1] = criaVertice('C');
	GRAFO[2] = criaVertice('D');
	GRAFO[3] = criaVertice('E');
	GRAFO[4] = criaVertice('F');
	// Liga todos os vértices de acordo com o GRAFO apresentado na introdução
	ligaVertices(GRAFO[0], GRAFO[1]);
	ligaVertices(GRAFO[1], GRAFO[4]);
	ligaVertices(GRAFO[4], GRAFO[3]);
	ligaVertices(GRAFO[3], GRAFO[0]);
	ligaVertices(GRAFO[0], GRAFO[2]);
	ligaVertices(GRAFO[1], GRAFO[2]);
	ligaVertices(GRAFO[4], GRAFO[2]);
	ligaVertices(GRAFO[3], GRAFO[2]);*/

	/*GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');
	GRAFO[4] = criaVertice('E');
	GRAFO[5] = criaVertice('F');
	GRAFO[6] = criaVertice('G');
	ligaVertices(GRAFO[0], GRAFO[1]);
	ligaVertices(GRAFO[1], GRAFO[2]);
	ligaVertices(GRAFO[2], GRAFO[3]);
	ligaVertices(GRAFO[3], GRAFO[4]);
	ligaVertices(GRAFO[4], GRAFO[5]);
	ligaVertices(GRAFO[5], GRAFO[0]);
	ligaVertices(GRAFO[1], GRAFO[5]);
	ligaVertices(GRAFO[2], GRAFO[4]);
	ligaVertices(GRAFO[1], GRAFO[6]);
	ligaVertices(GRAFO[2], GRAFO[6]);
	ligaVertices(GRAFO[4], GRAFO[6]);
	ligaVertices(GRAFO[5], GRAFO[6]);*/

    /*
    //Grafo hamiltoniano
    GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');
	GRAFO[4] = criaVertice('E');

    ligaVertices(GRAFO[0], GRAFO[1]);
    ligaVertices(GRAFO[0], GRAFO[2]);
    ligaVertices(GRAFO[0], GRAFO[3]);
    ligaVertices(GRAFO[0], GRAFO[4]);

    ligaVertices(GRAFO[1], GRAFO[2]);
    ligaVertices(GRAFO[1], GRAFO[3]);
    ligaVertices(GRAFO[1], GRAFO[4]);

    ligaVertices(GRAFO[2], GRAFO[3]);
    ligaVertices(GRAFO[2], GRAFO[4]);

    ligaVertices(GRAFO[3], GRAFO[4]);*/

    /*//Hamiltoniano e semi-euleriano
    GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');

    ligaVertices(GRAFO[0], GRAFO[1]);
    ligaVertices(GRAFO[0], GRAFO[2]);
    ligaVertices(GRAFO[0], GRAFO[3]);

    ligaVertices(GRAFO[1], GRAFO[2]);

    ligaVertices(GRAFO[2], GRAFO[3]);*/

    GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');
	GRAFO[4] = criaVertice('E');

    ligaVertices(GRAFO[0], GRAFO[1]);
    ligaVertices(GRAFO[0], GRAFO[2]);
    ligaVertices(GRAFO[0], GRAFO[3]);

    ligaVertices(GRAFO[1], GRAFO[2]);

    ligaVertices(GRAFO[2], GRAFO[3]);
    ligaVertices(GRAFO[2], GRAFO[4]);












	//int teste[MAX_VERTICES];
	int contImpar = 0;

	for(int i = 0; i < MAX_VERTICES; i++){
        if(GRAFO[i]->nroVizinhos%2 != 0)
            contImpar++;
	}

	if(contImpar == 0)
        printf("\nEh euleriano\n");
    else if(contImpar == 2)
        printf("\nEh semi-euleriano\n");
    else
        printf("\nNao eh euleriano\n");

	for (int i = 0; i < MAX_VERTICES; i++){
		solucao[i] = criaVertice('0');
	}

	if( cicloHamiltoniano(GRAFO) ){
		printf("Ciclo Hamiltoniano:\n");
		for (int i = 0; i < MAX_VERTICES; i++){
			printf("%c, ",solucao[i]->id);
		}
		printf("\n\n");
	}else{
		printf("Nao possui Ciclo Hamiltoniano\n");
	}

	return 0;
}