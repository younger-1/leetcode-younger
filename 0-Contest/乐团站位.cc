#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
   public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int i = min({xPos, yPos, num - 1 - xPos, num - 1 - yPos});
        int l = i, u = i, d = num - i - 1, r = num - i - 1, mod = 9;
        // 外正方形面积-内正方形面积 num*num-(num-2*i)*(num-2*i)
        // 平方差公式化简为 4*i*(n-i)
        // int res = i * (num - i) * 4;
        int res = i % mod * ((num - i) % mod) * 4;
        if (u == xPos) {
            res = (res + yPos - l) % mod;
            return res + 1;
        } else {
            res = (res + r - l + 1) % mod;
            u++;
        }
        if (r == yPos) {
            res = (res + xPos - u) % mod;
            return res + 1;
        } else {
            res = (res + d - u + 1) % mod;
            r--;
        }
        if (d == xPos) {
            res = (res + r - yPos) % mod;
            return res + 1;
        } else {
            res = (res + r - l + 1) % mod;
            d--;
        }
        if (l == yPos) {
            res = (res + d - xPos) % mod;
            return res + 1;
        } else {
            res = (res + d - u + 1) % mod;
            l++;
        }

        return res + 1;
    }
};

class Solution_0 {
   public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int mod = 9;
        int k = min({xPos, yPos, num - 1 - xPos, num - 1 - yPos});
        // int k = circle(num, xPos, yPos);
        int len_before = k % mod * ((num - k) % mod) * 4;
        // int len_before = 2 * ((num - 1) % 9 + (num - 2 * k + 1) % 9) * k % 9;
        len_before %= mod;
        int len = getLen(num - 2 * k, xPos - k, yPos - k);
        len %= mod;
        int total = len_before + len;
        return (total - 1) % mod + 1;
    }

    int circle(int num, int x, int y) {
        int x_ = min(x + 1, num - x);
        int y_ = min(y + 1, num - y);
        int layer = min(x_, y_);
        return layer - 1;
    }

    int getLen(int n, int x, int y) {
        if (x == 0) {
            return y + 1;
        } else if (y == n - 1) {
            return (n - 1) + x + 1;
        } else if (x == n - 1) {
            return 2 * (n - 1) + (n - y);
        } else if (y == 0) {
            return 3 * (n - 1) + (n - x);
        }
        return 0;
    }
};

int main() {
    Solution s = Solution();
    // cout << s.orchestraLayout(3, 0, 2) << endl;
    // cout << s.orchestraLayout(4, 1, 2) << endl;
    cout << s.orchestraLayout(5, 2, 3) << endl;
}