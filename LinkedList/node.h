#include <stdlib.h>

struct node 
{
    int value;
    struct node * nextNode;
};

struct node * new_node(int value) 
{
    struct node * new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->nextNode = NULL;
    return new_node;
}