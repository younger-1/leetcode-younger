
#include <stdio.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Solution {
   public:
    void solve(vector<vector<int>> &infos) {
        int n = infos.size();
        vector<int> ot(n);
        auto cmp = [](auto &a, auto &b) -> bool { return a[0] == b[0] ? a[2] > b[2] : a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.push(infos[i]);
        }
        int t = 1;
        while (!pq.empty()) {
            auto cur = pq.top();
            t = max(t, cur[0]);
            if (cur[1] >= t) {
                ot[cur[2]] = t;
                ++t;
            } else {
                ot[cur[2]] = 0;
            }
            pq.pop();
        }
        for (int i = 0; i < n - 1; ++i) {
            printf("%d ", ot[i]);
        }
        if (n > 0)
            printf("%d", ot[n - 1]);
        printf("\n");
    }
};
int main() {
    int T, n;
    scanf("%d", &T);
    Solution a;
    while (T--) {
        scanf("%d", &n);
        vector<vector<int>> infos(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &infos[i][0], &infos[i][1]);
            infos[i][2] = i;
        }
        a.solve(infos);
    }
    return 0;
}
