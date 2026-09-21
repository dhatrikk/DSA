# #17 — Letter Combinations of a Phone Number

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 02:06 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 9 MB *(beats 89.5%)* |
| **Topics** | `Hash Table` `String` `Backtracking` |

🔗 [View on LeetCode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

---

## 📋 Problem Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

**Example 1:**

```
**Input:** digits = "23"
**Output:** ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```
**Input:** digits = "2"
**Output:** ["a","b","c"]
```

 

**Constraints:**

	- `1 <= digits.length <= 4`

	- `digits[i]` is a digit in the range `['2', '9']`.

---

## ✅ Accepted Solution

```cpp
class Solution {
    string ss(char n){
        if(n=='2'){
            return "abc";
        }else if(n=='3'){
            return "def";
        }else if(n=='4'){
            return "ghi";
        }else if(n=='5'){
            return "jkl";
        }else if(n=='6'){
            return "mno";
        }else if(n=='7'){
            return "pqrs";
        }else if(n=='8'){
            return "tuv";
        }

        return "wxyz";
    }

    void f(vector<string>& ans, string& s, int i, string& digit){
        if(i==digit.size()){
            ans.push_back(s);
            return;
        }
        for(char c:ss(digit[i])){
            s+=c;
            f(ans, s, i+1, digit);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digit) {
        vector<string> ans;
        string s="";
        f(ans, s, 0, digit);
        return ans;
    }
};
```
