# Write your MySQL query statement below


# select max(salary) as SecondHighestSalary from employee where salary < (select max(salary) from employee);


# USE DISTINCT KEYWORD else, this limit query does not include null values
# select salary as SecondHighestSalary from employee order by salary desc LIMIT 1,1;

select (

    Select distinct salary  from employee order by salary desc limit 1,1
)

as SecondHighestSalary;