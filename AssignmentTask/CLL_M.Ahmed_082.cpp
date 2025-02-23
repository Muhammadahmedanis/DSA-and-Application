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


    void InsertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail -> next = newNode;
        }else {
            newNode -> next = head;
            tail -> next = newNode;
            tail = newNode; 
        }
    }
    
    void DeleteAtHead(){
        if(head == NULL){
            return;
        }else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = head;
            head = head -> next;
            tail -> next = head;
            temp -> next = NULL;
            delete temp;
        }
    }
    
    void DeleteAtTail(){
        if(head == NULL){
            return;
        }else if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* temp = tail;
            Node* prev = head;
            while(prev -> next != tail){
                prev = prev -> next;
            }
            tail = prev;
            tail -> next = prev;
            temp -> next = NULL;
            delete temp;
        }
    }
    
    
    int search(int val){
        Node* temp = head;
        if(head == NULL){
            return -1;
        }
        do {
            if (temp->data == val) {
                return 1;
            }
            temp = temp->next;
        } while (temp != head);
        return -1; 
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
    
    cl.InsertAtTail(4);
    cl.InsertAtTail(3);
    cl.InsertAtHead(2);
    cl.InsertAtHead(1);
    
    cl.DeleteAtHead();
    cl.DeleteAtTail();
    
    cl.print();
    
    cout<<cl.search(3);
    
    return 0;
}