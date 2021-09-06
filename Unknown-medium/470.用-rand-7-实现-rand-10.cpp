/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

// @lc code=end

class Solution_1 {
   public:
    int rand10() {
        int a = rand7(), b = rand7();
        while (a == 7) {
            a = rand7();
        }
        // b is union_dist of [1,5]
        while (b > 5) {
            b = rand7();
        }
        return (a & 1 ? 0 : 5) + b;
    }
};

class Solution_2 {
   public:
    int rand10() {
        int ans;
        while (true) {
            // 构造1~49的均匀分布
            // 只能为7，不重不漏
            ans = (rand7() - 1) * 7 + rand7();
            // 剔除大于40的值，1-40等概率出现
            // 取10也可，但更慢
            if (ans <= 40) {
                break;
            }
        }
        return ans % 10 + 1;
    }
};

class Solution_3 {
   public:
    int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40) {
                return 1 + (idx - 1) % 10;
            }
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60) {
                return 1 + (idx - 1) % 10;
            }
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20) {
                return 1 + (idx - 1) % 10;
            }
        }
    }
};
