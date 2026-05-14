# Write your MySQL query statement below
-- select w1.id from Weather as w1 where w1.temperature > (select w2.temperature from Weather as w2 where w2.recordDate = DATE_SUB(w1.recordDate, interval 1 day ))

select w1.id from Weather as w1 inner join Weather as w2 on  DATEDIFF(w1.recordDate,  w2.recordDate) = 1
where w1.temperature > w2.temperature


-- select w1.id from Weather as w1 INNER JOIN Weather as w2 on DATEDIFF(w1.recordDate , w2.recordDate) = 1 
-- where w1.temperature > w2. temperature