#include <stddef.h>
#include <stdlib.h>
#include "stack.h"

stack newStack()
{
  stack s;
  s = (stack) malloc(sizeof(struct stack));
  s->size = 0;
  s->last = NULL;
  return s;
}

long top(stack s)
{
  return s->last->val;
}

void push(stack s, long i)
{
  s->size++;
  nodept aux = s->last;
  s->last = (nodept)malloc(sizeof(node));
  s->last->next = aux;
  s->last->val = i;
}

long pop(stack s)
{
  node *aux = s->last;
  s->size--;
  s->last = s->last->next;
  int aux2 = aux->val;
  free(aux);
  return aux2;
}

void destroy(stack s)
{
  while(s->size>0) {
    pop(s);
  }
  free(s);
}
