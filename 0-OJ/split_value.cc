/*
求数组中比左边元素都大同时比右边元素都小的元素，返回这些元素的索引

要求时间复杂度 O(N)O\left(N\right)O(N)

    输入：[2, 3, 1, 8, 9, 20, 12]
    输出：3, 4
    解释：数组中 8, 9 满足题目要求，他们的索引分别是 3、4

链接：https://leetcode-cn.com/circle/discuss/fBUtcu/
*/

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> find(vector<int> nums) {
    vector<int> res;
    int n = nums.size();
    vector<int> left_max(n, INT_MIN);
    vector<int> right_min(n, INT_MAX);
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i - 1], nums[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right_min[i] = min(right_min[i + 1], nums[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        if (left_max[i] < nums[i] && nums[i] < right_min[i]) {
            res.push_back(i);
        }
    }
    return res;
}

vector<int> find_2(vector<int> nums) {
    int n = nums.size();
    vector<int> minArr(n);
    int min = INT_MAX;
    // 记录每一个元素，对应的数组右侧的最小值
    for (int i = n - 1; i >= 0; i--) {
        min = nums[i] < min ? nums[i] : min;
        minArr[i] = min;
    }

    int max = nums[0];
    vector<int> res;
    for (int i = 1; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
            if (minArr[i + 1] > nums[i]) {
                res.push_back(i);
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 3, 1, 8, 9, 20, 12};
    // auto res = find(arr);
    auto res = find_2(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
}
