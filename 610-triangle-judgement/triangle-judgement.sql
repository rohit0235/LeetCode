# Write your MySQL query statement below

select x,y,z,if( x+y>z and y+z>x and z+x>y, "Yes" ,"No" ) as triangle from Triangle;
-- select x,y,z, if(x+y>z and y+z>x and x+z>y, 'Yes', 'No') as triangle from triangle