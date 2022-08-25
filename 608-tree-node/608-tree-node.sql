# Write your MySQL query statement below

select id ,

CASE 

WHEN p_id IS NULL THEN "Root"
WHEN id NOT IN ( select p_id from tree where p_id IS NOT NULL) THEN "Leaf"
ELSE "Inner"

END AS type

from tree

ORDER BY id;

