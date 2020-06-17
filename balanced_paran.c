#include<stdio.h>
#include<stdlib.h>

struct stack_node {
   char data;
   struct stack_node *next;
};

void push (struct stack_node **root, char data) {
   struct stack_node *newnode;
   newnode = malloc(sizeof(struct stack_node));
   if (!newnode) {
      return;
   }
   newnode->data = data;
   newnode->next = *root;
   *root = newnode;
}

char pop(struct stack_node **root) {
   struct stack_node *temp;
   char data;

   if (!(*root)) {
      printf("stack is empty, cant pop anything...\n");
      return '\0';
   }
   temp = *root;
   *root = temp->next;
   data = temp->data;
   free(temp);
   return data;
}

void print(struct stack_node *root) {
    while (root!= NULL) {
       printf("<%c> --> ", root->data);
       root = root->next;
    }
}

int main() {
   struct stack_node *root = NULL;
   push(&root, 'a');
   push(&root, 'b');
   push(&root, 'c');
   printf("\n...<%c>..\n", pop(&root));
}
