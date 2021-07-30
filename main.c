#include <stdio.h>
#include "LinkedList/linked_list.h"

int main(int argc, char const *argv[])
{
    struct linked_list * list = new_list();
    add_value(list, 10);
    add_value(list, 100);
    add_value(list, 1000);
    remove_value(list, 1000);
    char * string_list = to_string(list);
    printf(string_list);
    return 0;
}
