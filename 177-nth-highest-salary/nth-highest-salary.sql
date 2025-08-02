CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      WITH cte AS (
          SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk 
          FROM employee
      )
      SELECT IFNULL(
          (SELECT DISTINCT salary FROM cte WHERE rnk = N),
          NULL
      ) AS getNthHighestSalary
  );
END