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

class Queue{
    public:
    Node* front;
    Node* rear;
    
    public:
    Queue(){
        front = rear = NULL;
    }
    
    bool isEmpty(){
        return front == NULL;
    }
    
    void enqueue(int val){
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << val << " into queue" << endl;
    }
    
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        cout << "Dequeued " << temp->data << " from queue" << endl;
        delete temp;
    }
    
    void print(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice, value;
    do{
        cout << "\n Enter choice:\n 1: Enqueue value\n 2: Dequeue value\n 3: Exit program\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                queue.print();
                break;
            case 2:
                queue.dequeue();
                queue.print();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 3);
    
    return 0;
}