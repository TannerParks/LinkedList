#include <iostream>
#include "node.h"

using namespace std;

class LinkedList{
    private:
        node *head = nullptr;
        node *second = nullptr;
        node *third = nullptr;
    public:
        LinkedList(){
            head = new node;    //head will remain the first in the list even if more nodes are added
            second = new node;  //second and third may no longer be second and third in the list if more nodes are added
            third = new node;

            head->value = 1;    //Adding nodes to the linked list
            head->next = second;

            second->value = 2;
            second->next = third;

            third->value = 3;
            third->next = nullptr;
        
        }

        void add_value(int pos, int new_value){
            node *new_node = new node;  //makes a new node

            new_node->value = new_value; //puts the new value into the new node

            if (pos < 1){
                cout << "Position can't be less than 1." << endl;
            }
            else if (pos == 1){
                new_node->next = head; //moves the old head up one spot
                head = new_node;    //new_node becomes the new head
            }
            else {
                node *temp = head;  //use temp to move around through the nodes
                for(int i = 1; i < pos-1; ++i){
                  if(temp != nullptr) {
                    temp = temp->next;  //makes temp the next node in the list
                  }
            }

            if(temp != nullptr){    //changes the links in the list
              new_node->next = temp->next;
              temp->next = new_node;  
            } 
            else {
              cout<<"\nThe previous node is null.";
            }       
            }
        }

        void remove_node(int pos){
            node *temp = head;  //use temp to move around through the nodes
            node *deleteThis = head;    //this is the node that will get deleted
            if (pos < 1){
                cout << "Position can't be less than 1" << endl; //the nodes start at 1 so there's nothing before 1
            }
            else if (pos == 1 && head != nullptr){  //checks to see if the node in the first position is null
                head = head->next; //moves the second node into the first position
                delete(deleteThis); //free(deleteThis) might be better
            }
            else{
                for (int i = 1; i < pos-1; ++i){ 
                    if (temp != nullptr){
                        temp = temp->next; //makes temp the next node in the list
                    }
                }
                if (temp != nullptr && temp->next != nullptr){  //changes the links in the list
                    deleteThis = temp->next;
                    temp->next = temp->next->next;
                    delete(deleteThis);
                } 
            }

        }

        int display_node(int pos){
        node *temp = head;
        //cout << third->value << endl;
        int count = 1;
        //cout << "Temp Value: " << temp->value << endl;
        while (temp != nullptr){
            if (count == pos){
                cout << temp->value;
                //return temp->value;   //I don't know how to get return to work
            }
            count++;
            temp = temp->next;
            //cout << "Temp Value: " << temp->value << endl;
        }
        return 0;
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

    myList.display_list();
    cout << endl;
    myList.add_value(1, 20);
    myList.add_value(4, 33);
    myList.display_list();
    cout << endl;
    myList.display_node(2);
    cout << endl;
    myList.remove_node(2);
    cout << endl;
    myList.display_list();
    
    return 0;
}