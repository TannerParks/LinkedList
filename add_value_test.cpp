#include <iostream>
#include "node.h"

using namespace std;

class LinkedList{
    private:
        node *head;
    public:
        LinkedList(){
            node *head = nullptr;
        
        }

        void add_value(int pos, int new_value){
            node *new_node = new node;
            int count;

            new_node->value = new_value;
            //new_node->next = nullptr;

            if (pos < 1){
                cout << "Position can't be less than 1." << endl;
            }
            else if (pos == 1){
                new_node->next = head; //puts old head the next node after the new one
                head = new_node;
            }
            else {
        
            node *temp = head;
            for(int i = 1; i < pos-1; i++) {
              if(temp != nullptr) {
                temp = temp->next;
              }
            }

            if(temp != nullptr) {
              new_node->next = temp->next;
              temp->next = new_node;  
            } 
            else {
              cout<<"\nThe previous node is null.";
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

    myList.add_value(1, 20);
    myList.add_value(2, 33);
    myList.display_list();

    return 0;
}