/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start

// TODO: ?
class WordDictionary {
   public:
    /** Initialize your data structure here. */
    WordDictionary() : children(26), isVal(false) {}

    void addWord(string word) {
        WordDictionary* node = this;
        for (char c : word) {
            c -= 'a';
            if (node->children[c] == nullptr) {
                node->children[c] = new WordDictionary();
            }
            node = node->children[c];
        }
        node->isVal = true;
    }

    bool search(string word) { return dfs(word, 0, this); }

   private:
    vector<WordDictionary*> children;
    bool isVal;
    bool dfs(string& word, int id, WordDictionary* node) {
        int n = word.size();
        if (id == n) {
            return node->isVal;
        }
        for (int i = id; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (node->children[j] == nullptr) {
                        continue;
                    }
                    if (dfs(word, i + 1, node->children[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                if (node->children[word[i] - 'a'] == nullptr) {
                    return false;
                }
                node = node->children[word[i] - 'a'];
            }
        }
        return node->isVal;
    }
};

// @lc code=end

#include <memory>

// TODO: redo
// @trie @DFS
class WordDictionary_1 {
   public:
    /** Initialize your data structure here. */
    WordDictionary_1() : root_(std::make_shared<TrieNode>()) {}

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto res = root_;
        for (auto c : word) {
            if (res->children_[c - 'a'] == nullptr) {
                res->children_[c - 'a'] = std::make_shared<TrieNode>();
            }
            res = res->children_[c - 'a'];
        }
        res->isWord_ = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one
     * letter. */
    bool search(string word) { return find(root_, word, 0); }

   private:
    struct TrieNode {
        TrieNode(bool a) : isWord_(false), children_(26, nullptr) {}
        bool isWord_;
        vector<std::shared_ptr<TrieNode>> children_;
    };

    std::shared_ptr<TrieNode> root_;

    bool find(std::shared_ptr<TrieNode> res, string& word, int idx) {
        if (res == nullptr) {
            return false;
        }
        if (word.size() == idx) {
            return res->isWord_;
        }
        if (word[idx] == '.') {
            for (auto child : res->children_) {
                if (find(child, word, idx + 1)) {
                    return true;
                }
            }
        } else {
            return find(res->children_[word[idx] - 'a'], word, idx + 1);
        }
        return false;
    }
};
