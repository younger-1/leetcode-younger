#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> cache(1e5 + 1);
vector<vector<pair<int, int>>> nums(1e5 + 1, vector<pair<int, int>>());

// 所有可能的质因子
int son(int n) {
    int nn = n;
    int i = 2;
    while (n != 1) {
        int k = 0;
        if (cache[n]) {
            nums[nn].reserve(nums[nn].size() + nums[n].size());
            nums[nn].insert(nums[nn].end(), nums[n].begin(), nums[n].end());
        }
        while (n % i == 0) {
            k++;
            n /= i;
        }
        if (k) {
            nums[nn].push_back({i, k + 1});
        }
        i++;
    }

    int res = 1;
    for (auto& [_, i] : nums[nn]) {
        res *= i;
    }
    // cout << res << ",";
    cache[nn] = res;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = son(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = son(b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int win = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] > b[j]) {
            win++;
            j++;
        }
    }
    cout << win << endl;
}
