SELECT title AS "Title of the longest movie"
FROM movies
	WHERE min_duration = 
	(SELECT MIN(NULLIF(min_duration, 0)) FROM movies);