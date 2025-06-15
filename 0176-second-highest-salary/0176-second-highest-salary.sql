# Write your MySQL query statement below
-- select max(salary) AS SecondHighestSalary from employee where
-- salary not in (select max(salary) from employee);

SELECT 
    (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET 1
    ) AS SecondHighestSalary;
