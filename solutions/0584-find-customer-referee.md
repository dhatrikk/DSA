# #584 — Find Customer Referee

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | postgresql |
| **Submitted** | 22 August 2026 at 11:00 pm IST |
| **Runtime** | 262 ms *(beats 52.0%)* |
| **Memory** | 0B *(beats 100.0%)* |
| **Topics** | `Database` |

🔗 [View on LeetCode](https://leetcode.com/problems/find-customer-referee/)

---

## 📋 Problem Description

Table: `Customer`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
In SQL, id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
```

 

Find the names of the customer that are either:

	1. **referred by** any customer with `id != 2`.

	2. **not referred by** any customer.

Return the result table in **any order**.

The result format is in the following example.

 

**Example 1:**

```
**Input:** 
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
**Output:** 
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
```

---

## ✅ Accepted Solution

```postgresql
-- Write your PostgreSQL query statement below

SELECT name FROM Customer
WHERE referee_id!=2 OR referee_id IS NULL;
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Be careful of the NULL value

</details>
