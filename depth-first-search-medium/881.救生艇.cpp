/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// @sort @two-pointer
class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++, j--;
            } else {
                j--;
            }
            ans++;
        }
        return ans;
    }
};
// @lc code=end
