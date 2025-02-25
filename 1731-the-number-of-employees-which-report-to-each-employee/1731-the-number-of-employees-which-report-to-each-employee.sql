# Write your MySQL query statement below

select B.employee_id, B.name, COUNT(A.employee_id) as reports_count, ROUND(AVG(A.age)) as average_age
from employees  A join employees B
on A.reports_to = B.employee_id
group by employee_id
order by employee_id
