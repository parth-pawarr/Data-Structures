#include <iostream>
using namespace std;

// Stack class to handle basic stack operations
class Stack {
private:
    char stack[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top < 99) {
            stack[++top] = c;
        }
    }

    char pop() {
        if (top >= 0) {
            return stack[top--];
        }
        return '\0'; 
    }

    bool isEmpty() {
        return top == -1;
    }

    
    int size() {
        return top + 1;
    }
};


void reverseString(const string &str) {
    Stack s;

    // Push each character onto the stack
    for (int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    // Pop characters from the stack and print them (reversed)
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}


bool isPalindrome(const string &str) {
    Stack s;
    int len = str.size();

    
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    
    for (int i = 0; i < len; i++) {
        if (str[i] != s.pop()) {
            return false;  
        }
    }

    return true;  
}

int main() {
    string str;

    
    cout << "Enter a string: ";
    getline(cin, str);


    cout << "Original string: " << str << endl;

    
    reverseString(str);

    
    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
