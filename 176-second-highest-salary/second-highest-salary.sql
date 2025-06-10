# Write your MySQL query statement below

-- select (select distinct salary from Employee  order by salary desc limit 1,1) as SecondHighestSalary;

# Write your MySQL query statement below
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM Employee)