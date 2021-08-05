/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// https://leetcode-cn.com/problems/valid-triangle-number/comments/30467
class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = n - 1; i >= 2; i--) {
            int k = 0;
            int j = i - 1;
            while (k < j) {
                // 满足该条件，说明从num[k]到num[j]的数都满足要求，结果直接加上j - k
                if (nums[k] + nums[j] > nums[i]) {
                    ans += j - k;
                    j--;
                } else {
                    k++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

class Solution_1 {
   public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = i;
            for (int j = i + 1; j < n; ++j) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    ++k;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    vector<int> v{2, 2, 3, 4};
    s.triangleNumber(v);
}
