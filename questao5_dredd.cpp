#include <iostream>
using namespace std;

class Noh
{
    friend class ListaDuploEncadeada;

private:
    Noh *proximo;
    Noh *anterior;
    int dado;

public:
    // noh();
    Noh(int dado = 0);
};

// construir dado a partir de um construtor
Noh::Noh(int dado = 0)
{
    dado = dado;
    proximo = NULL;
    anterior = NULL;
}

// lista encadeada
class ListaDuploEncadeada
{
private:
    int tamanho;
    Noh *primeiro;
    Noh *ultimo;

public:
    // construtor e destrutor
    ListaDuploEncadeada();
    ~ListaDuploEncadeada();
    // insercao, remoçao de repetidos e impressao, tanto normal quanto reversa
    void Insere(int dado);
    void InsereNoInicio(int dado);
    void InsereNoFim(int dado);
    void InsereNaPosicao(int dado, int pos);
    void RemoveRepetidos();
    void Imprime();
    void ImpressaoReversa();
};

// construçao de uma lista vazia
ListaDuploEncadeada::ListaDuploEncadeada()
{   
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
    
}

// construtor de copia
ListaDuploEncadeada::~ListaDuploEncadeada()
{
    Noh *atual = primeiro;
    Noh *temp = NULL;

    while (atual->proximo != NULL)
    {
        temp = atual;
        atual = atual->proximo;
        delete temp;
    }
}

// insere um dado na lista 
void ListaDuploEncadeada::Insere(int dado)
{
    Noh *novoNoh = new Noh(dado);
    primeiro = novoNoh;
    ultimo = novoNoh;
    tamanho++;
}

// insere no inicio
void ListaDuploEncadeada::InsereNoInicio(int dado)
{
    if (primeiro == NULL)
    {
        Insere(dado);
    }
    else
    {
        Noh *novoNoh = new Noh(dado);
        novoNoh->proximo = primeiro;
        primeiro->anterior = novoNoh;
        primeiro = novoNoh;
        tamanho++;
    }
}

// insere no final
void ListaDuploEncadeada::InsereNoFim(int dado)
{
    if (primeiro == NULL)
    {
        Insere(dado);
    }
    else
    {
        Noh *novoNoh = new Noh(dado);
        ultimo->proximo = novoNoh;
        novoNoh->anterior = ultimo;
        ultimo = novoNoh;
        tamanho++;
    }
}

// insere em determinada posicao
void ListaDuploEncadeada::InsereNaPosicao(int dado, int pos)
{
    if (primeiro == NULL)
    {
        Insere(dado);
    }
    else if (pos == 0) // insere no inicio
    {
        InsereNoInicio(dado);
    }
    else if (pos == tamanho) // insere no final
    {
        InsereNoFim(dado);
    }
    else //insere no meio da lista
    {
        Noh *aux = primeiro;
        int i = 0;

        while (i < pos)
        {
            aux = aux->proximo;
            i++;
        }
        Noh *novoNoh = new Noh(dado);
        Noh *auxAnterior = aux->anterior;
        auxAnterior->proximo = novoNoh;
        novoNoh->anterior = aux->anterior;
        novoNoh->proximo = aux;
        aux->anterior = novoNoh;
        tamanho++;
    }
}

// remove as repetiçoes da lista
void ListaDuploEncadeada::RemoveRepetidos()
{
    Noh *compara = primeiro;
    Noh *aux, *aux2, *aux3;

    while (compara->proximo != NULL)
    {
        aux = compara->proximo;
        if (aux->proximo == NULL)
        {
            if (compara->dado == aux->dado)
            {
                aux2 = aux->anterior;
                aux2->proximo = NULL;
                ultimo = aux2;
                tamanho--;
            }
        }
        while (aux->proximo != NULL)
        {
            if (compara->dado == aux->dado)
            {
                aux2 = aux->anterior;
                aux3 = aux->proximo;
                aux2->proximo = aux3;
                aux3->anterior = aux2;
                tamanho--;
                aux = aux2;
            }
            aux = aux->proximo;
            if (aux->proximo == NULL)
            {
                if (compara->dado == aux->dado)
                {
                    aux2 = aux->anterior;
                    aux2->proximo = NULL;
                    ultimo = aux2;
                    tamanho--;
                }
            }
        }
        if (compara->proximo == NULL)
        {
            break;
        }
        else
        {
            compara = compara->proximo;
        }
    }
}

// percorre a lista, imprimindo os elementos
void ListaDuploEncadeada::Imprime()
{
    Noh *nohAtual = primeiro;

    while (nohAtual != NULL)
    {
        cout << nohAtual->dado << " ";
        nohAtual = nohAtual->proximo;
    }
    cout << endl;
}

//imprime os dados de forma reversa (demonstração do duplo encadeamento)
void ListaDuploEncadeada::ImpressaoReversa()
{
    Noh *nohAtual = ultimo;

    while (nohAtual != NULL)
    {
        cout << nohAtual->dado << " ";
        nohAtual = nohAtual->anterior;
    }
    cout << endl;
}

int main()
{
    ListaDuploEncadeada lista;
    int tam;
    int valor;

    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cin >> valor;
        lista.InsereNaPosicao(valor, i);
    }

    lista.RemoveRepetidos();
    lista.Imprime();
    lista.ImpressaoReversa();

    return 0;
}