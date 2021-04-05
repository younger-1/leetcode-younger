/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};

// @lc code=end

// 0-8ms 9MB
class Solution_0 {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m - 1;
        int second = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (first != -1 && second != -1) {
                if (nums1[first] >= nums2[second]) {
                    nums1[i] = nums1[first];
                    first--;
                    continue;
                } else {
                    nums1[i] = nums2[second];
                    second--;
                    continue;
                }
            }
            if (first == -1) {
                if (second >= 0) {
                    nums1[i] = nums2[second];
                    second--;
                    continue;
                }
            }
        }
    }
};