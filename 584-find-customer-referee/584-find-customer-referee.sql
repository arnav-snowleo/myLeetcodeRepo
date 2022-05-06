# Write your MySQL query statement below

select name from CUSTOMER where (referee_id IS NULL || referee_id != 2 )