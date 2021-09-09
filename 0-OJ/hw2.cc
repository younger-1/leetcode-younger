
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "stdio.h"

using namespace std;

int main() {
    int n, m;
    int comma = 0;
    int dire[2][2] = {{0, 1}, {1, 0}};
    string dimention;
    cin >> dimention;
    while (comma < dimention.size() && dimention[comma] != ',') {
        comma++;
    }
    n = stoi(dimention.substr(0, comma));
    m = stoi(dimention.substr(comma + 1));
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &nums[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> steps(n, vector<int>(m, -1));
    steps[0][0] = 0;
    while (!q.empty()) {
        auto head = q.front();
        int x = head.first, y = head.second;
        q.pop();
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= nums[x][y]; j++) {
                int nx = x + dire[i][0] * j, ny = y + dire[i][1] * j;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && steps[nx][ny] == -1) {
                    steps[nx][ny] = steps[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << steps[n - 1][m - 1] << endl;
}
