# #450 — Delete Node in a BST

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 27 September 2026 at 08:02 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 34.3 MB *(beats 50.5%)* |
| **Topics** | `Tree` `Binary Search Tree` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/delete-node-in-a-bst/)

---

## 📋 Problem Description

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return *the **root node reference** (possibly updated) of the BST*.

Basically, the deletion can be divided into two stages:

	1. Search for a node to remove.

	2. If the node is found, delete the node.

 

**Example 1:**

```
**Input:** root = [5,3,6,2,4,null,7], key = 3
**Output:** [5,4,6,2,null,null,7]
**Explanation:** Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
```

**Example 2:**

```
**Input:** root = [5,3,6,2,4,null,7], key = 0
**Output:** [5,3,6,2,4,null,7]
**Explanation:** The tree does not contain a node with value = 0.
```

**Example 3:**

```
**Input:** root = [], key = 0
**Output:** []
```

 

**Constraints:**

	- The number of nodes in the tree is in the range `[0, 10^4]`.

	- `-10^5 <= Node.val <= 10^5`

	- Each node has a **unique** value.

	- `root` is a valid binary search tree.

	- `-10^5 <= key <= 10^5`

 

**Follow up:** Could you solve it with time complexity `O(height of tree)`?

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
class Solution {
    TreeNode* f(TreeNode* par, TreeNode* node, int k) {
        if(!node){
            return NULL;
        }
        if(node->val==k){
            return par;
        }else if(node->val > k){
            return f(node, node->left, k);
        }
        return f(node, node->right, k);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(!root){
            return NULL;
        }
        TreeNode* par, *l=NULL, *r=NULL, *node;
        bool lft=false;
        if(root->val==k){
            node=root;
            par=NULL;
            if(node->left){
                l=node->left;
            }
            if(node->right){
                r=node->right;
            }
        }else{
            par = f(NULL, root, k);
            if(!par){
                return root;
            }
            if(par->left && par->left->val==k){
                node=par->left;
                lft=true;
            }else{
                node=par->right;
            }
            if(node->left){
                l=node->left;
            }
            if(node->right){
                r=node->right;
            }
        }
        if(l && r){
            TreeNode* tmp=l;
            while(tmp->right){
                tmp=tmp->right;
            }
            tmp->right=r;
        }else if(r){
            l=r;
        }else{

        }
        delete(node);
        if(par){
            if(lft){
                par->left=l;
            }else{
                par->right=l;
            }
        }else{
            return l;
        }
        
        return root;
    }
};
```
