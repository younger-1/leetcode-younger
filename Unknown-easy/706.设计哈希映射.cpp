/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

#include <list>
#include <vector>

using namespace std;

// @lc code=start

// 36/36 cases passed (192 ms)
// Your runtime beats 17.45 % of cpp submissions
// Your memory usage beats 41.37 % of cpp submissions (51.7 MB)
// 链地址法
class MyHashMap {
   private:
    vector<list<pair<int, int>>> data;
    static constexpr int base = 769;
    static int hash(int key) { return key % base; }

   public:
    /** Initialize your data structure here. */
    MyHashMap() : data(base) {}

    /** value will always be non-negative. */
    void put(int key, int value) {
        int id = hash(key);
        for (auto it = data[id].begin(); it != data[id].end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        data[id].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) {
        int id = hash(key);
        for (auto it = data[id].begin(); it != data[id].end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) {
        int id = hash(key);
        for (auto it = data[id].begin(); it != data[id].end(); it++) {
            if (it->first == key) {
                data[id].erase(it);
                return;
            }
        }
    }
};
// @lc code=end

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
