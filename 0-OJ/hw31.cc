#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool flag = 0;

void split(const string &s, vector<string> &sv) {
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, ','))
        sv.emplace_back(temp);
}

int dfs(vector<vector<int>> &G, int cur, vector<int> &vis, vector<int> &cost, vector<int> &ret) {
    cout << cur << " ";
    int ans = 0;
    if (flag == 1) {
        cout << "f1"
             << " ";
        return -1;
    }
    if (cost[cur] == -1) {
        cout << "f2"
             << " ";
        flag = 1;
        return -1;
    }
    if (vis[cur] == 2) {
        cout << "vis[cur]=2"
             << " ";
        return ret[cur];
    } else if (vis[cur] == 1) {
        cout << "vis[cur]=1"
             << " ";
        flag = 1;
        return -1;
    }
    vis[cur] = 1;
    for (int i = 0; i < G[cur].size(); ++i) {
        ans = max(ans, dfs(G, G[cur][i], vis, cost, ret));
    }
    vis[cur] = 2;
    ret[cur] = ans + cost[cur];
    return ret[cur];
}

int main() {
    unordered_map<string, int> m;
    vector<int> timecost(50001, -1);
    vector<vector<int>> G;
    string str;
    int idx = 0;
    // cout << "idx:" << idx << endl;
    while (cin >> str) {
        vector<string> splitstr;
        int cost;
        split(str, splitstr);
        if (m.find(splitstr[0]) == m.end()) {
            m[splitstr[0]] = idx++;
            // cout << "m[]" << m[splitstr[0]] << endl;
            G.emplace_back(vector<int>(0));
        }
        if (splitstr.size() > 1) {
            cost = stoi(splitstr[1]);
            timecost[m[splitstr[0]]] = cost;
            for (int i = 2; i < splitstr.size(); ++i) {
                if (m.find(splitstr[i]) == m.end()) {
                    m[splitstr[i]] = idx++;
                    G.emplace_back(vector<int>(0));
                }
                G[m[splitstr[0]]].emplace_back(m[splitstr[i]]);
                // cout << m[splitstr[i]] << m[splitstr[0]] << endl;
            }
        }
    }
    cout << "G:" << idx << endl;
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            cout << G[i][j] << ",";
        }
        cout << " " << endl;
    }
    vector<int> vis(idx, 0);
    vector<int> ret(idx, -1);
    dfs(G, 0, vis, timecost, ret);
    if (flag) {
        ret[0] = -1;
    }
    cout << ret[0] << endl;
    return 0;
}
