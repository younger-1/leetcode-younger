/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// @force
class Solution {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            for (int j = 0; j < ranges.size(); ++j) {
                if (i >= ranges[j][0] && i <= ranges[j][1]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt == (right - left + 1);
    }
};

// @lc code=end

#include <array>
class Solution_1 {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // https://stackoverflow.com/questions/1920430/c-array-initialization
        std::array<bool, 50 + 1> flag{0};
        int j;
        for (auto& range : ranges) {
            fill(flag.begin() + range[0], flag.begin() + range[1] + 1, true);
        }
        for (int i = left; i <= right; i++) {
            if (!flag[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution_2 {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for (auto& range : ranges) {
            if (range[0] <= left && range[1] >= left)
                left = range[1] + 1;
        }
        return left > right;
    }
};

// @prefix-sum
// 差分数组的前缀和不仅能查询是否被覆盖，还能查询某一区间被覆盖几次。
class Solution_3 {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);  // 差分数组
        for (auto&& range : ranges) {
            ++diff[range[0]];
            --diff[range[1] + 1];
        }
        // 前缀和
        int curr = 0;
        for (int i = 1; i <= 50; ++i) {
            curr += diff[i];
            if (i >= left && i <= right && curr <= 0) {
                return false;
            }
        }
        return true;
    }
};

#include <iostream>
int main() {
    vector<vector<int>> ranges{{5, 9}, {1, 3}, {2, 4}};
    auto s = Solution_1();
    cout << s.isCovered(ranges, 2, 8);
}
