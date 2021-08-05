// 剑指 Offer 41. 数据流中的中位数
// https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/

#include <queue>

using namespace std;

// TODO: redo
/*
    https://leetcode-cn.com/problems/find-median-from-data-stream/comments/40863
    在数据流中，数据会不断涌入结构中，那么也就面临着需要多次动态调整以获得中位数。
    因此实现的数据结构需要既需要快速找到中位数，也需要做到快速调整。
    首先能想到就是二叉搜索树，在平衡状态下，树顶必定是中间数，然后再根据长度的奇偶性决定是否取两个数。
    此方法效率高，但是手动编写较费时费力。
    根据只需获得中间数的想法，可以将数据分为左右两边，一边以最大堆的形式实现，可以快速获得左侧最大数，
    另一边则以最小堆的形式实现。其中需要注意的一点就是左右侧数据的长度差不能超过1。
    这种实现方式的效率与AVL平衡二叉搜索树的效率相近，但编写更快
 */
class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        // Wrong: push{4,3,2}
        // minheap.push(num);

        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if (maxheap.size() < minheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        if (maxheap.size() == minheap.size()) {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        return maxheap.top();
    }

   private:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#include <iostream>
int main() {
    auto s = MedianFinder();
    s.addNum(1);
    s.addNum(4);
    cout << s.findMedian() << endl;
    s.addNum(6);
    cout << s.findMedian() << endl;
    s.addNum(3);
    cout << s.findMedian() << endl;
}
