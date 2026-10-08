# #1423 — Maximum Points You Can Obtain from Cards

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 9 October 2026 at 02:06 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 46.4 MB *(beats 32.4%)* |
| **Topics** | `Array` `Sliding Window` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)

---

## 📋 Problem Description

There are several cards **arranged in a row**, and each card has an associated number of points. The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array `cardPoints` and the integer `k`, return the *maximum score* you can obtain.

 

**Example 1:**

```
**Input:** cardPoints = [1,2,3,4,5,6,1], k = 3
**Output:** 12
**Explanation:** After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```

**Example 2:**

```
**Input:** cardPoints = [2,2,2], k = 2
**Output:** 4
**Explanation:** Regardless of which two cards you take, your score will always be 4.
```

**Example 3:**

```
**Input:** cardPoints = [9,7,7,9,7,7,9], k = 7
**Output:** 55
**Explanation:** You have to take all the cards. Your score is the sum of points of all cards.
```

 

**Constraints:**

	- `1 <= cardPoints.length <= 10^5`

	- `1 <= cardPoints[i] <= 10^4`

	- `1 <= k <= cardPoints.length`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int window=cardPoints.size()-k;
        int score=0, curr=0, total=0;
        for(int i:cardPoints){
            total+=i;
        }

        for(int i=0;i<window;i++){
            curr+=cardPoints[i];
        }
        score=curr;

        int l=0, r=window-1;
        while(r<cardPoints.size()-1){
            curr-=cardPoints[l];
            l++;
            r++;
            curr+=cardPoints[r];
            score=min(score, curr);
        }
        return total-score;
    }
};



// class Solution {
// public:
//     int maxScore(vector<int>& points, int k) {
//         int sum = 0;
//         int n = points.size();
//         k=n-k;

//         for(int i=0;i<k;i++){
//             sum+=points[i];
//         }

//         int l=0, r=k-1;
//         int maxi=sum;

//         while(r<n-1){
//             r++;
//             sum+=points[r];
//             sum-=points[l];
//             l++;
//             maxi=min(sum,maxi);
//         }

//         sum=0;
//         for(int i=0;i<n;i++){
//             sum+=points[i];
//         }

//         return sum-maxi;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Let the sum of all points be total_pts. You need to remove a sub-array from cardPoints with length n - k.

**Hint 2:** Keep a window of size n - k over the array. The answer is max(answer, total_pts - sumOfCurrentWindow)

</details>
