struct node {
  int val;
  struct node* next;
};

typedef struct node node;
typedef node* nodept;

struct stack {
  int size;
  nodept last;
};

typedef struct stack* stack;

stack newStack();
int top(stack s, int i);
void push(stack s, int i);
int pop(stack s);
void destroy(stack s);
