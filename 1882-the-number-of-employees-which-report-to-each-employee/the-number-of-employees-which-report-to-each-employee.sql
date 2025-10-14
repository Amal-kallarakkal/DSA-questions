/* Write your T-SQL query statement below */
select  mgr.employee_id,
        mgr.name,
        count(emp.reports_to) as reports_count,
        round(avg(emp.age * 1.0), 0) as average_age 
from Employees mgr
join Employees emp on mgr.employee_id = emp.reports_to
group by mgr.employee_id,mgr.name
order by employee_id
