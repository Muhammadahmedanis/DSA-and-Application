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
        }else if(pos == 0){
            push_front(val);
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
        while(temp != NULL){
            temp = temp -> next;
            if(temp -> data == val){
                return 1;
            }
        }
        return 0;
    };

    void searchAll(int data){
        if(head != NULL){
           Node* temp = head;
           vector<int>arr;
           while(temp != NULL){
               if(temp -> data == data){
                   arr.push_back(data);
               }
               temp = temp -> next;
           }
           cout<<"value found "<<arr.size()<<" times"<<endl;
       }
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


// 2nd Approach
#include <iostream>
#include <vector>
using namespace std;


struct Node{
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};


Node* convertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
};

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
};



Node* removeTail(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = NULL;
    delete temp -> next;
    return head;
};


Node* removePos(Node* head, int pos){
    if(pos < 0) return head;
    if(pos == 0) return removeHead(head);
    
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    
    while(temp != NULL){
        if(count == pos){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        count++;
        prev = temp;
        temp = temp -> next;
    }
    
    return head;
};


Node* removeValue(Node* head, int val){
    if(val < 0) return head;
    Node* temp = head;
    if(val == temp -> data) return removeHead(head);
    Node* prev = NULL;
    while(temp != NULL){
        if(temp -> data == val){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
};


Node* insertAt(Node* head, int val, int pos){
    if(val < 0 && pos < 0) return head;
    if(pos == 0){
        Node* temp = head;
        Node* newNode = new Node(val); 
        newNode -> next = temp;
        temp = newNode;
        return temp;
    }
    Node* temp = head;
    for(int i = 0; i < pos-1; i++){
        temp = temp -> next;
    }
    Node* newNode = new Node(val);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    return head;  
};


int findMin(Node* head){
    if(head == NULL){
        cout<<"List is empty";
        return -1;
    }
    int minVal = head -> data;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data < minVal){
            minVal = temp -> data;
        }   
        temp = temp -> next;
    }
    return minVal;
};


int findMax(Node* head){
    if(head == NULL){
        cout<<"List is empty";
        return -1;
    }
    int minVal = head -> data;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data > minVal){
            minVal = temp -> data;
        }   
        temp = temp -> next;
    }
    return minVal;
};


int sumLL(Node* head){
    int sum = 0;
    Node* temp = head;
    while(temp != NULL){
        sum += temp -> data;
        temp = temp -> next;
    }
    return sum;
};


int main() {
    vector<int> arr = {2, 5, 7, 8};
    Node* head = convertArr2LL(arr);
    head = removeHead(head);
    head = removeTail(head);
    head = removePos(head, 1);
    head = removeValue(head, 5);
    head = insertAt(head, 1, 1);
    
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<"->";
        temp = temp -> next;
    };
    cout<<"NULL\n";

    cout<<"\nSum: "<<sumLL(head);

    cout<<"\nMin value: "<<findMin(head);
    cout<<"\nMax value: "<<findMax(head);
}