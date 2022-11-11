/*
Link: https://leetcode.com/problems/second-highest-salary/
Author: Kyle Hurd

Description:

Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

For example, given the above Employee table, the query should return 200 as
the second highest salary. If there is no second highest salary, then
the query should return null.
*/

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary NOT IN (
    SELECT MAX(salary)
    FROM Employee
);


-- Option 2. Where `1` is the N-1, 2nd highest salary - 1 = 1
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee e1
WHERE 1 = (
    SELECT COUNT(DISTINCT salary)
    FROM Employee e2
    WHERE e2.salary > e1.salary
    )