// 剑指 Offer 38. 字符串的排列
// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> permutation(string s) {
        vector<string> ans;
        dfs(ans, s, 0);
        return ans;
    }

   private:
    void dfs(vector<string>& ans, string& s, int idx) {
        if (idx == s.length()) {
            ans.push_back(s);
            return;
        }
        bool flag;
        for (int i = idx; i < s.length(); i++) {
            flag = true;
            // 剪枝：当前位置 i 的字符已经处理过
            for (int j = idx; j < i; j++) {
                if (s[j] == s[i]) {
                    flag = false;
                }
            }
            if (flag) {
                swap(s[i], s[idx]);
                dfs(ans, s, idx + 1);
                swap(s[i], s[idx]);
            }
        }
    }
};
