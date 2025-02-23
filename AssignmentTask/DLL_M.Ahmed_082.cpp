#include <iostream>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyLL{
    Node* head;
    Node* tail;
    
    public:
    DoublyLL(){
        head = tail = NULL;
    }
    
    void push_Front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    
    void push_Back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void pop_Front(){
        Node* temp = head;
        head = head -> next;
        if(head == NULL){
            cout<<"Empty List!";
        }else{
            head -> prev = NULL;
            temp -> next = NULL;
            delete temp;
        }
    }
    
    void pop_Back(){
        Node* temp = tail;
        tail = tail -> prev;
        if(tail == NULL){
             cout<<"Empty List";
        }else{
            tail -> next = NULL;
            temp -> prev = NULL;
            delete temp;
        }
    }
    
    int search(int val){
        Node* temp = head;
        if(head == NULL){
            return -1;
        }else{
            while(temp != NULL){
                if(temp -> data == val){
                    return 1;
                }
                temp = temp -> next;
            }
                return -1;
        }
    }
    
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data << " <=> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};


int main() {
    DoublyLL dl;
    dl.push_Front(2);
    dl.push_Front(1);
    
    dl.push_Back(1);
    dl.push_Back(2);
    dl.push_Back(3);
    dl.push_Back(4);
    
    
    dl.pop_Front();
    
    dl.pop_Back();
    
    dl.print();
    
    cout<<dl.search(2);
    
    return 0;
}