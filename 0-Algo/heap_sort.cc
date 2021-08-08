#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 原文链接：https://blog.csdn.net/lzuacm/article/details/52853194

// 从索引 start 向下调整堆
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

void hs_1(vector<int>& arr) {
    int len = arr.size();
    // 1. 建最大堆
    // 从最后一个非叶结点开始, 对每一个非叶结点进行堆调整
    for (int i = len / 2 - 1; i >= 0; i--) {
        shift_down(arr, i, len);
    }
    // 2. 排序
    for (int i = len - 1; i >= 1; i--) {
        // 将当前最大的放置到数组末尾
        swap(arr[0], arr[i]);
        shift_down(arr, 0, i);
    }
}

// [start, end]
void shift_down_2(vector<int>& arr, int begin, int start, int end) {
    int left = begin + 2 * (start - begin) + 1;
    int right = begin + 2 * (start - begin) + 2;
    int idx = start;
    // idx 弄成3个数中最大数的下标
    if (left <= end && arr[left] > arr[idx]) {
        idx = left;
    }
    if (right <= end && arr[right] > arr[idx]) {
        idx = right;
    }
    // 如果 start 的值有更新
    if (idx != start) {
        swap(arr[idx], arr[start]);
        // 递归调整其他不满足堆性质的部分
        shift_down_2(arr, begin, idx, end);
    }
}

void hs_2(vector<int>& arr, int begin, int end) {
    // 1. 建最大堆
    // 从最后一个非叶结点开始, 对每一个非叶结点进行堆调整
    int last = begin + (end - begin - 1) / 2;
    for (int i = last; i >= begin; i--) {
        shift_down_2(arr, begin, i, end);
    }
    // 2. 排序
    for (int i = end; i >= begin + 1; i--) {
        // 将当前最大的放置到数组末尾
        swap(arr[begin], arr[i]);
        shift_down_2(arr, begin, begin, i - 1);
        int e = 3;
    }
}

int main() {
    vector<int> array{8, 6, 14, 3, 21, 1, 5, 10};
    // hs_1(array);
    hs_2(array, 1, 5);
    for (auto it : array) {
        cout << it << endl;
    }
    return 0;
}
