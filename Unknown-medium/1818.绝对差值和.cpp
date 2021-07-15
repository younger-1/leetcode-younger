/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 *
 * [1818] 绝对差值和
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

/*
[5,2,7]
[10,7,12]

sorted [2 5 7]

 */
class Solution {
   public:
    static constexpr int mod = 1'000'000'007;
    // static constexpr int mod = 1.0e+9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted(nums1);
        sort(sorted.begin(), sorted.end());
        int maxn = 0;
        int sum = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            // lower_bound
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (sorted[mid] < nums2[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            if (left < n) {
                maxn = max(maxn, diff - (sorted[left] - nums2[i]));
            }
            if (left > 0) {
                maxn = max(maxn, diff - (nums2[i] - sorted[left - 1]));
            }
        }
        return (sum - maxn + mod) % mod;
    }
};
// @lc code=end

class Solution_1 {
   public:
    static constexpr int mod = 1'000'000'007;
    // static constexpr int mod = 1.0e+9 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(nums1);
        sort(rec.begin(), rec.end());
        int maxn = 0;
        int sum = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            int idx = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
            if (idx < n) {
                maxn = max(maxn, diff - (rec[idx] - nums2[i]));
            }
            if (idx > 0) {
                maxn = max(maxn, diff - (nums2[i] - rec[idx - 1]));
            }
        }
        // 遍历过程中使用了取模操作，可能会导致最终 sum < maxn，因此结果要使用 (sum - maxn + mod) % mod 的形式
        return (sum - maxn + mod) % mod;
    }
};

#include <iostream>
int main() {
    Solution s = Solution();
    auto a = vector<int>{5, 2, 7};
    auto b = vector<int>{10, 7, 12};
    int t = s.minAbsoluteSumDiff(a, b);
    cout << t;
}