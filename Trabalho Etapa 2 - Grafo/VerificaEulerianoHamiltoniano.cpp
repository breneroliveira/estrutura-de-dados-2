#include <iostream> 

using namespace std;

#define VERTICES_MAXIMOS 7 // Numero maximo de vertices (e necessario mudar conforme o teste realizado).

typedef struct NO {
	char id_vertice;
	int numero_de_vizinhos;
	struct NO* vizinhos[VERTICES_MAXIMOS];
	bool vertice_visitado;
} *vertice;

vertice solucao_ciclo_hamiltoniano[VERTICES_MAXIMOS]; // Vetor que guarda o Ciclo Hamiltoniano.

// Cria vertice.
vertice criaVertice(char id_vertice) {
	NO *novoVertice = new NO();

	novoVertice->id_vertice = id_vertice;
	novoVertice->numero_de_vizinhos = 0;
	novoVertice->vertice_visitado = false;

	for (int i = 0; i < VERTICES_MAXIMOS; i++) {
		novoVertice->vizinhos[i] = NULL;
	}

	return novoVertice;
}

// Liga os vertices (cria arestas).
bool ligaVertices(vertice v1, vertice v2) {
	int aux = 0;

	while(v1->vizinhos[aux] != NULL) { // Busca a primeira posição dos vizinhos.
		aux++;
	}

	v1->vizinhos[aux] = v2; // Adiciona o novo vizinho a lista de vizinhos.
	aux = 0;

	while(v2->vizinhos[aux] != NULL) { // Busca a primeira posição dos vizinhos.
		aux++;
	}

	v2->vizinhos[aux] = v1; // Adiciona o novo vizinho a lista de vizinhos.
	v1->numero_de_vizinhos++;
	v2->numero_de_vizinhos++;
}

bool cicloHamiltonianoAuxiliar(int aux) {
	if(aux == VERTICES_MAXIMOS) {
		for (int i = 0; i < solucao_ciclo_hamiltoniano[aux-1]->numero_de_vizinhos; i++) {
			if(solucao_ciclo_hamiltoniano[aux-1]->vizinhos[i] == solucao_ciclo_hamiltoniano[0]) {
				return true;
			}
		}
		return false;
	}

	vertice s = solucao_ciclo_hamiltoniano[aux-1]; // Variavel auxiliar.

	for (int i = 0; i < s->numero_de_vizinhos; i++) { // Percorre todos os vizinhos do vertice.
		if(s->vizinhos[i]->vertice_visitado == false) {
			s->vizinhos[i]->vertice_visitado = true;
			solucao_ciclo_hamiltoniano[aux] = s->vizinhos[i];
			
			if(cicloHamiltonianoAuxiliar(aux+1) == true) {
				return true;
			}

			s->vizinhos[i]->vertice_visitado = false;
		}
	}

	return false;
}

bool cicloHamiltoniano(vertice grafo[VERTICES_MAXIMOS]) {
	grafo[0]->vertice_visitado = true; // Marca a posicao inicial como visitada.
	solucao_ciclo_hamiltoniano[0] = grafo[0]; // Vetor que guaradara a solucao do ciclo hamiltoniano.

	return cicloHamiltonianoAuxiliar(1);
}

void verificaEuleriano(vertice grafo[VERTICES_MAXIMOS]) {
	int cont_impar = 0;

	for(int i = 0; i < VERTICES_MAXIMOS; i++) {
		if(grafo[i]->numero_de_vizinhos%2 != 0) // Verifica o grau de cada vertice (numero de arestas). 
			cont_impar++;
	}

	if(cont_impar == 0)
		cout << "Eh um Grafo Euleriano.\n\n";
	else if(cont_impar == 2)
		cout << "Eh um Grafo Semi-Euleriano.\n\n";
	else
		cout << "Nao eh um Grafo Euleriano.\n\n";
}

int main() {
	vertice grafo[VERTICES_MAXIMOS];

	int menu = -1;

    do {
        system("cls");

        cout << "0 - Sair;" << endl;
        cout << "1 - Grafo Euleriano (7 vertices);" << endl;
        cout << "2 - Grafo Semi-Euleriano (6 vertices);" << endl;
        cout << "3 - Grafo Nao Euleriano (5 vertices);" << endl;
        cout << "4 - Grafo Hamiltoniano (5 vertices);" << endl;
        cout << "5 - Grafo Hamiltoniano (5 vertices);" << endl;
        cout << "6 - Grafo Nao Hamiltoniano (6 vertices);" << endl;
        cout << "7 - Teste pessoal." << endl;

        cout << "\nEscolha um grafo para ser testado: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 0:
                system("cls");

                cout << "Programa finalizado.\n";

            break;
            case 1:
                system("cls");
                
				grafo[0] = criaVertice('A');
				grafo[1] = criaVertice('B');
				grafo[2] = criaVertice('C');
				grafo[3] = criaVertice('D');
				grafo[4] = criaVertice('E');
				grafo[5] = criaVertice('F');
				grafo[6] = criaVertice('G');

				ligaVertices(grafo[0], grafo[1]);
				ligaVertices(grafo[1], grafo[2]);
				ligaVertices(grafo[2], grafo[3]);
				ligaVertices(grafo[3], grafo[4]);
				ligaVertices(grafo[4], grafo[5]);
				ligaVertices(grafo[5], grafo[0]);
				ligaVertices(grafo[1], grafo[5]);
				ligaVertices(grafo[2], grafo[4]);
				ligaVertices(grafo[1], grafo[6]);
				ligaVertices(grafo[2], grafo[6]);
				ligaVertices(grafo[4], grafo[6]);
				ligaVertices(grafo[5], grafo[6]);

				verificaEuleriano(grafo);

                system("pause");
            break;
            case 2:
                system("cls");
                
				grafo[0] = criaVertice('A');
				grafo[1] = criaVertice('B');
				grafo[2] = criaVertice('C');
				grafo[3] = criaVertice('D');
				grafo[4] = criaVertice('E');
				grafo[5] = criaVertice('F');

				ligaVertices(grafo[0], grafo[1]);
				ligaVertices(grafo[1], grafo[2]);
				ligaVertices(grafo[2], grafo[3]);
				ligaVertices(grafo[3], grafo[4]);
				ligaVertices(grafo[4], grafo[0]);
				ligaVertices(grafo[1], grafo[3]);
				ligaVertices(grafo[0], grafo[5]);
				ligaVertices(grafo[1], grafo[5]);
				ligaVertices(grafo[3], grafo[5]);
				ligaVertices(grafo[4], grafo[5]);

				verificaEuleriano(grafo);

                system("pause");
            break;
            case 3:
                system("cls");
              
				grafo[0] = criaVertice('A');
				grafo[1] = criaVertice('B');
				grafo[2] = criaVertice('C');
				grafo[3] = criaVertice('D');
				grafo[4] = criaVertice('E');

				ligaVertices(grafo[0], grafo[1]);
				ligaVertices(grafo[1], grafo[2]);
				ligaVertices(grafo[2], grafo[3]);
				ligaVertices(grafo[3], grafo[0]);
				ligaVertices(grafo[0], grafo[4]);
				ligaVertices(grafo[1], grafo[4]);
				ligaVertices(grafo[2], grafo[4]);
				ligaVertices(grafo[3], grafo[4]);

				verificaEuleriano(grafo);
                
                system("pause");
            break;
            case 4:
                system("cls");
              
				grafo[0] = criaVertice('A');
				grafo[1] = criaVertice('B');
				grafo[2] = criaVertice('C');
				grafo[3] = criaVertice('D');
				grafo[4] = criaVertice('E');
	
				ligaVertices(grafo[0], grafo[1]);
				ligaVertices(grafo[1], grafo[2]);
				ligaVertices(grafo[2], grafo[3]);
				ligaVertices(grafo[3], grafo[4]);
				ligaVertices(grafo[4], grafo[0]);
				ligaVertices(grafo[0], grafo[2]);
				ligaVertices(grafo[0], grafo[3]);
				ligaVertices(grafo[1], grafo[4]);
				ligaVertices(grafo[1], grafo[3]);
				ligaVertices(grafo[2], grafo[4]);

				for (int i = 0; i < VERTICES_MAXIMOS; i++) {
					solucao_ciclo_hamiltoniano[i] = criaVertice('0');
				}

				if(cicloHamiltoniano(grafo)) {
					cout << "Eh um Grafo Hamiltoniano.\n\n";

					cout << "Ciclo Hamiltoniano: ";
					for(int i = 0; i < VERTICES_MAXIMOS; i++) {
						cout << solucao_ciclo_hamiltoniano[i]->id_vertice << ", ";
					}
					cout << endl << endl;
				} else {
					cout << "Nao eh um Grafo Hamiltoniano.\n\n";
				}
                
                system("pause");
            break;
            case 5:
                system("cls");

				grafo[0] = criaVertice('A');
				grafo[1] = criaVertice('B');
				grafo[2] = criaVertice('C');
				grafo[3] = criaVertice('D');
				grafo[4] = criaVertice('E');

				ligaVertices(grafo[0], grafo[1]);
				ligaVertices(grafo[1], grafo[2]);
				ligaVertices(grafo[2], grafo[3]);
				ligaVertices(grafo[3], grafo[0]);
				ligaVertices(grafo[0], grafo[4]);
				ligaVertices(grafo[1], grafo[4]);
				ligaVertices(grafo[2], grafo[4]);

				for (int i = 0; i < VERTICES_MAXIMOS; i++) {
					solucao_ciclo_hamiltoniano[i] = criaVertice('0');
				}

				if(cicloHamiltoniano(grafo)) {
					cout << "Eh um Grafo Hamiltoniano.\n\n";

					cout << "Ciclo Hamiltoniano: ";
					for(int i = 0; i < VERTICES_MAXIMOS; i++) {
						cout << solucao_ciclo_hamiltoniano[i]->id_vertice << ", ";
					}
					cout << endl << endl;
				} else {
					cout << "Nao eh um Grafo Hamiltoniano.\n\n";
				}
                
                system("pause");
            break;
            case 6:
                system("cls");
              
				grafo[0] = criaVertice('A');
				grafo[1] = criaVertice('B');
				grafo[2] = criaVertice('C');
				grafo[3] = criaVertice('D');
				grafo[4] = criaVertice('E');
				grafo[5] = criaVertice('F');

				ligaVertices(grafo[0], grafo[1]);
				ligaVertices(grafo[1], grafo[2]);
				ligaVertices(grafo[2], grafo[3]);
				ligaVertices(grafo[3], grafo[4]);
				ligaVertices(grafo[1], grafo[4]);
				ligaVertices(grafo[4], grafo[5]);

				for (int i = 0; i < VERTICES_MAXIMOS; i++) {
					solucao_ciclo_hamiltoniano[i] = criaVertice('0');
				}

				if(cicloHamiltoniano(grafo)) {
					cout << "Eh um Grafo Hamiltoniano.\n\n";

					cout << "Ciclo Hamiltoniano: ";
					for(int i = 0; i < VERTICES_MAXIMOS; i++) {
						cout << solucao_ciclo_hamiltoniano[i]->id_vertice << ", ";
					}
					cout << endl << endl;
				} else {
					cout << "Nao eh um Grafo Hamiltoniano.\n\n";
				}
                
                system("pause");
            break;
			case 7:
                system("cls");
              
				// Insira aqui neste case o seu grafo para testes.



				for (int i = 0; i < VERTICES_MAXIMOS; i++) {
					solucao_ciclo_hamiltoniano[i] = criaVertice('0');
				}

				if(cicloHamiltoniano(grafo)) {
					cout << "Eh um Grafo Hamiltoniano.\n\n";

					cout << "Ciclo Hamiltoniano: ";
					for(int i = 0; i < VERTICES_MAXIMOS; i++) {
						cout << solucao_ciclo_hamiltoniano[i]->id_vertice << ", ";
					}
					cout << endl << endl;
				} else {
					cout << "Nao eh um Grafo Hamiltoniano.\n\n";
				}

				verificaEuleriano(grafo);
                
                system("pause");
            break;
            default:
                system("cls");
                
                cout << "Opcao invalida.\n\n";
                
                system("pause");
            break;
        };
    } while(menu != 0);

	return 0;
}