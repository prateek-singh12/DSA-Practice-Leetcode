# Write your MySQL query statement below
-- LEAD() and LAG() are window functions in SQL that allow you to access data from previous or next rows without using joins.   
SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num, 
           LAG(num) OVER (ORDER BY id) AS prev_num, 
           LEAD(num) OVER (ORDER BY id) AS next_num
    FROM Logs
) temp
WHERE num = prev_num AND num = next_num;
