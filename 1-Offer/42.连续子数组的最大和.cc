// 剑指 Offer 42. 连续子数组的最大和
// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
// 注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/

#include <vector>

using namespace std;

// TODO: redo
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        // sum 为每一个可能子数组的元素和
        int sum = 0, ans = -100;
        for (auto num : nums) {
            if (sum <= 0) {
                sum = num;
            } else {
                sum += num;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

// @prefix-sum
class Solution_1 {
   public:
    int maxSubArray(vector<int>& nums) {
        // 记录前缀和中小于0的最小值
        int min = 0;
        // sum 为前缀和
        int sum = 0, ans = -100;
        for (auto num : nums) {
            sum += num;
            ans = max(ans, sum - min);
            if (sum < min) {
                min = sum;
            }
        }
        return ans;
    }
};

// @DP
class Solution_2 {
   public:
    // f(i) 代表以第 i 个数结尾的「连续子数组的最大和」
    // - 为何定义最大和 f(i) 中必须包含元素 f(i) ：保证 f(i) 递推到 f(i) 的正确性

    // f(i) = max{f(i−1) + nums[i], nums[i]}
    int maxSubArray(vector<int>& nums) {
        int f = 0, maxAns = nums[0];
        for (const auto& x : nums) {
            f = max(f + x, x);
            maxAns = max(maxAns, f);
        }
        return maxAns;
    }
};

#include <iostream>
int main() {
    vector<int> nums{1, -2, 3, 5, -1, 2};
    auto s = Solution();
    cout << s.maxSubArray(nums);
}
