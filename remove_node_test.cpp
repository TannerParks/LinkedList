#include <iostream>
#include "node.h"

using namespace std;

class LinkedList{
    private:
        //node *head;
        node *head = nullptr;
        node *second = nullptr;
        node *third = nullptr;
    public:
        LinkedList(){
            head = new node;
            second = new node;
            third = new node;

            head->value = 1;
            head->next = second;

            second->value = 2;
            second->next = third;

            third->value = 3;
            third->next = nullptr;
        
        }

    void remove_node(int pos){
        node *temp = head;
        node *deleteThis = head;
        if (pos < 1){
            cout << "Position can't be less than 1" << endl;
        }
        else if (pos == 1 && head != nullptr){
            head = head->next; //moves the second node into the first position
            delete(deleteThis); //free(deleteThis) might be better
        }
        else{
            for (int i = 1; i < pos-1; ++i){ 
                if (temp != nullptr){
                    temp = temp->next; //moves around the nodes
                }
            }
            if (temp != nullptr && temp->next != nullptr){
                deleteThis = temp->next;
                temp->next = temp->next->next;
                delete(deleteThis);
            } 
        }
        
    }

    void display_list(){ 
        node *n = head;
        while (n != nullptr){   //checks to see the node isn't null
            cout << n->value << endl;
            n = n->next;    //goes to the next node in the list
        }
    }
};

int main(){
    LinkedList myList;

    //myList.remove_node(2);
    myList.display_list();
    myList.remove_node(1);
    cout << endl;
    myList.display_list();

    return 0;
}