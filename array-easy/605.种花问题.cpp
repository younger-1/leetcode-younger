/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start

// 124/124 cases passed (24 ms)
// Your runtime beats 80.42 % of cpp submissions
// Your memory usage beats 5 % of cpp submissions (20.7 MB)
class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        vector<int> bed(m + 2, 0);
        for (int i = 0; i < m; i++) {
            bed[i + 1] = flowerbed[i];
        }

        int i = 0;
        while (i < m) {
            i += 1;
            if (bed[i - 1] || bed[i] || bed[i + 1]) {
                continue;
            }
            bed[i] = 1;
            n -= 1;
        }

        return n > 0 ? false : true;
    }
};
// @lc code=end

int main() {
    vector<int> v{1, 0, 0, 0, 1};
    Solution s = Solution();
    cout << boolalpha << s.canPlaceFlowers(v, 3);
}