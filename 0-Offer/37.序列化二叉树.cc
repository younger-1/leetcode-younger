// 剑指 Offer 37. 序列化二叉树
// https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#include <string>

using namespace std;

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs_seri(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        idx = 0;
        return dfs_deseri(data);
    }

   private:
    int idx;
    void dfs_seri(TreeNode* root, string& s) {
        if (root == nullptr) {
            s.push_back('#');
            s.push_back(',');
            return;
        }
        s += to_string(root->val) + ',';
        dfs_seri(root->left, s);
        dfs_seri(root->right, s);
    }
    TreeNode* dfs_deseri(string& data) {
        int count = data.find(',', idx) - idx;
        string s = data.substr(idx, count);
        idx += count + 1;
        if (s == "#") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(s));
        node->left = dfs_deseri(data);
        node->right = dfs_deseri(data);
        return node;
    }
};

// TODO: redo
// 作者：moao
// 链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/solution/lun-ru-he-yong-acmei-ri-yi-ti-by-moao-i6zk/
#include <sstream>
class Codec_1 {
   public:
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "(*￣︶￣)";
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return dfs_deserialize(iss);
    }

   private:
    TreeNode* dfs_deserialize(istringstream& iss) {
        string val;
        iss >> val;
        if (val == "(*￣︶￣)")
            return nullptr;
        return new TreeNode(stoi(val), dfs_deserialize(iss), dfs_deserialize(iss));
    }
};

#include <iostream>
int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    auto c = Codec();
    string s = c.serialize(root);
    cout << s << endl;
    c.deserialize(s);
}
