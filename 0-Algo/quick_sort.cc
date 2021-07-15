
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        // while (low < high && arr[high] >= pivot) {
        //     high--;
        // }
        // if (low < high) {
        //     arr[low++] = arr[high];
        // }
        // while (low < high && arr[low] <= pivot) {
        //     low++;
        // }
        // if (low < high) {
        //     arr[high++] = arr[low];
        // }

        while (low < high && arr[high] >= pivot) {
            high--;
        }
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        if (low < high) {
            swap(arr[low], arr[high]);
        }
    }
    arr[low] = pivot;
    return low;
}

void qs_1(vector<int>& arr, int low, int high) {
    if (low < high) {
        int idx = partition(arr, low, high);
        qs_1(arr, low, idx - 1);
        qs_1(arr, idx + 1, high);
    }
}

int main() {
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    qs_1(arr, 0, arr.size() - 1);
    for (auto num : arr) {
        cout << num << " ";
    }
}
