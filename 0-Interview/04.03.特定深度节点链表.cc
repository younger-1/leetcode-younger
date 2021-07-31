// 面试题 04.03. 特定深度节点链表
// https://leetcode-cn.com/problems/list-of-depth-lcci/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <string>
#include <vector>

using namespace std;

// @DFS
class Solution {
   public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        dfs(tree, 0);
        return ans;
    }

   private:
    vector<ListNode*> ans;
    void dfs(TreeNode* tree, int depth) {
        if (!tree) {
            return;
        }
        if (ans.size() < depth + 1) {
            ans.push_back(new ListNode(tree->val));
        } else {
            ListNode* node = ans[depth];
            while (node->next) {
                node = node->next;
            }
            node->next = new ListNode(tree->val);
        }
        dfs(tree->left, depth + 1);
        dfs(tree->right, depth + 1);
    }
};

// TODO:
// @BFS
// 链接：https://leetcode-cn.com/problems/list-of-depth-lcci/solution/cchao-100de-yan-du-you-xian-by-ffreturn-96yx/
#include <queue>

class Solution_1 {
   public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        // 返回的结果
        vector<ListNode*> res;
        if (tree == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(tree);

        while (!q.empty()) {
            ListNode* head = nullptr;
            ListNode* prev = nullptr;
            // 只遍历当前层的大小
            int currSize = q.size();
            for (int i = 0; i < currSize; ++i) {
                TreeNode* currNode = q.front();
                ListNode* newNode = new ListNode(currNode->val);
                q.pop();
                // 这里需要考虑链表首结点和构建
                if (head == nullptr) {
                    head = newNode;
                } else {
                    prev->next = newNode;
                }
                prev = newNode;

                if (currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr) {
                    q.push(currNode->right);
                }
            }
            res.push_back(head);
        }
        return res;
    }
};
