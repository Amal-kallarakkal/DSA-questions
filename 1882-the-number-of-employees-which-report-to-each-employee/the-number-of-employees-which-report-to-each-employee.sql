/* Write your T-SQL query statement below */
select  e2.reports_to as employee_id,
        max(e1.name) as name,
        count(e2.reports_to) as reports_count,
        round(avg(e2.age * 1.0), 0) as average_age 
from Employees e1
join Employees e2 on e1.employee_id = e2.reports_to
group by e2.reports_to;