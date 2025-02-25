#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    public:
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack{
    public:
    Node* top;
    
    public:
    Stack(){
        top = NULL;
    }
    
    bool isEmpty(){
        return top == NULL;
    }
    
    void push(int val){
        Node* newNode = new Node(val);
        newNode -> next = top;
        top = newNode;
        cout<<"Pushed "<< val <<" stack"<< endl; 
    }
    
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty";
        }
        
        Node* temp = top;
        top = top -> next;
        temp -> next = NULL;
        cout<<"Pooped " << temp -> data <<" from stack "<<endl;
        delete temp;
    }
    
    void print(){
       if(isEmpty()){
            cout<<"Stack is empty";
        }
        Node* temp = top;
        cout<<"Stack elements: ";
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;
    do{
        cout<<"\n Enter value \n 1: For push a value enter 1. \n 2: For pop a value enter 2. \n 3: For exist program enter 3 \n";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter value to push ";
            cin >> value;
            stack.push(value);
            stack.print();
            break;
            
            case 2:
            stack.pop();
            stack.print();
            break;
            
            case 3:
            cout<<"Exist the program..." << endl;
            break;
            
            default:
            cout<<"Invalid choice Please try adain."<<endl;
        }
    } while(choice != 3);
    
    return 0;
}