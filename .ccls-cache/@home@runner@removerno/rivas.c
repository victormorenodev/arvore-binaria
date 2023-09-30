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
    EmOrdem(x->esq);
    printf("%d\n", x->chave);
    EmOrdem(x->dir);
  }
}

void Remover(No *raiz, int no) {
  No *x = raiz;
  while (x != NULL && x->chave != no) {
    if (no < x->chave) {
      x = x->esq;
    } else {
      x = x->dir;
    }
  }
  printf(
      "\nChave de x: %d;\nChave esq de x: %d;\nChave dir de x: %d;\nChave pai "
      "de x: %d.",
      x->chave, x->esq->chave, x->dir->chave, x->pai->chave);
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
  n8->dir = NULL;

  return raiz;
}

int main(void) {
  No *arvore = CriarArvore();
  EmOrdem(arvore);
  Remover(arvore, 8);
}