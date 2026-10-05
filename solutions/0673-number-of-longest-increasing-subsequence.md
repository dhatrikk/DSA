# #673 — Number of Longest Increasing Subsequence

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 5 October 2026 at 09:04 pm IST |
| **Runtime** | 32 ms *(beats 43.7%)* |
| **Memory** | 17.5 MB *(beats 66.5%)* |
| **Topics** | `Array` `Dynamic Programming` `Binary Indexed Tree` `Segment Tree` `Longest Increasing Subsequence` |

🔗 [View on LeetCode](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

---

## 📋 Problem Description

Given an integer array `nums`, return *the number of longest increasing subsequences.*

**Notice** that the sequence has to be **strictly** increasing.

 

**Example 1:**

```
**Input:** nums = [1,3,5,4,7]
**Output:** 2
**Explanation:** The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
```

**Example 2:**

```
**Input:** nums = [2,2,2,2,2]
**Output:** 5
**Explanation:** The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
```

 

**Constraints:**

	- `1 <= nums.length <= 2000`

	- `-10^6 <= nums[i] <= 10^6`

	- The answer is guaranteed to fit inside a 32-bit integer.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> cnt(n, 1);
        vector<int> len(n, 1);

        int mx=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(len[i]<len[j]+1){
                        len[i]=len[j]+1;
                        cnt[i]=cnt[j];
                    }else if(len[i]==len[j]+1){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            mx=max(mx, len[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mx==len[i]){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};
```
