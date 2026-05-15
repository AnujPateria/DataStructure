-- select employee_id, name, count(employee_id) as reports_count, avg(age) as average_age from Employees group by reports_to;

select e2.employee_id, e2.name, count(e1.employee_id) as reports_count, ROUND(avg(e1.age)) as average_age from Employees as e1  join
Employees e2 
on 
e1.reports_to = e2.employee_id
group by e2.employee_id, e2.name order by e2.employee_id;


-- //select name from employee where employee_id = report_id