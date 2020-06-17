#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * append_node(int data, struct node *last, struct node **root) {
     struct node *newnode;

     newnode = malloc(sizeof(struct node));
     if (!newnode) {
         printf("malloc failed..\n");
         return;
     }
     newnode->data = data;
     if (*root == NULL) {
         *root = newnode;
     } else {
         last->next = newnode;
     }
     newnode->next = *root;
     return newnode;
}

int survivor(int len, int k) {
    int count = 1, i;
    struct node *start_root, *prev;
    

    struct node *root = NULL, *newnode = NULL;
    for (i = 1; i<=len; i++) {
        newnode = append_node(i, newnode, &root);
    }

    start_root = root;

    if (k == 1) {
        while ((root->next) != start_root){
           root = root->next;
        }
        return root->data;
    }
    while (len != 1) {
        if (count == k) {
           count = 0;
           len--;
           prev->next = root->next;
        }
        count++;
        prev = root;
        root = root->next;
    }
    return root->data;
}

int main() {
    printf("last guy : <%d>...\n", survivor(7, 3));
    printf("last guy : <%d>...\n", survivor(11, 19));
    printf("last guy : <%d>...\n", survivor(1, 300));
    printf("last guy : <%d>...\n", survivor(14, 2));
    printf("last guy : <%d>...\n", survivor(100, 1));
}

