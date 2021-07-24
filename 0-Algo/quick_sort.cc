
#include <iostream>
#include <vector>

using namespace std;

// 挖坑填数
int partition_1(vector<int>& arr, int low, int high) {
    // 挖出基准数
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        // 填坑
        if (low < high) {
            arr[low++] = arr[high];
        }
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        // 填坑
        if (low < high) {
            arr[high++] = arr[low];
        }
    }
    // 填入基准数
    arr[low] = pivot;

    return low;
}

void qs_1(vector<int>& arr, int low, int high) {
    if (low < high) {
        int idx = partition_1(arr, low, high);
        qs_1(arr, low, idx - 1);
        qs_1(arr, idx + 1, high);
    }
}

// 交换
// 链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/jian-zhi-offer-40-zui-xiao-de-k-ge-shu-j-9yze/
void qs_2(vector<int>& arr, int l, int r) {
    // 子数组长度为 1 时终止递归
    if (l >= r)
        return;
    // 哨兵划分操作（以 arr[l] 作为基准数）
    int i = l, j = r;
    while (i < j) {
        while (i < j && arr[j] >= arr[l])
            j--;
        while (i < j && arr[i] <= arr[l])
            i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);
    // 递归左（右）子数组执行哨兵划分
    qs_2(arr, l, i - 1);
    qs_2(arr, i + 1, r);
}

int main() {
    vector<int> arr{10, 9, 7, 6, 5, 4, 8, 3, 2, 1};
    qs_2(arr, 0, arr.size() - 1);
    for (auto num : arr) {
        cout << num << " ";
    }
}
