// 剑指 Offer 42. 连续子数组的最大和
// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
// 注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/

#include <vector>

using namespace std;

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

class Solution_1 {
   public:
    int maxSubArray(vector<int>& nums) {
        // 记录前缀和中的最小值
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
