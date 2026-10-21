#include <iostream>
using namespace std;

struct No {
    string name;
    int prioridade;
    No* prox;
};

int definirPrioridade (string prioridade) {
    if (prioridade == "idoso"){return 4;}
    else if (prioridade == "pcd"){return 3;}
    else if (prioridade == "gestante"){return 3;}
    else if (prioridade == "autista"){return 2;}
    else {return 1;}
}

void inserir (No *&inicio, string nome, string prioridade) {

    No *novo = new No;
    novo->name = nome;
    novo->prioridade = definirPrioridade(prioridade);
    novo->prox = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
        return;
    }

    No *aux = inicio;

    while (aux->prox != nullptr) {
        aux = aux->prox;
    }

    aux->prox = novo;
}

void remover (No *& inicio) {
    int maiorPrioridade = 0;
    No *aux = inicio;

    while (aux != nullptr) {
        if (aux->prioridade > maiorPrioridade) {
            maiorPrioridade = aux->prioridade;
        }
        aux = aux->prox;
    }

    No *atual = inicio;
    No *anterior = nullptr;
    while (atual != nullptr) {
        if (atual->prioridade == maiorPrioridade) {
            if (anterior == nullptr) {
                inicio = inicio->prox;
            }else {
                anterior->prox = atual ->prox;
            }
            delete atual;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void listar(No *inicio) {
    No *aux = inicio;
    while (aux != nullptr) {
        cout << aux->name;
        cout << " prioridade: " << aux->prioridade << endl;
        aux = aux->prox;
    }
}

int main() {
    No* no = nullptr;

    inserir(no, "balbucio", "idoso");
    inserir(no, "flstudio", "pcd");
    inserir(no, "cocacola", "gestante");
    inserir(no, "joao", "autista");
    inserir(no, "marcin", "abnwoidboawd");

    listar(no);

    remover(no);

    listar(no);

}