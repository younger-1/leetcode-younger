/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class MonotonicQueue {
   private:
    deque<int> data;

   public:
    void push(int n) {
        while (!data.empty() && data.back() < n)
            data.pop_back();
        data.push_back(n);
    }

    int max() { return data.front(); }

    void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

// TODO: redo
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {  //先填满窗口的前 k - 1
                window.push(nums[i]);
            } else {  // 窗口向前滑动
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    auto s = Solution();
    vector<int> arr{1, 3, -1, -3, 5, 3, 6, 7};
    auto res = s.maxSlidingWindow(arr, 3);
    for (auto n : res) {
        cout << n << " ";
    }
}
