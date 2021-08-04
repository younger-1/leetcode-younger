#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
常用的位运算包括&（按位与）、|（按位或）、~（按位取反）、^（按位异或）、<<（左移）、>>（右移）。
————————————————
  - &通常用于需要选择特定的数位的情况，因为任何一个数位和1相与得到的是其本身；
  - |通常用于要求尽可能保留1的情况，因为只要有1，或运算的结果一定是1；
  - ~按位取反会将符号位一同取反，得到的还是一个有符号整数；
  - ^常用于去除重复元素的情况，和“负负得正”这种情况比较类似；
  - <<和>>通常和上面4种位运算符搭配使用，不过要注意在Python中左移是不会发生溢出的，需要人为判断溢出。
 */
int main() {
    int a = 12;
    int b = 0;

    bool c;
    int d;

    c = (a > 0) ^ (b > 0);

    // Bitwise negation from last 1
    d = a - 1;

    // Remove the last 1
    // 1100 & 1011 = 1000
    /*
        https://blog.csdn.net/qq_16137569/article/details/82790378
        case1: 判断一个数x是不是2的整数幂
        case2: 计算给定整数的二进制表达中有多少个1
     */
    d = a & (a - 1);

    // All 1 from last 1
    // 1100 ^ 1011 = 0111
    d = a ^ (a - 1);

    // Last 1 position
    d = ((a ^ (a - 1)) + 1) >> 1;

    // 除数为2的指数幂时，高效取余：
    // a % b
    b = 1 << 3;
    int idx = a & (b - 1);
}
