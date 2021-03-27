#include <stdio.h>

#include <vector>
using namespace std;

int longest_continuous_ones(vector<int>& nums) {
    int n = nums.size();
    vector<int> zeros;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zeros.push_back(i);
        }
    }

    if (zeros.size() == n) {
        return 0;
    }
    if (zeros.size() < 2) {
        return n - 1;
    }
    int m = zeros.size();
    int res = max(zeros[1] - 1, n - zeros[m - 2] - 2);

    for (int i = 1; i < m - 1; i++) {
        res = max(res, zeros[i + 1] - zeros[i - 1] - 2);
    }

    return res;
}

/*
 * 输入：T 组， 每组 n 个数， 都是由 0，1 组成
 * 输出：每组数去掉任何一个 0 后，找到最长的连续的 1，打印其长度
 */
int main() {
    int T, n;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        vector<int> nums;
        int num;
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            nums.push_back(num);
        }
        int res = longest_continuous_ones(nums);
        printf("%d\n", res);
    }
}