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

            second->value = 400;
            second->next = third;

            third->value = 3;
            third->next = nullptr;
        
        }

    int display_node(int pos){
        node *temp = head;
        //cout << third->value << endl;
        int count = 1;
        //cout << "Temp Value: " << temp->value << endl;
        while (temp != nullptr){
            if (count == pos){
                //return temp->value;   //why doesn't return work here???????????????????
                cout << temp->value;
            }
            count++;
            temp = temp->next;
            //cout << "Temp Value: " << temp->value << endl;
        }
        return 0;
    }
};

int main(){
    LinkedList myList;

    myList.display_node(2);

    return 0;
}