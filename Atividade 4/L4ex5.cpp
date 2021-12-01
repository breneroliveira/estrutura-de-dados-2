#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct arv {
    int info;
    int fb;
    arv *sae;
    arv *sad;
} arvore;

arvore* cria_arvore();
int testa_vazia(arvore *p);
void inserir(arvore **p, int num);
void mostra(arvore *p);
void mostra_em_ordem(arvore *p);
void mostra_pos(arvore *p);
arvore* remover(arvore **p, int num);
arvore * limpa_arvore(arvore *p);
int altura(arvore *p);
int fator_bal(arvore *p);
void calcula_fb(arvore *p);
arvore * rotacionar_esq_esq(arvore *p);
arvore * rotacionar_esq_dir(arvore *p);
arvore * rotacionar_dir_esq(arvore *p);
arvore * rotacionar_dir_dir(arvore *p);
arvore * balancear(arvore *p);

main() {
    arvore *t = cria_arvore();
    int menu = -1, valor;

    do {
        system("cls");

        cout << "0 - SAIR" << endl;
        cout << "1 - INCLUIR" << endl;
        cout << "2 - MOSTRAR" << endl;
        cout << "3 - EXCLUIR" << endl;
        cout << "4 - LIMPA ARVORE" << endl;
        cout << "5 - ALTURA DA ARVORE" << endl;
       
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 0 :
                system("cls");

                cout << "Programa finalizado.";

                getchar();

            break;
            case 1 :
                system("cls");
                
                cout << "Informe o valor a ser inserido: ";
                cin >> valor;
                fflush(stdin);
                
                /// Chamar funcao inserir.
                inserir(&t,valor);
                cout << "VALOR INSERIDO COM SUCESSO!";
                calcula_fb(t);
                t = balancear(t);
                calcula_fb(t);

                getchar();
            break;
            case 2 :
                system("cls");
                
                if(testa_vazia(t))
                    cout << "ARVORE VAZIA.";
                else {
                    cout << "ELEMENTOS NA ARVORE PRE-FIXA: " << endl;
                    mostra(t);
                    cout << "\n\nELEMENTOS NA ARVORE EM ORDEM: " << endl;
                    mostra_em_ordem(t);
                    cout << "\n\nELEMENTOS NA ARVORE POS-FIXA: " << endl;
                    mostra_pos(t);
                }

                getchar();
            break;
            case 3 :
                system("cls");
              
                if(testa_vazia(t))
                    cout << "ARVORE VAZIA.";
                else {
                    cout << "Informe o elemento a ser removido: ";
                    cin >> valor;
                    fflush(stdin);
                    
                    remover(&t, valor);
                    calcula_fb(t);
                    t = balancear(t);
                    calcula_fb(t);
                }
                
                getchar();
            break;
            case 4 :
                system("cls");
              
                if(testa_vazia(t))
                    cout << "ARVORE VAZIA.";
                else {
                    t = limpa_arvore(t);
                    cout << "ARVORE LIMPA COM SUCESSO.";
                }
                
                getchar();
            break;
            case 5 :
                system("cls");
              
                if(testa_vazia(t))
                    cout << "ARVORE VAZIA.";
                else {
                    cout << "ALTURA DA ARVORE: " << altura(t) << endl;
                }
                
                getchar();
            break;
            default:
                system("cls");
                
                cout << "OPCAO INVALIDA.";
                
                getchar();
            break;
        };
    } while(menu != 0);
}


arvore* cria_arvore() {
    return NULL;
}

int testa_vazia(arvore *p) {
    if(p == NULL)
        return 1;
    if(p->info == NULL)
        return 1;
    return 0;
}

void inserir(arvore **p, int num) {
    if(*p == NULL) {
        *p = new arvore;
        (*p)->sae = NULL;
        (*p)->sad = NULL;
        (*p)->info = num;
    } else {
        if(num < (*p)->info)
            inserir(&(*p)->sae, num);
        else
            inserir(&(*p)->sad, num);
    }
}

void mostra(arvore *p) {
    cout << "<";
    if(!testa_vazia(p)) {
        cout << p->info << "(" << p->fb << ")";
        mostra (p->sae);
        mostra (p->sad);
    }
    cout << ">";
}

void mostra_em_ordem(arvore *p) {
    cout << "<";
    if(!testa_vazia(p)) {
        mostra_em_ordem(p->sae);
        cout << p->info;
        mostra_em_ordem (p->sad);
    }
    cout << ">";
}

void mostra_pos(arvore *p) {
    cout << "<";
    if(!testa_vazia(p)) {
        mostra_pos(p->sae);
        mostra_pos (p->sad);
        cout << p->info;
    }
    cout << ">";
}

arvore* remover(arvore **p, int num) {
    if(*p == NULL) {
        cout << "ELEMENTO NAO ENCONTRADO.";
        return *p;
    }

    if(num < (*p)->info)
        remover(&(*p)->sae, num);
    else if(num > (*p)->info)
        remover(&(*p)->sad, num);
    else {
        arvore *aux = *p;
        /// Se for um nodo folha.
        if(((*p)->sae == NULL) && ((*p)->sad == NULL)) {
            delete(aux);
            (*p) = NULL;
        } else if((*p)->sae == NULL) {
            /// So tem filho a direita.
            (*p) = (*p)->sad;
            aux->sad =  NULL;
            delete(aux);
            aux = NULL;
        } else if((*p)->sad == NULL) {
            /// So tem filho a esquerda.
            (*p) = (*p)->sae;
            aux->sae =  NULL;
            delete(aux);
            aux = NULL;
        } else {
            aux = (*p)->sae;
            while(aux->sad != NULL)
                aux = aux->sad;
            (*p)->info = aux->info;
            aux->info = num;
            (*p)->sae = remover(&(*p)->sae, num);
        }
        cout << "ELEMENTO REMOVIDO COM SUCESSO.";
    }
    return *p;
}

arvore * limpa_arvore(arvore *p) {
    if(p != NULL) {
        limpa_arvore(p->sae);
        limpa_arvore(p->sad);
        delete(p);
    }
    return NULL;
}

int altura(arvore *p) {
    if(p == NULL)
        return 0;
    else {
        int he = altura(p->sae);
        int hd = altura(p->sad);
        if(he < hd)
            return (hd + 1);
        else
            return (he + 1);
    }
}

int fator_bal(arvore *p) {
    int fator = 0;
    if(p->sae)
        fator += altura(p->sae);
    if(p->sad)
        fator -= altura(p->sad);
    return fator;
}

void calcula_fb(arvore *p) {
    if(!testa_vazia(p)) {
        p->fb = fator_bal(p);
        if(p->sae != NULL)
            calcula_fb(p->sae);
        if(p->sad != NULL)
            calcula_fb(p->sad);
    }
}

arvore * rotacionar_esq_esq(arvore *p) {
    arvore *temp = p;
    arvore *esq = temp->sae;
    temp->sae = esq->sad;
    esq->sad = temp;
    return esq;
}

arvore * rotacionar_esq_dir(arvore *p) {
    arvore *temp = p;
    arvore *esq = temp->sae;
    arvore *dir = esq->sad;

    temp->sae = dir->sad;
    esq->sad = dir->sae;
    dir->sae = esq;
    dir->sad = temp;

    return dir;
}

arvore * rotacionar_dir_esq(arvore *p) {
    arvore *temp = p;
    arvore *dir = temp->sad;
    arvore *esq = dir->sae;

    temp->sad = esq->sae;
    dir->sae = esq->sad;
    esq->sad = dir;
    esq->sae = temp;

    return esq;
}

arvore * rotacionar_dir_dir(arvore *p) {
    arvore *temp = p;
    arvore *dir = temp->sad;
    temp->sad = dir->sae;
    dir->sae = temp;
    return dir;
}

arvore * balancear(arvore *p) {
    arvore *nodo_balanceado = NULL;
    if(p->sae)
        p->sae = balancear(p->sae);
    if(p->sad)
        p->sad = balancear(p->sad);

    int fator = p->fb;

    if(fator >= 2) {
        /// Arvore pesando para a esquerda.
        if(p->sae->fb <= -1)
            nodo_balanceado = rotacionar_esq_dir(p);
        else
            nodo_balanceado = rotacionar_esq_esq(p);
    } else if(fator <= -2) {
        /// Arvore pesando para a direita.
        if(p->sad->fb >= 1)
            nodo_balanceado = rotacionar_dir_esq(p);
        else
            nodo_balanceado = rotacionar_dir_dir(p);
    } else
        nodo_balanceado = p;

    return nodo_balanceado;
}