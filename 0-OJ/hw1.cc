
#include <iostream>
#include <string>
#include <vector>

#include "stdio.h"

using namespace std;

/*

Input:

 */
struct Node {
    int val, id;
    Node *left, *right;
    Node(int val, int id) : val(val), id(id) {}
};

int dfs(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    root->val += dfs(root->left) + dfs(root->right);
    return root->val;
}

void diff_helper(Node *root, int &sum, int &tmp, int &ans) {
    if (root == nullptr) {
        return;
    }
    int diff = abs(sum - 2 * root->val);
    if (diff >= tmp) {
        if (diff == tmp) {
            if (ans > root->id) {
                ans = root->id;
            }
        }
        tmp = diff;
        ans = root->id;
    }
    diff_helper(root->left, sum, tmp, ans);
    diff_helper(root->right, sum, tmp, ans);
}

int main() {
    int n, value;
    scanf("%d", &n);
    vector<Node *> vec(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        vec[i] = new Node(value, i);
    }
    // cout << vec.size() << endl;
    int foo, bar;
    while (scanf("%d%d", &foo, &bar) != EOF) {
        if (vec[foo]->left == nullptr) {
            vec[foo]->left = vec[bar];
        } else {
            vec[foo]->right = vec[bar];
        }
    }
    int sum = dfs(vec[0]);
    int tmp = 0;
    int ans = 0;
    diff_helper(vec[0], sum, tmp, ans);
    cout << ans << endl;
    return 0;
}
