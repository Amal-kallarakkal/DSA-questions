/* Write your T-SQL query statement below */
with  cte as (
    select employee_id , max(department_id) as department_id
    from Employee 
    group by employee_id
    having count(department_id) = 1 
)
select employee_id, department_id
from cte
union
select employee_id, department_id
from Employee
where  primary_flag = 'Y'
