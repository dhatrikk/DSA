# #1331 — Rank Transform of an Array

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 12 July 2026 at 11:08 am IST |
| **Runtime** | 37 ms *(beats 65.7%)* |
| **Memory** | 43.1 MB *(beats 77.4%)* |
| **Topics** | `Array` `Hash Table` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/rank-transform-of-an-array/)

---

## 📋 Problem Description

Given an array of integers `arr`, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

	- Rank is an integer starting from 1.

	- The larger the element, the larger the rank. If two elements are equal, their rank must be the same.

	- Rank should be as small as possible.

 

**Example 1:**

```
**Input:** arr = [40,10,20,30]
**Output:** [4,1,2,3]
**Explanation**: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
```

**Example 2:**

```
**Input:** arr = [100,100,100]
**Output:** [1,1,1]
**Explanation**: Same elements share the same rank.
```

**Example 3:**

```
**Input:** arr = [37,12,28,9,100,56,80,5,12]
**Output:** [5,3,4,2,8,6,7,1,3]
```

 

**Constraints:**

	- `0 <= arr.length <= 10^5`

	- `-10^9 <= arr[i] <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> an = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int n = 1;
        for (int i : arr) {
            if (mp[i] == 0) {
                mp[i] = n;
                n++;
            }
        }
        n=an.size();
        for (int i = 0; i < n; i++) {
            an[i] = mp[an[i]];
        }
        return an;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use a temporary array to copy the array and sort it.

**Hint 2:** The rank of each element is the number of unique elements smaller than it in the sorted array plus one.

</details>
