#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printNGE(const vector<int>& arr) {
    stack<int> s;
    vector<int> nge(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    printNGE(arr);
    return 0;
}
