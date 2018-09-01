#include<stdio.h>
#include<stdlib.h>

typedef struct ArvBin {
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
} NO;

// Uma fun��o para criar um novo n� na �rvore de Busca Bin�ria
NO *novoNo(int item) {
    NO *temp =  (NO *)malloc(sizeof(NO));
    temp->info = item;
    temp->esq = temp->dir = NULL;
    return temp;
}

// Guilherme Cardozo | 01/09/2018 - fun��o para imprimir a �rvore em pr� ordem (RAIZ, ESQ, DIR)
void preOrdem(NO *raiz) {
    if(raiz != NULL) {
        printf("%d ", raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Uma fun��o para fazer o percurso EmOrdem na �rvore de Busca Bin�ria
void emordem(NO *raiz) {
    if(raiz != NULL) {
        emordem(raiz->esq);
        printf("%d ", raiz->info);
        emordem(raiz->dir);
    }
}

// Guilherme Cardozo | 01/09/2018 - fun��o para imprimir a �rvore em p�s ordem (ESQ, DIR, RAIZ)
void posOrdem(NO *raiz) {
    if(raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->info);
    }
}

// Uma fun��o para inserir um novo n� com uma dada chave (info) na �rvore de Busca Bin�ria
NO *insere(NO *no, int info) {
    // Se a �rvore estiver vazia, retorne um novo n�
    if (no == NULL)
        return novoNo(info);

    // Caso contr�rio, volte pela �rvore
    if (info < no->info)
        no->esq  = insere(no->esq, info);
    else if (info > no->info)
        no->dir = insere(no->dir, info);

    // retorna o ponteiro do n� (inalterado)
    return no;
}

// Teste das fun��es
int main()
{
    /* Criar a seguinte �rvore de Busca Bin�ria
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

    printf("\n�rvore de Busca Bin�ria: Inser��o e Percurso;\n\n");
    printf("\nValores inseridos: 50, 30, 20, 40, 70, 60 e 80.\n\n");

    // Imprimir o percurso EmOrdem da �rvore de Busca Bin�ria
    printf("\nPercurso Em Ordem: ");
    emordem(raiz);

    printf("\nPercurso em pr� ordem: ");
    preOrdem(raiz);

    printf("\nPercurso em p�s-ordem: ");
    posOrdem(raiz);
    return 0;

}
