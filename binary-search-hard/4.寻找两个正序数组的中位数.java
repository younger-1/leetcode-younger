/*
 * @lc app=leetcode.cn id=4 lang=java
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1 = nums1.length;
        int length2 = nums2.length;
        int[] arr1 = length1 <= length2 ? nums1 : nums2;
        int[] arr2 = length1 > length2 ? nums1 : nums2;
        if (arr1.length == 0) {
            return middleOfArray(arr2);
        }

        int left1,right1,left2,right2;

        int len1 = arr1.length;
        int len2 = arr2.length;

        int mid1 = len1 / 2;
        int mid2 = len2 / 2;

        int mid11 = mid1 - 1;
        int mid12 = len1 % 2 == 1 ? mid1 + 1 : mid1;
        int mid21 = mid2 - 1;
        int mid22 = len2 % 2 == 1 ? mid2 + 1 : mid2;

        if (len1 == 1) {
            left1 = 0;
            right1 = 0;
            left2 = 0;
            right2 = len2 - 1;
        } else if (arr1[mid12] < arr2[mid2] || arr2[mid21] > arr1[mid1]) {
            left1 = mid1;
            right1 = len1 - 1;
            right2 = mid2;
            left2 = mid2 - (right1 - left1);
        } else if (arr1[mid11] > arr2[mid2] || arr2[mid22] < arr1[mid1]){
            left1 = 0;
            right1 = mid1;
            left2 = mid2;
            right2 = mid2 + (right1 - left1);
        } else {
            return (arr1[mid1] + arr2[mid2]) / 2;
        }

        while (left1 < right1) {
            mid1 = (left1 + right1) / 2;
            mid2 = (left2 + right2) / 2;

            mid11 = mid1 - 1;
            mid12 = len1 % 2 == 1 ? mid1 + 1 : mid1;
            mid21 = mid2 - 1;
            mid22 = len2 % 2 == 1 ? mid2 + 1 : mid2;

            if (arr1[mid1 + 1] < arr2[mid2] || arr2[mid2 - 1] > arr1[mid1]) {
                left1 = mid1;
                right2 = mid2;
            } else {
                right1 = mid1;
                left2 = mid2;
            }
        }

        double result = -1;
        if (len1 % 2 == 1 && len2 % 2 == 1 || len1 % 2 == 0 && len2 % 2 == 0) {
            result = (arr1[mid12] + arr2[mid21]) / 2.0;
        } else if (len1 % 2 == 1) {
            result = arr1[mid1];
        } else if (len2 % 2 == 1) {
            result = arr2[mid2];
        }
        return result;

    }
    
    double middleOfArray(int[] nums) {
        int length = nums.length;
        return length % 2 == 0 ? (nums[length / 2] + nums[length / 2 - 1]) / 2.0 : nums[length / 2];
    }
}
// @lc code=end

