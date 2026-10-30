# #610 — Triangle Judgement

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | postgresql |
| **Submitted** | 31 October 2026 at 01:38 am IST |
| **Runtime** | 223 ms *(beats 15.6%)* |
| **Memory** | 0B *(beats 100.0%)* |
| **Topics** | `Database` |

🔗 [View on LeetCode](https://leetcode.com/problems/triangle-judgement/)

---

## 📋 Problem Description

Table: `Triangle`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
In SQL, (x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.
```

 

Report for every three line segments whether they can form a triangle.

Return the result table in **any order**.

The result format is in the following example.

 

**Example 1:**

```
**Input:** 
Triangle table:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
**Output:** 
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+
```

---

## ✅ Accepted Solution

```postgresql
-- Write your PostgreSQL query statement below

SELECT * , 
CASE
 WHEN x < 0 OR y < 0 OR z < 0 THEN 'No'
 WHEN x + y <= z THEN 'No'
 WHEN x + z <= y THEN 'No'
 WHEN z + y <= x THEN 'No'
 ELSE 'Yes'
END as triangle
FROM Triangle;
```
