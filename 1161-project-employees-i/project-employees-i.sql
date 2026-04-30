# Write your MySQL query statement below
select e1.project_id, ROUND(AVG(e2.experience_years), 2) as average_years from Project as e1 LEFT JOIN 
Employee as e2 on e1.employee_id = e2.employee_id  group by e1.project_id