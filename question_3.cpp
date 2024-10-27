#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> firstNegativeInWindow(const vector<int>& arr, int k) {
    vector<int> result;
    deque<int> negatives;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            negatives.push_back(i);
        }

        if (i >= k - 1) {
            if (!negatives.empty() && negatives.front() < i - k + 1) {
                negatives.pop_front();
            }

            if (!negatives.empty()) {
                result.push_back(arr[negatives.front()]);
            } else {
                result.push_back(0);
            }
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the window size (k): ";
    cin >> k;

    vector<int> result = firstNegativeInWindow(arr, k);

    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
