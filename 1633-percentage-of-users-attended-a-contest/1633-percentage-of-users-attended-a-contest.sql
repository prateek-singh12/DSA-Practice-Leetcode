SELECT 
    r.contest_id,
    ROUND(COUNT(DISTINCT r.user_id) * 100.0 / COUNT(DISTINCT u.user_id), 2) AS percentage
FROM Register r
JOIN Users u
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;


-- select B.contest_id, round((count(B.user_id)/(select count(*) from Users))*100,2) as percentage 
-- from Users A, Register B
-- where A.user_id=B.user_id
-- group by B.contest_id
-- order by percentage DESC, B.contest_id ASC;
-- -- Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.