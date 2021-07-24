#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 筛选法
vector<int> prime_1(int n) {
    vector<int> res;
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!isprime[i]) {
            continue;
        }
        // 2*i, 3*1,... 都已被排除了
        for (int j = i * i; j <= n; j += i) {
            isprime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            res.push_back(i);
        }
    }
    return res;
}

// 六倍法
// https://blog.csdn.net/hpu2022/article/details/79854707
/*
 *对于大于等于5的数字，我们可以用6的倍数来表示它，即，6x-1, 6x, 6x+1, 6x+2, 6x+3, 6x+4的轮回；
 *其中 6x, 6x+2=2(3x+1), 6x+3=3(2x+1), 6x+4=2(3x+2),
 *显然这些并不是素数；那么，我们可以总结为，对4以上的数字来说，只有6的倍数的左右两位才有可能是素数；
 */
bool is_prime(int x) {
    if (x <= 1)
        return 0;
    if (x == 2 || x == 3 || x == 5)
        return 1;
    if (x % 2 == 0 || x % 3 == 0) /*判断是否为2,3的倍数*/
        return 0;
    for (int i = 6; i * i <= x; i += 6) {
        if (x % (i - 1) == 0 || x % (i + 1) == 0)
            return 0;
    }
    return 1;
}

int main() {
    auto ans = prime_1(25);
    for (auto a : ans) {
        cout << a << " ";
    }
    // int idx = 0;
    // for (int i = 0; i <= ans.back(); i++) {
    //     if (i % 10 == 0) {
    //         cout << endl;
    //     }
    //     cout << (i < ans[idx] ? " " : to_string(ans[idx++])) << " ";
    // }
}
