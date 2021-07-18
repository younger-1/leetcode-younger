// 面试题 10.02. 变位词组
// https://leetcode-cn.com/problems/group-anagrams-lcci/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Wrong: get_hash not implemented
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int, int> index;
        vector<vector<string>> ans;
        for (auto& str : strs) {
            int hash = get_hash(str);
            if (index.end() == index.find(hash)) {
                index[hash] = ans.size();
                ans.push_back(vector<string>());
            }
            ans[index[hash]].push_back(str);
        }
        return ans;
    }

   private:
    int get_hash(string& s) {
        int res = 0;
        for (auto c : s) {
            res += (c - 'a') * (c - 'a' + 100);
        }
        return res;
    }
};

#include <algorithm>

class Solution_1 {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
