# #678 — Valid Parenthesis String

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 7 August 2026 at 03:08 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8 MB *(beats 93.9%)* |
| **Topics** | `String` `Dynamic Programming` `Stack` `Greedy` `Bracket Sequences` |

🔗 [View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)

---

## 📋 Problem Description

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` *if* `s` *is **valid***.

The following rules define a **valid** string:

	- Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.

	- Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.

	- Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.

	- `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

 

**Example 1:**

```
**Input:** s = "()"
**Output:** true
```
**Example 2:**

```
**Input:** s = "(*)"
**Output:** true
```
**Example 3:**

```
**Input:** s = "(*))"
**Output:** true
```

 

**Constraints:**

	- `1 <= s.length <= 100`

	- `s[i]` is `'('`, `')'` or `'*'`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int o=0, c=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]==')'){
                o--;
            }else{
                o++;
            }
            if(o<0){
                return false;
            }
        }

        for(int i=0;i<n;i++){
            if(s[n-1-i]=='('){
                c--;
            }else{
                c++;
            }
            if(c<0){
                return false;
            }
        }

        return true;
    }
};








// Recursion
// class Solution {
//     bool f(string& s, int cnt, int i, int n, vector<vector<int>>& dp){

//         if(i==n){
//             return cnt==0;
//         }

//         if(cnt<0){
//             return false;
//         }

//         if(dp[i][cnt]!=-1){
//             return dp[i][cnt]; 
//         }


//         if(s[i]=='('){
//             return dp[i][cnt] = f(s, cnt+1, i+1, n, dp);
//         }else if(s[i]==')'){
//             return dp[i][cnt] = f(s, cnt-1, i+1, n, dp);
//         }
        
//         return dp[i][cnt] = f(s, cnt+1, i+1, n, dp) || f(s, cnt-1, i+1, n, dp) || f(s, cnt, i+1, n, dp);
//     }
// public:
//     bool checkValidString(string s) {
//         int n=s.size();
//         vector<vector<int>> dp(n, vector<int> (n,-1));
//         return f(s, 0, 0, n, dp);
//     }
// };








// My Method
// class Solution {
// public:
//     bool checkValidString(string s) {

//         int n=s.size();
//         int st=0;
//         int cnt=0;

//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 cnt++;
//             }else if(s[i]==')'){
//                 cnt--;
//             }else{
//                 st++;
//             }
//             if(cnt<0){
//                 if(st){
//                     st--;
//                     cnt++;
//                 }else{
//                     return false;
//                 }
//             }
//         }

//         cnt=0, st=0;
//         for(int i=n-1;i>=0;i--){
//             if(s[i]==')'){
//                 cnt++;
//             }else if(s[i]=='('){
//                 cnt--;
//             }else{
//                 st++;
//             }
//             if(cnt<0){
//                 if(st){
//                     st--;
//                     cnt++;
//                 }else{
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use backtracking to explore all possible combinations of treating '*' as either '(', ')', or an empty string. If any combination leads to a valid string, return true.

**Hint 2:** DP[i][j] represents whether the substring s[i:j] is valid.

**Hint 3:** Keep track of the count of open parentheses encountered so far. If you encounter a close parenthesis, it should balance with an open parenthesis. Utilize a stack to handle this effectively.

**Hint 4:** How about using 2 stacks instead of 1? Think about it.

</details>
