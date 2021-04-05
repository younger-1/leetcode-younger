// OJ在线编程常见输入输出练习
// https://ac.nowcoder.com/acm/contest/5657

#include "stdio.h"

// A.
// 输入: 包括两个正整数a,b, 输入数据包括多组。
// 输出: a+b 的结果
void A() {
    int a, b;
    // Ctrl_C is EOF
    while (scanf("%d %d", &a, &b) != EOF) {
        // note: "\n"
        printf("%d\n", a + b);
    }
}

// B.
// 输入: 第一行包括一个数据组数 t, 接下来每行包括两个正整数 a,b
// 输出: a+b 的结果
void B() {
    int t;
    int a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
}

// D.
// 输入: 数据包括多组。每组数据一行,每行的第一个整数为整数的个数n, n为 0 的时候结束输入。接下来输入n个正整数
// 输出: 每组数据输出求和的结果
void D() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        int sum = 0;
        int a;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
    }
} 

// G.
// 输入: 数据有多组, 每行表示一组输入数据。每行不定有n个整数，空格隔开。(1 <= n <= 100)。
// 输出: 每组数据输出求和的结果
void G() {
    int sum = 0;
    int a;
    while (scanf("%d", &a) != EOF) {
        sum += a;
        // note:
        if (getchar() == '\n') {
            printf("%d\n", sum);
            sum = 0;
        }
    }
}

int main() {
    // A();
    // B();
    // D();
    G();
    return 0;
}
