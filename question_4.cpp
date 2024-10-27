#include <iostream>
#include <queue>
using namespace std;

void interweaveQueue(queue<int>& q) {
    int n = q.size() / 2;
    queue<int> firstHalf, secondHalf;

    for (int i = 0; i < n; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        secondHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(secondHalf.front());
        secondHalf.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int n, element;
    queue<int> q;

    cout << "Enter the number of elements (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Please enter an even number of elements." << endl;
        return 1;
    }

    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        q.push(element);
    }

    cout << "Original queue: ";
    printQueue(q);

    interweaveQueue(q);

    cout << "Interwoven queue: ";
    printQueue(q);

    return 0;
}
