#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    
    
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void pop_front(){
        if(head == NULL){
            cout<<"Head is not exist";
            return;
        }else{
            Node* temp = head;
            head = head -> next;
            temp->next = NULL;
            delete temp;
        }
    }
    
    void pop_back(){
        if(head == NULL){
            cout<<"Head is not exist";
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    void insert(int val, int pos){
        if(pos < 0){
            cout<<"Po";
            return;
        }else if(pos == 0){
            push_front(val);
            return;
        }else{
            Node* temp = head;
            for(int i = 0; i < pos -1; i++){
                if(temp != NULL){
                    temp = temp->next;
                }
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    int search(int val){
        Node* temp = head;
        int index = 0;
        while(temp != NULL){
            if(temp -> data == val){
                return index;
            }
            temp = temp -> next;
            index++;
        }
        return -1;
    }


    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next; 
        }
        cout << "NULL" << endl; 
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    
    ll.push_back(4);
    
    ll.pop_front();
    
    ll.pop_back();
    
    ll.insert(4, 1);
    
    cout<<ll.search(2)<<endl;
    
    ll.printLL();
    
    return 0;
}
