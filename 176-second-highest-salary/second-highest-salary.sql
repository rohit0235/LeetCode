# Write your MySQL query statement below

select (select distinct salary as SecondHighestSalary from Employee  order by salary desc limit 1,1) as SecondHighestSalary;