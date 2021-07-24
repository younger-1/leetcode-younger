
#include <iostream>
#include <vector>

using namespace std;

// merge的下标为 [low, mid] 和 [mid+1, high]
void merge(vector<int>& arr, int low, int mid, int high) {
    // vector<int> tmp(arr.begin() + low, arr.begin() + high + 1);
    int i = low, j = mid + 1;
    int k = 0;
    vector<int> tmp(high - low + 1);
    while (i <= mid && j <= high) {
        // 等号保证归并排序的稳定性
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = arr[i++];
    }
    while (j <= high) {
        tmp[k++] = arr[j++];
    }
    // 将排好序的存回 arr 中
    for (k = 0; low <= high;) {
        arr[low++] = tmp[k++];
    }
}

// @recursion
void ms_1(vector<int>& arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    ms_1(arr, begin, mid);
    ms_1(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

// 每次 merge 相邻的两个子组，子组内的 k 个数都是已经排好序的
void merge_iter(vector<int>& arr, int k, int begin, int end) {
    int low = begin;
    while (low + 2 * k - 1 < end) {
        merge(arr, low, low + k - 1, low + 2 * k - 1);
        low += 2 * k;
    }
    if (low + k - 1 < end) {
        merge(arr, low, low + k - 1, end);
    }
}

// @iteration
void ms_2(vector<int>& arr, int begin, int end) {
    int k = 1, len = end - begin + 1;
    while (k < len) {
        merge_iter(arr, k, begin, end);
        k *= 2;
    }
}

int main() {
    vector<int> arr{10, 9, 7, 6, 5, 4, 8, 3, 2, 1};
    ms_1(arr, 5, arr.size() - 1);
    for (auto num : arr) {
        cout << num << " ";
    }
}
