/*
   Guilherme Cardozo da Silva
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct ArvBin {
    int info;
    struct ArvBin *esq;
    struct ArvBin *dir;
} NO;

/* declaração das funções utilizadas no código */
int arvoreEhVazia(NO *raiz) ;
void preOrdem(NO *raiz);
void emordem(NO *raiz);
void posOrdem(NO *raiz);
NO *insere(NO *no, int info);
int buscaElemento(NO *raiz, int info);

// Uma função para criar um novo nó na Árvore de Busca Binária
NO *novoNo(int item) {
    NO *temp =  (NO *)malloc(sizeof(NO));
    temp->info = item;
    temp->esq = temp->dir = NULL;
    return temp;
}

/* função que verifica se a árvore está vazia*/
int arvoreEhVazia(NO *raiz) {
    // retina 1 se árvore for vazia e o 0 caso não seja vazia
    return raiz == NULL;
}


/* função para imprimir a árvore em pré ordem (RAIZ, ESQ, DIR) */
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

/* função para imprimir a árvore em pós ordem (ESQ, DIR, RAIZ) */
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

/* funçaõ responsável por tratar os 3 casos de remoção */
NO* remove_atual(NO* atual) {
    NO *no1, *no2;
    /* se não tem filho na esquerda, aponta para o filho da direita.
	   Trata o nó folha e o nó com 1 filho.*/
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    /* procura o filho mais a direita na sub=árvore da esquerda */
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior (a esquerda) da raiz 
    // no1 é o pai de no2
    /* copia o filho mais a direita na sub-árvore esquerda para o lugar
       do nó removido */
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

/* função responsavél por remover um nó da árvore */
int remove_ArvBin(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    NO* ant = NULL;
    NO* atual = raiz;
    while(atual != NULL){
        // Achou o nó a ser removido e verifica de qual lado irá remover
        if(valor == atual->info){
            if(atual == raiz)
                raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        //  busca o nó a ser removido
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
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
    int opcao, info, achou;
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
                if(remove_ArvBin(raiz, info) == 1)
					printf("Elemento %d removido com sucesso!", info);
				else
					printf("Não existe esse elemento na árvore.");
                //system("clear");
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
