struct node {
  long val;
  struct node* next;
};

typedef struct node node;
typedef node* nodept;

struct stack {
  long size;
  nodept last;
};

typedef struct stack* stack;

stack newStack();
long top(stack s);
void push(stack s, long i);
long pop(stack s);
void destroy(stack s);
