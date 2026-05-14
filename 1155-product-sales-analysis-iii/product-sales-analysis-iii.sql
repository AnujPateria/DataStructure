-- # Write your MySQL query statement below
-- select s1.product_id, s1.year as first_year, s1.quantity, price from Sales  s1 where s1.year = (select min(s2.year) from Sales  s2 where s1.product_id = s2.product_id);

select s1.product_id, s1.year as first_year, s1.quantity, s1.price from Sales s1
join 
(select min(year) as first_year, product_id from Sales group by product_id ) s2 ON 
s1.product_id = s2.product_id AND s1.year = s2.first_year ;