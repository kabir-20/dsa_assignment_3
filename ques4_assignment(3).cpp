#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    int isEmpty() { return top == -1; }
    int isFull() { return top == MAX - 1; }
    void push(char x) {
        if (isFull()) return;
        arr[++top] = x;
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

int prec(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

int isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}

string infixToPostfix(string exp) {
    Stack s;
    string res = "";
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (isOperand(ch))
            res += ch;
        else if (ch == '(')
            s.push(ch);
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                res += s.pop();
            s.pop();
        } else {
            while (!s.isEmpty() && prec(ch) <= prec(s.peek()))
                res += s.pop();
            s.push(ch);
        }
    }
    while (!s.isEmpty())
        res += s.pop();
    return res;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;
    cout << "Postfix expression: " << infixToPostfix(exp);
    return 0;
}

