# Write your MySQL query statement below
-- select customer_id from Customer as c group by customer_id join Product 
-- having count(distinct c.product_id)  = c

select c1.customer_id from Customer c1  
cross join Product p 
left join Customer c2
on c1.customer_id = c2.customer_id
and 
c2.product_key = p.product_key
group by c1.customer_id
having count(c2.product_key) = count(p.product_key);



