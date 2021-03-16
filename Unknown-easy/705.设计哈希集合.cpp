/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

#include <list>
#include <vector>

using namespace std;

// @lc code=start

// 32/32 cases passed (88 ms)
// Your runtime beats 92.13 % of cpp submissions
// Your memory usage beats 46.98 % of cpp submissions (40.8 MB)
class MyHashSet {
   private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key) { return key % base; }

   public:
    /** Initialize your data structure here. */
    MyHashSet() : data(base) {}

    void add(int key) {
        int id = hash(key);
        for (auto val : data[id]) {
            if (val == key) {
                return;
            }
        }
        data[id].push_back(key);
    }

    void remove(int key) {
        int id = hash(key);
        for (auto val : data[id]) {
            if (val == key) {
                data[id].remove(key);
                return;
            }
        }
        // Or use erase
        // for (auto it = data[id].begin(); it != data[id].end(); it++) {
        //     if ((*it) == key) {
        //         data[id].erase(it);
        //         return;
        //     }
        // }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int id = hash(key);
        for (auto val : data[id]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

#include <iostream>
int main() {
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    cout << obj->contains(1) << endl;
    cout << obj->contains(3) << endl;
    obj->add(2);
    cout << obj->contains(2) << endl;
    obj->remove(2);
    cout << obj->contains(2) << endl;
}