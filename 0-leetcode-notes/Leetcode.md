- [初级算法](#初级算法)
  - [数组](#数组)
    - [136 只出现一次的数字](#136-只出现一次的数字)
    - [189 旋转数组](#189-旋转数组)
    - [350 两个数组的交集 II](#350-两个数组的交集-ii)
    - [1 两数之和](#1-两数之和)
    - [283 移动零](#283-移动零)
  - [字符串](#字符串)
    - [344 反转字符串](#344-反转字符串)
    - [387 字符串中的第一个唯一字符](#387-字符串中的第一个唯一字符)
    - [8 字符串转换整数 (atoi)](#8-字符串转换整数-atoi)
    - [28 实现 strStr()](#28-实现-strstr)
  - [链表](#链表)
    - [237 删除链表中的节点](#237-删除链表中的节点)
    - [206 反转链表](#206-反转链表)
    - [21 合并两个有序链表](#21-合并两个有序链表)
  - [树](#树)
    - [234 回文链表](#234-回文链表)
    - [104 二叉树的最大深度](#104-二叉树的最大深度)
    - [98 验证二叉搜索树](#98-验证二叉搜索树)
    - [102 二叉树的层序遍历](#102-二叉树的层序遍历)
    - [108 将有序数组转换为二叉搜索树](#108-将有序数组转换为二叉搜索树)
  - [排序和搜索](#排序和搜索)
    - [88 合并两个有序数组](#88-合并两个有序数组)
    - [278 第一个错误的版本](#278-第一个错误的版本)
  - [动态规划](#动态规划)
    - [爬楼梯](#爬楼梯)
    - [买卖股票最佳时机](#买卖股票最佳时机)
    - [最大子序和](#最大子序和)



## 初级算法



### 数组



#### 136 只出现一次的数字


```cpp
//36ms
class Solution0 {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for (auto elem : nums) {
            if (s.count(elem))
            {
                s.erase(elem);
            }
            else {
                s.insert(elem);
            }
        }
        return *s.begin();
    }
};

//0-20ms 11.7MB
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            num = num ^ nums[i];
        }
        return num;
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            num = num ^ *it;
        }
        return num;
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for (auto n:nums) a^=n;
        return a;
    }
};
```



#### 189 旋转数组

```cpp
// time out
#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
    int tmp;
    k %= nums.size(); //reduce unnecessary iterations
    for (int i = 1; i != k + 1; i++) {
        tmp = nums.back();
        for (auto it = --nums.end(); it != nums.begin(); it--)
            *it = *(it - 1);
        nums[0] = tmp;
    }
}
int main() {
    vector<int> v{ 2,3,4,5,6,7,8,9,10 };
    rotate(v,3);
    for (auto i : v) cout << i << " ";
}

// time out
class Solution0 {
   public:
    void rotate(vector<int>& nums, int k) {
        int tmp;
        k %= nums.size();
        // reduce unnecessary iterations
        for (int i = 0; i != k % nums.size(); i++) {
            tmp = nums.back();
            for (int index = nums.size() - 1; index != 0; index--)
                nums[index] = nums[index - 1];
            nums[0] = tmp;
        }
    }
};

// 4ms
// 加一个数组, 不满足O(1)
// (i + k) % nums.size() 可直接获取元素旋转之后的位置
class Solution1 {
   public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2(nums);
        int n = nums.size();
        for (int i = 0; i != n; ++i) {
            nums[(i + k) % n] = nums2[i];  // image a cirlce
        }
    }
};

// 0ms
class Solution1 {
   public:
    void rotate(vector<int>& nums, int k) {
        int* temp;
        temp = (int*)malloc(sizeof(int) * nums.size());
        k = k % nums.size();
        for (int i = 0; i < k; i++) {
            temp[i] = nums[nums.size() - k + i];  //后面k个
        }
        for (int i = k; i < nums.size(); i++) {
            temp[i] = nums[i - k];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }
    }
};

// 4ms
// 三次翻转
class Solution2 {
   public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= nums.size();
        reverse(&nums[0], &nums[length]);
        reverse(&nums[0], &nums[k]);
        reverse(&nums[k], &nums[length]);
    }
};

class Solution2 {
   public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
```



#### 350 两个数组的交集 II

```cpp
#include <iostream>
#include <vector>
using namespace std;
//16ms
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    for (int elem : nums1)
    {
        for (auto it = nums2.begin(); it != nums2.end(); it++)
            if (elem == *it)
            {
                res.push_back(elem);
                nums2.erase(it);
                break;
            }
    }
    return res;
}
int main() {
    vector<int> nums1{ 1, 2, 2, 1 }, nums2 = { 2, 3 };
    vector<int> res = intersect(nums1, nums2);
    for (auto elem : res) cout << elem << " ";
}

//4-16ms 10.6MB
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i : nums1) {
            map[i]++;
        }
        for (int i : nums2) {
            if (map.find(i) != map.end() && map[i] != 0) //不用vector，索引可能为负
            // or if(map[i]>0)
            {
                res.push_back(i);
                map[i]--;
            }
        }
        return res;
    }
};

//4ms
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s, s1(nums1), s2(nums2);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int len1 = s1.size();
        int len2 = s2.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (s1[i] > s2[j]) {
                j++;
            }
            else if (s1[i] < s2[j]) {
                i++;
            }
            else {
                s.push_back(s1[i]);
                i++;
                j++;
            }
        }
        return s;
    }
};
```



#### 1 两数之和

```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i=0;i!=nums.size();i++)
    {
        for (int j=i+1;j!=nums.size();j++) //j=i+1 reduce repeated times
        {
            if (target == nums[i] + nums[j])
            {
                res.push_back(i);
                res.push_back(j);
                return res;
                // gcc编译: control reaches the end of non-void function
                // 控制到达非void函数的结尾.
                // 就是说你的一些本应带有返回值的函数到达结尾后可能并没有返回任何值。
                // 这时候，最好检查一下是否每个控制流都会有返回值
            }
        }
    }
}

//多个返回语句
//200ms
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i != nums.size(); i++)
    {
        for (int j = i+1; j != nums.size(); j++)
        {
            if (target == nums[i] + nums[j])
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

//goto语句
//340 ms
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i != nums.size(); i++)
    {
        for (int j = i+1; j != nums.size(); j++)
        {
            if (target == nums[i] + nums[j])
            {
                res.push_back(i);
                res.push_back(j);
                goto over;
            }
        }
    }
over:return res;
}

//每层循环都 break
//184 ms
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i != nums.size(); i++)
    {
        for (int j = i+1; j != nums.size(); j++)
        {
            if (target == nums[i] + nums[j])
            {
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        if (!res.empty()) break;
    }
    return res;
}

//do...while
//1116 ms
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int i = 0;
    do {
        int j = i +   1;
        do {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
            }
            j++;
        } while (j!=nums.size()&&res.empty());
        i++;
    } while (res.empty());
    return res;
}

//for进入循环的开关多加一个条件
//1300ms
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for (int i = 0; i != nums.size()&&res.empty(); i++)
    {
        for (int j = i+1; j != nums.size()&&res.empty(); j++)
        {
            if (target == nums[i] + nums[j])
            {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}
int main() {
    vector<int> v{ 2,4,6,2,4,3 };
    int tar = 7;
    auto ts=twoSum(v, tar);
    for (int elem : ts) cout << elem << " ";
}

//0-12ms
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) { //find
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashs;
        for(int i=0;i<nums.size();++i)
        {
            if(hashs.find(target-nums[i])!=hashs.end())
                return vector<int>{hashs[target-nums[i]],i};
            hashs[nums[i]]=i;
        }
        return vector<int>{};    //awesome
    }
};

//return vector
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapIndex;
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = target - nums[i];
            if (mapIndex.count(n) == 1)  //count
            {
                return { mapIndex[n], i }; //awesome
            }
            mapIndex[nums[i]] = i;
        }
        return { -1, -1 };     //return {};
    }
};
```



#### 283 移动零

```cpp
//4ms
class Solution0 {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for (int i = 0; i != nums.size(); i++)
        {
            if (0 == nums[i]) {
                zeros++;
            } else if (zeros) {
                nums[i - zeros] = nums[i];
                nums[i] = 0;
            }
        }
    }
};

//8ms
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        for(int l = 0, r = 0; r < nums.size(); ++r) {
            if (0 == nums[l]) {
                if ( 0!= nums[r]) {
                    nums[l] = nums[r];
                    nums[r] = 0;
                    l++;
                }
            }
            else {
                l++;
            }
        }
    }
};

//4ms
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 不是0的数
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
```



### 字符串



#### 344 反转字符串

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

```cpp
//32-88ms
class Solution0 {
   public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            char ch = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = ch;
        }
    }
};
```



#### 387 字符串中的第一个唯一字符

cpp

```cpp
#include <iostream>
#include <string>
using namespace std;
//wrong solution
int firstUniqChar(string s) {
    for (int i = 0; i != s.size()-1; i++) {
        if (s.find(s[i], i+1) == -1) {
            return i;
        }
    }
    return -1;
}
int main() {
    string s("loveleetcode");
    cout << firstUniqChar(s);
}

//76-124ms
class Solution0 {
public:
    int firstUniqChar(string s) {
        map<char,int> ma;
        int n=s.size();
        for(int i=0;i!=n;i++) {
            ma[s[i]]++;
        }
        for(int i=0;i!=n;i++) {
            if(ma[s[i]]==1)
                return i;
        }
        return -1;
    }
};


//8ms
class Solution1 {
public:
    int firstUniqChar(string s) {
        int ma[26]{0};
        int n=s.size();
        for(int i=0;i!=n;i++) {
            ma[s[i]-'a']++;
        }
        for(int i=0;i!=n;i++) {
            if(ma[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
```





#### 8 字符串转换整数 (atoi)

```cpp
#include <iostream>
using namespace std;
//4ms
int myAtoi(string str) {
    long res=0; //long
    int elem=0;
    bool inStr=false;
    int symbol=1; //存储+-标志位
    for(int i=0;i!=str.size();i++)
    {
        int elem=str[i]-'0';
        if(str[i]==' '&&inStr==false) //using char ''
        {
            continue;
        }
        if(str[i]=='-'&&inStr==false)   //bool==false, not using !bool
        {
            symbol=-1;
            inStr=true;
            continue;
        }
        if(str[i]=='+'&&inStr==false)
        {
            inStr=true;
            continue;
        }
        if(elem>=0&&elem<=9) // or if(str[i]>='0'&&str[i]<='9')
        {
            res=res*10+elem;
            if(symbol*res>INT_MAX) return INT_MAX;
            if(symbol*res<INT_MIN) return INT_MIN;
            inStr=true;
            continue;
        }
        else
        {
            break;
        }
    }
    return symbol*res;
}
int main()
{
    string s=" -324 33";
    cout<<myAtoi(s);
    //cout<<(int)'-';
}
```



#### 28 实现 strStr()

```cpp
#include <iostream>
using namespace std;
//0-4ms
int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    int ptr = 0;
    int start = 0;
    for (int i = 0; i != haystack.size(); i++) {
        if (haystack[i] == needle[ptr]) {
            if (ptr == 0) start = i;
            ptr++;
        } else {
            if (ptr != 0) i = start;
            ptr = 0;
            start = 0;
        }
        if (ptr == needle.size()) return start;
    }
    if (haystack.size() == 0 && needle.size() == 0) return 0;
    return -1;
}
int main() {
    string s1 = "mississippi";
    string s2 = "si"; //issip
    //string s1 = "aabaaabaaac";
    //string s2 = "aabaaac";
    cout << strStr(s1, s2);
}

//0ms
class Solution0 {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int ptr = 0;
        for (int i = 0; i != haystack.size(); i++) {
            if (haystack[i] == needle[ptr]) ptr++;
            else {
                if (ptr != 0) i -= ptr;
                ptr = 0;
            }
            if (ptr == needle.size()) return (i - ptr + 1);
        }
        return -1;
    }
};

//0ms
class Solution1 {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        int i = 0, j= 0;
        while(i < l1 && j < l2){
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        if(j == l2) return (i - j);
        else return -1;
    }
};
```





### 链表



#### 237 删除链表中的节点

请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。



#### 206 反转链表

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//递归
//4ms 9.6MB
class Solution0 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        else { //else can be removed
            ListNode* res = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return res;
        }
    }
};

//双指针
//8ms 9.2MB
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* first = NULL, * second = head;
        while (second) {
            ListNode* tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }
        return first;
    }
};
```



#### 21 合并两个有序链表

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //8 ms 6.5MB
class Solution0 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (nullptr == l1) return l2;
        if (nullptr == l2) return l1;
        ListNode* head = l1->val < l2->val ? l1 : l2;
        ListNode* cur = nullptr;
        ListNode* pre = nullptr;
        while (nullptr != l1 && nullptr != l2) {
            if (l1->val < l2->val) {
                cur = l1;
                l1 = l1->next;
                cur->next = l2;
            }
            else {
                cur = l2;
                l2 = l2->next;
                cur->next = l1;
            }
            if (nullptr == pre) pre = cur;
            if (pre != cur) {
                pre->next = cur;
                pre = cur;
            }
        }
        return head;
    }
};
//递归
//0-4ms
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* pHead;
        if (l1->val > l2->val) {
            pHead = l2;
            pHead->next = mergeTwoLists(l1, l2->next);
        }
        else {
            pHead = l1;
            pHead->next = mergeTwoLists(l1->next, l2);
        }
        return pHead;
    }
};

//dummy[哨兵节点]
//4ms
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(p1 && p2){
            if(p1 -> val < p2 -> val){
                p -> next = p1;
                p1 = p1 -> next;
            }
            else {
                p -> next = p2;
                p2 = p2 -> next;
            }
            p = p -> next;
        }
        if(p1) p -> next = p1;
        if(p2) p -> next = p2;
        return dummy -> next;
    }
};
```



### 树



#### 234 回文链表

```cpp
class Solution0 {
   public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> nums;
        for (; head != nullptr; head = head->next) {
            nums.push_back(head->val);
        }
        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() - 1 - i])
                return false;
        }
        return true;
    }
};

//将所有节点值入栈，然后一一出栈并比较
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *p = head;
        while(p){
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while(p){
            if(p->val != s.top()){
                return 0;
            }
            s.pop();
            p = p->next;
        }
        return 1;
    }
};

//用快慢指针遍历的同时翻转前半部分，然后与后半部分比较
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return 1;
        ListNode *fast = head, *slow = head;
        ListNode *p, *pre = NULL;
        while(fast && fast->next){
            p = slow;
            slow = slow->next;    //快慢遍历
            fast = fast->next->next;

            p->next = pre;  //翻转
            pre = p;
        }
        if(fast)  //奇数个节点时跳过中间节点
            slow = slow->next;

        while(p){       //前半部分和后半部分比较
            if(p->val != slow->val)
                return 0;
            p = p->next;
            slow = slow->next;
        }
        return 1;
    }
};
```



#### 104 二叉树的最大深度

```cpp
//0-4ms
//深度优先 递归
class Solution1 {
   public:
    int maxDepth(TreeNode* root) {
        return (root == nullptr)
                   ? 0
                   : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//广度优先 队列
class Solution2 {
   public:
    int maxDepth(TreeNode* root) {
        if (nullptr == root)
            return 0;
        std::deque<TreeNode*> q;
        q.push_back(root);
        int deep = 0;
        while (!q.empty()) {
            deep++;
            int num = q.size();
            for (int i = 1; i <= num; i++) {
                TreeNode* node = q.front();
                q.pop_front();
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }
        }
        return deep;
    }
};
```



#### 98 验证二叉搜索树

cpp

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 12ms 18.1MB
// @递归
class Solution1 {
   public:
    bool helper(TreeNode *root, long long lower, long long upper) {
        if (root == nullptr)
            return true;
        if (root->val <= lower || root->val >= upper)
            return false;
        return helper(root->left, lower, root->val) &&
               helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root) { return helper(root, LONG_MIN, LONG_MAX); }
};

// 20ms 18.4MB
// @中序遍历
class Solution2 {
   public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        long long inorder = (long long)INT_MIN - 1;
        while (s.empty() == false || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->val <= inorder)
                return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
```

python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 52ms 15.8MB
# @BFS
class Solution:
    def isValidBST(self, root):
        def BFS(root, left, right):
            if root is None:
                return True

            if left < root.val < right:
                return BFS(root.left, left, root.val) and BFS(
                    root.right, root.val, right)
            else:
                return False

        return BFS(root, -float('inf'), float('inf'))
```



#### 102 二叉树的层序遍历

cpp

```cpp
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 4ms 11.7MB
// @BFS
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q{{root}};
        if (nullptr == root)
            return res;
        while (false == q.empty()) {
            vector<int> elem;
            int len = q.size();
            // or: for(int i = q.size(); i>0; i--)
            for (int i = 0; i != len; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left != nullptr)  // 等价于：if(tmp->left)
                    q.push(tmp->left);
                if (tmp->right != nullptr)
                    q.push(tmp->right);
                elem.push_back(tmp->val);
            }
            res.push_back(elem);
        }
        return res;
    }
};
```



#### 108 将有序数组转换为二叉搜索树

```cpp
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 20ms 23MB
// @递归
class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (r < l)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, r);
        return root;
    }
};

// fail
class Solution0 {
   public:
    int dfs_inorder(TreeNode* node, int levels, int k, vector<int>& nums) {
        if (levels == 1) {
            if (k == nums.size())
                return k;
            node->val = nums[k];
            return k + 1;
        }
        if (k < nums.size()) {
            TreeNode* left_tree = new TreeNode(-1);
            node->left = left_tree;
            k = dfs_inorder(node->left, levels - 1, k, nums);
        }
        node->val = nums[k];

        if (k == nums.size()) {
            return k;
        }
        k++;

        if (k < nums.size()) {
            TreeNode* right_tree = new TreeNode(-1);
            node->right = right_tree;
            k = dfs_inorder(node->right, levels - 1, k, nums);
        }

        return k;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int levels = 0;
        int len = nums.size();
        while (len > 0) {
            len >> 1;
            levels++;
        }
        TreeNode* middle = new TreeNode(nums[0]);
        int k = 1;
        for (int i = 1; i != levels + 1; i++) {
            TreeNode* temp = new TreeNode(nums[k]);
            temp->left = middle;
            middle = temp;
            TreeNode* right_tree = new TreeNode(-1);
            middle->right = right_tree;
            k = dfs_inorder(right_tree, i, k + 1, nums);
        }
    }
};
```



### 排序和搜索



#### 88 合并两个有序数组

```cpp
// 0-8ms 9MB
class Solution0 {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m - 1;
        int second = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (first != -1 && second != -1) {
                if (nums1[first] >= nums2[second]) {
                    nums1[i] = nums1[first];
                    first--;
                    continue;
                } else {
                    nums1[i] = nums2[second];
                    second--;
                    continue;
                }
            }
            if (first == -1) {
                if (second >= 0) {
                    nums1[i] = nums2[second];
                    second--;
                    continue;
                }
            }
        }
    }
};
// 0-8ms 9MB
class Solution1 {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] =
                (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};
```






#### 278 第一个错误的版本

```cpp
// The API   isBadVersion is defined for you.
// bool isBadVersion(int version);

// 0 ms 5.9 MB
class Solution0 {
   public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        if (n == 1)
            return 1;
        while (low < high - 1) {
            int middle = low + (high - low) / 2;
            if (isBadVersion(middle)) {
                high = middle;
            } else {
                low = middle;
            }
        }
        return high;
    }
};
```





### 动态规划



#### 爬楼梯



#### 买卖股票最佳时机



#### 最大子序和
