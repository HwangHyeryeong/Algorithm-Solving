SELECT COUNT(*) AS FISH_COUNT, MAX(N.FISH_NAME) AS FISH_NAME
FROM FISH_NAME_INFO N
JOIN FISH_INFO F
ON F.FISH_TYPE = N.FISH_TYPE
GROUP BY F.FISH_TYPE
ORDER BY FISH_COUNT DESC;