# Write your MySQL query statement below
SELECT name,bonus 
FROM Employee 
LEFT JOIN Bonus ON Employee.empId = Bonus.empId 
-- > LEFT JOIN Bonus USING (empId)   --or use this
WHERE bonus < 1000 OR bonus IS NULL;
