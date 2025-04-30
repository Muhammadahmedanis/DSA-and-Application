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

    private:
    Node* lastNode(Node* node) {
        while (node && node->next)
            node = node->next;
        return node;
    }

    Node* partition(Node* low, Node* high) {
        int pivot = high->data;
        Node* i = low->prev;

        for (Node* j = low; j != high; j = j->next) {
            if (j->data <= pivot) {
                i = (i == NULL) ? low : i->next;
                swap(i->data, j->data);
            }
        }
        i = (i == NULL) ? low : i->next;
        swap(i->data, high->data);
        return i;
    }

    void _quickSort(Node* low, Node* high) {
        if (high != NULL && low != high && low != high->next) {
            Node* p = partition(low, high);
            _quickSort(low, p->prev);
            _quickSort(p->next, high);
        }
    }

    void quickSort() {
        Node* last = lastNode(head);
        _quickSort(head, last);
    }
};


int main() {
    DoublyLL dl;
    dl.push_Front(2);
    dl.push_Front(1);
    
    dl.push_Back(30);
    dl.push_Back(3);
    dl.push_Back(4);
    dl.push_Back(20);
    dl.push_Back(5);

    cout << "Before Sorting: ";
    dl.print();

    dl.quickSort();

    cout << "After Quick Sort: ";

    dl.print();

    // cout<<dl.search(2);    
    return 0;
}



    // 2nd Approach ************************************************

#include <iostream>
#include <vector>
using namespace std;
struct Node{
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
    
    void convertArr2DLL(vector<int> &arr){
       if (arr.empty()) return;
        head = new Node(arr[0]);
        Node* mover = head;

        for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            temp->prev = mover;
            mover = temp;
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
    vector<int>  arr = {12, 5, 7, 8};
    dl.convertArr2DLL(arr);
    dl.print();
    
    return 0;
}
