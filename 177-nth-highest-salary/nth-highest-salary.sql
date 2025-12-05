CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN   
 SET N =N-1;
  RETURN (

        select distinct salary as getNthHighestSalary

        FROM Employee 
        ORDER BY salary desc 
        LIMIT 1 OFFSET N
    


  );
END