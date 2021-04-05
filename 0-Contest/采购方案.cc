#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 双指针
    int purchasePlans(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int res = 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;

        while (left < right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                res += right - left;
                left++;
            }
            res %= mod;
        }
        return res %= mod;
    }
};

class Solution_0 {
   public:
    int purchasePlans(vector<int>& nums, int target) {
        int n = nums.size();
        long res = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;

        while (j != n && nums[i] + nums[j] <= target) {
            res += j;
            i++;
            j++;
        }

        while (j != n) {
            while (i >= 0 && nums[i] + nums[j] > target) {
                i--;
                if (i == -1) {
                    break;
                }
            }
            res += (i + 1);
            j++;
        }

        return res % 1000000007;
    }
};

int main() {
    Solution s = Solution();

    // vector<int> v{2, 2, 1, 9};
    // cout << s.purchasePlans(v, 10);

    vector<int> v{2, 5, 3, 5};
    cout << s.purchasePlans(v, 6);
}