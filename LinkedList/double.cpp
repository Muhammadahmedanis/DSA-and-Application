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
    Node* next;
    Node* prev;
    int data;
    
    Node(int data){
        this -> data = data;
        next = prev = NULL;
    }
};


Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        temp -> prev = mover;
        mover = temp;
    }
    return head;
};


Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    head -> prev = NULL;
    delete temp;
    return head;
};


Node* removeTail(Node* head){
    if(head == NULL) return head;
    if(head -> next == NULL){
        delete head;
        head = NULL;
        return NULL;
    };
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = NULL;
    delete temp -> next;
    return head;
};



Node* insertAt(Node* head, int val, int pos){
    if(pos < 0 && val < 0) return head;
    Node* newNode = new Node(val);
    if(pos == 0){
        Node* temp = head;
        newNode -> next = temp;
        temp -> prev = newNode;
        temp = newNode;
        return temp;
    };
    Node* temp = head;
    for(int i = 0; i < pos-1; i++){
        temp = temp -> next;
    }
    
    if(temp == NULL) return head;
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    
    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    
    temp -> next = newNode;
    return head;
};



Node* removeVal(Node* head, int val){
    if(head == NULL) return head;   
    Node* temp = head;
    if(temp -> data == val){
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete temp;
        return head;
    }
    while(temp != NULL && temp->data != val){
        temp = temp -> next;
    }
    temp -> prev -> next = temp -> next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    delete temp;
    return head;
};



Node* removePos(Node* head, int pos) {
    if (head == NULL || pos < 0) return head;
    Node* temp = head;
    if (pos == 0) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        return head;
    }
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return head;
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    return head;
};



int main() {
    vector<int> arr = {3, 5, 1, 89, 32};
    Node* head = convertArr2DLL(arr);
    // head = removeHead(head);
    // head = removeTail(head);
    // head = insertAt(head, 4, 1);
    // head = removeVal(head, 89);
    // head = removePos(head, 1);

    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<"<=>";
        temp = temp -> next;
    };
    
    return 0;
}
