# Write your MySQL query statement below
select  firstName,lastname,city,state
from Person
LEFT  JOIN  Address ON Person.personId=Address.personId;