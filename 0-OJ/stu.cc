#include <queue>
#include <vector>

using namespace std;

vector<int> time_get_food(vector<int> L, vector<int> R) {
    auto cmp = [](auto& a, auto& b) {
        if (a.first > b.first) {
            return true;
        } else if (a.first < b.first) {
            return false;
        }
        return a.second > b.second;
    };
    using _pair = pair<int, int>;
    using _container = vector<_pair>;
    priority_queue<_pair, _container, decltype(cmp)> q(cmp);

    int n = L.size();
    for (int i = 0; i < n; i++) {
        q.push({L[i], R[i]});
    }
    vector<int> res;
    res.reserve(n);
    int t = 1;
    while (!q.empty()) {
        auto [l, r] = q.top();
        q.pop();
        if (t < l) {
            t = l;
        }
        if (r < t) {
            res.push_back(0);
        } else {
            t += 1;
            res.push_back(t);
        }
    }
    return res;
}

/*
 * Input:   1. First line is an integer(1<=t<=100), which is the number of test group;
 *          2. Next t groups, the first line of each group is an integer(1<=n<=10000);
 *          3. Next n lines, every line are two integer: L[i], R[i] (1<=L[i]<=R[i]<=5000)
 */
int main() {}