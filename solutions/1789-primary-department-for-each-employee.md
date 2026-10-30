# #1789 — Primary Department for Each Employee

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | postgresql |
| **Submitted** | 31 October 2026 at 03:20 am IST |
| **Runtime** | 220 ms *(beats 76.7%)* |
| **Memory** | 0B *(beats 100.0%)* |
| **Topics** | `Database` |

🔗 [View on LeetCode](https://leetcode.com/problems/primary-department-for-each-employee/)

---

## 📋 Problem Description

Table: `Employee`

```
+---------------+---------+
| Column Name   |  Type   |
+---------------+---------+
| employee_id   | int     |
| department_id | int     |
| primary_flag  | varchar |
+---------------+---------+
(employee_id, department_id) is the primary key (combination of columns with unique values) for this table.
employee_id is the id of the employee.
department_id is the id of the department to which the employee belongs.
primary_flag is an ENUM (category) of type ('Y', 'N'). If the flag is 'Y', the department is the primary department for the employee. If the flag is 'N', the department is not the primary.
```

 

Employees can belong to multiple departments. When the employee joins other departments, they need to decide which department is their primary department. Note that when an employee belongs to only one department, their primary column is `'N'`.

Write a solution to report all the employees with their primary department. For employees who belong to one department, report their only department.

Return the result table in **any order**.

The result format is in the following example.

 

**Example 1:**

```
**Input:** 
Employee table:
+-------------+---------------+--------------+
| employee_id | department_id | primary_flag |
+-------------+---------------+--------------+
| 1           | 1             | N            |
| 2           | 1             | Y            |
| 2           | 2             | N            |
| 3           | 3             | N            |
| 4           | 2             | N            |
| 4           | 3             | Y            |
| 4           | 4             | N            |
+-------------+---------------+--------------+
**Output:** 
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 1             |
| 3           | 3             |
| 4           | 3             |
+-------------+---------------+
**Explanation:** 
- The Primary department for employee 1 is 1.
- The Primary department for employee 2 is 1.
- The Primary department for employee 3 is 3.
- The Primary department for employee 4 is 3.
```

---

## ✅ Accepted Solution

```postgresql
-- Write your PostgreSQL query statement below

SELECT e.employee_id, e.department_id FROM(
    SELECT *, COUNT(department_id) OVER(PARTITION BY employee_id) as tot 
    FROM Employee 
) as e
WHERE (e.primary_flag = 'Y') OR (e.tot = 1);
```
