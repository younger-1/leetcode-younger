#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

int sum = 0;
int ans = 0;
void dfs(vector<vector<int>>& v, vector<int>& t, int x) {
    sum += t[x];
    ans = max(ans, sum);
    for (int y : v[x]) {
        dfs(v, t, y);
    }
    sum -= t[x];
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>());
    vector<int> out_degree(n, 0);
    vector<int> in_degree(n, 0);
    vector<int> t(n, 0);
    for (int i = 0; i < n; i++) {
        string part1;
        cin >> part1;
        cin >> t[i];
        stringstream ss(part1);
        string num;
        while (getline(ss, num, ',')) {
            int num_ = stoi(num);
            if (num_ != -1) {
                v[i].push_back(num_);
                out_degree[i]++;
                in_degree[num_]++;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0 && out_degree[i] != 0) {
            q.push(i);
        }
    }
    if (q.empty()) {
        cout << -1;
        return 0;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        dfs(v, t, x);
    }
    cout << ans;
}
