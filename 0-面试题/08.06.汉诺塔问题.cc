#include <vector>

using namespace std;

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 39.49% 的用户
// 内存消耗： 6.6 MB , 在所有 C++ 提交中击败了 46.07% 的用户
class Solution {
   public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        move(n - 1, A, C, B);
        C.push_back(A.back());
        A.pop_back();
        move(n - 1, B, A, C);
    }
};