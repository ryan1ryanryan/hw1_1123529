#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(topElement);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topElement);
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    int n, element;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    cout << "Enter the elements of the stack: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        s.push(element);
    }

    cout << "Original stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed stack: ";
    printStack(s);

    return 0;
}
