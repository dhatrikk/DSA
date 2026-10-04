# #863 — All Nodes Distance K in Binary Tree

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 4 October 2026 at 04:46 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 14.7 MB *(beats 97.2%)* |
| **Topics** | `Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

---

## 📋 Problem Description

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return *an array of the values of all nodes that have a distance *`k`* from the target node.*

You can return the answer in **any order**.

 

**Example 1:**

```
**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
**Output:** [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

**Example 2:**

```
**Input:** root = [1], target = 1, k = 3
**Output:** []
```

 

**Constraints:**

	- The number of nodes in the tree is in the range `[1, 500]`.

	- `0 <= Node.val <= 500`

	- All the values `Node.val` are **unique**.

	- `target` is the value of one of the nodes in the tree.

	- `0 <= k <= 1000`

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
    bool p(TreeNode* node, TreeNode* target, vector<TreeNode*>& path){
        if(!node){
            return false;
        }
        path.push_back(node);
        if(node==target){
            return true;
        }
        if(p(node->left, target, path)) return true;
        if(p(node->right, target, path)) return true;
        path.pop_back();
        return false;
    }

    void f(TreeNode* node, TreeNode* nn, int k, vector<int>& ans){
        if(!node || node==nn){
            return;
        }
        if(k==0){
            ans.push_back(node->val);
            return;
        }
        f(node->left, nn, k-1, ans);
        f(node->right, nn, k-1, ans);
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        p(root, target, path);

        vector<int> ans;
        int n=path.size();
        f(target, NULL, k, ans);

        for(int i=n-2;i>=0;i--){
            k--;
            if(k<0){
                break;
            }
            f(path[i], path[i+1], k, ans);
        }
        return ans;
    }
};
```
