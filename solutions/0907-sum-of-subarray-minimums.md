# #907 — Sum of Subarray Minimums

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 17 October 2026 at 02:14 am IST |
| **Runtime** | 135 ms *(beats 5.2%)* |
| **Memory** | 202 MB *(beats 13.4%)* |
| **Topics** | `Array` `Dynamic Programming` `Stack` `Monotonic Stack` |

🔗 [View on LeetCode](https://leetcode.com/problems/sum-of-subarray-minimums/)

---

## 📋 Problem Description

Given an array of integers arr, find the sum of `min(b)`, where `b` ranges over every (contiguous) subarray of `arr`. Since the answer may be large, return the answer **modulo** `10^9 + 7`.

 

**Example 1:**

```
**Input:** arr = [3,1,2,4]
**Output:** 17
**Explanation:** 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

**Example 2:**

```
**Input:** arr = [11,81,94,43,3]
**Output:** 444
```

 

**Constraints:**

	- `1 <= arr.length <= 3 * 10^4`

	- `1 <= arr[i] <= 3 * 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> pre(n);
        vector<int> nxt(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (st.size() && st.top().first >= arr[i]) {
                st.pop();
            }
            if (st.size()) {
                pre[i] = st.top().second;
            } else {
                pre[i] = -1;
            }
            st.push({arr[i], i});
        }

        while (st.size()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && st.top().first > arr[i]) {
                st.pop();
            }
            if (st.size()) {
                nxt[i] = st.top().second;
            } else {
                nxt[i] = n;
            }
            st.push({arr[i], i});
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long m = 1;
            m *= i - pre[i];
            m *= nxt[i] - i;
            m *= arr[i];
            ans += m;
            ans = ans% mod;;
        }

        return ans;
    }
};

// class Solution {
//     int mod=1e9+7;
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int ans=0;
//         int n=arr.size();

//         for(int i=0;i<n;i++){
//             int m=arr[i];
//             for(int j=i;j<n;j++){
//                 m=min(arr[j],m);
//                 ans+=m;
//                 ans%=mod;
//             }
//         }
//         return ans;
//     }
// };
```
