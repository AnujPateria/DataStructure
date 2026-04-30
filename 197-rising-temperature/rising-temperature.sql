-- select w1.id from Weather as w1 INNER JOIN Weather as w2 on DATEDIFF(w1.recordDate , w2.recordDate) = 1 
-- where w1.temperature > w2. temperature

select w1.id from Weather as w1 where temperature > ( select temperature from Weather as w2 where w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
);