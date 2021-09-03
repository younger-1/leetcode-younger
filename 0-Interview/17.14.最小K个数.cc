// 面试题 17.14. 最小K个数
// https://leetcode-cn.com/problems/smallest-k-lcci/

#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans(k);
        if (k == 0) {
            return ans;
        }
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};

class Solution_1 {
   public:
    vector<int> smallestK(vector<int>& nums, int k) {
        qsort(nums, k, 0, nums.size() - 1);
        return res;
    }

   private:
    vector<int> res;
    void qsort(vector<int>& nums, int k, int left, int right) {
        if (left > right)
            return;
        int i = left;
        int j = right;
        // nums[left] is base
        while (i < j) {
            while (i < j && nums[j] >= nums[left])
                --j;
            while (i < j && nums[i] <= nums[left])
                ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[left]);
        // k - 1 is Ok, too.
        if (i == k)
            res.assign(nums.begin(), nums.begin() + k);
        else if (i > k)
            qsort(nums, k, left, i - 1);
        else
            qsort(nums, k, i + 1, right);
    }
};
