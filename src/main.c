#include "Include/linkedlist.h"

void test1();
void test2();

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}

void test1() {
    LinkedList* list = create_list();
    put(list, 3);
    put(list, 5);
    put(list, 7);
    put(list, 55);
    put(list, 1);
    put(list, 0);
    
    print(list);

    int data = remove_first(list);
    printf("Removed value: %d\n", data);

    print(list);
}