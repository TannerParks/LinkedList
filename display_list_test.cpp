#include <iostream>
#include "node.h"

using namespace std;

//display each value in the list
void display_list(node *n){ 
    while (n != nullptr){   //checks to see the node isn't null
        cout << n->value << endl;
        n = n->next;    //goes to the next node in the list
    }
}

int main(){
    node *head = nullptr;
    head = new node;

    head->value = 1;
    head->next = nullptr;

    display_list(head);

    return 0;
}