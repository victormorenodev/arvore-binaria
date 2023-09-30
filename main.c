#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *esq;
  struct no *dir;
  struct no *pai;
} No;

void EmOrdem(No *x) {
  if (x != NULL) {
    printf("%d\n", x->chave);
    EmOrdem(x->esq);
    EmOrdem(x->dir);
  }
}

void Remover(No *raiz, int no) {
  No *x = raiz;
  No *pai = NULL;

  // Busca o elemento no
  while (x != NULL && x->chave != no) {
    pai = x;
    if (no < x->chave) {
      x = x->esq;
    } else {
      x = x->dir;
    }
  }

  // Caso no não tenha filhos
  if (x->esq == NULL && x->dir == NULL) {
    if (pai->dir == x) {
      pai->dir = NULL;
    } else {
      pai->esq = NULL;
    }
  }

  // Caso no só tenha um filho
  else if ((x->esq == NULL || x->dir == NULL) && (x->esq != x->dir)) {
    No *filho_do_removido;
    if (x->dir != NULL) {
      filho_do_removido = x->dir;
    } else {
      filho_do_removido = x->esq;
    }
    if (pai->dir == x) {
      pai->dir = filho_do_removido;
      filho_do_removido->pai = pai;
    } else {
      pai->esq = filho_do_removido;
    }
  }

  // Caso no tenha dois filhos
  else if (x->esq != NULL && x->dir != NULL) {
    No *pai_min;
    No *min = x->dir;
    while (min->esq != NULL) {
      pai_min = min;
      min = min->esq;
    }
    printf("\n\nSUCESSOR: %d\n", min->chave);
    Remover(x, min->chave);
    if (pai->dir == x) {
      pai->dir = min;
    } else {
      pai->esq = min;
    }
    min->pai = pai;
    min->dir = x->dir;
    min->esq = x->esq;
    min->dir->pai = min;
    min->esq->pai = min;
    x->pai = NULL;
    x->esq = NULL;
    x->dir = NULL;
  }

  // Imprime informações importantes
  printf("\n\nElemento removido: %d\n\n", x->chave);

  printf("\nChave do pai do elemento removido: %d;", pai->chave);

  if (pai->pai == NULL) {
    printf("\nChave pai de pai: NULL;");
  } else {
    printf("\nChave pai de pai: %d;", pai->pai->chave);
  }
  if (pai->esq == NULL) {
    printf("\nChave esq de pai: NULL;");
  } else {
    printf("\nChave esq de pai: %d;", pai->esq->chave);
  }
  if (pai->dir == NULL) {
    printf("\nChave dir de pai: NULL.\n\n");
  } else {
    printf("\nChave dir de pai: %d.\n\n", pai->dir->chave);
  }
}

No *CriarArvore() {
  No *raiz = (No *)malloc(sizeof(No));
  No *n0 = (No *)malloc(sizeof(No));
  No *n1 = (No *)malloc(sizeof(No));
  No *n2 = (No *)malloc(sizeof(No));
  No *n4 = (No *)malloc(sizeof(No));
  No *n5 = (No *)malloc(sizeof(No));
  No *n6 = (No *)malloc(sizeof(No));
  No *n7 = (No *)malloc(sizeof(No));
  No *n8 = (No *)malloc(sizeof(No));
  No *n9 = (No *)malloc(sizeof(No));

  raiz->chave = 3;
  raiz->pai = NULL;
  raiz->esq = n1;
  raiz->dir = n5;

  n1->chave = 1;
  n1->pai = raiz;
  n1->esq = n0;
  n1->dir = n2;

  n0->chave = 0;
  n0->pai = n1;
  n0->esq = NULL;
  n0->dir = NULL;

  n2->chave = 2;
  n2->pai = n1;
  n2->esq = NULL;
  n2->dir = NULL;

  n5->chave = 5;
  n5->pai = raiz;
  n5->esq = n4;
  n5->dir = n7;

  n4->chave = 4;
  n4->pai = n5;
  n4->esq = NULL;
  n4->dir = NULL;

  n7->chave = 7;
  n7->pai = n5;
  n7->esq = n6;
  n7->dir = n8;

  n6->chave = 6;
  n6->pai = n7;
  n6->esq = NULL;
  n6->dir = NULL;

  n8->chave = 8;
  n8->pai = n7;
  n8->esq = NULL;
  n8->dir = n9;

  n9->chave = 9;
  n9->pai = n8;
  n9->esq = NULL;
  n9->dir = NULL;

  return raiz;
}

int main(void) {
  No *arvore = CriarArvore();
  EmOrdem(arvore);
  Remover(arvore, 7);
  EmOrdem(arvore);
}