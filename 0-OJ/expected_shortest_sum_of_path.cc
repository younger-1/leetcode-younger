#include <stdio.h>

#include <vector>

using namespace std;

double expected_shortest_sum_of_path(vector<vector<int>>& mat, vector<vector<int>>& three) {
    double res;
    return res;
}

/*
 * 输入：第一行的 n 代表有 n 个节点，接下来 n-1 行是节点之间的距离：
 * eg. [2 4 6] 代表节点 2 与节点 4 之间的距离为 6
 * 接下来 3 行是分别是小明，小红，小刚三人可以入住的节点（酒店），都以相同的概率入住
 * eg. [4 1 2 3 4] 代表小某以 1/4 概率入住这 4 个节点，[2 4 3] 代表小某以 1/2 的概率入住 4，3 节点
3
1 2 6
2 4 9
1 3 3
1 2
1 3
2 1 4
 */
int main() {
    int n;
    scanf("%d", &n);
    int s, t, w;
    // 0 is not real node, just a placeholder
    vector<vector<int>> mat(1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &s);
        scanf("%d", &t);
        scanf("%d", &w);
        if (s > t) {
            int tmp = s;
            s = t;
            t = tmp;
        }
        while (s + 1 > mat.size()) {
            // 0 is not real node, just a placeholder
            mat.push_back(vector<int>(1, 0));
        }
        while (t + 1 > mat[s].size()) {
            mat[s].push_back(0);
        }
        mat[s][t] = w;
    }

    // int* three[3];
    vector<vector<int>> three(3, vector<int>());
    int m, k;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &k);
            three[i].push_back(k);
        }
    }

    double res = expected_shortest_sum_of_path(mat, three);
    printf("%f", res);

    // for (auto v : mat) {
    //     for (int i : v) {
    //         printf("%d ", i);
    //     }
    //     printf("\n");
    // }

    return 0;
}