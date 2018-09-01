#include<stdio.h>
#include<stdlib.h>

typedef struct ArvBin
{
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
} NO;

// Uma função para criar um novo nó na Árvore de Busca Binária 
NO *novoNo(int item)
{
    NO *temp =  (NO *)malloc(sizeof(NO));
    temp->info = item;
    temp->esq = temp->dir = NULL;
    return temp;
}

// Uma função para fazer o percurso EmOrdem na Árvore de Busca Binária
void emordem(NO *raiz)
{
    if (raiz != NULL)
    {
        emordem(raiz->esq);
        printf("%d ", raiz->info);
        emordem(raiz->dir);
    }
}

// Uma função para inserir um novo nó com uma dada chave (info) na Árvore de Busca Binária
NO *insere(NO *no, int info)
{
    // Se a árvore estiver vazia, retorne um novo nó
    if (no == NULL) return novoNo(info);

    // Caso contrário, volte pela árvore 
    if (info < no->info)
        no->esq  = insere(no->esq, info);
    else if (info > no->info)
        no->dir = insere(no->dir, info);

    // retorna o ponteiro do nó (inalterado)
    return no;
}

// Teste das funções
int main()
{
    /* Criar a seguinte Árvore de Busca Binária
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    NO *raiz = NULL;
    raiz = insere(raiz, 50);
    insere(raiz, 30);
    insere(raiz, 20);
    insere(raiz, 40);
    insere(raiz, 70);
    insere(raiz, 60);
    insere(raiz, 80);

    printf("\nÁrvore de Busca Binária: Inserção e Percurso;\n\n");
    printf("\nValores inseridos: 50, 30, 20, 40, 70, 60 e 80.\n\n");

    // Imprimir o percurso EmOrdem da Árvore de Busca Binária
    printf("\nPercurso Em Ordem: ");
    emordem(raiz);

    return 0;

}
