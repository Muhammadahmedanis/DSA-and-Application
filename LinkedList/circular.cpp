#include <iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLL{
    Node* head;
    Node* tail;
    
    public:
    CircularLL(){
        head = tail = NULL;
    }
    
    void InsertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail -> next = newNode;
        }else {
            newNode -> next = head;
            head = newNode; 
            tail -> next = newNode;
        }
    }
    
    void print(){
        if(head == NULL) return;
        Node* temp = head;
         do {
            cout << temp->data << " <=> ";
            temp = temp->next;
        } while(temp != head);
        
        cout<<"HEAD\n";
    }
};


int main() {
    CircularLL cl;
    cl.InsertAtHead(2);
    cl.InsertAtHead(1);
    
    cl.print();
    
    return 0;
}
