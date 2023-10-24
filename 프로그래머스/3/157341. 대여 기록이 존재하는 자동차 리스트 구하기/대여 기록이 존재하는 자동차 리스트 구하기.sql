-- 코드를 입력하세요
select distinct c.car_id
from car_rental_company_car c
join car_rental_company_rental_history h
on c.car_id = h.car_id
where h.start_date between '2022-10-01' and '2022-10-31'
and car_type = '세단'
order by c.car_id desc;
