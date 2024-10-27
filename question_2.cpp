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
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printNGE(arr);

    return 0;
}
