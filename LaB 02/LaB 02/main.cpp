//
//  main.cpp
//  LaB 02
//
//  Created by Muhammad Suhaib Salarzai on 04/11/2020.
//

#include<iostream>

using namespace std;

class Node{   //creating class node
public:
    int data;
    Node *next;

};
class LinkedList{
public:

    Node *start;
    Node *PreLoc;
    Node *Loc;
    Node *last;

    LinkedList(){      //constructor

        start = NULL;
        PreLoc= NULL;
        Loc = NULL;
    }

    bool isEmpty(){
        return start == NULL;
    }

    void insertAtFront(int value){
        Node *newnode = new Node();
        newnode->data = value;
        if (isEmpty())
        {
            start = newnode;
            last = newnode;
            
        }
        else
        {
            
            newnode->next = start;
            start = newnode;
        }
}

    void insertAtEnd(int value){
        Node *newnode = new Node();
        if (isEmpty())
        {
            start = newnode;
            last = newnode;
        }
        else{
            newnode->data = value;
            newnode->next = last->next;
            last->next = newnode;
            last = newnode;
        }
    }

    void printList(){

        Node *temp = start;
        if (!isEmpty())
        while (temp != NULL)
        {
           // cout << "test1" << endl;
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void search(int value){
        Loc = start;
        PreLoc = NULL;

        while (Loc != NULL && Loc->data < value){
            PreLoc = Loc;
            Loc = Loc->next;
        }
        if (Loc != NULL && Loc->data != value)
            Loc = NULL;
        if (isEmpty()){
            return;
            //cout << "List is empty." << endl;
        }
    }
    void insertSorted(int value){
        search(value);
        if (Loc != NULL)
            cout << "value already exist duplication not allowed" << endl;

        else if (Loc == NULL && PreLoc == NULL){
            //cout << "test2" << endl;
            insertAtFront(value);
        }

        else if (Loc == NULL && PreLoc != NULL)
        {
            if (PreLoc == last)
            {
               // cout << "test3" << endl;
                insertAtEnd(value);
            }
            else{
               // cout << "test4" << endl;
                Node *newnode = new Node();
                newnode->data = value;
                newnode->next = PreLoc->next;
                PreLoc->next = newnode;
            }
        }
    }
    void Delete(int value){
        search(value);
        if (Loc != NULL){
            if (PreLoc == NULL){
                if (Loc == last){
                    start = NULL;
                    last = NULL;
                }
                else
                    start = start->next;
                delete Loc;
            }
        }
        else{
            if (Loc == last)
                last = PreLoc;
            PreLoc->next = Loc->next;
            delete Loc;
            
        }
    }
    void DestroyList(){
        while (start != NULL){
            Node *temp = start;
            start = start->next;
            delete temp;
        }
        last = NULL;
    }
};

int main()
{

    LinkedList *Linkly = new LinkedList();

    Linkly->insertSorted(4);
    Linkly->insertSorted(7);
    Linkly->insertSorted(9);
    Linkly->insertSorted(8);
    Linkly->insertSorted(3);
    
    Linkly->insertAtEnd(10);
    Linkly->printList();
    
    Linkly->Delete(3);
    cout<<"After deleting value list is ";
    Linkly->printList();
    
    Linkly->DestroyList();
    cout<<"After destroying list is ";
    Linkly->printList();
    
    return 0;

}
