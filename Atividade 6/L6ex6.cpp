#include<iostream>
#include<cstdio>
#include<cstdlib>

#define tam 20

using namespace std;

void cria_matriz(int m[][tam]);
void mostra_matriz(int m[][tam]);
void incluir_aresta(int m[][tam]);
void remover_aresta(int m[][tam]);
void mostra_adjacente(int m[][tam]);
void mostra_grau(int m[][tam]);

main() {
    int menu;
    int mat[tam][tam];
    cria_matriz(mat);

    do {
        system("cls");
        cout << "0 - Sair" << endl;
        cout << "1 - Incluir aresta" << endl;
        cout << "2 - Mostrar a Matriz" << endl;
        cout << "3 - Remover aresta" << endl;
        cout << "4 - Mostra vertices adjacentes" << endl;
        cout << "5 - Mostra o grau de um vertice" << endl;
        
        cout << "\nSua escolha: ";
        cin >> menu;
        fflush(stdin);
        
        switch(menu) {
            case 0:
                system("cls");
                cout << "Programa finalizado.";
                getchar();
            break;

            case 1:
                system("cls");
                incluir_aresta(mat);
                cout << "\nAresta inserida com sucesso.";
                getchar();
            break;

            case 2:
                system("cls");
                mostra_matriz(mat);
                getchar();
            break;

            case 3:
                system("cls");
                remover_aresta(mat);
                getchar();
            break;

            case 4:
                system("cls");
                mostra_adjacente(mat);
                getchar();
            break;

            case 5:
                system("cls");
                mostra_grau(mat);
                getchar();
            break;

            default:
                system("cls");
                cout << "Opcao invalida.";
                getchar();
            break;
        };
    } while(menu != 0);
}

void cria_matriz(int m[][tam]) {
    for(int l = 0; l < tam; l++) {
        for(int c = 0; c < tam; c++)
            m[l][c] = 0;
    }
}

void mostra_matriz(int m[][tam]) {
    for(int l = 0; l <= tam; l++) {
        if(l < 9)
            cout << l << " ";
        else
            cout << l << " ";
    }

    cout << "\n";

    for(int l = 0; l < tam; l++) {
        if(l < 9)
            cout << l + 1 << " ";
        else
            cout << l + 1 << " ";

        for(int c = 0; c < tam; c++) {
            cout << m[l][c] << " ";
        }
        cout << "\n";
    }
}

void incluir_aresta(int m[][tam]) {
    int ini, fim;

    cout << "Informe o vertice inicial: ";
    cin >> ini;
    fflush(stdin);

    cout << "Informe o vertice final: ";
    cin >> fim;
    fflush(stdin);

    m[ini - 1][fim - 1] = 1;
}

void remover_aresta(int m[][tam]) {
    int ini, fim;

    cout << "Informe o vertice inicial: ";
    cin >> ini;
    fflush(stdin);

    cout << "Informe o vertice final: ";
    cin >> fim;
    fflush(stdin);

    if(m[ini - 1][fim - 1] == 0)
        cout << "\nAresta inexistente.";
    else {
        m[ini - 1][fim - 1] = 0;
        cout << "\nAresta removida com sucesso.";
    }
}

void mostra_adjacente(int m[][tam]) {
    int v, cont = 0;

    cout << "Informe o vertice: ";
    cin >> v;
    fflush(stdin);

    cout << "\nAdjacentes ao vertice " << v << ": " << endl;
    for(int c = 0; c < tam; c++) {
        if(m[v - 1][c] == 1) {
            cout << c + 1 << ", ";
            cont++;
        }
    }
    if(cont == 0)
        cout << "\nNenhum vertice adjacente encontrado";
}

void mostra_grau(int m[][tam]) {
    int v, cont = 0;

    cout << "Informe o vertice: ";
    cin >> v;
    fflush(stdin);

    cout << "\nGrau do vertice " << v << ": " << endl;
    for(int c = 0; c < tam; c++) {
        if(m[v - 1][c] == 1) {
            cont++;
        }
    }
    cout << cont;
}