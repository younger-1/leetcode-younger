#include <iostream>
#include <vector>

using namespace std;

// 四边形

// 无向图中的四边形由四个不同的点a,b,c,d和四条属于这张无向图的边(a,b),(b,c),(c,d),(d,a)组成。
// 若两个四边形的点集和边集相同，则我们认为这两个四边形是同一个四边形。小美的这张无向图有点大，她希望你帮她算出这个难题的答案。

/*
输入描述
第一行有一个整数n代表这张无向图中的点数。n的范围为小于等于500
接下来n行给出这张无向图的邻接矩阵，每行有n个由空格隔开的整数，每个整数的值为0或1。
输入保证对角元为0，即这张图没有自环。
6
0 1 1 1 0 0
1 0 1 0 1 0
1 1 0 0 0 1
1 0 0 0 1 1
0 1 0 1 0 1
0 0 1 1 1 0

输出描述
输出一个整数，代表这张无向图中有多少个不同的四边形。
3
 */

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;

    for (int a1 = 0; a1 < n - 1; a1++) {
        for (int b1 = a1 + 1; b1 < n; b1++) {
            for (int a2 : g[a1]) {
                if (a2 == 0) {
                    continue;
                }
                for (int b2 : g[b1]) {
                    if (b2 == 0) {
                        continue;
                    }
                    if (g[a1][b1] && g[a2][b2]) {
                        ans++;
                    }
                    if (g[a1][b2] && g[a2][b1]) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
}
