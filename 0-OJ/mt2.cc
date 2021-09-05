#include <memory.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// 坐公交

// 美团市中共有n个公交站，编号为1到n。同时也有m条公交线路，编号为1到m。小美想知道对于每一对公交站(i ,j) 从编号为 i
// 的站坐公交到编号为 j 的站至少需要乘坐几条不同的公交线路。

/*
输入描述
第一行有两个空格隔开的整数n,m(1<=n<=500 , 1<=m<=500 且1<=n+m<=500)，代表公交站的个数和公交线路的条数。
接下来n行，每一行开头有一个整数k(1<=k<=m)，代表从这个站可以乘坐k条不同的公交线路。接下来有k个整数，代表这k条公交线路的编号。数字间用空格隔开。
3 2
1 1
2 1 2
1 2

输出描述
输出一个n×n的矩阵，矩阵中第 i 行第 j 列的数代表从编号为 i 的站坐到编号为j的站至少需要乘坐多少条不同的公交线路。
矩阵中每行中的元素由单个空格隔开，且行末不能有空格。
0 1 2
1 0 1
2 1 0
 */

int ans[1000], flags[1000];
vector<vector<int>> arrs, lines;

void test(int u, bool is_do, queue<int>& q) {
    for (auto x : arrs[u]) {
        if (flags[x]) {
            continue;
        }
        for (auto j : lines[x]) {
            if (ans[j] == -1) {
                ans[j] = is_do ? 1 : ans[u] + 1;
                q.push(j);
            }
        }
        flags[x] = 1;
    }
}
int main() {
    int n, m, k;
    cin >> n >> m;
    arrs = vector<vector<int>>(n + 1, vector<int>());
    lines = vector<vector<int>>(m + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> k;
        arrs[i] = vector<int>(k);
        for (int j = 0; j < k; j++) {
            cin >> arrs[i][j];
            lines[arrs[i][j]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        memset(ans, -1, sizeof(ans));
        memset(flags, 0, sizeof(flags));
        test(i, true, q);
        while (q.size()) {
            int x = q.front();
            q.pop();
            test(x, false, q);
        }
        ans[i] = 0;
        for (int j = 0; j < n; j++) {
            cout << ans[j + 1] << " ";
        }
        cout << endl;
    }
}
