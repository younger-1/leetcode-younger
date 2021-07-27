
#include <iostream>
#include <numeric>
using namespace std;

// greatest common divisor
// 辗转相除法（欧几里得算法）
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

// least common multiple
int lcm(int x, int y) { return x * y / gcd(x, y); }

// n个数的最大公约数ngcd
int ngcd(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return gcd(arr[n - 1], ngcd(arr, n - 1));
}
// n个数的最小公倍数nlcm
int nlcm(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return lcm(arr[n - 1], nlcm(arr, n - 1));
}

int main() {
    int x = 12;
    int y = 16;
    cout << gcd(x, y) << endl;
    cout << lcm(x, y) << endl;
}
