/* Write your T-SQL query statement below */
with cte as (
    select * ,
        lead(num) over(order by id) as next_num,
        lag(num) over (order by id) as prev_num
    from Logs
)

select distinct(num) as ConsecutiveNums 
from cte
where next_num = prev_num and num = next_num
