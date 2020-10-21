#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
    struct node * next;
    int data;
}
void add_at_beg(struct node ** head,int data){
    struct node * temp = malloc(sizeof(struct node));
    temp->next = *head;
    temp->data = data;
    *head = temp;
}
void store_
