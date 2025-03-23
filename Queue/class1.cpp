#include <iostream>
using namespace std;

class Queue{
    int *arr;
    int size;
    int rear = -1;
    
    public:
    Queue(int size){
        this -> size = size;
        arr = new int[size];
    }
    
    bool isEmpty(){
        return rear == -1;
    };
    
    void enqueue(int data){
        if(rear == size-1){
            cout<<"Stack full";
            return;
        }
        arr[++rear] = data;
    };
    
    int dequeue(){
        if(isEmpty()){
            cout<<"Empty queue";
            return 0;
        }
        
        int front = arr[0];
        for(int i = 0; i < rear; i++){
            arr[i] = arr[i + 1];
        }
        rear--;
        return front;
    };
    
    int getTop(){
        if(isEmpty()){
            cout<<"Empty queue";
            return 0;
        }
        return arr[0];
    }
};


struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;
    
    public:
    Queue(){
        rear = front = NULL;
    };
    
    bool isEmpty(){
        return front == NULL;
    }
    
    void enqueue(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            front = rear = newNode;
        }else{
            rear -> next = newNode;
            rear = newNode;
        }
    };
    
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty";
        }
        Node* temp = front;
        front = front -> next;
        delete temp;
    };
    
    int getFront(){
        return front -> data;
    }
    
};


int main() {
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.getTop()<<endl;
    cout<<q.dequeue();
    while(!q.isEmpty()){
        cout<<q.dequeue()<<" ";
    }
    
    
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    
    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.dequeue();
    }
    
    return 0;
}















#include <iostream>
using namespace std;

class circularQueue{
    int *arr;
    int currSize, cap;
    int front, rear;
    
    public:
    Queue(int size){
        front = 0;
        rear = -1;
        currSize = 0;
        cap = size;
        this -> size = size;
        arr = new int[cap];
    }
    
    bool isEmpty(){
        return currSize == 0;
    };
    
    void enqueue(int data){
        if(currSize < 0){
            cout<<"Stack full";
        }
        rear = ( rear + 1 ) % cap;
        arr[rear] = data;
        currSize++;
    };
    
    void dequeue(){
        if(isEmpty()){
            cout<<"Empty queue";
            return 0;
        }
        front = ( front + 1 ) % cap;
        currSize--;
    };
    
    int getTop(){
        if(isEmpty()){
            cout<<"Empty queue";
            return 0;
        }
        return arr[front];
    }
};


int main() {
    circularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.getTop()<<endl;
    cout<<q.dequeue();
    while(!q.isEmpty()){
        cout<<q.dequeue()<<" ";
    }
    
    return 0;
}