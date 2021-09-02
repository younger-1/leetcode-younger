#include <climits>
#include <vector>

using namespace std;

int largest(vector<int>& nums) {
    int sum = 0, ans = -100;
    for (auto num : nums) {
        if (sum <= 0) {
            sum = num;
        } else {
            sum += num;
        }
        ans = max(ans, sum);
    }
    return ans;
}

int max_sum_of_matrix(int n, int m, vector<vector<int>>& arr) {
    int sum = INT_MIN, ans = INT_MIN;
    vector<int> heights(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            heights[j] += arr[i][j];
        }
        ans = max(ans, largest(heights));
    }
    return ans;
}
