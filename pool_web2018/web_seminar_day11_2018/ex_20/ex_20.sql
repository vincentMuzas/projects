SELECT prod_year, count(prod_year) FROM movies
WHERE prod_year > 0 GROUP BY prod_year;