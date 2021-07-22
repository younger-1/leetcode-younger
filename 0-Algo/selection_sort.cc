#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ss_1(vector<int>& arr) {
    int n = arr.size();
    // n-1 趟
    for (int i = 0; i < n - 1; i++) {
        // 最小值下标
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        if (k != i) {
            swap(arr[k], arr[i]);
        }
    }
}

// 每跑一趟不仅仅记录最大的元素还可以记录最小的元素，这不是一举两得嘛。这时候只需要跑N/2趟
void ss_2(vector<int>& arr) {
    int n = arr.size();
    // n/2 趟
    for (int i = 0; i < n / 2; i++) {
        int i_min = i;
        int i_max = i;
        for (int j = i + 1; j < n - i; j++) {
            if (arr[j] < arr[i_min]) {
                i_min = j;
            } else if (arr[j] > arr[i_max]) {
                i_max = j;
            }
        }
        if (i_min != i) {
            swap(arr[i_min], arr[i]);
            if (i_max == i) {
                i_max = i_min;
            }
        }
        if (i_max != n - 1 - i) {
            swap(arr[i_min], arr[n - 1 - i]);
        }
    }
}

int main() {
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ss_2(arr);
    for (auto num : arr) {
        cout << num << " ";
    }
}
