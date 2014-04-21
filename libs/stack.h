typedef struct node {
  long val;
  struct node *next;
} node, *nodept;

typedef struct stack2 {
  long size;
  nodept last;
} *stack;

stack newStack();
long top(stack s);
void push(stack s, long i);
long pop(stack s);
void destroy(stack s);
