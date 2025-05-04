// Using Number

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* LChild;
    BSTNode* RChild;
    
    BSTNode(int val){
        data = val;
        LChild = RChild = nullptr;
    }
};


BSTNode* insert(BSTNode* root, int val){
    if(root == nullptr){
        return new BSTNode(val);
    }
    
    if(val > root -> data){
        root->RChild = insert(root->RChild, val);
    }else{
        root->LChild = insert(root->LChild, val); 
    }
    
    return root;
};


BSTNode* search(BSTNode* root, int val){
    if(root == nullptr){
        return nullptr;
    }
    
    if(val == root->data){
        return root;
    }
    
    if(val > root->data){
        return search(root->RChild, val);
    }else{
        return search(root->LChild, val);
    }
    return nullptr;
};



BSTNode* Min(BSTNode* node) {
    while (node->LChild != nullptr) {
        node = node->LChild;
    }
    return node;
};



BSTNode* Max(BSTNode* node) {
    while (node->RChild != nullptr) {
        node = node->RChild;
    }
    return node;
};



BSTNode* delNode(BSTNode* root, int val){
    if(root == nullptr){
        return root;
    }
    
    if(val > root->data){
        root->RChild = delNode(root->RChild, val);
    }else if (val < root->data){
        root->LChild = delNode(root->LChild, val);
    }else{
        if(root->LChild == nullptr && root->RChild == nullptr){
            delete root;
            return nullptr;
        }else if(root->LChild == nullptr){
            BSTNode* temp = root->RChild;
            delete root;
            return temp;
        }else if(root->RChild == nullptr){
            BSTNode* temp = root->LChild;
            delete root;
            return temp;
        }else{
            BSTNode* temp = Min(root->RChild);
            root -> data = temp -> data;
            root -> RChild = delNode(root->RChild, temp->data);
        }
    };
    
    return root;
};



void preorder(BSTNode* root){
    if(root != nullptr){
        cout<<root -> data<<" ";
        preorder(root -> LChild);
        preorder(root -> RChild);
    }
}


void inorder(BSTNode* root){
   if(root != nullptr){
        preorder(root -> LChild);
        cout<<root -> data<<" ";
        preorder(root -> RChild);
    } 
}


void postorder(BSTNode* root){
    if(root != nullptr){
        preorder(root -> LChild);
        preorder(root -> RChild);
        cout<<root -> data<<" ";
    }
};


void levelOrder(BSTNode* root){
    if(root == nullptr){
        return;
    }
    
    queue<BSTNode*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        BSTNode* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            };            
        };
        
        cout<<curr->data<<" ";
        
        if(curr->LChild != nullptr){
            q.push(curr->LChild);
        };
        
        if(curr->RChild != nullptr){
            q.push(curr->RChild);
        };
    };
};


int size(BSTNode* root){
    if(root == nullptr){
        return 0;
    }
    return  1 + size(root -> LChild) + size(root -> RChild);
};


int sum(BSTNode* root){
    if(root == nullptr){
        return 0;
    }
    return root -> data + sum(root -> LChild) + sum(root -> RChild);
};


int height(BSTNode* root){
    if(root == nullptr){
        return 0;
    }
    
    int leftHeight = height(root->LChild);
    int rightHeight = height(root->RChild);
    return  1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
};



int findMin(BSTNode* root){
    if (!root) return INT_MAX;

    int leftMin = findMin(root->LChild);
    int rightMin = findMin(root->RChild);
    int minVal = root->data;

    if (leftMin < minVal) minVal = leftMin;
    if (rightMin < minVal) minVal = rightMin;

    return minVal;
    
};



int findMax(BSTNode* root){
    if (!root) return INT_MIN;

    int leftMax = findMax(root->LChild);
    int rightMax = findMax(root->RChild);
    int maxVal = root->data;

    if (leftMax > maxVal) maxVal = leftMax;
    if (rightMax > maxVal) maxVal = rightMax;

    return maxVal;
};




int main() {
    BSTNode* root = nullptr;
    root = insert(root, 150);
    root = insert(root, 90);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 28);
    root = insert(root, 88);
    root = insert(root, 100);
    root = insert(root, 120);
    root = insert(root, 140);
    root = insert(root, 176);
    root = insert(root, 160);
    root = insert(root, 170);
    
    cout<<"Preorder: ";
    preorder(root);
    
    cout<<"\nInorder: ";
    inorder(root);
    
    cout<<"\nPostorder: ";
    postorder(root);
    
    cout<<"\nBFS / Level Order Traversal:"<<endl;
    levelOrder(root);
    
    BSTNode* result = search(root, 20);
    cout << (result ? "\n\nFound "  : "\nNot found ");
    
    cout<<"\nSize: "<<size(root);
    cout<<"\nSum: "<<sum(root);
    cout<<"\nHeight: "<<height(root);
    cout<<"\nMin value: "<<findMin(root);
    cout<<"\nMin value: "<<Min(root) -> data;
    cout<<"\nMax value: "<<Max(root) -> data;
    cout<<"\nMax value: "<<findMax(root);
    
    root = delNode(root, 170);
    cout<<"\nAfter delete 170: ";
    preorder(root);

    return 0;
}




// using Char

#include <iostream>
#include <queue>
using namespace std;

struct BSTNode {
    char data;
    BSTNode* LChild;
    BSTNode* RChild;

    BSTNode(char val) {
        data = val;
        LChild = RChild = nullptr;
    }
};

BSTNode* insert(BSTNode* root, char val) {
    if (root == nullptr) return new BSTNode(val);
    if (val > root->data)
        root->RChild = insert(root->RChild, val);
    else
        root->LChild = insert(root->LChild, val);
    return root;
}

BSTNode* search(BSTNode* root, char val) {
    if (root == nullptr) return nullptr;
    if (val == root->data) return root;
    if (val > root->data)
        return search(root->RChild, val);
    else
        return search(root->LChild, val);
}

BSTNode* Min(BSTNode* node) {
    while (node->LChild != nullptr) {
        node = node->LChild;
    }
    return node;
}

BSTNode* delNode(BSTNode* root, char val) {
    if (!root) return root;

    if (val > root->data) {
        root->RChild = delNode(root->RChild, val);
    } else if (val < root->data) {
        root->LChild = delNode(root->LChild, val);
    } else {
        if (!root->LChild && !root->RChild) {
            delete root;
            return nullptr;
        } else if (!root->LChild) {
            BSTNode* temp = root->RChild;
            delete root;
            return temp;
        } else if (!root->RChild) {
            BSTNode* temp = root->LChild;
            delete root;
            return temp;
        } else {
            BSTNode* temp = Min(root->RChild);  
            root->data = temp->data;
            root->RChild = delNode(root->RChild, temp->data);
        }
    }
    return root;
}

void preorder(BSTNode* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->LChild);
        preorder(root->RChild);
    }
}

void inorder(BSTNode* root) {
    if (root) {
        inorder(root->LChild);
        cout << root->data << " ";
        inorder(root->RChild);
    }
}

void postorder(BSTNode* root) {
    if (root) {
        postorder(root->LChild);
        postorder(root->RChild);
        cout << root->data << " ";
    }
}

void levelOrder(BSTNode* root) {
    if (!root) return;

    queue<BSTNode*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        BSTNode* curr = q.front(); q.pop();
        if (!curr) {
            cout << endl;
            if (!q.empty()) q.push(nullptr);
        } else {
            cout << curr->data << " ";
            if (curr->LChild) q.push(curr->LChild);
            if (curr->RChild) q.push(curr->RChild);
        }
    }
}

int size(BSTNode* root) {
    if (!root) return 0;
    return 1 + size(root->LChild) + size(root->RChild);
}

int sum(BSTNode* root) {
    if (!root) return 0;
    return root->data + sum(root->LChild) + sum(root->RChild);  
}

int height(BSTNode* root) {
    if (!root) return 0;
    int leftHeight = height(root->LChild);
    int rightHeight = height(root->RChild);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

char findMin(BSTNode* root) {
    if (!root) return '~'; // Highest ASCII printable char
    char leftMin = root->LChild ? findMin(root->LChild) : root->data;
    char rightMin = root->RChild ? findMin(root->RChild) : root->data;
    char minVal = root->data;
    if (leftMin < minVal) minVal = leftMin;
    if (rightMin < minVal) minVal = rightMin;
    return minVal;
}

char findMax(BSTNode* root) {
    if (!root) return ' '; 
    char leftMax = root->LChild ? findMax(root->LChild) : root->data;
    char rightMax = root->RChild ? findMax(root->RChild) : root->data;
    char maxVal = root->data;
    if (leftMax > maxVal) maxVal = leftMax;
    if (rightMax > maxVal) maxVal = rightMax;
    return maxVal;
}

int main() {
    BSTNode* root = nullptr;
    string values = "FBDACEGHK";
    // for (char c : values) {
    //     root = insert(root, c);
    // }
    
    for(int i = 0; i < values.length(); i++){
        root = insert(root, values[i]);
    }

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order:\n";
    levelOrder(root);

    cout << "\nSize: " << size(root);
    cout << "\nASCII Sum: " << sum(root);
    cout << "\nHeight: " << height(root);
    cout << "\nMin: " << findMin(root);
    cout << "\nMax: " << findMax(root);

    root = delNode(root, 'G');
    cout << "\n\nAfter deleting G:\nPreorder: ";
    preorder(root);

    return 0;
}