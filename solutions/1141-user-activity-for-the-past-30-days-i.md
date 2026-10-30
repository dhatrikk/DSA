# #1141 — User Activity for the Past 30 Days I

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | postgresql |
| **Submitted** | 31 October 2026 at 01:18 am IST |
| **Runtime** | 327 ms *(beats 81.4%)* |
| **Memory** | 0B *(beats 100.0%)* |
| **Topics** | `Database` |

🔗 [View on LeetCode](https://leetcode.com/problems/user-activity-for-the-past-30-days-i/)

---

## 📋 Problem Description

Table: `Activity`

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
This table may have duplicate rows.
The activity_type column is an ENUM (category) of type ('open_session', 'end_session', 'scroll_down', 'send_message').
The table shows the user activities for a social media website. 
Note that each session belongs to exactly one user.
```

 

Write a solution to find the daily active user count for a period of `30` days ending `2019-07-27` inclusively. A user was active on someday if they made at least one activity on that day.

Return the result table in **any order**.

The result format is in the following example.

Note: **Any** activity from (`'open_session'`, `'end_session'`, `'scroll_down'`, `'send_message'`) will be considered valid activity for a user to be considered active on a day.

 

**Example 1:**

```
**Input:** 
Activity table:
+---------+------------+---------------+---------------+
| user_id | session_id | activity_date | activity_type |
+---------+------------+---------------+---------------+
| 1       | 1          | 2019-07-20    | open_session  |
| 1       | 1          | 2019-07-20    | scroll_down   |
| 1       | 1          | 2019-07-20    | end_session   |
| 2       | 4          | 2019-07-20    | open_session  |
| 2       | 4          | 2019-07-21    | send_message  |
| 2       | 4          | 2019-07-21    | end_session   |
| 3       | 2          | 2019-07-21    | open_session  |
| 3       | 2          | 2019-07-21    | send_message  |
| 3       | 2          | 2019-07-21    | end_session   |
| 4       | 3          | 2019-06-25    | open_session  |
| 4       | 3          | 2019-06-25    | end_session   |
+---------+------------+---------------+---------------+
**Output:** 
+------------+--------------+ 
| day        | active_users |
+------------+--------------+ 
| 2019-07-20 | 2            |
| 2019-07-21 | 2            |
+------------+--------------+ 
**Explanation:** Note that we do not care about days with zero active users.
```

---

## ✅ Accepted Solution

```postgresql
-- Write your PostgreSQL query statement below

SELECT e.activity_date as day, COUNT(*) as active_users FROM (
    SELECT user_id, activity_date, COUNT(*) as cnt
    FROM Activity 
    GROUP BY user_id, activity_date
) as e 
GROUP BY day
HAVING  e.activity_date::DATE <= '2019-07-27'::DATE AND
e.activity_date::DATE > '2019-07-27'::DATE - 30;
```
