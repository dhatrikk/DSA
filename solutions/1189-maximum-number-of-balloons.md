# #1189 — Maximum Number of Balloons

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 6 July 2026 at 05:19 pm IST |
| **Runtime** | 3 ms *(beats 11.8%)* |
| **Memory** | 9.1 MB *(beats 6.7%)* |
| **Topics** | `Hash Table` `String` `Counting` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-number-of-balloons/)

---

## 📋 Problem Description

Given a string `text`, you want to use the characters of `text` to form as many instances of the word **"balloon"** as possible.

You can use each character in `text` **at most once**. Return the maximum number of instances that can be formed.

 

**Example 1:**

****

```
**Input:** text = "nlaebolko"
**Output:** 1
```

**Example 2:**

****

```
**Input:** text = "loonbalxballpoon"
**Output:** 2
```

**Example 3:**

```
**Input:** text = "leetcode"
**Output:** 0
```

 

**Constraints:**

	- `1  2287: Rearrange Characters to Make Target String.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;

        for(char c:text){
            if(c=='b'){
                mp[c]++;
            }else if(c=='a'){
                mp[c]++;
            }else if(c=='l'){
                mp[c]++;
            }else if(c=='o'){
                mp[c]++;
            }else if(c=='n'){
                mp[c]++;
            }
        }
        mp['o']/=2;
        mp['l']/=2;
        
        return min({mp['b'],mp['a'],mp['l'],mp['o'],mp['n']});
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Count the frequency of letters in the given string.

**Hint 2:** Find the letter than can make the minimum number of instances of the word "balloon".

</details>
