/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

#include <iostream>
#include <vector>

using namespace std;

#include <array>
#include <vector>

using namespace std;

// @lc code=start

// Time out
class Solution {
   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r = m, c = n;
        dfs(maxMove, startRow, startColumn);
        return ans;
    }

   private:
    int ans, r, c;
    // https://stackoverflow.com/questions/27669200/how-should-i-brace-initialize-an-stdarray-of-stdpairs
    std::array<pair<int, int>, 4> dire{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    void dfs(int move, int row, int col) {
        dire[0] = {1, 2};
        if (row < 0 || col < 0 || row >= r || col >= c) {
            ans++;
        }
        if (0 == move) {
            return;
        }
        // 剪枝：如果小球不管怎么移动都无法越出网格，那就剪掉这个枝
        // if (i - moveCount >= 0 && j - moveCount >= 0 && i + moveCount < m && j + moveCount < n) {
        //     return;
        // }
        for (auto [i, j] : dire) {
            move--;
            dfs(move, row + i, col + j);
            move++;
        }
    }
};
// @lc code=end

int main() {
    vector<int> items{6, 3, 7, 12};
    int v = 24;
    vector<int> dp(v + 1);
    dp[0] = true;
    for (int i = 0; i < items.size(); i++) {
        for (int j = v; j >= 1; j--) {
            if (j >= items[i]) {
                dp[j] = dp[j - items[i]];
            }
        }
    }
    int idx = v;
    while (!dp[idx]) {
        idx--;
    }
    cout << v - idx << endl;
}
