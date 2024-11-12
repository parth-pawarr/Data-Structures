#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string stack[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(string str) {
        if (top < 99) {
            stack[++top] = str;
        }
    }

    string pop() {
        if (!isEmpty()) {
            return stack[top--];
        }
        return " ";
    }

    string peek() {
        if (!isEmpty()) {
            return stack[top];
        }
        return "";
    }

    int size() {
        return top + 1;
    }

    string at(int index) {
        if (index >= 0 && index <= top) {
            return stack[index];
        }
        return "";
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isOperand(char c) {
    return !(isOperator(c) || c == '(' || c == ')');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void reverseString(string &str) {
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

string infixToPrefix(string infix) {
    Stack operators;
    string prefix = "";
    reverseString(infix);

    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];

        if (isOperand(c)) {
            prefix += c;
        } else if (c == ')') {
            operators.push(string(1, c));
        } else if (c == '(') {
            while (!operators.isEmpty() && operators.peek() != ")") {
                prefix += operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && precedence(c) <= precedence(operators.peek()[0])) {
                prefix += operators.pop();
            }
            operators.push(string(1, c));
        }
    }

    while (!operators.isEmpty()) {
        prefix += operators.pop();
    }

    reverseString(prefix);
    return prefix;
}

string prefixToPostfix(string prefix) {
    Stack s;
    string postfix = "";

    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperand(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            string operand1 = s.pop();
            string operand2 = s.pop();
            s.push(operand1 + operand2 + string(1, c));
        }
    }

    return s.peek();
}

string prefixToInfix(string prefix) {
    Stack s;
    string infix = "";

    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isOperand(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            string operand1 = s.pop();
            string operand2 = s.pop();
            s.push("(" + operand1 + string(1, c) + operand2 + ")");
        }
    }

    return s.peek();
}

string postfixToInfix(string postfix) {
    Stack s;
    string infix = "";

    for (int i = 0; i < postfix.size(); i++) {
        char c = postfix[i];

        if (isOperand(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            string operand2 = s.pop();
            string operand1 = s.pop();
            s.push("(" + operand1 + string(1, c) + operand2 + ")");
        }
    }

    return s.peek();
}

string postfixToPrefix(string postfix) {
    Stack s;
    string prefix = "";

    for (int i = 0; i < postfix.size(); i++) {
        char c = postfix[i];

        if (isOperand(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            string operand2 = s.pop();
            string operand1 = s.pop();
            s.push(string(1, c) + operand1 + operand2);
        }
    }

    return s.peek();
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\nMenu: \n";
        cout << "1. Infix to Prefix\n";
        cout << "2. Prefix to Postfix\n";
        cout << "3. Prefix to Infix\n";
        cout << "4. Postfix to Infix\n";
        cout << "5. Postfix to Prefix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Infix expression: ";
                cin >> expression;
                cout << "Prefix expression: " << infixToPrefix(expression) << endl;
                break;

            case 2:
                cout << "Enter Prefix expression: ";
                cin >> expression;
                cout << "Postfix expression: " << prefixToPostfix(expression) << endl;
                break;

            case 3:
                cout << "Enter Prefix expression: ";
                cin >> expression;
                cout << "Infix expression: " << prefixToInfix(expression) << endl;
                break;

            case 4:
                cout << "Enter Postfix expression: ";
                cin >> expression;
                cout << "Infix expression: " << postfixToInfix(expression) << endl;
                break;

            case 5:
                cout << "Enter Postfix expression: ";
                cin >> expression;
                cout << "Prefix expression: " << postfixToPrefix(expression) << endl;
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
