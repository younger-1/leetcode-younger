#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void split(string& s, vector<string>& sv) {
    istringstream iss(s);
    string tmp;
    while (getline(iss, tmp, ',')) {
        sv.push_back(tmp);
    }
}
int main() {
    unordered_map<string, vector<string> > m_deps;
    unordered_map<string, int> cost, count, res;
    string dst, input;
    cin >> dst;
    queue<string> q;
    int len = 3;
    while (len--) {
        cin >> input;
        vector<string> sv;
        split(input, sv);
        cost[sv[0]] = stoi(sv[1]);
        count[sv[0]] = sv.size() - 2;
        res[sv[0]] = -1;
        for (int i = 2; i < sv.size(); i++) {
            m_deps[sv[i]].push_back(sv[0]);
        }
        if (!count[sv[0]]) {
            q.push(sv[0]);
            res[sv[0]] = cost[sv[0]];
        }
    }
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        for (auto x : m_deps[temp]) {
            res[x] = max(res[x], cost[x] + res[temp]);
            if ((--count[x]) == 0) {
                q.push(x);
            }
        }
    }
    cout << res[dst] << endl;
}
