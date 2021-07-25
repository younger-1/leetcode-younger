#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 原文链接：https://blog.csdn.net/lzuacm/article/details/52853194
void shift_down(vector<int>& arr, int start, int len) {
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    int idx = start;
    // idx 弄成3个数中最大数的下标
    if (left < len && arr[left] > arr[idx]) {
        idx = left;
    }
    if (right < len && arr[right] > arr[idx]) {
        idx = right;
    }
    // 如果 start 的值有更新
    if (idx != start) {
        swap(arr[idx], arr[start]);
        // 递归调整其他不满足堆性质的部分
        shift_down(arr, idx, len);
    }
}

void hs_1(vector<int>& arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        shift_down(arr, i, len);
    }
    for (int i = len - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        shift_down(arr, 0, i);
    }
}

int main() {
    vector<int> array{8, 1, 14, 3, 21, 5, 7, 10};
    hs_1(array, 8);
    for (auto it : array) {
        cout << it << endl;
    }
    return 0;
}
