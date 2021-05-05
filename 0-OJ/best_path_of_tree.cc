#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tree {
    int val;
    Tree* left;
    Tree* right;
    Tree(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool backtrace(Tree* tree, vector<int>& path, int target, int sum) {
    path.push_back(tree->val);
    sum += tree->val;

    if (sum == target) {
        return true;
    } else if (sum > target) {
        return false;
    } else if (backtrace(tree->left, path, target, sum)) {
        return true;
    } else if (backtrace(tree->right, path, target, sum)) {
        return true;
    }

    path.pop_back();
    sum -= tree->val;

    return false;
}

vector<int> best_path_of_tree(Tree* tree, int target) {
    vector<int> res;
    backtrace(tree, res, target, 0);
    return {};
}

/*
 * stdin: 1. Level-order traversal of a tree. 2. A value
[3,1,5,2,null,4,6]
8
 * stdout: Path which starts from root should sum to the value.
[3,5]
 */
int main() {
    vector<string> data;
    string tmp;
    while (getline(cin, tmp, ',')) {
        data.push_back(tmp);
        if (cin.get() == '\n') {
            break;
        }
    }

    for (auto d : data) {
        cout << d << " ";
    }
}