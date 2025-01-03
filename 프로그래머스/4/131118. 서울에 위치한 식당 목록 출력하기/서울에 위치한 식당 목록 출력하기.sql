-- 식당 ID, 식당 이름, 음식 종류, 즐겨찾기수, 주소, 리뷰 평균 점수를 조회(이때 리뷰 평균점수는 소수점 세 번째 자리에서 반올림)
SELECT I.REST_ID AS REST_ID, I.REST_NAME AS REST_NAME, I.FOOD_TYPE AS FOOD_TYPE, 
    I.FAVORITES AS FAVORITES, I.ADDRESS AS ADDRESS, ROUND(AVG(R.REVIEW_SCORE), 2) AS SCORE
FROM REST_REVIEW R
JOIN REST_INFO I
ON I.REST_ID = R.REST_ID
-- 서울에 위치한
WHERE ADDRESS LIKE '서울%'
GROUP BY R.REST_ID
-- 평균점수를 기준으로 내림차순 정렬, 평균점수가 같다면 즐겨찾기수를 기준으로 내림차순 정렬
ORDER BY SCORE DESC, FAVORITES DESC;