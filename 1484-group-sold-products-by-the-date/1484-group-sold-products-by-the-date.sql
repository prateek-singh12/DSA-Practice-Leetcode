# Write your MySQL query statement below
# Write your MySQL query statement below
-- only serious challange of this problem is how to aggregate the product names in one cell. In MySql, this can be done using GROUP_CONCAT, in which you can also specify the sorting mechanism for the group concatenation (aggregation). The rest is simple.

-- SYNTAX:-SELECT GROUP_CONCAT(column_name SEPARATOR 'separator') FROM table_name;

Select sell_date, count(distinct product) as num_sold, group_concat(distinct product order by product asc) as products
from Activities
group by sell_date
order by sell_date