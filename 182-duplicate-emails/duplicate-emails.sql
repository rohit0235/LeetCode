# Write your MySQL query statement below
select  distinct email   from Person
group by email 
having count(email)>1;

-- select email from person where email = (
--      select count
-- )