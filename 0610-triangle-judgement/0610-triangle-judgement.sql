/* Write your T-SQL query statement below */
select * , 
    case 
        when x + y > z and z + x > y and z + y > x then 'Yes'
        else 'No'
        end as triangle
from Triangle 