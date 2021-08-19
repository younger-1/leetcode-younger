/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

#include <string>

using namespace std;

// @lc code=start

class Solution_1 {
   public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && vowels.find(s[left]) == -1) {
                left++;
            }
            while (left < right && vowels.find(s[right]) == -1) {
                right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }

   private:
    const string vowels = "aoeiuAOEIU";
};
// @lc code=end
class Solution {
   public:
    string reverseVowels(string s) {
        // MODERN C++ FEATURES: USER-DEFINED LITERALS
        // https://accu.org/journals/overload/24/136/mertz_2318
        auto isVowel = [vowels = "aeiouAEIOU"s](char ch) { return vowels.find(ch) != string::npos; };

        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && !isVowel(s[i])) {
                ++i;
            }
            while (j > 0 && !isVowel(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};
