# Write your MySQL query statement below
-- select  distinct p.email from Person p
-- INNER JOIN Person p2 on (p.id!=p2.id && p.email=p2.email);


select distinct email from person p group by email having count(*)>1;