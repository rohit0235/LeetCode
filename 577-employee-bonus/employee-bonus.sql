# Write your MySQL query statement below

select e.name,b.bonus from Employee as  e  left JOIN bonus as b on  e.empId=b.empId where b.bonus<1000 OR b.bonus IS NULL;