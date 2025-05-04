#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct TernaryNode {
    int data;
    TernaryNode* LChild;
    TernaryNode* MChild;
    TernaryNode* RChild;
    
    TernaryNode(int val) {
        data = val;
        LChild = MChild = RChild = nullptr;
    }
};

TernaryNode* insert(TernaryNode* root, int val) {
    if (root == nullptr) {
        return new TernaryNode(val);
    }

    if (val < root->data) {
        root->LChild = insert(root->LChild, val);
    } else if (val == root->data) {
        root->MChild = insert(root->MChild, val);
    } else {
        root->RChild = insert(root->RChild, val);
    }

    return root;
}


TernaryNode* search(TernaryNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (val == root->data) {
        return root;
    } else if (val < root->data) {
        return search(root->LChild, val);
    } else {
        return search(root->RChild, val);
    }
}


TernaryNode* Min(TernaryNode* node) {
    while (node && node->LChild) {
        node = node->LChild;
    }
    return node;
}


TernaryNode* Max(TernaryNode* node) {
    while (node && node->RChild) {
        node = node->RChild;
    }
    return node;
}


TernaryNode* delNode(TernaryNode* root, int val) {
    if (root == nullptr) {
        return root;
    }

    if (val < root->data) {
        root->LChild = delNode(root->LChild, val);
    } else if (val > root->data) {
        root->RChild = delNode(root->RChild, val);
    } else {
        if (root->MChild) {
            root->MChild = delNode(root->MChild, val);
        } else {
            if (!root->LChild && !root->RChild) {
                delete root;
                return nullptr;
            } else if (!root->LChild) {
                TernaryNode* temp = root->RChild;
                delete root;
                return temp;
            } else if (!root->RChild) {
                TernaryNode* temp = root->LChild;
                delete root;
                return temp;
            } else {
                TernaryNode* temp = Min(root->RChild);
                root->data = temp->data;
                root->RChild = delNode(root->RChild, temp->data);
            }
        }
    }

    return root;
}


void preorder(TernaryNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->LChild);
        preorder(root->MChild);
        preorder(root->RChild);
    }
}


void inorder(TernaryNode* root) {
    if (root != nullptr) {
        inorder(root->LChild);
        cout << root->data << " ";
        inorder(root->MChild);
        inorder(root->RChild);
    }
}


void postorder(TernaryNode* root) {
    if (root != nullptr) {
        postorder(root->LChild);
        postorder(root->MChild);
        postorder(root->RChild);
        cout << root->data << " ";
    }
}


void levelOrder(TernaryNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TernaryNode*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        TernaryNode* curr = q.front();
        q.pop();
        if (curr == nullptr) {
            if (!q.empty()) {
                cout << endl;
                q.push(nullptr);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->LChild) q.push(curr->LChild);
        if (curr->MChild) q.push(curr->MChild);
        if (curr->RChild) q.push(curr->RChild);
    }
}


int size(TernaryNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + size(root->LChild) + size(root->MChild) + size(root->RChild);
}


int sum(TernaryNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sum(root->LChild) + sum(root->MChild) + sum(root->RChild);
}


int height(TernaryNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->LChild);
    int middleHeight = height(root->MChild);
    int rightHeight = height(root->RChild);

    return 1 + max({leftHeight, middleHeight, rightHeight});
}


int findMinValue(TernaryNode* root) {
    if (!root) return INT_MAX;

    int leftMin = findMinValue(root->LChild);
    int middleMin = findMinValue(root->MChild);
    int rightMin = findMinValue(root->RChild);
    int minVal = root->data;

    return min({minVal, leftMin, middleMin, rightMin});
}


int findMaxValue(TernaryNode* root) {
    if (!root) return INT_MIN;

    int leftMax = findMaxValue(root->LChild);
    int middleMax = findMaxValue(root->MChild);
    int rightMax = findMaxValue(root->RChild);
    int maxVal = root->data;

    return max({maxVal, leftMax, middleMax, rightMax});
}

int main() {
    TernaryNode* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order:\n";
    levelOrder(root);

    TernaryNode* result = search(root, 20);
    cout << (result ? "\nFound " : "\nNot found ");

    cout << "\nSize: " << size(root);
    cout << "\nSum: " << sum(root);
    cout << "\nHeight: " << height(root);
    cout << "\nMin value: " << findMinValue(root);
    cout << "\nMax value: " << findMaxValue(root);

    root = delNode(root, 170);
    cout << "\nAfter deleting 170: ";
    preorder(root);

    return 0;
}