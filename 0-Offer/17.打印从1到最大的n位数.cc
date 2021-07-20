// 剑指 Offer 17. 打印从1到最大的n位数
// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> printNumbers(int n) {
        int max = 1;
        while (n--) {
            max *= 10;
        }
        vector<int> ans;
        int i = 1;
        while (i < max) {
            ans.push_back(i);
            i++;
        }
        return ans;
    }
};

#include <string>
// @DFS
class Solution_1 {
   public:
    vector<int> printNumbers(int n) {
        s.resize(n, '0');
        dfs(n, 0);
        return nums;
    }

   private:
    vector<int> nums;
    string s;

    // 枚举所有情况
    void dfs(int end, int index) {
        if (index == end) {
            save();
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            s[index] = i + '0';
            dfs(end, index + 1);
        }
    }

    // 去除首部0
    void save() {
        int ptr = 0;
        while (ptr < s.size() && s[ptr] == '0')
            ptr++;
        if (ptr != s.size())
            nums.emplace_back(stoi(s.substr(ptr)));
    }
};
