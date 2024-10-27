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
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Original queue: ";
    printQueue(q);

    interweaveQueue(q);

    cout << "Interwoven queue: ";
    printQueue(q);

    return 0;
}
