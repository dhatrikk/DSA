# #94 — Binary Tree Inorder Traversal

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 11 October 2026 at 09:06 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.8 MB *(beats 67.4%)* |
| **Topics** | `Stack` `Tree` `Depth-First Search` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/binary-tree-inorder-traversal/)

---

## 📋 Problem Description

Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.

 

**Example 1:**

**Input:** root = [1,null,2,3]

**Output:** [1,3,2]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,5,null,8,null,null,6,7,9]

**Output:** [4,2,6,5,7,1,3,9,8]

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Morris 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        TreeNode* node=root, *prev;

        while(node){
            if(node->left){
                prev= node->left;
                while(prev->right && prev->right!=node){
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right=node;
                    node=node->left;
                }else if(prev->right==node){
                    prev->right=nullptr;
                    ans.push_back(node->val);
                    node=node->right;
                }
            }else{
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};




// Using Stack 
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root){
//             return {};
//         }
//         stack<TreeNode*> st;
//         TreeNode* curr=root;
//         vector<int> ans;

//         while(st.size() || curr){
//             while(curr){
//                 st.push(curr);
//                 curr=curr->left;
//             }
//             curr=st.top();
//             st.pop();
//             ans.push_back(curr->val);
//             curr=curr->right;
//         }
//         return ans;
//     }
// };




// Recursion
// class Solution {
//     void f(TreeNode* node, vector<int>& ans){
//         if(!node){
//             return;
//         }
//         f(node->left, ans);
//         ans.push_back(node->val);
//         f(node->right, ans);
//     }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root){
//             return {};
//         }
//         vector<int> ans;
//         f(root, ans);

//         return ans;
//     }
// };
```
