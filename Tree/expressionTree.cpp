// POSTFIX EVALUATION USING STACK

// #include <iostream>
// #include <stack>
// using namespace std;

// int getValue(char ch){
//     if(ch == 'a') return 1;
//     if(ch == 'b') return 2;
//     if(ch == 'c') return 4;
//     if(ch == 'd') return 2;
//     if(ch == 'x') return 5;
//     return 0;
// }

// int evaluatePostFix(string expr){
//     stack<int> st;
    
//     for(int i = 0; i < expr.length(); i++){
//         char ch = expr[i];
//         if(ch >= '0' && ch <= '9'){
//             int num = ch - 48;
//             st.push(num);
//         }else if(ch >= 'a' && ch <= 'z'){
//             st.push(getValue(ch));
//         }else{
//             int b = st.top(); st.pop();
//             int a = st.top(); st.pop();
            
//             switch(ch){
//                 case '+': st.push(a + b); break;
//                 case '-': st.push(a - b); break;
//                 case '*': st.push(a * b); break;
//                 case '/': st.push(a / b); break;
//             }
//         }
//     }
//     return st.top();
// }

// int main() {
//     string postFix = "124*2/+125*+5/-";
//     cout<<"PostFix evaluation: "<<evaluatePostFix(postFix);
//     return 0;
// }



//String Infix to Postfix conversion using stack


// int precedence(char op){
//     if(op == '+' || op == '-') return 1;
//     if(op == '*' || op == '/') return 2;
//     return 0;
// }


// string infixToPostfix(string infix){
//     stack<char> opStack;
//     string postFix = "";    
//     for(int i = 0; i < infix.length(); i++){
//         char ch = infix[i];
//         if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || 
//             (ch >= '0' && ch <= '9') ){
//             postFix += ch;
//         }else if(ch == '('){
//             opStack.push(ch);            
//         }else if(ch == ')'){
//             while(!opStack.empty() && opStack.top() != '('){
//                 postFix += opStack.top();
//                 opStack.pop();
//             }
//             if(!opStack.empty()) opStack.pop();
//         }else{
//             while(!opStack.empty() && 
//             precedence(ch) <= precedence(opStack.top())){
//             postFix += opStack.top();
//             opStack.pop();
//          }
//          opStack.push(ch);
//         }
//     }
//     while(!opStack.empty()){
//        postFix += opStack.top();
//        opStack.pop();
//     }
//     return postFix;
// };



// int main(){
//     string infix;
//     cout<<"Enter an infix expression: ";
//     cin>>infix;
//     string postFix = infixToPostfix(infix);
//     cout<<"PostFix expression: "<<postFix;
// }



// Infix expression tree using stack



// struct Node{
//     char value;
//     Node* left;
//     Node* right;
    
//     Node(char v){
//         value = v;
//         left = right = NULL;
//     }
// };


// int precedence(char op){
//     if(op == '+' || op == '-') return 1;
//     if(op == '*' || op == '/') return 2;
//     return 0;
// }


// string infixToPostfix(string infix){
//     stack<char> opStack;
//     string postFix = "";
    
//     for(int i = 0; i < infix.length(); i++){
//         char ch = infix[i];
//         if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || 
//             (ch >= '0' && ch <= '9') ){
//             postFix += ch;
//         }else if(ch == '('){
//             opStack.push(ch);            
//         }else if(ch == ')'){
//             while(!opStack.empty() && opStack.top() != '('){
//                 postFix += opStack.top();
//                 opStack.pop();
//             }
//             if(!opStack.empty()) opStack.pop();
//         }else{
//             while(!opStack.empty() && 
//             precedence(ch) <= precedence(opStack.top())){
//             postFix += opStack.top();
//             opStack.pop();
//          }
//          opStack.push(ch);
//         }
//     }
//     while(!opStack.empty()){
//       postFix += opStack.top();
//       opStack.pop();
//     }
//     return postFix;
// };


// Node* buildExpressionTree(string postFix){
//     stack<Node*> st;
    
//     for(int i = 0; i < postFix.length(); i++){
//         char ch = postFix[i];
//         Node* newNode = new Node(ch);
//         if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || 
//             (ch >= '0' && ch <= '9') ){
//             st.push(newNode);
//         }else{
//             newNode -> right = st.top(); st.pop();
//             newNode -> left = st.top(); st.pop();
//             st.push(newNode);
//         }
//     }
    
//     return st.top();
// }

// void inorder(Node* root){
//     if(root != NULL){
//       bool isOp = (root->value == '+' || root->value == '-' || 
//                     root->value == '*' || root->value == '/');
//         if (isOp) cout << "(";
//         inorder(root->left);
//         cout << root->value;
//         inorder(root->right);
//         if (isOp) cout << ")";
//     }
// }

// int main(){
//     string infix;
//     cout<<"Enter an infix expression: ";
//     cin>>infix;
    
//     string postFix = infixToPostfix(infix);
//     cout<<"PostFix expression: "<<postFix;
    
//     Node* root =buildExpressionTree(postFix);
//     cout<<"\nexpression tree: ";
//     inorder(root);
// }



// Infix to Prefix conversion using stack


// #include <iostream>
// #include <stack>
// using namespace std;

// int precedence(char op) {
//     if (op == '+' || op == '-') return 1;
//     if (op == '*' || op == '/') return 2;
//     return 0;
// }

// bool isOperand(char ch) {
//     return (isalnum(ch));  // letter or digit
// }

// // Custom reverse function
// void reverseString(string &s) {
//     int start = 0;
//     int end = s.length() - 1;
//     while (start < end) {
//         char temp = s[start];
//         s[start] = s[end];
//         s[end] = temp;
//         start++;
//         end--;
//     }
// }

// string infixToPostfix(string infix) {
//     stack<char> opStack;
//     string postFix = "";

//     for (int i = 0; i < infix.length(); i++) {
//         char ch = infix[i];
        
//         if (isOperand(ch)) {
//             postFix += ch;
//         } else if (ch == '(') {
//             opStack.push(ch);
//         } else if (ch == ')') {
//             while (!opStack.empty() && opStack.top() != '(') {
//                 postFix += opStack.top();
//                 opStack.pop();
//             }
//             if (!opStack.empty()) opStack.pop(); // remove '('
//         } else { // operator
//             while (!opStack.empty() && precedence(ch) <= precedence(opStack.top())) {
//                 postFix += opStack.top();
//                 opStack.pop();
//             }
//             opStack.push(ch);
//         }
//     }

//     while (!opStack.empty()) {
//         postFix += opStack.top();
//         opStack.pop();
//     }

//     return postFix;
// }

// string infixToPrefix(string infix) {
//     reverseString(infix);

//     // Swap '(' with ')' and vice versa
//     for (int i = 0; i < infix.length(); i++) {
//         if (infix[i] == '(') infix[i] = ')';
//         else if (infix[i] == ')') infix[i] = '(';
//     }

//     string postfix = infixToPostfix(infix);
//     reverseString(postfix);
//     return postfix;
// }

// int main() {
//     string infix;
//     cout << "Enter infix expression: ";
//     cin >> infix;

//     string prefix = infixToPrefix(infix);
//     cout << "Prefix expression: " << prefix << endl;
//     return 0;
// }






//  muitl digit 


// #include <iostream>
// #include <stack>
// using namespace std;

// int getNum(char ch) {
//     if (ch == 'a') return 1;
//     if (ch == 'b') return 2;
//     if (ch == 'c') return 4;
//     if (ch == 'd') return 2;
//     if (ch == 'x') return 5;
//     return 0;
// }

// int stringToInt(string s) {
//     int num = 0;
//     int i = 0;
//     bool isNegative = false;
//     if (s[0] == '-') {
//         isNegative = true;
//         i = 1;
//     }

//     for (; i < s.length(); i++) {
//         num = num * 10 + (s[i] - '0');
//     }

//     return isNegative ? -num : num;
// }

// int evaluatePostFix(string expr) {
//     stack<int> st;
//     int i = 0;
//     while (i < expr.length()) {
//         if (expr[i] == ' ') {
//             i++;
//             continue;
//         }

//         if (isdigit(expr[i]) || (expr[i] == '-' && isdigit(expr[i + 1]))) {
//             // Build full number
//             string numStr = "";
//             if (expr[i] == '-') {
//                 numStr += expr[i++];
//             }
//             while (i < expr.length() && isdigit(expr[i])) {
//                 numStr += expr[i++];
//             }
//             int number = stringToInt(numStr);
//             st.push(number);
//         }
//         else if (isalpha(expr[i])) {
//             st.push(getNum(expr[i]));
//             i++;
//         }
//         else {
//             // Operator
//             int b = st.top(); st.pop();
//             int a = st.top(); st.pop();

//             switch (expr[i]) {
//                 case '+': st.push(a + b); break;
//                 case '-': st.push(a - b); break;
//                 case '*': st.push(a * b); break;
//                 case '/': st.push(a / b); break;
//             }
//             i++;
//         }
//     }

//     return st.top();
// }

// int main() {
//     string postFix = "23 90 + a * 5 /";
//     cout << "Postfix evaluation: " << evaluatePostFix(postFix) << endl;
//     return 0;
// }


// #include <iostream>
// #include <stack>
// #include <string>
// #include <cctype>  // for isdigit()
// #include <sstream>  // for stringstream
// using namespace std;


// int precedence(char op) {
//     if (op == '+' || op == '-') return 1;
//     if (op == '*' || op == '/') return 2;
//     return 0;
// }

// string infixToPostfix(string infix) {
//     stack<char> opStack;
//     string postFix = "";
//     string number = "";

//     for (int i = 0; i < infix.length(); i++) {
//         char ch = infix[i];

//         if (isdigit(ch)) {
//             number += ch; 
//         } else {
//             if (!number.empty()) {  
//                 postFix += number + " ";
//                 number = "";  
//             }

//             if (ch == '(') {
//                 opStack.push(ch);
//             } else if (ch == ')') {
//                 while (!opStack.empty() && opStack.top() != '(') {
//                     postFix += opStack.top();
//                     postFix += " ";
//                     opStack.pop();
//                 }
//                 if (!opStack.empty()) opStack.pop();  // Pop the '('
//             } else {  // Operator
//                 while (!opStack.empty() && precedence(ch) <= precedence(opStack.top())) {
//                     postFix += opStack.top();
//                     postFix += " ";
//                     opStack.pop();
//                 }
//                 opStack.push(ch);
//             }
//         }
//     }

//     if (!number.empty()) {
//         postFix += number + " ";
//     }

//     while (!opStack.empty()) {
//         postFix += opStack.top();
//         postFix += " ";
//         opStack.pop();
//     }

//     return postFix;
// }

// int getNum(char ch) {
//     if (ch == 'a') return 1;
//     if (ch == 'b') return 2;
//     if (ch == 'c') return 4;
//     if (ch == 'd') return 2;
//     if (ch == 'x') return 5;
//     return 0;
// }

// int evaluatePostFix(string expr) {
//     stack<int> st;
//     stringstream ss(expr);
//     string token;

//     while (ss >> token) {  
//         if (isdigit(token[0])) {
//             st.push(stoi(token));
//         } else if (isalpha(token[0])) {
//             st.push(getNum(token[0]));
//         } else {
//             int b = st.top(); st.pop();
//             int a = st.top(); st.pop();
            
//             switch (token[0]) {
//                 case '+': st.push(a + b); break;
//                 case '-': st.push(a - b); break;
//                 case '*': st.push(a * b); break;
//                 case '/': st.push(a / b); break;
//             }
//         }
//     }
//     return st.top();
// }

// int main() {
//     string infix = "a*(24+20)/5"; 
//     string postfix = infixToPostfix(infix);
//     cout << "Postfix Expression: " << postfix << endl;
//     cout << "Postfix Evaluation: " << evaluatePostFix(postfix) << endl;
//     return 0;
// }