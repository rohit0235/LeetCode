-- # Write your MySQL query statement below
-- select name  as Employee  from Employee e1

-- where e1.salary >= (select salary from Employee e2 where e1.managerId = e2.id);

SELECT e1.Name AS Employee
FROM Employee e1
JOIN Employee e2
ON e1.ManagerId = e2.Id AND e1.Salary > e2.Salary;