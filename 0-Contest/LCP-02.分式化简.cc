// LCP 02. 分式化简
// https://leetcode-cn.com/problems/deep-dark-fraction/

#include <vector>

using namespace std;

// @iteration
class Solution {
   public:
    vector<int> fraction(vector<int>& cont) {
        int a = 1, b = 0, tmp;
        int n = cont.size();
        for (int i = n - 1; i >= 0; i--) {
            tmp = a;
            a = cont[i] * a + b;
            b = tmp;
        }
        return {a, b};
    }
};

// @recursion
class Solution_01 {
   public:
    vector<int> fraction(vector<int>& cont) {
        auto [a, b] = helper(cont, 0);
        return {a, b};
    }
    pair<int, int> helper(vector<int>& cont, int id) {
        if (id == cont.size() - 1) {
            return {cont[id], 1};
        }
        auto [a, b] = helper(cont, id + 1);
        return {cont[id] * a + b, a};
    }
};
