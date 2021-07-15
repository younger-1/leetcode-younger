#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

void is_1(vector<int>& arr) {
    int n = arr.size();
    // n-1 趟
    for (int i = 1; i < n; i++) {
        int k = i;
        while (k > 0 && arr[k] < arr[k - 1]) {
            swap(arr[k], arr[k - 1]);
            k--;
        }
    }
}

int main() {
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    is_1(arr);
    for (auto num : arr) {
        cout << num << " ";
    }
}
