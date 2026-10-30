# #197 — Rising Temperature

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | postgresql |
| **Submitted** | 30 October 2026 at 07:44 am IST |
| **Runtime** | 211 ms *(beats 79.2%)* |
| **Memory** | 0B *(beats 100.0%)* |
| **Topics** | `Database` |

🔗 [View on LeetCode](https://leetcode.com/problems/rising-temperature/)

---

## 📋 Problem Description

Table: `Weather`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the column with unique values for this table.
There are no different rows with the same recordDate.
This table contains information about the temperature on a certain day.
```

 

Write a solution to find all dates' `id` with higher temperatures compared to its previous calendar dates (yesterday).

Return the result table in **any order**.

The result format is in the following example.

 

**Example 1:**

```
**Input:** 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
**Output:** 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
**Explanation:** 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
```

---

## ✅ Accepted Solution

```postgresql
-- Write your PostgreSQL query statement below
SELECT id FROM (
    SELECT *, 
    LAG(temperature) OVER(ORDER BY recordDate) as prev,
    LAG(recordDate) OVER(ORDER BY recordDate) as prevdate
    FROM Weather
) AS w WHERE temperature > prev AND recordDate = prevdate + INTERVAL '1 day';
```
