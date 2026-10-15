# #804 — Unique Morse Code Words

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 15 October 2026 at 05:53 pm IST |
| **Runtime** | 3 ms *(beats 15.9%)* |
| **Memory** | 11.4 MB *(beats 77.1%)* |
| **Topics** | `Array` `Hash Table` `String` |

🔗 [View on LeetCode](https://leetcode.com/problems/unique-morse-code-words/)

---

## 📋 Problem Description

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

	- `'a'` maps to `".-"`,

	- `'b'` maps to `"-..."`,

	- `'c'` maps to `"-.-."`, and so on.

For convenience, the full table for the `26` letters of the English alphabet is given below:

```
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
```

Given an array of strings `words` where each word can be written as a concatenation of the Morse code of each letter.

	- For example, `"cab"` can be written as `"-.-..--..."`, which is the concatenation of `"-.-."`, `".-"`, and `"-..."`. We will call such a concatenation the **transformation** of a word.

Return *the number of different **transformations** among all words we have*.

 

**Example 1:**

```
**Input:** words = ["gin","zen","gig","msg"]
**Output:** 2
**Explanation:** The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".
```

**Example 2:**

```
**Input:** words = ["a"]
**Output:** 1
```

 

**Constraints:**

	- `1 <= words.length <= 100`

	- `1 <= words[i].length <= 12`

	- `words[i]` consists of lowercase English letters.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> s;

        vector<string> v = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                            "--.",  "....", "..",   ".---", "-.-",  ".-..",
                            "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--",  "-..-",
                            "-.--", "--.."};


        for(auto word:words){
            string ss="";
            for(char c:word){
                ss+=v[c-'a'];
            }
            s.insert(ss);
        }                

        return s.size();    
    }
};
```
