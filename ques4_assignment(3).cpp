 #include <iostream>
 using namespace std;
 #define MAX 100
 class Stack {
    char arr[MAX];
    int top;
 public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(char val) {
        if (isFull()) { cout << "Stack Overflow\n"; return; }
        arr[++top] = val;
    }
    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }
    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
 };
 int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return -1;
 }
 bool isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    return false;
 }
 string infixToPostfix(string expr) {
    Stack s;
    string result = "";
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (isOperand(ch)) result += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') result += s.pop();
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(ch) <= precedence(s.peek())) result += s.pop();
            s.push(ch);
        }
    }
    while (!s.isEmpty()) result += s.pop();
    return result;
 }
 int main() {
    string expr;
    cout<<"Enter infix expression : ";
    cin>>expr;
    cout<<"Postfix expression : "<<infixToPostfix(expr)<<endl;
    return 0;
 }
