/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int h = N;
        while (h) {
            if (citations[N - h] >= h) {
                return h;
            }
            h--;
        }
        return 0;
    }
};
// @lc code=end
