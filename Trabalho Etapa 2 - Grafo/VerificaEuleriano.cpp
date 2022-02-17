#include<iostream>
#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <time.h>

#define linha 10
#define coluna 10

/// O que foi feito:
/// Foi implementada a função verificarConexo2, ela tem um problema pois o tamanho da matris influencia;
/// Nesse sentido, foi adicionado um case 10 para que seja informado a quantidade de vértices a ser inserido;
/// Com isso, esse valor foi passado para a nova função que percorre até o valor de vértices informado.

/// O que precisa arrumar:
/// Arrumar o case 10 para 1
/// Arrumar os tamanhos, no caso criando a matriz e tudo mais a partir da quantia de vértices informado;
/// Arrumar para que seja possível acionar as outras opções somente quando a quantia de vértices for informada.


using namespace std;

void inserirAresta(int m[][coluna], int vInicial, int vFinal);
void mostrar(int m[][coluna], int qtdVertices);
void removerAresta(int m[][coluna], int vInicial, int vFinal);
void mostrarAdjacente(int m[][coluna], int vertice, int qtdVertices);
int mostrarGrau(int m[][coluna], int vertice, int qtdVertices);
int verificarConexo(int m[][coluna], int qtdVertices);
void verificaEuleriano(int m[][coluna], int qtdVertices);

int main() {
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    int m[linha][coluna] = {};
    int menu = -1, leu1 = 0, leu2 = 0;
    int verticeInicial, verticeFinal, qtdVertices;
    int vertice;

    do{
        system("cls");
        cout << "****************************************************************" << endl;
        cout << "* 0 - Sair                                                     *" << endl;
        cout << "* 1 - Informar o número de vertices a ser utilizado            *" << endl;
        cout << "* 2 - Incluir aresta (vertice inicial e final)                 *" << endl;
        cout << "* 3 - Mostrar matriz                                           *" << endl;
        cout << "* 4 - Remover aresta (vertice inicial e final)                 *" << endl;
        cout << "* 5 - Informar um vertice e apresentar seus adjacentes         *" << endl;
        cout << "* 6 - Informar um vertice e informar seu grau                  *" << endl;
        cout << "* 7 - Verificar se o grafo é conexo                            *" << endl;
        cout << "* 8 - Verificar se o grafo é euleriano, semi-euleriano ou não  *" << endl;
        cout << "****************************************************************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch (menu){
            case 0:
                system("cls");
                cout << "OPÇÃO 0 - SAIR" << endl << endl;
                cout << "PROGRAMA FINALIZADO!";
                getchar();
                break;

            case 1:
                system("cls");
                cout << "OPÇÃO 1 - INFORMAR A QUANTIDADE DE VERTICES A SER UTILIZADO" << endl << endl;
                cout << "Informe a quantidade de vértices: ";
                cin >> qtdVertices;
                fflush(stdin);
                leu1 = 1;
                getchar();
                break;

            case 2:
                system("cls");
                cout << "OPÇÃO 2 - INCLUIR ARESTA (VERTICE INICIAL E FINAL)" << endl << endl;

                if(leu1 == 1){
                    cout << "Informe o vertice inicial: ";
                    cin >> verticeInicial;
                    fflush(stdin);
                    cout << "Informe o vertice final: ";
                    cin >> verticeFinal;
                    fflush(stdin);

                    inserirAresta(m, verticeInicial, verticeFinal);

                    leu2 = 1;

                    cout << endl;
                } else
                    cout << "Insira o número de vértices" << endl;

                getchar();
                break;

            case 3:
                system("cls");
                cout << "OPÇÃO 3 - MOSTRAR MATRIZ" << endl << endl;

                if(leu1 == 1 && leu2 == 1)
                    mostrar(m, qtdVertices);
                else if(leu1 == 1 && leu2 == 0)
                    cout << "Insira ao menos uma aresta " << endl;
                else
                    cout << "Execute a opção 1 e 2 primeiro" << endl;

                getchar();
                break;

            case 4:
                system("cls");
                cout << "OPÇÃO 4 - REMOVER ARESTA (VERTICE INICIAL E FINAL)" << endl << endl;

                if(leu1 == 1 && leu2 == 1){
                    cout << "Informe o vertice inicial: ";
                    cin >> verticeInicial;
                    fflush(stdin);
                    cout << "Informe o vertice final: ";
                    cin >> verticeFinal;
                    fflush(stdin);

                    removerAresta(m, verticeInicial, verticeFinal);

                    cout << endl;
                }else if(leu1 == 1 && leu2 == 0)
                    cout << "Insira ao menos uma aresta " << endl;
                else
                    cout << "Execute a opção 1 e 2 primeiro" << endl;

                getchar();
                break;

            case 5:
                system("cls");
                cout << "OPÇÃO 5 - INFORMAR UM VERTICE E APRESENTAR SEUS ADJACENTES" << endl << endl;

                if(leu1 == 1 && leu2 == 1){
                    cout << "Informe o vertice: ";
                    cin >> vertice;
                    fflush(stdin);

                    mostrarAdjacente(m, vertice, qtdVertices);

                    cout << endl;
                }else if(leu1 == 1 && leu2 == 0)
                    cout << "Insira ao menos uma aresta " << endl;
                else
                    cout << "Execute a opção 1 e 2 primeiro" << endl;

                getchar();
                break;

            case 6:
                system("cls");
                cout << "OPÇÃO 6 - INFORMAR UM VERTICE E INFORMAR SEU GRAU" << endl << endl;

                if(leu1 == 1 && leu2 == 1){
                    cout << "Informe o vertice: ";
                    cin >> vertice;
                    fflush(stdin);

                    cout << endl;

                    cout << "O grau do vertice " << vertice << " é: " << mostrarGrau(m, vertice, qtdVertices);

                    cout << endl;
                }else if(leu1 == 1 && leu2 == 0)
                    cout << "Insira ao menos uma aresta " << endl;
                else
                    cout << "Execute a opção 1 e 2 primeiro" << endl;

                getchar();
                break;

            case 7:
                system("cls");
                cout << "OPÇÃO 7 - VERIFICAR SE O GRAFO É CONEXO" << endl << endl;

                if(leu1 == 1 && leu2 == 2){
                    if((verificarConexo(m, qtdVertices) / 2) < qtdVertices - 1)
                        cout << "\nGrafo nao e conexo";
                    else
                        cout << "\nGrafo conexo";
                } else if(leu1 == 1 && leu2 == 0)
                    cout << "Insira ao menos uma aresta " << endl;
                else
                    cout << "Execute a opção 1 e 2 primeiro" << endl;

                getchar();
                break;

            case 8:
                system("cls");
                cout << "OPÇÃO 8 - VERIFICAR SE O GRAFO É EULERIANO, SEMI-EULERIANO OU NÃO" << endl << endl;
                verificaEuleriano(m, qtdVertices);
                getchar();
                break;
        }
    }while(menu != 0);

}

void inserirAresta(int m[][coluna], int vInicial, int vFinal){
    m[vInicial][vFinal] = 1;
    m[vFinal][vInicial] = 1;
}

void mostrar(int m[][coluna], int qtdVertices){
    cout << "Matriz normal: " << endl;
    for(int l = 0; l < qtdVertices; l++){
        for(int c = 0; c < qtdVertices; c++){
            cout << m[l][c] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void removerAresta(int m[][coluna], int vInicial, int vFinal){
    if(m[vInicial][vFinal] = 0){
        cout << "A aresta informada não existe" << endl;
    }else{
        m[vInicial][vFinal] = 0;
        m[vFinal][vInicial] = 0;
    }
}

void mostrarAdjacente(int m[][coluna], int vertice, int qtdVertices){
   for(int l = 0; l < qtdVertices; l++){
        if(l == vertice){
            for(int c = 0; c < qtdVertices; c++){
                    if(m[l][c] == 1)
                        cout << c + 1 << ", ";
            }
        }
    }
}

int mostrarGrau(int m[][coluna], int vertice, int qtdVertices){
    int grau = 0;

    for(int l = 0; l < qtdVertices; l++){
        if(l == vertice){
            for(int c = 0; c < qtdVertices; c++){
                    if(m[l][c] == 1)
                        grau++;
            }
        }
    }

    return grau;
}

int verificarConexo(int m[][coluna], int qtdVertices){
    int cont = 0;
    for(int l = 0; l < qtdVertices; l++){
        for(int c = 0; c < qtdVertices; c++){
            if(m[l][c] == 1)
                cont++;
        }
    }
    return cont;
}

//0-1; 1-2; 1-4; 2-3; 3-4; 4-5;

void verificaEuleriano(int m[][coluna], int qtdVertices){
    int grau, grauPar = 0, grauImpar = 0;

    for(int l = 0; l < qtdVertices; l++){
        grau = 0;
        for(int c = 0; c < qtdVertices; c++){
            if(m[l][c] == 1)
                grau++;
        }
        if(grau%2 == 0)
            grauPar++;
        else
            grauImpar++;
    }

    if(grauImpar == 0)
        cout << "O GRAFO É EULERIANO!" << endl;
    else if(grauImpar == 2)
        cout << "O GRAFO É SEMI-EULERIANO" << endl;
    else
        cout << "O GRAFO NÃO É EULERIANO" << endl;

}

/*
int mostrarGrau(int m[][coluna], int vertice, int qtdVertices){
    int grau = 0;

    for(int l = 0; l < qtdVertices; l++){
        if(l == vertice){
            for(int c = 0; c < qtdVertices; c++){
                    if(m[l][c] == 1)
                        grau++;
            }
        }
    }

    return grau;
}
*/