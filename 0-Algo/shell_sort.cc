// 原文链接：https://blog.csdn.net/zpznba/article/details/88407089

#include <iostream>
#include <vector>

using namespace std;

void ss_1(vector<int>& arr) {
    int n = arr.size(), gap = n;
    while (gap) {
        gap /= 2;
        for (int i = gap; i < n; i++) {
            int k = i;
            while (k >= gap && arr[k] < arr[k - gap]) {
                swap(arr[k], arr[k - gap]);
                k -= gap;
            }
        }
    }
}

void ss_2(vector<int>& arr) {
    int n = arr.size(), gap = n;
    while (gap) {
        gap /= 2;
        for (int i = 0; i < gap; i++) {
            for (int j = i + gap; j < n; j += gap) {
                int k = j;
                while (k >= j && arr[k] < arr[k - gap]) {
                    swap(arr[k], arr[k - gap]);
                    k -= gap;
                }
            }
        }
    }
}

int main() {
    vector<int> array{2, 1, 4, 3, 11, 6, 5, 7, 8, 10, 15};
    ss_2(array);
    for (auto it : array) {
        cout << it << " ";
    }
    return 0;
}
