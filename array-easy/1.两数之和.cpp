/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// 52/52 cases passed (4 ms)
// Your runtime beats 99.77 % of cpp submissions
// Your memory usage beats 49.69 % of cpp submissions (9.3 MB)
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tab;
        for (int i = 0; i < nums.size(); i++) {
            auto it = tab.find(target - nums[i]);
            if (tab.end() != it) {
                return {it->second, i};
            }
            tab[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

// @设计API
/*
 * class TwoSum {
 *    public:
 *     // 向数据结构中添加一个数 number
 *     void add(int number);
 *     // 寻找当前数据结构中是否存在两个数的和为 value
 *     bool find(int value);
 * };
 */

// add方法是 O(1)，find方法是 O(N)，空间复杂度为 O(N)
class TwoSum_1 {
   public:
    void add(int number) {
        // 记录number出现的次数
        freq[number]++;
    }
    bool find(int value) {
        for (auto& elem : freq) {
            int other = value - elem.first;
            if (other != elem.first && freq[other] > 0 || other == elem.first && freq[other] > 1) {
                return true;
            }
        }
        return false;
    }

   private:
    unordered_map<int, int> freq;
};

// 对于频繁使用find方法的场景，借助哈希集合来针对性优化find方法
#include <unordered_set>
class TwoSum_2 {
   public:
    void add(int number) {
        for (auto n : nums) {
            sum.insert(number + n);
        }
        nums.push_back(number);
    }
    bool find(int value) { return sum.count(value); }

   private:
    vector<int> nums;
    unordered_set<int> sum;
};

int main() {
    auto s = Solution();
    vector<int> arr{2, 1, 2};
    s.twoSum(arr, 4);
}
