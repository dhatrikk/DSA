# #870 — Advantage Shuffle

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 27 October 2026 at 12:03 am IST |
| **Runtime** | 223 ms *(beats 5.2%)* |
| **Memory** | 93.1 MB *(beats 5.0%)* |
| **Topics** | `Array` `Two Pointers` `Greedy` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/advantage-shuffle/)

---

## 📋 Problem Description

You are given two integer arrays `nums1` and `nums2` both of the same length. The **advantage** of `nums1` with respect to `nums2` is the number of indices `i` for which `nums1[i] > nums2[i]`.

Return *any permutation of *`nums1`* that maximizes its **advantage** with respect to *`nums2`.

 

**Example 1:**

```
**Input:** nums1 = [2,7,11,15], nums2 = [1,10,4,11]
**Output:** [2,11,7,15]
```
**Example 2:**

```
**Input:** nums1 = [12,24,8,32], nums2 = [13,25,32,11]
**Output:** [24,32,8,12]
```

 

**Constraints:**

	- `1 <= nums1.length <= 10^5`

	- `nums2.length == nums1.length`

	- `0 <= nums1[i], nums2[i] <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int, vector<int>> ind;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            ind[nums2[i]].push_back(i);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums1[j] <= nums2[i]) {
                j++;
            }
            if (j<n && nums1[j] > nums2[i]) {
                if (ind[nums2[i]].size()) {
                    int id = ind[nums2[i]][ind[nums2[i]].size()-1];
                    ans[id] = nums1[j];
                    nums1[j]=-1;
                    ind[nums2[i]].pop_back();
                }
                j++;
            }
        }

        j=0;
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                while(j<n && nums1[j]==-1){
                    j++;
                }
                if(j<n && nums1[j]!=-1){
                    ans[i]=nums1[j];
                    nums1[j]=-1;
                    j++;
                }
            }
        }

        return ans;
    }
};
```
