#include <stdio.h>

#include <vector>

using namespace std;

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

int f(int x) {
    int i = 1, ans = 0;
    while (i * i <= x) {
        if (x % i == 0 && 1 == gcd(i, x / i)) {
            ans++;
        }
        i++;
    }
    return ans;
}

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", f(N));
    }
}
