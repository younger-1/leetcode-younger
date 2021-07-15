#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * The address of a and b must be different, or will result in 0.
 */
void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

void bs_1(vector<int>& arr) {
    int n = arr.size();
    // n-1 趟
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bs_2(vector<int>& arr) {
    int n = arr.size();
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        n--;
    }
}

void bs_3(vector<int>& arr) {
    int n = arr.size();
    int last_exchange = n - 1;
    while (last_exchange > 0) {
        int k = last_exchange;
        last_exchange = 0;
        for (int j = 0; j < k; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                last_exchange = j;
            }
        }
    }
}

int main() {
    int a = 4, b = 6;
    swap(a, b);
    cout << a << b << endl;

    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bs_2(arr);
    for (auto num : arr) {
        cout << num << " ";
    }
}
