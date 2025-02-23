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

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void swapNodes(int x, int y) {
        if (x == y) return;

        Node *prevX = NULL, *currX = head;
        Node *prevY = NULL, *currY = head;

        // Find node X and its previous node
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        // Find node Y and its previous node
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        // If either node is not found, return
        if (!currX || !currY) return;

        // Update previous node pointers
        if (prevX) prevX->next = currY;
        else head = currY;

        if (prevY) prevY->next = currX;
        else head = currX;

        // Swap next pointers
        Node* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
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

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.printLL();

    int x, y;
    cout << "Enter two values to swap: ";
    cin >> x >> y;

    ll.swapNodes(x, y);
    ll.printLL();

    return 0;
}
