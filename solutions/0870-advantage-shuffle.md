# #870 — Advantage Shuffle

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 26 October 2026 at 11:06 pm IST |
| **Runtime** | 114 ms *(beats 13.8%)* |
| **Memory** | 82.7 MB *(beats 8.9%)* |
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
        map<int, int> mp;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            mp[nums1[i]]++;
        }

        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back({nums2[i], i});
        }

        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++) {
            int node = vec[i].first;
            int ind = vec[i].second;
            int mx = mp.rbegin()->first;

            if (node >= mx) {
                continue;
            }

            auto it=mp.begin();

            while(it != mp.end()){
                if(it->first>node){
                    break;
                }
                it++;
            }

            if (it != mp.end()) {
                ans[ind] = it->first;
                it->second--;
                if (it->second == 0) {
                    mp.erase(it);
                }
            }
        }

        int k = 0;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            while(it->second>0){
                while(k<n && ans[k]!=-1){
                    k++;
                }
                ans[k]=it->first;
                it->second--;
            }
        }

        return ans;
    }
};
```
