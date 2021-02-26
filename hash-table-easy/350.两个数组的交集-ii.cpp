/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int i : nums1) {
            map[i]++;
        }

        vector<int> res;
        for (int i : nums2) {
            if (map.find(i) != map.end() &&
                map[i] != 0)  //不用vector，索引可能为负
                              // or if(map[i]>0)
            {
                res.push_back(i);
                map[i]--;
            }
        }
        return res;
    }
};
// @lc code=end
