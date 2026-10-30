# #619 — Biggest Single Number

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | postgresql |
| **Submitted** | 31 October 2026 at 12:45 am IST |
| **Runtime** | 207 ms *(beats 36.6%)* |
| **Memory** | 0B *(beats 100.0%)* |
| **Topics** | `Database` |

🔗 [View on LeetCode](https://leetcode.com/problems/biggest-single-number/)

---

## 📋 Problem Description

Table: `MyNumbers`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
This table may contain duplicates (In other words, there is no primary key for this table in SQL).
Each row of this table contains an integer.
```

 

A **single number** is a number that appeared only once in the `MyNumbers` table.

Find the largest **single number**. If there is no **single number**, report `null`.

The result format is in the following example.

 
 

**Example 1:**

```
**Input:** 
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 3   |
| 3   |
| 1   |
| 4   |
| 5   |
| 6   |
+-----+
**Output:** 
+-----+
| num |
+-----+
| 6   |
+-----+
**Explanation:** The single numbers are 1, 4, 5, and 6.
Since 6 is the largest single number, we return it.
```

**Example 2:**

```
**Input:** 
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 7   |
| 7   |
| 3   |
| 3   |
| 3   |
+-----+
**Output:** 
+------+
| num  |
+------+
| null |
+------+
**Explanation:** There are no single numbers in the input table so we return null.
```

---

## ✅ Accepted Solution

```postgresql
-- Write your PostgreSQL query statement below

SELECT MAX(num) as num FROM (
    SELECT num, COUNT(*) as count
    FROM MyNumbers
    GROUP BY num) as e
WHERE e.count=1;
```
