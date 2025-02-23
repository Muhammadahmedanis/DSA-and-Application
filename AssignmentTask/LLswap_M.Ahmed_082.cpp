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

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int num) {
        if (num % 3 == 0) {  
            insertAtEnd(num);
        } else {
            int skipCount = (num % 3 == 1) ? 1 : 2; 
            insertWithSkip(num, skipCount);
        }
    }

    void insertAtEnd(int num) {
        Node* newNode = new Node(num);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertWithSkip(int num, int skipCount) {
        Node* newNode = new Node(num);
        if (!head) {  
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        int skipped = 0;

        while (temp->next && skipped < skipCount) {
            temp = temp->next;
            skipped++;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (!newNode->next) {
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int num;

    cout << "Enter numbers to insert (enter -1 to stop):\n";

    while (true) {
        cin >> num;
        if (num == -1) break;
        list.insert(num);
    }

    cout << "\nFinal Linked List:\n";
    list.display();

    return 0;
}