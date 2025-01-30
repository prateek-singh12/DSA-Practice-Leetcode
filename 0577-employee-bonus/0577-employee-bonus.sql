# Write your MySQL query statement below
-- bonus amount of each employee --> left join
select Employee.name, Bonus.bonus from Employee, Bonus 
where Bonus.bonus<1000 OR Bonus.bonus IS NULL
AND Employee.empID=Bonus.empID
GROUP BY Employee.empID;

-- bonus is NULL (i.e., they don’t have an entry in the Bonus table)