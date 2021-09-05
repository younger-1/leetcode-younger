#include <iostream>
#include <vector>

using namespace std;

// ab串

// “有多少个长度为n的仅由a和b组成的字符串既不包含aba也不包含bab？如果你算不来大数你可以告诉我这个问题的答案模上998244353是多少”

/*
输入描述
第一行有一个整数n(1<=n<=100000)，代表小美问题中的参数。
3

输出描述
输出一个整数，即小美所问问题的答案除以998244353所得余数。
6
 */
int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[3] = 2;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + (1 << (i - 2));
    }
    int res = (1 << n) - dp[n];
    res %= 998244353;
    cout << res;
}
