// 一个无序的字符串数组，求不重复的个数，要求不能使用STL库函数；
// vector<string>
// 例如：xx adafaf aa aa aa xx xxxx ieaffa aaaaa

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int j = 0;

void qs(vector<string>& ss, int begin, int end) {
    if (begin > end) {
        return;
    }
    int l = begin, r = end;
    string& pivot = ss[begin];
    while (l < r) {
        while (l < r && ss[r] >= pivot) {
            r--;
        }
        while (l < r && ss[l] <= pivot) {
            l++;
        }
        swap(ss[l], ss[r]);
    }
    swap(ss[l], ss[begin]);
    qs(ss, begin, l - 1);
    qs(ss, l + 1, end);
}

int main() {
    vector<string> ss{"1", "1", "2", "3", "3"};
    // vector<string> ss{"1"};
    // vector<string> ss{"x", "adafaf", "aa", "aa", "aa", "xx", "xxxx", "ieaffa", "aaaaa"};
    int n = ss.size();
    qs(ss, 0, n - 1);

    // for (auto& s : ss) {
    //     cout << s << " ";
    // }

    int i = 0, ans = 0;
    while (i < n) {
        if ((i == 0 || ss[i] != ss[i - 1]) && (i == n - 1 || ss[i] != ss[i + 1])) {
            ans++;
        }
        i++;
    }

    cout << ans << endl;
}
