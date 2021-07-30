#include "node.h"
#include <limits.h>
#include <string.h>

struct linked_list
{
    struct node * head; //First node in the list
    struct node * tail; //Last node in the list
    int size; //Current amount of nodes in the list
};

struct linked_list * new_list() //Returns a new linked_list
{
    struct linked_list * new_list = malloc(sizeof(struct linked_list));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

void add_node(struct linked_list * list, struct node * node)  //Adds the entered node to the list
{
    if (list->head == NULL) 
    {
        list->head = node;
    } else 
    {
        list->tail->nextNode = node;
    }
    list->tail = node;
    list->size++;
}

void add_value(struct linked_list * list, int value) //Adds a new node with the entered value to the list
{
    struct node * node = new_node(value);
    node->value = value;
    add_node(list, node);
}

void index_to_big() 
{
    printf("\033[1;31m");
    printf("Index cannot be bigger than size! \n");
    printf("\033[0m");
}

int get_value(struct linked_list * list, int index) //Gets the value of the node at index
{
    if (index >= list->size) 
    {
        index_to_big();
    }

    struct node * currentNode = list->head;
    for (int i = 0; i < index; i++) 
    {
        currentNode = currentNode->nextNode;
    }

    return currentNode->value;
}

int get_index_of(struct linked_list * list, int value) //Returns the index of the first node with a matching value to index. Returns -1 if no match is found
{
    int index = 0;
    struct node * current_node = list->head;
    while (current_node != NULL) 
    {
        if (current_node->value == value)
        {
            break;
        }

        current_node = current_node->nextNode;
        index++;

        if (current_node == NULL) 
        {
            index = -1;
        }
    }
    return index;
}

struct node * get_node(struct linked_list * list, int index) //Returns the node at the entered index in the list
{
    if (index >= list->size) 
    {
        index_to_big();
    }

    struct node * currentNode = list->head;
    for (int i = 0; i < index; i++) 
    {
        currentNode = currentNode->nextNode;
    }

    return currentNode;
}

void remove_node(struct linked_list * list, int index) //Removes the node at the entered index of the list
{
    if (index >= list->size) 
    {
        index_to_big();
    }

    if (index == 0) 
    {
        struct node * orphaned_node = list->head;
        list->head = orphaned_node->nextNode;
        free(orphaned_node);
    } else 
    {
        struct node * parent = get_node(list, index - 1);
        struct node * orphaned_node = parent->nextNode;
        parent->nextNode = orphaned_node->nextNode;
        free(orphaned_node);
    }
}

//Removes the first node in list that's value matches the entered value. If a match is found returns 1 otherwise returns -1
int remove_value(struct linked_list * list, int value)
{
    int result = -1;
    if (list->head->value == value) 
    {
        struct node * orphaned_node = list->head;
        list->head = orphaned_node->nextNode;
        free(orphaned_node);
        result = 1;
    } else 
    {
        struct node * current_node = list->head->nextNode;
        struct node * previous_node = list->head;
        while (current_node != NULL)
        {
            if (current_node->value == value) 
            {
                previous_node->nextNode = current_node->nextNode;
                free(current_node);
                result = 1;
                break;
            }
            previous_node = current_node;
            current_node = current_node->nextNode;
        }
    }
    return result;
}

char * to_string(struct linked_list * list)
{
    static char result[1] = "[";
    struct node * current_node = list->head;
    while (current_node != NULL)
    {
        char * value;
        sprintf(value, "%i", current_node->value);
        realloc(result, sizeof(result) + sizeof(value) + 2);
        strcat(result, value);
        current_node = current_node->nextNode;
        if (current_node != NULL)
        {
            strcat(result, ", ");
        }
        free(value);
    }
    strcat(result, "]");
    return result;
}