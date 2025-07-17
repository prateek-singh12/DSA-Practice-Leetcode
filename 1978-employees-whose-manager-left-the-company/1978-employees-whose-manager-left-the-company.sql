select e1.employee_id 
from Employees e1 join Employees e2
on e1.employee_id=e2.employee_id
where e1.salary<30000 and
e1.manager_id is NOT NULL 
and e1.manager_id NOT in (select employee_id from Employees)
ORDER BY e1.employee_id;

-- # Write your MySQL query statement below
-- SELECT employee_id
-- FROM Employees e
-- WHERE salary < 30000 
-- AND manager_id IS NOT NULL  
-- AND manager_id NOT IN (SELECT employee_id FROM Employees) 
-- ORDER BY employee_id;
