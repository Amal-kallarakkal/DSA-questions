# Write your MySQL query statement below
SELECT
    customer_id,
    COUNT(*) AS count_no_trans
FROM 
    Visits as V
    LEFT JOIN Transactions as T ON V.visit_id = T.visit_id
WHERE 
    T.visit_id IS NULL
GROUP BY 
    customer_id
