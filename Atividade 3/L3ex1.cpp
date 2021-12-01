#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

/* Cada no armazena tras informacoes:
   nesse caso um numero (num),
   ponteiro para subarvore a direita (sad)
   e ponteiro para subarvore a esquerda (sae).
*/

typedef struct arv {
    int info;
    arv *sad;
    arv *sae;
} arvore;

/* A estrutura da arvore e representada por um ponteiro
   para o no raiz. Com esse ponteiro, temos acesso aos
   demais nos.
*/

/* Funcao que cria uma arvore e retorna um ponteiro do tipo arvore. */
arvore* cria_arvore() {
    /* Uma arvore e representada pelo endereco do no raiz,
     essa funcao cria uma arvore com nenhum elemento,
     ou seja, cria uma arvore vazia, por isso retorna NULL.
    */
    return NULL;
}

/* Funcao que verifica se uma arvore a vazia. */
int testa_vazia(arvore *t) {
  /* Retorna 1 se a arvore for vazia e 0 caso contrario. */
    if(t == NULL)
        return 1;
    if(t->info == NULL)
        return 1;
    return 0;
}

/* Funcao que mostra a informacao da arvore em preordem. */
void mostra(arvore *t) {
    /* Essa funcao imprime os elementos de forma recursiva. */
    cout << "<"; /* Notacao para organizar na hora de mostrar os elementos. */
    if(!testa_vazia(t)) { /* Se a arvore nao for vazia. */
    /* Mostra os elementos em pre-ordem. */
        cout << t->info; /* Mostra a raiz. */
        mostra(t->sae); /* Mostra a sae (subarvore a esquerda). */
        mostra(t->sad); /* Mostra a sad (subarvore a direita). */
    }
    cout << ">"; /* Notacao para organizar na hora de mostrar os elementos. */
}

/* Exibe arvore em ordem. */
void mostra_2(arvore *t) {
    cout << "<"; /* Notacao para organizar na hora de mostrar os elementos. */
    if(!testa_vazia(t)) { /* Se a arvore nao for vazia. */
        mostra_2(t->sae); /* Mostra a sae (subarvore a esquerda). */
        cout << t->info; /* Mostra a raiz. */
        mostra_2(t->sad); /* Mostra a sad (subarvore a direita). */
    }
    cout << ">"; /* Notacao para organizar na hora de mostrar os elementos. */
}

/* Exibe arvore em posOrdem mesma descricao dos mostra anteriores. */
void mostra_3(arvore *t) {
    cout << "<";
    if(!testa_vazia(t)) {
        mostra_3(t->sae);
        mostra_3(t->sad);
        cout << t->info;
    }
    cout << ">";
}

arvore* buscaNo(arvore *t, int c) {
    arvore *aux;
    if(testa_vazia(t))
        return NULL; /* Arvore vazia: nao encontrou. */
    else if(t->info == c)
        return t;
    else {
        aux = buscaNo(t->sae, c); /* Busca na sae. */
        if(aux == NULL)
            aux = buscaNo(t->sad, c); /* Busca na sad. */
        return aux;
    }
}

/* Funcao que insere um dado na arvore. */
void inserir(arvore **t, int v) {
    /* Essa funcao insere os elementos de forma recursiva. */
    if(*t == NULL) {
        *t = new arvore; /* Aloca memoria para a estrutura. */
        (*t)->sae = NULL; /* Subarvore a esquerda e NULL. */
        (*t)->sad = NULL; /* Subarvore a direita a NULL. */
        (*t)->info = v; /* Armazena a informacao. */
    } else {
        if(v < (*t)->info) { /* Se o numero for menor entao vai pra esquerda. */
            /* Percorre pela subarvore a esquerda. */
            inserir(&(*t)->sae, v);
        }
        if(v >= (*t)->info) { /* Se o numero for maior entao vai pra direita */
            /* Percorre pela subarvore a direita */
            inserir(&(*t)->sad, v);
        }
    }
}

arvore* remover(arvore **t, int v) {
    if(v < (*t)->info)
        remover(&(*t)->sae, v);
    else if(v > (*t)->info)
        remover(&(*t)->sad, v);
    else {
        /// Achou o elemento a ser removido.
        arvore *aux = *t;
        if(((*t)->sae == NULL) && ((*t)->sad == NULL)) {
            /// E um no folha.
            delete(aux);
            (*t) = NULL;
        } else if((*t)->sae == NULL) {
            /// So tem filho a direita.
            (*t) = (*t)->sad;
            aux->sad = NULL;
            delete(aux);
            aux = NULL;
        } else if ((*t)->sad == NULL) {
            /// So tem filho a esquerda.
            (*t) = (*t)->sae;
            aux->sae = NULL;
            delete(aux);
            aux = NULL;
        } else {
            aux = (*t)->sae;
            while(aux->sad != NULL) {
                aux = aux->sad;
            }
            (*t)->info = aux->info;
            aux->info = v;
            (*t)->sae = remover(&(*t)->sae, v);
        }
    }
    return *t;
}

int alturaArvore(arvore *t) {
    if (t == NULL)
        return 1;
    else {
        int he = 1 + alturaArvore(t->sae);
        int hd = 1 + alturaArvore(t->sad);
        if (he < hd)
        return hd;
    else
        return he;
    }
}

arvore* limpa_arvore(arvore *t) {
    if(t != NULL) {
        limpa_arvore(t->sae);
        limpa_arvore(t->sad);
        delete(t);
    }
    return NULL;
}

void acha_nivel(arvore *t, int v, int nivel) {
    if(!testa_vazia(t)) {
        nivel++;
        if(t->info == v) {
            cout << "\nO valor " << t->info << " esta no nivel ";
            cout << nivel << "." << endl;
        }
        acha_nivel(t->sae, v, nivel);
        acha_nivel(t->sad, v, nivel);
        nivel--;
    }
}

int main() {
    arvore *t = cria_arvore(); /* Cria uma arvore. */
    arvore *no_pai;
    int menu = -1, num;

    do {
        system("cls");
        
        cout << "*------------------------------------*" << endl;
        cout << "|           MENU DE OPCOES           |" << endl;
        cout << "*------------------------------------*" << endl;
        cout << "| 0 - Sair                           |" << endl;
        cout << "| 1 - Incluir                        |" << endl;
        cout << "| 2 - Mostrar                        |" << endl;
        cout << "| 3 - Remover                        |" << endl;
        cout << "| 4 - Mostrar altura da arvore       |" << endl;
        cout << "| 5 - Limpar todos os nos da arvore  |" << endl;
        cout << "| 6 - Buscar nivel                   |" << endl;
        cout << "*------------------------------------*" << endl;
        
        cout << "\nSua escolha: ";
        cin >> menu;
        fflush(stdin);
        
        switch (menu) {
            case 0:
                system("cls");

                delete(t);
                cout << "PROGRAMA FINALIZADO.";

                getchar();
            break;

            case 1:
                system("cls");

                cout << "Informe o valor a ser incluido: ";
                cin >> num;
                fflush(stdin);

                inserir(&t, num);
                cout << "\nVALOR INCLUIDO COM SUCESSO.";

                getchar();
            break;

            case 2:
                system("cls");

                if(testa_vazia(t)) /* Verifica se a arvore esta vazia. */
                    cout << "Arvore vazia.\n";
                else {
                    cout << "ELEMENTOS NA ARVORE EM PRE-ORDEM: " << endl;
                    mostra(t);
                    cout << "\nELEMENTOS NA ARVORE EM ORDEM: " << endl;
                    mostra_2(t);
                    cout << "\nELEMENTOS NA ARVORE EM POS-ORDEM: " << endl;
                    mostra_3(t);
                }

                getchar();
            break;
            
            case 3:
                system("cls");

                if(testa_vazia(t)) /* Verifica se a arvore esta vazia. */
                    cout << "Arvore vazia.\n";
                else {
                    cout << "Informe o valor a ser removido: ";
                    cin >> num;
                    fflush(stdin);

                    if(t->sae == NULL && t->sad == NULL) {
                        delete(t);
                        t = NULL;
                    } else {
                        /// Consulta se o valor pertence a arvore.
                        if(buscaNo(t, num)) {
                            remover(&t, num);
                            cout << "\nVALOR REMOVIDO COM SUCESSO.";
                        } else
                            cout << "\nVALOR NAO PERTENCE A ARVORE.";
                    }
                }

                getchar();
            break;

            case 4:
                system("cls");

                if(testa_vazia(t)) /* Verifica se a arvore esta vazia. */
                    cout << "Arvore vazia.\n";
                else {
                    cout << "ALTURA SAE: " << endl;
                    if(t->sae == NULL)
                        cout << "-1" << endl;
                    else
                        cout << alturaArvore(t->sae);
                    cout << "\nALTURA SAD: " << endl;
                    if(t->sad == NULL)
                        cout << "-1" << endl;
                    else
                        cout << alturaArvore(t->sad);
                    cout << "\nALTURA DA ARVORE: " << endl;
                    if(alturaArvore(t->sae) > alturaArvore(t->sad))
                        cout << alturaArvore(t->sae);
                    else
                        cout << alturaArvore(t->sad);
                }

                getchar();
            break;
            
            case 5:
                system("cls");

                if(testa_vazia(t)) /* Verifica se a arvore esta vazia. */
                    cout << "Arvore vazia.\n";
                else {
                    t = limpa_arvore(t);
                    cout << "Todos os nos foram eliminados. Arvore vazia.";
                }

                getchar();
            break;

            case 6:
                system("cls");

                if(testa_vazia(t)) /* Verifica se a arvore esta vazia. */
                    cout << "Arvore vazia.\n";
                else {
                    cout << "Informe o valor a ser consultado o nivel: ";
                    cin >> num;
                    fflush(stdin);
                    /// Consulta se o valor pertence a arvore.
                    if(buscaNo(t, num)) {
                        acha_nivel(t, num, -1);
                    } else
                        cout << "\nVALOR NAO PERTENCE A ARVORE.";
                }

                getchar();
            break;

            default:
                system("cls");

                cout << "Opcao invalida." << endl;

                getchar();
            break;
        };
    } while (menu != 0);
}