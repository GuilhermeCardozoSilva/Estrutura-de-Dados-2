#include<stdio.h>
#include<stdlib.h>

typedef struct ArvBin {
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
} NO;

// Uma função para criar um novo nó na Árvore de Busca Binária
NO *novoNo(int item) {
    NO *temp =  (NO *)malloc(sizeof(NO));
    temp->info = item;
    temp->esq = temp->dir = NULL;
    return temp;
}

// Guilherme Cardozo | 01/09/2018 - função para imprimir a árvore em pré ordem (RAIZ, ESQ, DIR)
void preOrdem(NO *raiz) {
    if(raiz != NULL) {
        printf("%d ", raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

// Uma função para fazer o percurso EmOrdem na Árvore de Busca Binária
void emordem(NO *raiz) {
    if(raiz != NULL) {
        emordem(raiz->esq);
        printf("%d ", raiz->info);
        emordem(raiz->dir);
    }
}

// Guilherme Cardozo | 01/09/2018 - função para imprimir a árvore em pós ordem (ESQ, DIR, RAIZ)
void posOrdem(NO *raiz) {
    if(raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->info);
    }
}

// Uma função para inserir um novo nó com uma dada chave (info) na Árvore de Busca Binária
NO *insere(NO *no, int info) {
    // Se a árvore estiver vazia, retorne um novo nó
    if (no == NULL)
        return novoNo(info);

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

    // Guilherme Cardozo | 01/09/2018 - Criação do menu
    int opcao, info;
    system("clear");
    printf("\nValores inseridos: 50, 30, 20, 40, 70, 60 e 80.");
    do {
        printf("\n\n------------------ ARVORE DE BUSCA BINARIA ------------------\n\n");
        printf("[1] Excluir elemento da arvore.\n");
        printf("[2] Imprimir arvore em pré ordem.\n");
        printf("[3] Imprimir arvore em ordem.\n");
        printf("[4] Imprimir arvore em pós ordem.\n");
        printf("[0] Sair.\n");
        printf("Digite a opção desejada: \n");

        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                system("clear");
                printf("Digite o valor que você quer eliminar da arvore: \n");
                scanf("%d", &info);
                system("clear");
                break;
            case 2:
                system("clear");
                printf("\nPercurso em pré ordem: ");
                preOrdem(raiz);
                break;
            case 3:
                system("clear");
                printf("\nPercurso em ordem: ");
                emordem(raiz);
                break;
            case 4:
                system("clear");
                printf("\nPercurso em pós-ordem: ");
                posOrdem(raiz);
                break;
            case 0:
                system("clear");
                break;
            default:
                system("clear");
                printf("\nOperação inválida, verifique se o número que você digitou está no menu.\n");
        }
    } while(opcao != 0);
    return 0;
}
