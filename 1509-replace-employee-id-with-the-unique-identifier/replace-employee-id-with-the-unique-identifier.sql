# Write your MySQL query statement below
select ee.unique_id, e.name FROM Employees as e LEFT JOIN EmployeeUNI as ee on e.id = ee.id