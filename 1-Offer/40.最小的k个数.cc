// 剑指 Offer 40. 最小的k个数
// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

#include <queue>
#include <vector>

using namespace std;

// @heap
class Solution_1 {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) {
            return {};
        }
        priority_queue<int> que;
        for (int i = 0; i < k; i++) {
            que.push(arr[i]);
        }
        int n = arr.size();
        for (int i = k; i < n; i++) {
            if (que.top() > arr[i]) {
                que.pop();
                que.push(arr[i]);
            }
        }
        vector<int> res(k, 0);
        for (int i = 0; i < k; i++) {
            res[i] = que.top();
            que.pop();
        }
        return res;
    }
};

// TODO: redo
// @sort
// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/jian-zhi-offer-40-zui-xiao-de-k-ge-shu-j-9yze/
class Solution_2 {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;
        return quickSort(arr, k, 0, arr.size() - 1);
    }

   private:
    vector<int> quickSort(vector<int>& arr, int k, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l])
                j--;
            while (i < j && arr[i] <= arr[l])
                i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        if (i > k)
            return quickSort(arr, k, l, i - 1);
        if (i < k)
            return quickSort(arr, k, i + 1, r);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
};
