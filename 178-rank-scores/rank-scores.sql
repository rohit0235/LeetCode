
 select score , DENSE_RANK() OVER (ORDER  BY SCORE DESC) as 'rank' from Scores 


