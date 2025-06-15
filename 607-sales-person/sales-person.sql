# Write your MySQL query statement below

select name from SalesPerson p

where p.sales_id not in 

(select sales_id from Company c inner join  Orders o on (c.com_id=o.com_id and c.name='Red'));