# #144 — Binary Tree Preorder Traversal

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 11 October 2026 at 09:52 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.8 MB *(beats 74.5%)* |
| **Topics** | `Stack` `Tree` `Depth-First Search` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/binary-tree-preorder-traversal/)

---

## 📋 Problem Description

Given the `root` of a binary tree, return *the preorder traversal of its nodes' values*.

 

**Example 1:**

**Input:** root = [1,null,2,3]

**Output:** [1,2,3]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,5,null,8,null,null,6,7,9]

**Output:** [1,2,4,5,6,7,3,8,9]

**Explanation:**

**Example 3:**

**Input:** root = []

**Output:** []

**Example 4:**

**Input:** root = [1]

**Output:** [1]

 

**Constraints:**

	- The number of nodes in the tree is in the range `[0, 100]`.

	- `-100 <= Node.val <= 100`

 

**Follow up:** Recursive solution is trivial, could you do it iteratively?

---

## ✅ Accepted Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Morris 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        TreeNode *node = root, *prev;
        vector<int> ans;

        while (node) {
            if (node->left) {
                prev = node->left;
                while (prev->right && prev->right != node) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = node;
                    ans.push_back(node->val);
                    node = node->left;
                } else {
                    prev->right = nullptr;
                    node = node->right;
                }
            } else {
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};

// Stack
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         if(!root){
//             return {};
//         }
//         stack<TreeNode*> st;
//         st.push(root);
//         vector<int> ans;

//         while(st.size()){
//             TreeNode* node=st.top();
//             st.pop();
//             ans.push_back(node->val);
//             if(node->right){
//                 st.push(node->right);
//             }
//             if(node->left){
//                 st.push(node->left);
//             }
//         }

//         return ans;
//     }
// };

// Recursion
// class Solution {
//     void f(vector<int>& ans, TreeNode* node){
//         if(!node){
//             return;
//         }
//         ans.push_back(node->val);
//         f(ans, node->left);
//         f(ans, node->right);
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         if(!root){
//             return {};
//         }
//         vector<int> ans;
//         f(ans, root);
//         return ans;
//     }
// };
```
