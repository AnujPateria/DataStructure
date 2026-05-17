# Write your MySQL query statement below

select v1.customer_id , count(*) as count_no_trans from Visits v1
where v1.visit_id not in (select visit_id from Transactions) group by customer_id;