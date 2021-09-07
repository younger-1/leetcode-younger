#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 找到最优的货物组合时货车的剩余空间
/*
假设货车的容量为V(正整数 0 <= V <= 20000), 货物的总个数为(0 < n <= 32)
找出如何将货车的容量充分利用(剩余空间最小)

输入V货车的容量,数组n表示每个货物占用 的体积
输出:个整数,表示货车的剩余容量
 */
int bestFit(int v, vector<int>& item) {
    if (item.empty()) {
        return v;
    }
    vector<vector<int>> dp(32 + 1, vector<int>(20000 + 1));
    int res = v;
    dp[0][0] = 1;
    for (int i = 0; i < item.size(); i++) {
        for (int j = 0; j <= v; j++) {
            dp[i + 1][j] = dp[i][j];
            if (j >= item[i] && dp[i][j - item[i]]) {
                dp[i + 1][j] = 1;
            }
            if (dp[i + 1][j]) {
                res = min(res, v - j);
            }
        }
    }
    return res;
}

int bestFit_1(vector<int> items, int v) {
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
    return v - idx;
}

int main() {
    int v = 24;
    vector<int> it = {8, 3, 12, 7, 9, 7};
    it[2] = 2;
    int ans = bestFit(v, it);
    cout << ans << endl;
}
