# #56 — Merge Intervals

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 31 July 2026 at 05:47 am IST |
| **Runtime** | 3 ms *(beats 88.9%)* |
| **Memory** | 23.7 MB *(beats 95.6%)* |
| **Topics** | `Array` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/merge-intervals/)

---

## 📋 Problem Description

Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.

 

**Example 1:**

```
**Input:** intervals = [[1,3],[2,6],[8,10],[15,18]]
**Output:** [[1,6],[8,10],[15,18]]
**Explanation:** Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

**Example 2:**

```
**Input:** intervals = [[1,4],[4,5]]
**Output:** [[1,5]]
**Explanation:** Intervals [1,4] and [4,5] are considered overlapping.
```

**Example 3:**

```
**Input:** intervals = [[4,7],[1,4]]
**Output:** [[1,7]]
**Explanation:** Intervals [1,4] and [4,7] are considered overlapping.
```

 

**Constraints:**

	- `1 <= intervals.length <= 10^4`

	- `intervals[i].length == 2`

	- `0 <= start_i <= end_i <= 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        int n=in.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(ans.size() && ans.back()[1]>=in[i][0]){
                ans.back()[1]=max(ans.back()[1], in[i][1]);
            }else{
                ans.push_back(in[i]);
            }
        }

        return ans;
    }
};




// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& in) {
//         sort(in.begin(), in.end(), [](vector<int> a, vector<int> b){
//             return a[0] < b[0];
//         });

//         for(int i=1;i<in.size();i++){
//             if(in[i-1][1]>=in[i][0]){
//                 in[i-1][1]=max(in[i][1],in[i-1][1]);
//                 in.erase(in.begin()+i);
//                 i--;
//             }
//         }

//         return in;
//     }
// };
```
