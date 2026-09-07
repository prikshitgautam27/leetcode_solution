# Write your MySQL query statement below
select sw.id from Weather w
join 
Weather sw
 on Datediff(sw.recordDate ,w.recordDate )=1
where sw.temperature >w.temperature;