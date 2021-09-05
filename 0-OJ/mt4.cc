#include <iostream>
#include <sstream>
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

template <typename T, template <typename ELEM, typename ALLOC = std::allocator<ELEM>> class Container>
std::ostream& operator<<(std::ostream& o, const Container<T>& container) {
    typename Container<T>::const_iterator beg = container.begin();
    o << "[";  // 1
    while (beg != container.end()) {
        o << " " << *beg++;  // 2
    }
    o << " ]";  // 3
    return o;
}

int main() {
    int n;
    cin >> n;
#define test
#ifdef test
    istringstream cin(
        "0 1 1 1 0 0"
        "1 0 1 0 1 0"
        "1 1 0 0 0 1"
        "1 0 0 0 1 1"
        "0 1 0 1 0 1"
        "0 0 1 1 1 0");
#endif
    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<vector<int>> edges(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 1) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    cout << g << endl;
    cout << edges << endl;

    int ans = 0;
    for (int a1 = 0; a1 < n - 1; a1++) {
        for (int b1 = a1 + 1; b1 < n; b1++) {
            for (int a2 : edges[a1]) {
                if (a2 == a1 || a2 == b1) {
                    continue;
                }
                for (int b2 : edges[b1]) {
                    if (b2 == a1 || b2 == b1 || b2 == a2) {
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
    cout << ans << endl;
}
