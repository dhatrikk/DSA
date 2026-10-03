# #236 — Lowest Common Ancestor of a Binary Tree

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 3 October 2026 at 10:02 pm IST |
| **Runtime** | 66 ms *(beats 42.0%)* |
| **Memory** | 43.9 MB *(beats 78.1%)* |
| **Topics** | `Tree` `Depth-First Search` `Binary Tree` `Binary Lifting` `Lowest Common Ancestor` |

🔗 [View on LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

---

## 📋 Problem Description

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: &ldquo;The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).&rdquo;

 

**Example 1:**

```
**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
**Output:** 3
**Explanation:** The LCA of nodes 5 and 1 is 3.
```

**Example 2:**

```
**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
**Output:** 5
**Explanation:** The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
**Input:** root = [1,2], p = 1, q = 2
**Output:** 1
```

 

**Constraints:**

	- The number of nodes in the tree is in the range `[2, 10^5]`.

	- `-10^9 <= Node.val <= 10^9`

	- All `Node.val` are **unique**.

	- `p != q`

	- `p` and `q` will exist in the tree.

---

## ✅ Accepted Solution

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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }

        TreeNode* l= lowestCommonAncestor(root->left, p, q);
        TreeNode* r= lowestCommonAncestor(root->right, p, q);

        if(l && r){
            return root;
        }else if(l){
            return l;
        }else if(r){
            return r;
        }else{
            return NULL;
        }
    }
};




// class Solution {
//     bool f(TreeNode* node, TreeNode* target, vector<TreeNode*>& vec){
//         if(!node){
//             return false;
//         }
//         vec.push_back(node);
//         if(node==target){
//             return true;
//         }
//         if(f(node->left, target, vec)){
//             return true;
//         }
//         if(f(node->right, target, vec)){
//             return true;
//         }
//         vec.pop_back();
//         return false;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> pp, qq;
//         TreeNode* node=root;
//         f(node, p, pp);
//         f(node, q, qq);

//         int n=min(pp.size(), qq.size());
//         int i=0;

//         while(i<n && pp[i]==qq[i]){
//             i++;
//         }

//         return pp[i-1];

//     }
// };
```
