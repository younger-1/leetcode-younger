/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> count;
        for (int y : answers) {
            ++count[y];
        }
        int ans = 0;
        // 有 x 只兔子都回答 y
        for (auto &[y, x] : count) {
            // x/(y+1) 的上界
            // ans += ceil((double)(x) / (y + 1)) * (y + 1);
            ans += (x + y) / (y + 1) * (y + 1);
        }
        return ans;
    }
};
// @lc code=end

int main() {
    auto s = Solution();
    auto v = vector<int>{2, 3, 4};
    cout << s.numRabbits(v);
}