/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
   public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> hash;
        for (char c : stones) {
            hash[c]++;
        }
        int res = 0;
        for (char c : jewels) {
            if (hash.count(c)) {
                res += hash[c];
            }
        }
        return res;
    }
};
// @lc code=end

#include <algorithm>
#include <unordered_set>

class Solution_1 {
   public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        for (char ch : J)
            s.insert(ch);
        return count_if(begin(S), end(S), [&](char ch) { return s.count(ch); });
    }
};
