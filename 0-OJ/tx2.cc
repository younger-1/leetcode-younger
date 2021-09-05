

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> cache((int)1e5 + 1);

// 所有可能的质因子
int son(int n) {
    if (cache[n]) {
        return cache[n];
    }
    vector<int> p;
    int i = 2;
    while (n != 1) {
        int k = 0;
        while (n % i == 0) {
            k++;
            n /= i;
        }
        i++;
        p.push_back(k + 1);
    }

    int res = 1;
    for (int i : p) {
        res *= i;
    }
    // cout << res << ",";
    cache[n] = res;
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
