# Write your MySQL query statement below
select ROUND(sum(case when order_date = customer_pref_delivery_date then 1 else 0 end) * 100.0 / count(*)  , 2) as immediate_percentage from delivery as d JOIN (
select customer_id, min(order_date) as first_order from delivery group by customer_id ) f on
d.customer_id = f.customer_id and
d.order_date = f.first_order