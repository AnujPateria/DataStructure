# Write your MySQL query statement below
-- select e2.unique_id, e1.name from Employees e1 left join 
-- EmployeeUNI e2 on e1.id = e2.id;

select (select e2.unique_id from EmployeeUNI e2 where e1.id = e2.id) as unique_id , e1.name from Employees e1;