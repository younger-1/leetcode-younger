/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            shift_down(nums, i, n);
        }
        for (int i = n - 1; i >= n - k; i--) {
            swap(nums[i], nums[0]);
            shift_down(nums, 0, i);
        }
        return nums[n - k];
    }

   private:
    void shift_down(vector<int>& nums, int i, int n) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int j = i;
        if (left < n && nums[left] > nums[j]) {
            j = left;
        }
        if (right < n && nums[right] > nums[j]) {
            j = right;
        }
        if (j != i) {
            swap(nums[j], nums[i]);
            shift_down(nums, j, n);
        }
    }
};

// @lc code=end
// @heap [小根堆]
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/607242
class Solution_1 {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        // 对前k个元素建成小根堆
        for (int i = 0; i < k; i++) {
            swim(nums, i);
        }
        // 剩下的元素与堆顶比较，若大于堆顶则去掉堆顶，再将其插入
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                swap(nums[0], nums[i]);
                sink(nums, 0, k - 1);
            }
        }
        // 结束后第k个大的数就是小根堆的堆顶
        return nums[0];
    }

   private:
    // 若v1比v2优先度高，返回true
    bool priorityThan(int v1, int v2) { return v1 < v2; }

    // 上浮 从下到上调整堆
    void swim(vector<int>& heap, int i) {
        while (i > 0 && priorityThan(heap[i], heap[(i - 1) / 2])) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // 下沉 从上到下调整堆
    void sink(vector<int>& heap, int i, int N) {
        while (2 * i + 1 <= N) {
            int j = 2 * i + 1;
            if (j + 1 <= N && priorityThan(heap[j + 1], heap[j])) {
                j++;
            }
            if (priorityThan(heap[i], heap[j])) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    }
};

#include <iostream>

int main() {
    vector<int> array{3, 2, 3, 1, 2, 4, 5, 5, 6};
    auto s = Solution();
    s.findKthLargest(array, 4);
    for (auto it : array) {
        cout << it << " ";
    }
    return 0;
}
