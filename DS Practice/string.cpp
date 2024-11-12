#include<iostream>
using namespace std;

class StringOps {
    private:
        string str;

    public:
        void read();
        void display();
        int length();
        int frequency(char c);
        string extract(int pos, int len);
        string remove(char ch);
        string replace(string w, string x);
        bool palindrome();
};

void StringOps::read() {
    cout << "Enter the string: ";
    getline(cin, str);
}

void StringOps::display() {
    cout << str;
}

int StringOps::length() {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int StringOps::frequency(char c) {
    int freq = 0;
    for (int i = 0; i < length(); i++) {
        if (str[i] == c) {
            freq++;
        }
    }
    return freq;
}

string StringOps::extract(int pos, int len) {
    string result = "";
    for (int i = pos; i < pos + len && i < length(); i++) {
        result += str[i];
    }
    return result;
}

string StringOps::remove(char ch) {
    string result = "";
    for (int i = 0; i < length(); i++) {
        if (str[i] != ch) {
            result += str[i];
        }
    }
    return result;
}

string StringOps::replace(string w, string x) {
    string result = "";
    for (int i = 0; i < length(); i++) {
        bool match = true;
        for (int j = 0; j < w.length(); j++) {
            if (i + j >= length() || str[i + j] != w[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            result += x;
            i += w.length() - 1;
        } else {
            result += str[i];
        }
    }
    return result;
}

bool StringOps::palindrome() {
    int left = 0, right = length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    StringOps s;
    s.read();
    s.display();
    
    int choice;
    char ch;

    do {
        cout << "\n\nMenu:\n1. Frequency of a character\n2. Extract substring\n3. Remove character\n4. Replace substring\n5. Check palindrome\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character: ";
                cin >> ch;
                cout << "Frequency of '" << ch << "': " << s.frequency(ch) << endl;
                break;

            case 2: {
                int pos, len;
                cout << "Enter starting position and length: ";
                cin >> pos >> len;
                cout << "Extracted string: " << s.extract(pos, len) << endl;
                break;
            }

            case 3:
                cout << "Enter character to remove: ";
                cin >> ch;
                cout << "String after removal: " << s.remove(ch) << endl;
                break;

            case 4: {
                string w, x;
                cout << "Enter substring to replace and new string: ";
                cin >> w >> x;
                cout << "String after replacement: " << s.replace(w, x) << endl;
                break;
            }

            case 5:
                if (s.palindrome()) 
                    cout << "The string is a palindrome." << endl;
                else 
                    cout << "The string is not a palindrome." << endl;
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

