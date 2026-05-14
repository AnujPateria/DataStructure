# Write your MySQL query statement below
select max(n1.num) as num from MyNumbers n1 join (select num as number from MyNumbers group by num having count(num) = 1) n2
on n2.number = n1.num;