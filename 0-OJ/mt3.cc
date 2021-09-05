#include <iostream>

using namespace std;

// 不许ac

// 通过一系列交换相邻字符的操作使得操作后的串中不存在ac这个字串。
// 小团想知道他至少要交换多少次才能达成他的目的。

/*
输入描述
第一行有一个整数n(1<=n<=100000)，代表小美拥有的字符串长度。
第二行有一个仅由a和c组成的字符串，代表小美的字符串。
4
acca

输出描述
输出一个整数，代表小团想知道的答案。
如样例中先交换前两个字符再交换中间两个字符即可使小美的字符串变成ccaa。
2
 */

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (s[j] == 'a' && s[j + 1] == 'c') {
                s[j] = 'c', s[j + 1] = 'a';
                ans += 1;
            }
        }
    }
    cout << ans;
}
