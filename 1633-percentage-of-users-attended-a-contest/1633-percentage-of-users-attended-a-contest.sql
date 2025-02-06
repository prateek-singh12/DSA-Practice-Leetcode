# Write your MySQL query statement below
select B.contest_id, round((count(B.user_id)/(select count(*) from Users))*100,2) as percentage 
from Users A, Register B
where A.user_id=B.user_id
group by B.contest_id
order by percentage DESC, B.contest_id ASC;
-- Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.